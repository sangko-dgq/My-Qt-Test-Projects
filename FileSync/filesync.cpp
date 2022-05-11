/*
 * @FilePath: \FileSync\filesync.cpp
 * @Description: UI函数
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */

#include "filesync.h"
#include "./ui_filesync.h"

#include <QDebug>

FileSync::FileSync(QWidget *parent)
    : QWidget(parent), ui(new Ui::FileSync)
{
    ui->setupUi(this);

    fileWatcher.setWatchPath("C:\\Users\\22012\\Desktop\\Qt projects\\FileSync\\WatchPath_Test");
    fileWatcher.setWatchPath("C:\\Users\\22012\\Desktop\\Qt projects\\FileSync\\WatchPath_Test\\mono.txt");
    
    connect(&fileWatcher,
            SIGNAL(singal_DirectoryChanged(const QString)),
            this,
            SLOT(slot_DirectoryChanged(const QString)));
    connect(&fileWatcher,
            SIGNAL(singal_FileChanged(const QString)),
            this,
            SLOT(slot_FileChanged(const QString)));
}

FileSync::~FileSync()
{
    delete ui;
}

//************************************************************************SLOTS

void FileSync::slot_DirectoryChanged(const QString &path)
{
    ui->TBrwDebug->insertPlainText("[DirChanged]" + path);
    // 文本输出结束后自动换行
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));
}
void FileSync::slot_FileChanged(const QString &path)
{
    ui->TBrwDebug->insertPlainText("[FileChanged]" + path);
    // 文本输出结束后自动换行
    ui->TBrwDebug->moveCursor(QTextCursor::End);
    ui->TBrwDebug->append(QString(""));
}