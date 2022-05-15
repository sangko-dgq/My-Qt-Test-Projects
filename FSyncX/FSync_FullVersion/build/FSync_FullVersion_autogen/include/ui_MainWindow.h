/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHow_to_use;
    QAction *actionAbout_FSyncx;
    QAction *actionCheckUpdate;
    QAction *actionBackHome;
    QWidget *centralwidget;
    QStackedWidget *APPPage;
    QWidget *HomePage;
    QWidget *layoutWidget;
    QGridLayout *LOGO_2;
    QLabel *LOGO_T;
    QLabel *LOGO_S;
    QPushButton *btnFileBase;
    QPushButton *btnFileSync;
    QWidget *SyncPage;
    QGroupBox *Quick;
    QPushButton *BtnOpenSyncPath;
    QGroupBox *Debug;
    QTextBrowser *TBrwSyncDebug;
    QProgressBar *PBarCommon;
    QGroupBox *ConfigGBox;
    QProgressBar *PBarSyncConfig;
    QGroupBox *Sync;
    QPushButton *BtnStartSync;
    QGroupBox *Connect;
    QPushButton *BtnConnectToFBase;
    QLineEdit *LEditIP;
    QLineEdit *LEditPort;
    QGroupBox *SyncPath;
    QPushButton *BtnChoseSyncPath;
    QTextBrowser *TBrwSyncPath;
    QLabel *PageLOGO_2;
    QWidget *BasePage;
    QGroupBox *Quick_2;
    QPushButton *btnOpenPath_2;
    QGroupBox *ConfigGBox_2;
    QProgressBar *PBarCommon_3;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser_3;
    QLabel *label;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit_7;
    QTextBrowser *TBClientHost;
    QPushButton *BtnGetIP;
    QGroupBox *groupBox_6;
    QPushButton *BtnChoseBasePath;
    QTextBrowser *TBrwBasePath;
    QProgressBar *PBarCommon_4;
    QGroupBox *Debug_2;
    QTextBrowser *TBrwBaseDebug;
    QLabel *PageLOGO;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(400, 300));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionHow_to_use = new QAction(MainWindow);
        actionHow_to_use->setObjectName(QString::fromUtf8("actionHow_to_use"));
        actionAbout_FSyncx = new QAction(MainWindow);
        actionAbout_FSyncx->setObjectName(QString::fromUtf8("actionAbout_FSyncx"));
        actionCheckUpdate = new QAction(MainWindow);
        actionCheckUpdate->setObjectName(QString::fromUtf8("actionCheckUpdate"));
        actionBackHome = new QAction(MainWindow);
        actionBackHome->setObjectName(QString::fromUtf8("actionBackHome"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        APPPage = new QStackedWidget(centralwidget);
        APPPage->setObjectName(QString::fromUtf8("APPPage"));
        APPPage->setGeometry(QRect(20, 10, 771, 541));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code"));
        APPPage->setFont(font);
        HomePage = new QWidget();
        HomePage->setObjectName(QString::fromUtf8("HomePage"));
        layoutWidget = new QWidget(HomePage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 100, 272, 133));
        LOGO_2 = new QGridLayout(layoutWidget);
        LOGO_2->setObjectName(QString::fromUtf8("LOGO_2"));
        LOGO_2->setContentsMargins(0, 0, 0, 0);
        LOGO_T = new QLabel(layoutWidget);
        LOGO_T->setObjectName(QString::fromUtf8("LOGO_T"));
        LOGO_T->setStyleSheet(QString::fromUtf8("font: 64pt \"Ink Free\";\n"
""));
        LOGO_T->setAlignment(Qt::AlignCenter);

        LOGO_2->addWidget(LOGO_T, 0, 0, 1, 1);

        LOGO_S = new QLabel(layoutWidget);
        LOGO_S->setObjectName(QString::fromUtf8("LOGO_S"));
        LOGO_S->setStyleSheet(QString::fromUtf8("font: 12pt \"Gabriola\";"));
        LOGO_S->setAlignment(Qt::AlignCenter);

        LOGO_2->addWidget(LOGO_S, 1, 0, 1, 1);

        btnFileBase = new QPushButton(HomePage);
        btnFileBase->setObjectName(QString::fromUtf8("btnFileBase"));
        btnFileBase->setGeometry(QRect(240, 330, 271, 51));
        btnFileBase->setStyleSheet(QString::fromUtf8("font: 9pt \"Fira Code\";"));
        btnFileSync = new QPushButton(HomePage);
        btnFileSync->setObjectName(QString::fromUtf8("btnFileSync"));
        btnFileSync->setGeometry(QRect(240, 260, 271, 51));
        btnFileSync->setStyleSheet(QString::fromUtf8("font: 9pt \"Fira Code\";"));
        APPPage->addWidget(HomePage);
        SyncPage = new QWidget();
        SyncPage->setObjectName(QString::fromUtf8("SyncPage"));
        Quick = new QGroupBox(SyncPage);
        Quick->setObjectName(QString::fromUtf8("Quick"));
        Quick->setGeometry(QRect(10, 390, 361, 111));
        BtnOpenSyncPath = new QPushButton(Quick);
        BtnOpenSyncPath->setObjectName(QString::fromUtf8("BtnOpenSyncPath"));
        BtnOpenSyncPath->setGeometry(QRect(10, 20, 341, 81));
        Debug = new QGroupBox(SyncPage);
        Debug->setObjectName(QString::fromUtf8("Debug"));
        Debug->setGeometry(QRect(380, 40, 381, 461));
        TBrwSyncDebug = new QTextBrowser(Debug);
        TBrwSyncDebug->setObjectName(QString::fromUtf8("TBrwSyncDebug"));
        TBrwSyncDebug->setGeometry(QRect(20, 20, 331, 431));
        PBarCommon = new QProgressBar(SyncPage);
        PBarCommon->setObjectName(QString::fromUtf8("PBarCommon"));
        PBarCommon->setGeometry(QRect(-10, 530, 791, 20));
        PBarCommon->setFont(font);
        PBarCommon->setValue(50);
        PBarCommon->setTextVisible(false);
        ConfigGBox = new QGroupBox(SyncPage);
        ConfigGBox->setObjectName(QString::fromUtf8("ConfigGBox"));
        ConfigGBox->setGeometry(QRect(10, 40, 361, 351));
        PBarSyncConfig = new QProgressBar(ConfigGBox);
        PBarSyncConfig->setObjectName(QString::fromUtf8("PBarSyncConfig"));
        PBarSyncConfig->setGeometry(QRect(-30, 40, 411, 301));
        PBarSyncConfig->setFont(font);
        PBarSyncConfig->setValue(20);
        PBarSyncConfig->setTextVisible(false);
        PBarSyncConfig->setOrientation(Qt::Vertical);
        PBarSyncConfig->setInvertedAppearance(true);
        Sync = new QGroupBox(ConfigGBox);
        Sync->setObjectName(QString::fromUtf8("Sync"));
        Sync->setGeometry(QRect(0, 230, 361, 101));
        BtnStartSync = new QPushButton(Sync);
        BtnStartSync->setObjectName(QString::fromUtf8("BtnStartSync"));
        BtnStartSync->setGeometry(QRect(10, 20, 341, 81));
        Connect = new QGroupBox(ConfigGBox);
        Connect->setObjectName(QString::fromUtf8("Connect"));
        Connect->setGeometry(QRect(0, 110, 361, 101));
        BtnConnectToFBase = new QPushButton(Connect);
        BtnConnectToFBase->setObjectName(QString::fromUtf8("BtnConnectToFBase"));
        BtnConnectToFBase->setGeometry(QRect(10, 50, 341, 31));
        LEditIP = new QLineEdit(Connect);
        LEditIP->setObjectName(QString::fromUtf8("LEditIP"));
        LEditIP->setGeometry(QRect(10, 20, 241, 21));
        LEditPort = new QLineEdit(Connect);
        LEditPort->setObjectName(QString::fromUtf8("LEditPort"));
        LEditPort->setGeometry(QRect(260, 20, 91, 21));
        SyncPath = new QGroupBox(ConfigGBox);
        SyncPath->setObjectName(QString::fromUtf8("SyncPath"));
        SyncPath->setGeometry(QRect(0, 20, 361, 81));
        BtnChoseSyncPath = new QPushButton(SyncPath);
        BtnChoseSyncPath->setObjectName(QString::fromUtf8("BtnChoseSyncPath"));
        BtnChoseSyncPath->setGeometry(QRect(260, 40, 75, 23));
        TBrwSyncPath = new QTextBrowser(SyncPath);
        TBrwSyncPath->setObjectName(QString::fromUtf8("TBrwSyncPath"));
        TBrwSyncPath->setGeometry(QRect(10, 40, 241, 21));
        PageLOGO_2 = new QLabel(SyncPage);
        PageLOGO_2->setObjectName(QString::fromUtf8("PageLOGO_2"));
        PageLOGO_2->setGeometry(QRect(10, -10, 751, 51));
        PageLOGO_2->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe Print\";"));
        PageLOGO_2->setAlignment(Qt::AlignCenter);
        APPPage->addWidget(SyncPage);
        ConfigGBox->raise();
        Quick->raise();
        Debug->raise();
        PBarCommon->raise();
        PageLOGO_2->raise();
        BasePage = new QWidget();
        BasePage->setObjectName(QString::fromUtf8("BasePage"));
        Quick_2 = new QGroupBox(BasePage);
        Quick_2->setObjectName(QString::fromUtf8("Quick_2"));
        Quick_2->setGeometry(QRect(10, 390, 361, 111));
        btnOpenPath_2 = new QPushButton(Quick_2);
        btnOpenPath_2->setObjectName(QString::fromUtf8("btnOpenPath_2"));
        btnOpenPath_2->setGeometry(QRect(10, 20, 341, 81));
        ConfigGBox_2 = new QGroupBox(BasePage);
        ConfigGBox_2->setObjectName(QString::fromUtf8("ConfigGBox_2"));
        ConfigGBox_2->setGeometry(QRect(10, 40, 361, 351));
        PBarCommon_3 = new QProgressBar(ConfigGBox_2);
        PBarCommon_3->setObjectName(QString::fromUtf8("PBarCommon_3"));
        PBarCommon_3->setGeometry(QRect(-30, 40, 411, 301));
        PBarCommon_3->setFont(font);
        PBarCommon_3->setValue(20);
        PBarCommon_3->setTextVisible(false);
        PBarCommon_3->setOrientation(Qt::Vertical);
        PBarCommon_3->setInvertedAppearance(true);
        groupBox_4 = new QGroupBox(ConfigGBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 230, 361, 101));
        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 20, 171, 71));
        textBrowser_3 = new QTextBrowser(groupBox_4);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(190, 59, 131, 21));
        textBrowser_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 30, 91, 16));
        groupBox_5 = new QGroupBox(ConfigGBox_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(0, 110, 361, 101));
        pushButton_7 = new QPushButton(groupBox_5);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(250, 50, 101, 31));
        lineEdit_7 = new QLineEdit(groupBox_5);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(260, 20, 91, 21));
        TBClientHost = new QTextBrowser(groupBox_5);
        TBClientHost->setObjectName(QString::fromUtf8("TBClientHost"));
        TBClientHost->setGeometry(QRect(10, 20, 241, 21));
        BtnGetIP = new QPushButton(groupBox_5);
        BtnGetIP->setObjectName(QString::fromUtf8("BtnGetIP"));
        BtnGetIP->setGeometry(QRect(10, 50, 231, 31));
        groupBox_6 = new QGroupBox(ConfigGBox_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 20, 361, 81));
        BtnChoseBasePath = new QPushButton(groupBox_6);
        BtnChoseBasePath->setObjectName(QString::fromUtf8("BtnChoseBasePath"));
        BtnChoseBasePath->setGeometry(QRect(260, 40, 75, 23));
        TBrwBasePath = new QTextBrowser(groupBox_6);
        TBrwBasePath->setObjectName(QString::fromUtf8("TBrwBasePath"));
        TBrwBasePath->setGeometry(QRect(10, 40, 241, 21));
        PBarCommon_4 = new QProgressBar(BasePage);
        PBarCommon_4->setObjectName(QString::fromUtf8("PBarCommon_4"));
        PBarCommon_4->setGeometry(QRect(-10, 530, 791, 20));
        PBarCommon_4->setFont(font);
        PBarCommon_4->setValue(50);
        PBarCommon_4->setTextVisible(false);
        Debug_2 = new QGroupBox(BasePage);
        Debug_2->setObjectName(QString::fromUtf8("Debug_2"));
        Debug_2->setGeometry(QRect(380, 40, 381, 461));
        TBrwBaseDebug = new QTextBrowser(Debug_2);
        TBrwBaseDebug->setObjectName(QString::fromUtf8("TBrwBaseDebug"));
        TBrwBaseDebug->setGeometry(QRect(20, 20, 331, 411));
        PageLOGO = new QLabel(BasePage);
        PageLOGO->setObjectName(QString::fromUtf8("PageLOGO"));
        PageLOGO->setGeometry(QRect(10, -10, 751, 51));
        PageLOGO->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe Print\";"));
        PageLOGO->setAlignment(Qt::AlignCenter);
        APPPage->addWidget(BasePage);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionBackHome);
        menuMenu->addSeparator();
        menuMenu->addAction(actionHow_to_use);
        menuMenu->addAction(actionAbout_FSyncx);
        menuMenu->addSeparator();
        menuMenu->addAction(actionCheckUpdate);

        retranslateUi(MainWindow);

        APPPage->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "FSyncX", nullptr));
        actionHow_to_use->setText(QCoreApplication::translate("MainWindow", "How to use?", nullptr));
        actionAbout_FSyncx->setText(QCoreApplication::translate("MainWindow", "About FSyncx?", nullptr));
        actionCheckUpdate->setText(QCoreApplication::translate("MainWindow", "CheckUpdate", nullptr));
        actionBackHome->setText(QCoreApplication::translate("MainWindow", "BackHome", nullptr));
        LOGO_T->setText(QCoreApplication::translate("MainWindow", "FSyncX", nullptr));
        LOGO_S->setText(QCoreApplication::translate("MainWindow", "Root folder synchronization tool based on TCP", nullptr));
        btnFileBase->setText(QCoreApplication::translate("MainWindow", "I'm FileBase-Server >>", nullptr));
        btnFileSync->setText(QCoreApplication::translate("MainWindow", "I'm FileSync-Client >>", nullptr));
        Quick->setTitle(QCoreApplication::translate("MainWindow", "Quick", nullptr));
        BtnOpenSyncPath->setText(QCoreApplication::translate("MainWindow", "Open Sync PATH", nullptr));
        Debug->setTitle(QCoreApplication::translate("MainWindow", "Dubug", nullptr));
        ConfigGBox->setTitle(QCoreApplication::translate("MainWindow", "Config", nullptr));
        Sync->setTitle(QCoreApplication::translate("MainWindow", "Sync", nullptr));
        BtnStartSync->setText(QCoreApplication::translate("MainWindow", "Start Sync", nullptr));
        Connect->setTitle(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        BtnConnectToFBase->setText(QCoreApplication::translate("MainWindow", "Connect to FBase - Server", nullptr));
        LEditIP->setText(QCoreApplication::translate("MainWindow", "192.168.1.5", nullptr));
        LEditPort->setText(QCoreApplication::translate("MainWindow", "8888", nullptr));
        SyncPath->setTitle(QCoreApplication::translate("MainWindow", "SyncPath", nullptr));
        BtnChoseSyncPath->setText(QCoreApplication::translate("MainWindow", "ChosePath", nullptr));
        TBrwSyncPath->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Fira Code'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">NO PATH CHOOSE..</p></body></html>", nullptr));
        PageLOGO_2->setText(QCoreApplication::translate("MainWindow", "FileSync- Client", nullptr));
        Quick_2->setTitle(QCoreApplication::translate("MainWindow", "Quick", nullptr));
        btnOpenPath_2->setText(QCoreApplication::translate("MainWindow", "Open Base PATH", nullptr));
        ConfigGBox_2->setTitle(QCoreApplication::translate("MainWindow", "Config", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "On Sever Listen", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Start Listen", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Fira Code'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff557f;\">False</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Listen Statu", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "GetHost", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Share IP", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "8888", nullptr));
        TBClientHost->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Fira Code'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">null</p></body></html>", nullptr));
        BtnGetIP->setText(QCoreApplication::translate("MainWindow", "Refresh IP", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "BasePath", nullptr));
        BtnChoseBasePath->setText(QCoreApplication::translate("MainWindow", "ChosePath", nullptr));
        TBrwBasePath->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Fira Code'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">NO PATH CHOOSE..</p></body></html>", nullptr));
        Debug_2->setTitle(QCoreApplication::translate("MainWindow", "Dubug", nullptr));
        PageLOGO->setText(QCoreApplication::translate("MainWindow", "FileBase- Server", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H