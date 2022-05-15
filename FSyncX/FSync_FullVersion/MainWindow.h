/***
 * @Author: sangko-dgqq 2201225826@qq.com
 * @Date: 2022-05-15 02:40:39
 * @LastEditors: sangko-dgqq 2201225826@qq.com
 * @LastEditTime: 2022-05-15 19:31:17
 * @FilePath: \FSync_FullVersion\MainWindow.h
 * @Description:
 * @
 * @Copyright (c) 2022 by sangko-dgqq 2201225826@qq.com, All Rights Reserved.
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileInfo>
#include <QApplication>

#include <QWidget>
#include <QTextBrowser>
#include <QFileDialog>
#include <QLineEdit>

#include "APP_Sync/FileWatcher.h"
#include "APP_Sync/FileTransfer.h"
#include "APP_Base/FileBase.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

//******************************************************** MainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signal_ConnectToFBase(QString Host, QString port);
    


private slots:
    void on_btnFileSync_clicked();
    void on_btnFileBase_clicked();
    void on_actionBackHome_triggered();
    void on_BtnChoseSyncPath_clicked();
    void on_BtnChoseBasePath_clicked();
    void on_BtnConnectToFBase_clicked();

    /*APP_Sync*/
    void slot_DirectoryChanged(const QString &path);
    void slot_FileAdded(const QString &file);                              //增
    void slot_FileRemoved(const QString &file);                            //文件删除
    void slot_FileChanged(const QString &file);                            //目录下有改变
    void slot_FileRenamed(const QString &oldName, const QString &newName); //重命名

    /*接受FileTransfer的相关信息*/
    void slot_FromFileTransfer(QString content);

    /*APP_Base*/
    void slot_File(const QString &fileName, const QByteArray &data);
    void slot_Del(const QString &fileName);
    void slot_Rename(const QString &fileOld, const QString &fileNew);
    void slot_ServerListen(bool isServerListenOK);
    

private:
    Ui::MainWindow *ui;

    /*APP_Sync*/
    FileWatcher fileWatcher;
    FileTransfer fileTransfer;
    void FileWatcherInit();
    void FileBaseInit();

    void UIInit();

    /*SyncPage*/
    QString syncPath;
    QString HostToConnect, PortToConnect;

    /*BasePage*/
    FileBase fileBase;
    QString BasePath;
    

};

//******************************************************** CommonHelper
class CommonHelper
{
public:
    /*设置全局QSS样式*/
    static void setStyle(const QString &style);
    /*TextBrowser对象换行输出*/
    static void TBOut(QTextBrowser *TextBrowser, QString Content);
    /*获取LineEdit的内容*/
    static QString GetLEditContent(QLineEdit *LineEdit);
};

#endif // MAINWINDOW_H
