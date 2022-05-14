#include "FileBase.h"
#include <QDebug>

FileBase::FileBase(QObject *parent)
    : QObject{parent}
{
    connect(&server, SIGNAL(newConnection()), this, SLOT(slot_onNewConnection()));

    bool ok = server.listen(QHostAddress::AnyIPv4, 8888);
    qDebug() << "listen:" << ok;

    emit signal_ServerListen(ok);

    imageIndex = 0;
    sizePackLast = 0;
}

//***************************************************SLOTS

void FileBase::slot_onNewConnection()
{
    //使用这个socket客户端进行通信
    QTcpSocket *socket = server.nextPendingConnection();
    clients.append(socket);

    //连接信号和槽
    connect(socket, SIGNAL(readyRead()), this, SLOT(slot_onReadyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(slot_onConnected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(slot_onDisconnected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_onError(QAbstractSocket::SocketError)));
}

void FileBase::slot_onReadyRead()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(obj);

    //当前缓冲区里面数据的大小，收到的数据大小
    qint64 sizeNow = 0;
    do
    {
        sizeNow = socket->bytesAvailable();
        QDataStream stream(socket);

        if (sizePackLast == 0)
        {
            if (sizeNow < sizeof(quint32))
                return;
            stream >> sizePackLast; //已经在值了
        }

        //包不完整返回,等待包完整
        if (sizeNow < sizePackLast - 4)
            return;

        int msgType = MsgTypeInvalid;
        stream >> msgType;

        //设置为0
        sizePackLast = 0;
        //判断剩下的字节数，是否会有粘包的情况
        sizeNow = socket->bytesAvailable();

        switch (msgType)
        {
        case MsgTypeFile:
        {
            QString fileName;
            QByteArray dataFileContent;
            stream >> fileName >> dataFileContent;

            qDebug() << "File" << fileName << dataFileContent;

            emit signal_File(fileName, dataFileContent);
            break;
        }

        case MsgTypeDel:
        {
            QString fileDel;
            stream >> fileDel;

            qDebug() << "FileDel" << fileDel;

            emit signal_Del(fileDel);
            break;
        }

        case MsgTypeRename:
        {
            QString fileOld;
            QString fileNew;
            stream >> fileOld >> fileNew;

            qDebug() << "FileRename" << fileOld << "->" << fileNew;

            emit signal_Rename(fileOld, fileNew);
            break;
        }
        default:
        {
            break;
        }
        }
    } while (sizeNow > 0);
}

void FileBase::slot_onConnected()
{
    qDebug() << "connected";
}

void FileBase::slot_onDisconnected()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(obj);

    clients.removeAll(socket);
    socket->deleteLater();

    qDebug() << "disconnected";
}

void FileBase::slot_onError(QAbstractSocket::SocketError socketError)
{

    qDebug() << "error" << socketError;
}
