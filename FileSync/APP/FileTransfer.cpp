/*
 * @FilePath: \FileSync\APP\FileTransfer.cpp
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#include "FileTransfer.h"

FileTransfer::FileTransfer(QObject *parent)
    : QObject{parent}
{
    connect(&tcpSocket, SIGNAL(readyRead()), this, SLOT(slot_onReadReady()));
    connect(&tcpSocket, SIGNAL(connected()), this, SLOT(slot_onConnected()));
    connect(&tcpSocket, SIGNAL(disconnect()), this, SLOT(slot_onDisconnected()));
    connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_onError(QAbstractSocket::SocketError)));

    tcpSocket.connectToHost("127.0.0.1", 8888);
}

//************************************************************************Meathods

void FileTransfer::sendFile(const QString &fileName)
{
    //读取文件内容
    QByteArray dataFileContent;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "[sendFile]file open failed";
        return;
    }
    dataFileContent = file.readAll();
    file.close();

    //封装包头
    QByteArray dataSend; //封装的数据包

    QDataStream stream(&dataSend, QIODevice::WriteOnly);
    stream << (quint32)0 << MsgTypeFile << dataFileContent;
    stream.device()->seek(0);
    stream << dataSend.size();

    tcpSocket.write(dataSend);
}
void FileTransfer::sendDel(const QString &fileName)
{
    //封装包头
    QByteArray dataSend; //封装的数据包

    QDataStream stream(&dataSend, QIODevice::WriteOnly);
    stream << (quint32)0 << MsgTypeDel << fileName;
    stream.device()->seek(0);
    stream << dataSend.size();

    tcpSocket.write(dataSend);
}
void FileTransfer::sendRename(const QString &fileOld, const QString &fileNew)
{
    //封装包头
    QByteArray dataSend; //封装的数据包

    QDataStream stream(&dataSend, QIODevice::WriteOnly);
    stream << (quint32)0 << (int)MsgTypeRename << fileOld << fileNew;
    stream.device()->seek(0);
    stream << dataSend.size();

    tcpSocket.write(dataSend);
}

//************************************************************************SLOTS
void FileTransfer::slot_onReadReady()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(obj);

    //当前缓冲区里面数据的大小，收到的数据大小
    qint64 sizeNow = 0;
    qint64 sizePackLast;
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
            QByteArray dataFileContent;
            stream >> dataFileContent;
            break;
        }

        case MsgTypeDel:
        {
            QString fileDel;
            stream >> fileDel;
            break;
        }

        case MsgTypeRename:
        {
            QString fileOld;
            QString fileNew;
            stream >> fileOld >> fileNew;
            break;
        }
        default:
        {
            break;
        }
        }
    } while (sizeNow > 0);
}

void FileTransfer::slot_onConnected()
{
    qDebug() << "connected";
}
void FileTransfer::slot_onDisconnected()
{
    qDebug() << "disconnected";

    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(obj);
    if (socket == 0)
        return;

    socket->close();
}
void FileTransfer::slot_onError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "socket error";
}