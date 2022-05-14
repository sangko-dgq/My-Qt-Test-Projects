/*
 * @FilePath: \FileBase\widget.cpp
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(&fileBase, SIGNAL(signal_File(QString, QByteArray)), this, SLOT(slot_File(QString, QByteArray)));
    connect(&fileBase, SIGNAL(signal_Del(QString)), this, SLOT(slot_Del(QString)));
    connect(&fileBase, SIGNAL(signal_Rename(QString, QString)), this, SLOT(slot_Rename(QString, QString)));

    connect(&fileBase, SIGNAL(signal_ServerListen(bool)), this, SLOT(slot_ServerListen(bool)));
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
}

void Widget::slot_Del(const QString &fileName)
{
    qDebug() << "Del:" << fileName;

    ui->TBrwDebug->insertPlainText("[FileRemoved]" + fileName);
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));
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
