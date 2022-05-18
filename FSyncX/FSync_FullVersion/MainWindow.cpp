
#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    //Theme
    commonHelper->setStyle("://MacOS.qss");
    // Default Page
    ui->APPPage->setCurrentWidget(ui->HomePage);
    
}

void MainWindow::FileWatcherInit()
{
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
            SIGNAL(signal_CommonINFO_FromFileTransfer(QString)),
            this,
            SLOT(slot_CommonINFO_FromFileTransfer(QString)));
}

void MainWindow::FileBaseInit()
{
    connect(&fileBase, SIGNAL(signal_File(QString, QByteArray)), this, SLOT(slot_File(QString, QByteArray)));
    connect(&fileBase, SIGNAL(signal_Del(QString)), this, SLOT(slot_Del(QString)));
    connect(&fileBase, SIGNAL(signal_Rename(QString, QString)), this, SLOT(slot_Rename(QString, QString)));
    connect(&fileBase, SIGNAL(signal_CommonINFO_FromFileBase(QString)), this, SLOT(slot_CommonINFO_FromFileBase(QString)));

    connect(this, SIGNAL(signal_ONOFF_ServerListen(QString, QString, QString)), &fileBase, SLOT(slot_ONOFF_ServerListen(QString, QString, QString)));
}

