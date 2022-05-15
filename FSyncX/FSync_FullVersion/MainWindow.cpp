#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Theme
    //  CommonHelper::setStyle("://BlueSoulDark.qss");
    CommonHelper::setStyle("://Ubuntu.qss");

    // Init
    UIInit();
    FileWatcherInit();
    FileBaseInit();
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
}

//**************************************************************** COMMON HELPER
/*设置全局QSS样式*/
void CommonHelper::setStyle(const QString &style)
{
    QFile qss(style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}
/*TextBrowser对象换行输出*/
void CommonHelper::TBOut(QTextBrowser *TextBrowser, QString Content)
{
    TextBrowser->insertPlainText(Content);
    // 文本输出结束后自动换行
    TextBrowser->moveCursor(QTextCursor::End);
    TextBrowser->append(QString(""));
}

/*获取LineEdit的内容*/
QString CommonHelper::GetLEditContent(QLineEdit *LineEdit)
{
    return LineEdit->text();
}

//*************************s************************************** SLOTS
/*页面管理*/
/*I'm FileSync-Client >>*/
void MainWindow::on_btnFileSync_clicked()
{
    ui->APPPage->setCurrentWidget(ui->SyncPage);
}
/*I'm FileBase-Server >>*/
void MainWindow::on_btnFileBase_clicked()
{
    ui->APPPage->setCurrentWidget(ui->BasePage);
}
/*menubar-backhome action*/
void MainWindow::on_actionBackHome_triggered()
{
    ui->APPPage->setCurrentWidget(ui->HomePage);
}

//******************************************************FileSync Page
/*按钮点击-配置同步路径*/
void MainWindow::on_BtnChoseSyncPath_clicked()
{
    //文件夹路径
    syncPath = QFileDialog::getExistingDirectory(
        this, "choose SyncPath Directory",
        "/");

    if (syncPath.isEmpty())
    {
        return;
    }
    else
    {
        CommonHelper::TBOut(ui->TBrwSyncDebug, "[SyncPath]" + syncPath);

        ui->TBrwSyncPath->clear();
        CommonHelper::TBOut(ui->TBrwSyncPath, syncPath + "/");

        /*SetWatchPath-SyncPath*/
        fileWatcher.setWatchPath(syncPath);
    }
}

void MainWindow::on_BtnConnectToFBase_clicked()
{
    HostToConnect = CommonHelper::GetLEditContent(ui->LEditIP);
    PortToConnect = CommonHelper::GetLEditContent(ui->LEditPort);

    CommonHelper::TBOut(ui->TBrwSyncDebug,
                        "[SYS] Connect to ");
    CommonHelper::TBOut(ui->TBrwSyncDebug,
                        "HOST: " + HostToConnect);
    CommonHelper::TBOut(ui->TBrwSyncDebug,
                        "PORT: " + PortToConnect);
    //发送到FileTransfer.cpp
    emit signal_ConnectToFBase(HostToConnect, PortToConnect);
}

//******************************************************FileBase Page

void MainWindow::on_BtnChoseBasePath_clicked()
{
    //文件夹路径
    BasePath = QFileDialog::getExistingDirectory(
        this, "choose BasePath Directory",
        "/");

    if (BasePath.isEmpty())
    {
        return;
    }
    else
    {
        CommonHelper::TBOut(ui->TBrwBaseDebug, "[BasePath]" + BasePath);

        ui->TBrwBasePath->clear();
        CommonHelper::TBOut(ui->TBrwBasePath, BasePath + "/");
    }
}

//*******************************************************APP_Sync
void MainWindow::slot_DirectoryChanged(const QString &path)
{
    // CommonHelper::TBOut(ui->TBrwSyncDebug, "[DirChanged]" + path);
}

void MainWindow::slot_FileChanged(const QString &file)
{
    CommonHelper::TBOut(ui->TBrwSyncDebug, "[FileChanged]" + file);
    fileTransfer.sendFile(file);
}

void MainWindow::slot_FileAdded(const QString &file)
{
    CommonHelper::TBOut(ui->TBrwSyncDebug, "[FileAdded]" + file);
    fileTransfer.sendFile(file);
}
void MainWindow::slot_FileRemoved(const QString &file)
{
    CommonHelper::TBOut(ui->TBrwSyncDebug, "[FileRemoved]" + file);
    fileTransfer.sendDel(file);
}

void MainWindow::slot_FileRenamed(const QString &oldName, const QString &newName)
{
    CommonHelper::TBOut(ui->TBrwSyncDebug, "[FileRename]");
    CommonHelper::TBOut(ui->TBrwSyncDebug, oldName);
    CommonHelper::TBOut(ui->TBrwSyncDebug, "=>");
    CommonHelper::TBOut(ui->TBrwSyncDebug, newName);
    fileTransfer.sendRename(oldName, newName);
}

/*接受FileTransfer的相关信息*/
void MainWindow::slot_FromFileTransfer(QString content)
{
    CommonHelper::TBOut(ui->TBrwSyncDebug, content);

    /*采用禁用按钮的方式，避免已连接的情况, 再重复点击请求连接(实际上会自动阻塞，不能再连接)*/
    if (content == "[Sync/Base] Connected")
    {
        CommonHelper::TBOut(ui->TBrwBaseDebug, content);

        ui->BtnConnectToFBase->setEnabled(false);
        ui->PBarSyncConfig->setValue(55);
    }
    if (content == "[Sync/Base] Disconnected")
    {
        CommonHelper::TBOut(ui->TBrwBaseDebug, content);
        ui->BtnConnectToFBase->setEnabled(true);
        ui->PBarSyncConfig->setValue(20);
    }
}

//***************************************************APP_Base
void MainWindow::slot_File(const QString &fileName, const QByteArray &data)
{
    qDebug() << "File:" << fileName;

    CommonHelper::TBOut(ui->TBrwBaseDebug, "[FSync Success - FileAdded]" + fileName);

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

    CommonHelper::TBOut(ui->TBrwBaseDebug, "[FSync Success - FileRemoved]" + fileName);

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

    CommonHelper::TBOut(ui->TBrwBaseDebug, "[FSync Success - FileRename]");
    CommonHelper::TBOut(ui->TBrwBaseDebug, fileOld);
    CommonHelper::TBOut(ui->TBrwBaseDebug, "=>");
    CommonHelper::TBOut(ui->TBrwBaseDebug, fileNew);

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
        CommonHelper::TBOut(ui->TBrwBaseDebug, "Sync Rename SUCCESS!");
    }
    else
    {
        CommonHelper::TBOut(ui->TBrwBaseDebug, "Sync Rename ERROR!");
    }
}

void MainWindow::slot_ServerListen(bool isServerListenOK)
{
    QString ret;
    if (isServerListenOK)
        ret = "OK";
    else
        ret = "False";
    CommonHelper::TBOut(ui->TBrwBaseDebug, "[ServerListen] Listen :" + ret);
}
