/*
 * @FilePath: \FileSync\filesync.h
 * @Description: 
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#ifndef FILESYNC_H
#define FILESYNC_H

#include <QWidget>

#include "APP/FileWatcher.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class FileSync;
}
QT_END_NAMESPACE

class FileSync : public QWidget
{
    Q_OBJECT

public:
    FileSync(QWidget *parent = nullptr);
    ~FileSync();

private slots:
    void slot_DirectoryChanged(const QString &path);
    void slot_FileChanged(const QString &path);

private:
    Ui::FileSync *ui;
    FileWatcher fileWatcher;
};
#endif // FILESYNC_H
