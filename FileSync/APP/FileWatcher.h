/*
 * @FilePath: \FileSync\APP\FileWatcher.h
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QFileSystemWatcher>


class FileWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FileWatcher(QObject *parent = nullptr);
    
    void setWatchPath(const QString &path);
    
signals:
    void singal_DirectoryChanged(const QString &path);
    void singal_FileChanged(const QString &path);


// 私有表示，只能这个类能使用
private slots:
    void onDirectoryChanged(const QString &path);
    void onFileChanged(const QString &path);

private:
    QFileSystemWatcher watcher;
};

#endif // FILEWATCHER_H
