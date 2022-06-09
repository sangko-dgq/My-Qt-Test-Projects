/*
 * @FilePath: \FileSync\filesync.cpp
 * @Description: UI窗口函数
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */

#include "filesync.h"
#include "./ui_filesync.h"
#include <QDebug>

//************************************************************************构造与析构
FileSync::FileSync(QWidget *parent)
    : QWidget(parent), ui(new Ui::FileSync)
{
    ui->setupUi(this);

    fileWatcher.setWatchPath("C:\\Users\\22012\\Desktop\\Qt projects\\FSyncX\\FileSync\\SyncPath_Test");
    /*Singal - Slots*/
    connect(&fileWatcher,
            SIGNAL(singal_DirectoryChanged(const QString)),
            this,
            SLOT(slot_DirectoryChanged(const QString)));
    connect(&fileWatcher,
            SIGNAL(singal_FileChanged(const QString)),
            this,
            SLOT(slot_FileChanged(const QString)));
    connect(&fileWatcher,
            SIGNAL(singal_FileAdded(const QString)),
            this,
            SLOT(slot_FileAdded(const QString)));
    connect(&fileWatcher,
            SIGNAL(singal_FileRemoved(const QString)),
            this,
            SLOT(slot_FileRemoved(const QString)));
    connect(&fileWatcher,
            SIGNAL(singal_FileRenamed(const QString, const QString)),
            this,
            SLOT(slot_FileRenamed(const QString, const QString)));
}

FileSync::~FileSync()
{
    delete ui;
}

//************************************************************************SLOTS

void FileSync::slot_DirectoryChanged(const QString &path)
{
    // ui->TBrwDebug->insertPlainText("[DirChanged]" + path);
    // 文本输出结束后自动换行
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));
}
void FileSync::slot_FileChanged(const QString &file)
{
    ui->TBrwDebug->insertPlainText("[FileChanged]" + file);
    // 文本输出结束后自动换行
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));

     fileTransfer.sendFile(file);
}

void FileSync::slot_FileAdded(const QString &file)
{
    ui->TBrwDebug->insertPlainText("[FileAdded]" + file);
    // 文本输出结束后自动换行
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));


    fileTransfer.sendFile(file);
}
void FileSync::slot_FileRemoved(const QString &file)
{
    ui->TBrwDebug->insertPlainText("[FileRemoved]" + file);
    // 文本输出结束后自动换行
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));

    fileTransfer.sendDel(file);
}


void FileSync::slot_FileRenamed(const QString &oldName, const QString &newName)
{
    ui->TBrwDebug->insertPlainText("[FileRename]");
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));

    ui->TBrwDebug->insertPlainText(oldName);
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));

    ui->TBrwDebug->insertPlainText("=>");
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));

    ui->TBrwDebug->insertPlainText(newName);
    // 文本输出结束后自动换行
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));


    fileTransfer.sendRename(oldName, newName);
}




//************************************************************************Meathods
