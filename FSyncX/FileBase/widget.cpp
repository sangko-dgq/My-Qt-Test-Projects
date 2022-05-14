/*
 * @FilePath: \FileBase\widget.cpp
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(&fileBase, SIGNAL(signal_File(QString, QByteArray)), this, SLOT(slot_File(QString, QByteArray)));
    connect(&fileBase, SIGNAL(signal_Del(QString)), this, SLOT(slot_Del(QString)));
    connect(&fileBase, SIGNAL(signal_Rename(QString, QString)), this, SLOT(slot_Rename(QString, QString)));

    connect(&fileBase, SIGNAL(signal_ServerListen(bool)), this, SLOT(slot_ServerListen(bool)));

    fileBasePath = "C:\\Users\\22012\\Desktop\\Qt projects\\FSyncX\\FileBase\\BasePath_Test";
}

Widget::~Widget()
{
    delete ui;
}

//****************************************************************************SLOTS

void Widget::slot_File(const QString &fileName, const QByteArray &data)
{
    qDebug() << "File:" << fileName;

    ui->TBrwDebug->insertPlainText("[FileAdded]" + fileName);
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));

    /// fileName是客户端文件的路径-根据传过来的fileName(路径),取出文件名（纯）
    QFileInfo fileInfo(fileName);
    QString fileNamePure = fileInfo.fileName();

    // fileNameLocal是服务端文件的路径-则本地该文件的路径就是fileBasePath + "/" + fileNamePure
    QString fileNameLocal = fileBasePath + "/" + fileNamePure;

    //打开该文件路径，写入传过来的同步数据
    QFile file(fileNameLocal);
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "open file failed";
        return;
    }

    //将文件内容写入进去
    file.write(data);
    file.close();
}

void Widget::slot_Del(const QString &fileName)
{
    qDebug() << "Del:" << fileName;

    ui->TBrwDebug->insertPlainText("[FileRemoved]" + fileName);
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));

    /// fileName是客户端文件的路径-根据传过来的fileName(路径),取出文件名（纯）
    QFileInfo fileInfo(fileName);
    QString fileNamePure = fileInfo.fileName();

    // fileNameLocal是服务端文件的路径-则本地该文件的路径就是fileBasePath + "/" + fileNamePure
    QString fileNameLocal = fileBasePath + "/" + fileNamePure;

    QFile::remove(fileNameLocal);
}

void Widget::slot_Rename(const QString &fileOld, const QString &fileNew)
{
    qDebug() << "Rename:" << fileOld << fileNew;

    ui->TBrwDebug->insertPlainText("[FileRename]");
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));

    ui->TBrwDebug->insertPlainText(fileOld);
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));

    ui->TBrwDebug->insertPlainText("=>");
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));

    ui->TBrwDebug->insertPlainText(fileNew);
    // 文本输出结束后自动换行
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));

    /// fileName是客户端文件的路径-根据传过来的fileName(路径),取出文件名（纯）
    QFileInfo fileInfoOld(fileOld), fileInfoNew(fileNew);
    ;
    QString fileNamePureOld = fileInfoOld.fileName();
    QString fileNamePureNew = fileInfoNew.fileName();

    // fileNameLocal是服务端文件的路径-则本地该文件的路径就是fileBasePath + "/" + fileNamePure
    QString fileNameLocalOld = fileBasePath + "/" + fileNamePureOld;
    QString fileNameLocalNew = fileBasePath + "/" + fileNamePureNew;

    if (QFile::rename(fileNameLocalOld, fileNameLocalNew))
    {
        ui->TBrwDebug->insertPlainText("[同步重命名文件成功]");
        ui->TBrwDebug->moveCursor(QTextCursor::End);
        ui->TBrwDebug->append(QString(""));
    }
    else
    {
        ui->TBrwDebug->insertPlainText("[同步重命名文件失败]");
        ui->TBrwDebug->moveCursor(QTextCursor::End);
        ui->TBrwDebug->append(QString(""));
    }
    
}

void Widget::slot_ServerListen(bool isServerListenOK)
{
    QString ret;
    if (isServerListenOK)
        ret = "OK";
    else
        ret = "False";

    ui->TBrwDebug->insertPlainText("[Server Listen :]" + ret);
    // 文本输出结束后自动换行
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));
}
