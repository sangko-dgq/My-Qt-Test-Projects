/*
 * @FilePath: \FileSync\filesync.h
 * @Description: UI窗口函数
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#ifndef FILESYNC_H
#define FILESYNC_H

#include <QWidget>
#include "APP/FileWatcher.h"
#include "APP/FileTransfer.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class FileSync;
}
QT_END_NAMESPACE

class FileSync : public QWidget
{
    Q_OBJECT  //宏

public:
    FileSync(QWidget *parent = nullptr);
    ~FileSync();

private slots:
    void slot_DirectoryChanged(const QString &path);
    void slot_FileAdded(const QString &file);                              //增
    void slot_FileRemoved(const QString &file);                            //文件删除
    void slot_FileChanged(const QString &file);                            //目录下有改变
    void slot_FileRenamed(const QString &oldName, const QString &newName); //重命名

private:
    Ui::FileSync *ui;

    FileWatcher fileWatcher;
    FileTransfer fileTransfer;
};
#endif // FILESYNC_H
