/********************************************************************************
** Form generated from reading UI file 'imageviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewer
{
public:
    QAction *actionopen;
    QAction *actionclose;
    QAction *actionedit;
    QAction *actionLast;
    QAction *actionNext;
    QAction *actionLeft;
    QAction *actionRight;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionAbout;
    QWidget *centralwidget;
    QScrollArea *SettingPanel;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_logo;
    QLabel *label_logo_text;
    QLabel *label_version;
    QWidget *widget;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QDialogButtonBox *BBox_SaveSetting;
    QLabel *imagePanel;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuOperate;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QString::fromUtf8("ImageViewer"));
        ImageViewer->resize(867, 600);
        ImageViewer->setMouseTracking(false);
        ImageViewer->setContextMenuPolicy(Qt::DefaultContextMenu);
        ImageViewer->setLayoutDirection(Qt::LeftToRight);
        ImageViewer->setStyleSheet(QString::fromUtf8(""));
        ImageViewer->setAnimated(true);
        actionopen = new QAction(ImageViewer);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iconsA/images/icon_pack001/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen->setIcon(icon);
        actionclose = new QAction(ImageViewer);
        actionclose->setObjectName(QString::fromUtf8("actionclose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iconsA/images/icon_pack001/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionclose->setIcon(icon1);
        actionedit = new QAction(ImageViewer);
        actionedit->setObjectName(QString::fromUtf8("actionedit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iconsA/images/icon_pack001/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionedit->setIcon(icon2);
        actionLast = new QAction(ImageViewer);
        actionLast->setObjectName(QString::fromUtf8("actionLast"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/iconsA/images/icon_pack001/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLast->setIcon(icon3);
        actionNext = new QAction(ImageViewer);
        actionNext->setObjectName(QString::fromUtf8("actionNext"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/iconsA/images/icon_pack001/more.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNext->setIcon(icon4);
        actionLeft = new QAction(ImageViewer);
        actionLeft->setObjectName(QString::fromUtf8("actionLeft"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/iconsA/images/icon_pack001/TLeft.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLeft->setIcon(icon5);
        actionRight = new QAction(ImageViewer);
        actionRight->setObjectName(QString::fromUtf8("actionRight"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/iconsA/images/icon_pack001/TRight.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRight->setIcon(icon6);
        actionZoom_In = new QAction(ImageViewer);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/iconsA/images/icon_pack001/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_In->setIcon(icon7);
        actionZoom_Out = new QAction(ImageViewer);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/iconsA/images/icon_pack001/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_Out->setIcon(icon8);
        actionAbout = new QAction(ImageViewer);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/iconsA/images/icon_pack001/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon9);
        centralwidget = new QWidget(ImageViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SettingPanel = new QScrollArea(centralwidget);
        SettingPanel->setObjectName(QString::fromUtf8("SettingPanel"));
        SettingPanel->setEnabled(true);
        SettingPanel->setGeometry(QRect(180, 80, 441, 401));
        SettingPanel->setContextMenuPolicy(Qt::NoContextMenu);
        SettingPanel->setLayoutDirection(Qt::LeftToRight);
        SettingPanel->setAutoFillBackground(true);
        SettingPanel->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 232, 232);\n"
"anchors.centerIn: parent;"));
        SettingPanel->setFrameShape(QFrame::Box);
        SettingPanel->setFrameShadow(QFrame::Plain);
        SettingPanel->setWidgetResizable(true);
        SettingPanel->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 439, 399));
        layoutWidget = new QWidget(scrollAreaWidgetContents);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 441, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_logo = new QLabel(layoutWidget);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setLayoutDirection(Qt::LeftToRight);
        label_logo->setAutoFillBackground(false);
        label_logo->setStyleSheet(QString::fromUtf8("background-image: url(:/iconsA/images/icon_pack001/logo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-color: rgba(0, 0, 0, 0);"));
        label_logo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_logo);

        label_logo_text = new QLabel(layoutWidget);
        label_logo_text->setObjectName(QString::fromUtf8("label_logo_text"));
        label_logo_text->setAutoFillBackground(false);
        label_logo_text->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Segoe Script\";"));
        label_logo_text->setAlignment(Qt::AlignCenter);
        label_logo_text->setOpenExternalLinks(false);

        verticalLayout->addWidget(label_logo_text);

        label_version = new QLabel(layoutWidget);
        label_version->setObjectName(QString::fromUtf8("label_version"));
        label_version->setStyleSheet(QString::fromUtf8("font: 25 9pt \"Fira Code Light\";\n"
"color: rgb(107, 107, 107);"));
        label_version->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_version);

        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 170, 441, 191));
        widget->setToolTipDuration(-1);
        widget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(214, 214, 214);"));
        layoutWidget1 = new QWidget(widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 20, 311, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"Fira Code\";"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        layoutWidget_2 = new QWidget(widget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(60, 60, 311, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"Fira Code\";"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        comboBox_2 = new QComboBox(layoutWidget_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 100, 311, 61));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"font: 75 10pt \"Fira Code\";"));
        BBox_SaveSetting = new QDialogButtonBox(scrollAreaWidgetContents);
        BBox_SaveSetting->setObjectName(QString::fromUtf8("BBox_SaveSetting"));
        BBox_SaveSetting->setGeometry(QRect(150, 370, 151, 23));
        BBox_SaveSetting->setOrientation(Qt::Horizontal);
        BBox_SaveSetting->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        SettingPanel->setWidget(scrollAreaWidgetContents);
        widget->raise();
        layoutWidget->raise();
        BBox_SaveSetting->raise();
        imagePanel = new QLabel(centralwidget);
        imagePanel->setObjectName(QString::fromUtf8("imagePanel"));
        imagePanel->setGeometry(QRect(0, 20, 831, 551));
        imagePanel->setStyleSheet(QString::fromUtf8("background-color: rgb(198, 198, 198);"));
        ImageViewer->setCentralWidget(centralwidget);
        imagePanel->raise();
        SettingPanel->raise();
        menubar = new QMenuBar(ImageViewer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 867, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOperate = new QMenu(menubar);
        menuOperate->setObjectName(QString::fromUtf8("menuOperate"));
        ImageViewer->setMenuBar(menubar);
        toolBar = new QToolBar(ImageViewer);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setAcceptDrops(false);
        toolBar->setLayoutDirection(Qt::LeftToRight);
        toolBar->setAutoFillBackground(false);
        ImageViewer->addToolBar(Qt::LeftToolBarArea, toolBar);
        statusBar = new QStatusBar(ImageViewer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImageViewer->setStatusBar(statusBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOperate->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionopen);
        menuFile->addAction(actionclose);
        menuFile->addSeparator();
        menuFile->addAction(actionedit);
        menuOperate->addAction(actionLast);
        menuOperate->addAction(actionNext);
        menuOperate->addSeparator();
        menuOperate->addAction(actionLeft);
        menuOperate->addAction(actionRight);
        menuOperate->addSeparator();
        menuOperate->addAction(actionZoom_In);
        menuOperate->addAction(actionZoom_Out);
        toolBar->addAction(actionopen);
        toolBar->addAction(actionclose);
        toolBar->addSeparator();
        toolBar->addAction(actionLast);
        toolBar->addAction(actionNext);
        toolBar->addAction(actionLeft);
        toolBar->addAction(actionRight);
        toolBar->addAction(actionZoom_In);
        toolBar->addAction(actionZoom_Out);
        toolBar->addSeparator();
        toolBar->addAction(actionAbout);
        toolBar->addAction(actionedit);

        retranslateUi(ImageViewer);

        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QMainWindow *ImageViewer)
    {
        ImageViewer->setWindowTitle(QCoreApplication::translate("ImageViewer", "ImageViewer", nullptr));
        actionopen->setText(QCoreApplication::translate("ImageViewer", "open", nullptr));
        actionclose->setText(QCoreApplication::translate("ImageViewer", "close", nullptr));
        actionedit->setText(QCoreApplication::translate("ImageViewer", "Exit", nullptr));
        actionLast->setText(QCoreApplication::translate("ImageViewer", "Last", nullptr));
        actionNext->setText(QCoreApplication::translate("ImageViewer", "Next", nullptr));
        actionLeft->setText(QCoreApplication::translate("ImageViewer", "Left", nullptr));
        actionRight->setText(QCoreApplication::translate("ImageViewer", "Right", nullptr));
        actionZoom_In->setText(QCoreApplication::translate("ImageViewer", "Zoom In", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_In->setShortcut(QCoreApplication::translate("ImageViewer", "Ctrl+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_Out->setText(QCoreApplication::translate("ImageViewer", "Zoom Out", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_Out->setShortcut(QCoreApplication::translate("ImageViewer", "Ctrl+=", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("ImageViewer", "About", nullptr));
        label_logo->setText(QString());
        label_logo_text->setText(QCoreApplication::translate("ImageViewer", "ImageView", nullptr));
        label_version->setText(QCoreApplication::translate("ImageViewer", "1.0_dev", nullptr));
        label_2->setText(QCoreApplication::translate("ImageViewer", "Theme", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ImageViewer", "Basic_Light", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ImageViewer", "Basic_Dark", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ImageViewer", "Future_Dark_2022", nullptr));

        label_3->setText(QCoreApplication::translate("ImageViewer", "Language", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("ImageViewer", "English", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("ImageViewer", "\347\256\200\344\275\223\344\270\255\346\226\207", nullptr));

        pushButton->setText(QCoreApplication::translate("ImageViewer", "Check Update", nullptr));
        imagePanel->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("ImageViewer", "File", nullptr));
        menuOperate->setTitle(QCoreApplication::translate("ImageViewer", "Operate", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("ImageViewer", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
