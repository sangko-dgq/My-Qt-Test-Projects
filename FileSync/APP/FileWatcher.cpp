/*
 * @FilePath: \FileSync\APP\FileWatcher.cpp
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */

#include "FileWatcher.h"
#include <QDebug>

/*构造函数*/
FileWatcher::FileWatcher(QObject *parent)
    : QObject{parent}
{
    /*Singal - Slots*/
    connect(&watcher,
            SIGNAL(directoryChanged(QString)),
            this,
            SLOT(onDirectoryChanged(QString)));
    connect(&watcher,
            SIGNAL(fileChanged(QString)),
            this,
            SLOT(onFileChanged(QString)));
}

void FileWatcher::setWatchPath(const QString &path)
{
    watcher.addPath(path);
}

void FileWatcher::onDirectoryChanged(const QString &path)
{
    emit singal_DirectoryChanged(path);
    qDebug() << "[Dir Changed]" << path;
}
void FileWatcher::onFileChanged(const QString &path)
{
    emit singal_FileChanged(path);
    qDebug() << "[File Changed]" << path;

}
