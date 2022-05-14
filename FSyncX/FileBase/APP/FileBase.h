/*
 * @FilePath: \FileBase\APP\FileBase.h
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#ifndef FILEBASE_H
#define FILEBASE_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QList>

#include <QDataStream>

enum MsgType
{
    MsgTypeInvalid = 0,
    MsgTypeFile,
    MsgTypeDel,
    MsgTypeRename
};

class FileBase : public QObject
{
    Q_OBJECT
public:
    explicit FileBase(QObject *parent = nullptr);

signals:
    void signal_File(const QString &fileName, const QByteArray &data);
    void signal_Del(const QString &fileName);
    void signal_Rename(const QString &fileOld, const QString &fileNew);

    void signal_ServerListen(bool isServerListenOK);

public slots:
    void slot_onNewConnection();

    void slot_onReadyRead();
    void slot_onConnected();
    void slot_onDisconnected();
    void slot_onError(QAbstractSocket::SocketError socketError);

private:
    QTcpServer server;
    QList<QTcpSocket *> clients;

    qint64 imageIndex;
    int sizePackLast;
};

#endif // FILEBASE_H
