/*
 * @FilePath: \FileSync\APP\FileTransfer.h
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */

#ifndef FILETRANSFER_H
#define FILETRANSFER_H

#include <QObject>
#include <QTcpSocket>
#include <QIODevice>
#include <QDataStream>
#include <QFile>
#include <QDebug>

enum MsgType
{
    MsgTypeInvalid = 0,
    MsgTypeFile,
    MsgTypeDel,
    MsgTypeRename
};



class FileTransfer : public QObject
{
    Q_OBJECT

public:
    explicit FileTransfer(QObject *parent = nullptr);

    void sendFile(const QString &fileName);
    void sendDel(const QString &fileName);
    void sendRename(const QString &fileOld, const QString &fileNew);

signals:

public slots:
void slot_onReadyRead();
void slot_onConnected();
void slot_onDisconnected();
void slot_onError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket tcpSocket;
    

    
    


};

#endif // FILETRANSFER_H
