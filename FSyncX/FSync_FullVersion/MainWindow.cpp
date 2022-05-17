
#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QStackedWidget>
#include <QDesktopServices>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Theme
    // commonHelper->setStyle("://BlueSoulDark.qss");
    // commonHelper->setStyle("://Ubuntu.qss");
    // commonHelper->setStyle("://ConsoleStyle.qss");

    commonHelper->setStyle("://MacOS.qss");
    
    /*UI指针传递*/
    //在MainWindow的构造函数中，将ui指针的值通过UI文件夹下各个UI分文件，传递给XX.cpp中的ui这个全局变量
    //就可以在UI下面的XX.cpp中使用ui及其所有的控件了，和在mainwindow.cpp没有区别



    ContextMenuInit();
    UIInit();
    FileWatcherInit();
    FileBaseInit();


    //默认处于HomePage
    isHomePageNow = true;
    isSyncPageNow = false;
    isBasePageNow = false;

    isSyncPathValid = false;
    isSyncBaseConnected = false;
    isBasePathValid = false;
    isONSync = false;
    isONListen = false;

    Base_HostGot = commonHelper->getHostIPV4Address().toString();
    Base_PortSet = ui->LEditServerPort->text();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UIInit()
{
    // Default Page
    ui->APPPage->setCurrentWidget(ui->HomePage);
    
}

void MainWindow::FileWatcherInit()
{
    // /*SetWatchPath-SyncPath*/
    // fileWatcher.setWatchPath(syncPath);

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

    connect(this,
            SIGNAL(signal_ConnectToFBase(QString, QString)),
            &fileTransfer,
            SLOT(slot_ConnectToFBase(QString, QString)));

    connect(&fileTransfer,
            SIGNAL(signal_FromFileTransfer(QString)),
            this,
            SLOT(slot_FromFileTransfer(QString)));
}

void MainWindow::FileBaseInit()
{
    connect(&fileBase, SIGNAL(signal_File(QString, QByteArray)), this, SLOT(slot_File(QString, QByteArray)));
    connect(&fileBase, SIGNAL(signal_Del(QString)), this, SLOT(slot_Del(QString)));
    connect(&fileBase, SIGNAL(signal_Rename(QString, QString)), this, SLOT(slot_Rename(QString, QString)));

    connect(&fileBase, SIGNAL(signal_ServerListen(bool)), this, SLOT(slot_ServerListen(bool)));

    // basePath = "C:\\Users\\22012\\Desktop\\Qt projects\\FSyncX\\FileBase\\BasePath_Test";

    connect(this, SIGNAL(signal_ONOFF_ServerListen(QString, QString, QString)), &fileBase, SLOT(slot_ONOFF_ServerListen(QString, QString, QString)));
}


/*********************************右键菜单****************************/
/*右键菜单-基本元素构造*/
void MainWindow::ContextMenuInit()
{
    //重写Debug窗口自带默认的右键菜单 
    ui->TBrwSyncDebug->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->TBrwBaseDebug->setContextMenuPolicy(Qt::CustomContextMenu);

    //TBrwDebug
    CotextMenu_TBrwDebug =  new QMenu; //object
    action_cleanDebug = new QAction("Clean up", this); //Action
    CotextMenu_TBrwDebug -> addAction(action_cleanDebug);
    //customContextMenuRequested / SLOT_Show
    connect(ui->TBrwSyncDebug, SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(slot_showContextMenu_TBrwDebug(QPoint)));
    //QAction Signal/Slot
    connect(action_cleanDebug, SIGNAL(triggered()), this, SLOT(slotAct_cleanTBrwDebug()));
    
}

/*//@tag 弹出右键菜单-槽函数 */
void MainWindow::slot_showContextMenu_TBrwDebug(QPoint pos)
{
    CotextMenu_TBrwDebug->exec(QCursor::pos()); //在光标位置弹出TBrwDebug右键菜单 
}

void MainWindow::slotAct_cleanTBrwDebug()
{
    ui->TBrwSyncDebug->clear();
}











//*************************s***********************************************SLOTS
//************************************************** //@tag 页面管理
/*I'm FileSync-Client >>*/
void MainWindow::on_btnFileSync_clicked()
{
    ui->APPPage->setCurrentWidget(ui->SyncPage);
    isHomePageNow = false;
    isSyncPageNow = true;
    isBasePageNow = false;

}
/*I'm FileBase-Server >>*/
void MainWindow::on_btnFileBase_clicked()
{
    ui->APPPage->setCurrentWidget(ui->BasePage);
    isHomePageNow = false;
    isSyncPageNow = false;
    isBasePageNow = true;
}
/*menubar-backhome action*/
void MainWindow::on_actionBackHome_triggered()
{
    if (isHomePageNow)
        return;

    //弹出警告提示窗口
    //回到HomePage将中断当前页面属性的相关连接
    QMessageBox::StandardButton ret = QMessageBox::question(this, "Warning", "BackHomePage will break the Connection, Right?");

    if (ret == QMessageBox::No)
        return;

    /*同意退回到HomePage*/
    if (isSyncPageNow)
    {
        emit signal_Reject_or_Break_Connection(Sync_HostToConnect, Sync_PortToConnect, "Break"); //中断连接
        isONSync = false;                                                                        //关闭同步

        //*页面状态*//
        ui->APPPage->setCurrentWidget(ui->HomePage);
        ui->BtnConnectToFBase->setEnabled(true);
        ui->BtnStartSync->setEnabled(true);
        isHomePageNow = true;
        isSyncPageNow = false;
    }
    if (isBasePageNow)
    {
        emit signal_Reject_or_Break_Connection(Base_HostGot, Base_PortSet, "Break"); //中断
        emit signal_ONOFF_ServerListen(Base_HostGot, Base_PortSet, "OFF");           //向FileBase发送关闭监听信号
        isONListen = false;

        ui->APPPage->setCurrentWidget(ui->HomePage);
        ui->BtnStartListen->setEnabled(true);
        isHomePageNow = true;
        isBasePageNow = false;
    }
}

/****************************************************** //  @tag UI - FileSync Page */
void MainWindow::on_BtnChoseSyncPath_clicked()
{
    //文件夹路径
    syncPath = QFileDialog::getExistingDirectory(
        this, "choose SyncPath Directory",
        "/");

    if (syncPath.isEmpty())
    {
        isSyncPathValid = false;
        return;
    }

    isSyncPathValid = true;

    commonHelper->TBOut(ui->TBrwSyncDebug, "[SyncPath]" + syncPath);

    ui->TBrwSyncPath->clear();
    commonHelper->TBOut(ui->TBrwSyncPath, syncPath + "/");

    /*SetWatchPath-SyncPath*/
    fileWatcher.setWatchPath(syncPath);

    if (isSyncPathValid)
    {
        ui->PBarSyncConfig->setValue(1);
        commonHelper->Delay(100);
        ui->PBarSyncConfig->setValue(10);
        commonHelper->Delay(80);
        ui->PBarSyncConfig->setValue(20);
    }
    /*补充 - 因为允许先建立连接，再选择路径*/
    //置位连接状态
    if (isSyncBaseConnected && isSyncPathValid)
    {
        ui->PBarSyncConfig->setValue(30);
        commonHelper->Delay(100);
        ui->PBarSyncConfig->setValue(40);
        commonHelper->Delay(80);
        ui->PBarSyncConfig->setValue(55);
    }
}
/*按钮点击-请求连接FBase*/
void MainWindow::on_BtnConnectToFBase_clicked()
{
    Sync_HostToConnect = commonHelper->GetLEditContent(ui->LEditIP);
    Sync_PortToConnect = commonHelper->GetLEditContent(ui->LEditPort);

    commonHelper->TBOut(ui->TBrwSyncDebug,
                        "[SYS] Connect to ");
    commonHelper->TBOut(ui->TBrwSyncDebug,
                        "HOST: " + Sync_HostToConnect);
    commonHelper->TBOut(ui->TBrwSyncDebug,
                        "PORT: " + Sync_PortToConnect);
    //发送到FileTransfer.cpp
    emit signal_ConnectToFBase(Sync_HostToConnect, Sync_PortToConnect);
}

/*按钮点击-开启同步*/
void MainWindow::on_BtnStartSync_clicked()
{
    if (!isSyncPathValid || !isSyncBaseConnected)
    {
        commonHelper->TBOut(ui->TBrwSyncDebug, "[ONSync] [ERROR] SyncPath/Connection is not built...");
        return;
    }

    commonHelper->TBOut(ui->TBrwSyncDebug, "[ONSync] Congratulate! Syncing...");
    //打开全局 允许同步开关
    isONSync = true;
    //禁用打开同步按钮
    ui->BtnStartSync->setEnabled(false);
    ui->PBarSyncConfig->setValue(100);
}

/*按钮点击-打开FSync端同步文件夹*/
void MainWindow::on_BtnOpenSyncPath_clicked()
{
    if (!isSyncPathValid || !QDesktopServices::openUrl(QUrl::fromLocalFile(syncPath)))
    {
        commonHelper->TBOut(ui->TBrwSyncDebug, "[ERROR] Please Check syncPath!...");
        return;
    }

    commonHelper->TBOut(ui->TBrwSyncDebug, "[OpenSyncPath] Open SyncPath :");
    commonHelper->TBOut(ui->TBrwSyncDebug, syncPath);
}

//******************************************************** // @tag UI -  FileBase Page

void MainWindow::on_BtnChoseBasePath_clicked()
{
    //文件夹路径
    BasePath = QFileDialog::getExistingDirectory(
        this, "choose BasePath Directory",
        "/");

    if (BasePath.isEmpty())
    {
        isBasePathValid = false;
        return;
    }

    isBasePathValid = true;
    commonHelper->TBOut(ui->TBrwBaseDebug, "[BasePath]" + BasePath);
    ui->TBrwBasePath->clear();
    commonHelper->TBOut(ui->TBrwBasePath, BasePath + "/");

    if (isBasePathValid)
    {
        ui->PBarBaseConfig->setValue(1);
        commonHelper->Delay(100);
        ui->PBarBaseConfig->setValue(10);
        commonHelper->Delay(80);
        ui->PBarBaseConfig->setValue(20);
    }
    /*补充 - 因为允许先建立连接，再选择路径*/
    //置位连接状态
    if (isSyncBaseConnected && isBasePathValid)
    {
        ui->PBarBaseConfig->setValue(30);
        commonHelper->Delay(100);
        ui->PBarBaseConfig->setValue(40);
        commonHelper->Delay(80);
        ui->PBarBaseConfig->setValue(55);
    }
}

/*按钮点击-打开Base端同步文件夹*/
void MainWindow::on_BtnOpenBasePath_clicked()
{
    if (!QDesktopServices::openUrl(QUrl::fromLocalFile(BasePath)))
    {
        commonHelper->TBOut(ui->TBrwBaseDebug, "[ERROR] Please Check BasePath!...");
        return;
    }

    commonHelper->TBOut(ui->TBrwBaseDebug, "[OpenSyncPath] Open BasePath :");
    commonHelper->TBOut(ui->TBrwBaseDebug, BasePath);
}

/*按钮切换-切换监听状态*/
void MainWindow::on_BtnStartListen_clicked()
{
    if (!isBasePathValid) //路径无效
    {
        commonHelper->TBOut(ui->TBrwBaseDebug, "[ONListen] [ERROR] SyncPath is not built..");
        return;
    }
    commonHelper->TBOut(ui->TBrwBaseDebug, "[ONListen] Congratulate! Listening...");
    //打开全局 允许监听开关
    isONListen = true;

    /*向FileBase发送请求 监听*/
    emit signal_ONOFF_ServerListen(Base_HostGot, Base_PortSet, "ON");

    //禁用打开监听按钮
    ui->BtnStartListen->setEnabled(false);
    ui->PBarBaseConfig->setValue(30);
    commonHelper->Delay(200);
    ui->PBarBaseConfig->setValue(40);
    commonHelper->Delay(200);
    ui->PBarBaseConfig->setValue(60);
    commonHelper->Delay(200);
    ui->PBarBaseConfig->setValue(80);
    commonHelper->Delay(200);
    ui->PBarBaseConfig->setValue(100);
}

/*按钮点击-刷新获取IP*/
void MainWindow::on_BtnGetIP_clicked()
{
    //    if(!isBasePathValid || !isSyncBaseConnected) //路径无效或未连接
    //    {
    //        commonHelper->TBOut(ui->TBrwBaseDebug, "[ONListen] [ERROR] SyncPath/Connection is not built..");
    //        return;
    //    }

    commonHelper->TBOut(ui->TBrwBaseDebug, "Refresh IP...");

    /*更新BaseIPAddr*/
    BaseIPAddr = commonHelper->getHostIPV4Address().toString();

    /*填入TrwServerHos里面*/
    ui->TBrwServerHost->clear();
    commonHelper->TBOut(ui->TBrwServerHost, BaseIPAddr);

    if (isBasePathValid)
        ui->PBarBaseConfig->setValue(50);

    /*Debug*/
    commonHelper->TBOut(ui->TBrwBaseDebug, "[GOT IP]"  +  BaseIPAddr);
}

//******************************************************* //@tag 数据 - APP_Sync

void MainWindow::slot_DirectoryChanged(const QString &path)
{
    if (!isONSync)
        return;
    // commonHelper->TBOut(ui->TBrwSyncDebug, "[DirChanged]" + path);
}

void MainWindow::slot_FileChanged(const QString &file)
{
    if (!isONSync)
        return;
    commonHelper->TBOut(ui->TBrwSyncDebug, "[FileChanged]" + file);
    fileTransfer.sendFile(file);
}

void MainWindow::slot_FileAdded(const QString &file)
{
    if (!isONSync)
        return;
    commonHelper->TBOut(ui->TBrwSyncDebug, "[FileAdded]" + file);
    fileTransfer.sendFile(file);
}
void MainWindow::slot_FileRemoved(const QString &file)
{
    if (!isONSync)
        return;
    commonHelper->TBOut(ui->TBrwSyncDebug, "[FileRemoved]" + file);
    fileTransfer.sendDel(file);
}

void MainWindow::slot_FileRenamed(const QString &oldName, const QString &newName)
{
    if (!isONSync)
        return;
    commonHelper->TBOut(ui->TBrwSyncDebug, "[FileRename]");
    commonHelper->TBOut(ui->TBrwSyncDebug, oldName);
    commonHelper->TBOut(ui->TBrwSyncDebug, "=>");
    commonHelper->TBOut(ui->TBrwSyncDebug, newName);
    fileTransfer.sendRename(oldName, newName);
}

//*******************************************//@todo FromFileTransfer
/*接受FileTransfer的相关信息*/
void MainWindow::slot_FromFileTransfer(QString content)
{
    QMessageBox::StandardButton result;

    commonHelper->TBOut(ui->TBrwSyncDebug, content);

    /*采用禁用按钮的方式，避免已连接的情况, 再重复点击请求连接(实际上会自动阻塞，不能再连接)*/
    if (content == "[Sync/Base] Connected")
    {
        if (isBasePageNow) //限制弹窗只在对应的页面弹出
        {
            result = QMessageBox::question(ui->BasePage, "CONNECT", "[From Fsync-Client]Accept Requested Connection?");
        }

        if (result == QMessageBox::No)
        {
            commonHelper->TBOut(ui->TBrwBaseDebug, "[Wanning] You - Rejected - The Connection!");

            /*回传服务器拒绝信号*/
            connect(this, SIGNAL(signal_Reject_or_Break_Connection(QString, QString, QString)),
                    &fileTransfer,
                    SLOT(slot_Reject_or_Break_Connection(QString, QString, QString)));
            emit signal_Reject_or_Break_Connection(Sync_HostToConnect, Sync_PortToConnect, "Reject");

            return;
        }

        commonHelper->TBOut(ui->TBrwBaseDebug, content);
        ui->BtnConnectToFBase->setEnabled(false);

        if (isSyncPathValid)
            ui->PBarSyncConfig->setValue(55);

        //置位连接状态
        isSyncBaseConnected = true;
    }
    if (content == "[Sync/Base] Disconnected")
    {
        commonHelper->TBOut(ui->TBrwBaseDebug, content);
        ui->BtnConnectToFBase->setEnabled(true);
        ui->PBarSyncConfig->setValue(20);

        //置位连接状态
        isSyncBaseConnected = false;
    }

    /**********UI相关回传控制************/
    if (content == "[FileTransfer] Reject message received") // Server发起拒绝
    {
        if (isSyncPageNow)
        {
            QMessageBox::warning(ui->SyncPage, "Warning", "FBase-Server Rejected the Connection!");
        }
        commonHelper->TBOut(ui->TBrwBaseDebug, content);
        ui->BtnConnectToFBase->setEnabled(true);
        ui->PBarSyncConfig->setValue(20);
        isSyncBaseConnected = false;
    }
    if (content == "[FileTransfer] Break message received") // Server发起中断
    {

        QMessageBox::warning(this, "Warning", "Connection Broke!");
    }
}

//*************************************************** //@tag 数据 - APP_Base
void MainWindow::slot_File(const QString &fileName, const QByteArray &data)
{
    qDebug() << "File:" << fileName;

    commonHelper->TBOut(ui->TBrwBaseDebug, "[FSync Success - FileAdded]" + fileName);

    /// fileName是客户端文件的路径-根据传过来的fileName(路径),取出文件名（纯）
    QFileInfo fileInfo(fileName);
    QString fileNamePure = fileInfo.fileName();

    // fileNameLocal是服务端文件的路径-则本地该文件的路径就是fileBasePath + "/" + fileNamePure
    QString fileNameLocal = BasePath + "/" + fileNamePure;

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

void MainWindow::slot_Del(const QString &fileName)
{
    qDebug() << "Del:" << fileName;

    commonHelper->TBOut(ui->TBrwBaseDebug, "[FSync Success - FileRemoved]" + fileName);

    /// fileName是客户端文件的路径-根据传过来的fileName(路径),取出文件名（纯）
    QFileInfo fileInfo(fileName);
    QString fileNamePure = fileInfo.fileName();

    // fileNameLocal是服务端文件的路径-则本地该文件的路径就是fileBasePath + "/" + fileNamePure
    QString fileNameLocal = BasePath + "/" + fileNamePure;

    QFile::remove(fileNameLocal);
}

void MainWindow::slot_Rename(const QString &fileOld, const QString &fileNew)
{
    qDebug() << "Rename:" << fileOld << fileNew;

    commonHelper->TBOut(ui->TBrwBaseDebug, "[FSync Success - FileRename]");
    commonHelper->TBOut(ui->TBrwBaseDebug, fileOld);
    commonHelper->TBOut(ui->TBrwBaseDebug, "=>");
    commonHelper->TBOut(ui->TBrwBaseDebug, fileNew);

    /// fileName是客户端文件的路径-根据传过来的fileName(路径),取出文件名（纯）
    QFileInfo fileInfoOld(fileOld), fileInfoNew(fileNew);
    ;
    QString fileNamePureOld = fileInfoOld.fileName();
    QString fileNamePureNew = fileInfoNew.fileName();

    // fileNameLocal是服务端文件的路径-则本地该文件的路径就是fileBasePath + "/" + fileNamePure
    QString fileNameLocalOld = BasePath + "/" + fileNamePureOld;
    QString fileNameLocalNew = BasePath + "/" + fileNamePureNew;

    if (QFile::rename(fileNameLocalOld, fileNameLocalNew))
    {
        commonHelper->TBOut(ui->TBrwBaseDebug, "Sync Rename SUCCESS!");
    }
    else
    {
        commonHelper->TBOut(ui->TBrwBaseDebug, "Sync Rename ERROR!");
    }
}

/*来自FileBase的是否 server.listen成功*/
void MainWindow::slot_ServerListen(bool isServerListenOK)
{
    QString ret;
    if (isServerListenOK)
        ret = "OK";
    else
        ret = "False";
    commonHelper->TBOut(ui->TBrwBaseDebug, "[ServerListen] Listen :" + ret);
}
