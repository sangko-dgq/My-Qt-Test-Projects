/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionexport_as_a_excel;
    QAction *actionExit;
    QAction *actionCurrent_User;
    QWidget *Body;
    QGridLayout *gridLayout_3;
    QWidget *TopView;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QWidget *widget;
    QTreeWidget *tree_leftTreePanel;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_4;
    QPushButton *btn_serach;
    QPushButton *btn_simulation;
    QCheckBox *cbox_checkAll;
    QPushButton *btn_modify;
    QPushButton *btn_remove;
    QLineEdit *ld_serach;
    QLabel *label_5;
    QPushButton *btn_add;
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QPushButton *btn_clearUpStudent;
    QLabel *lb_totalCount;
    QComboBox *comboBox_2;
    QWidget *page_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuExport;
    QMenu *menuOption;
    QMenu *menuUser;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(940, 639);
        MainWindow->setMinimumSize(QSize(800, 480));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code"));
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionexport_as_a_excel = new QAction(MainWindow);
        actionexport_as_a_excel->setObjectName(QString::fromUtf8("actionexport_as_a_excel"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionCurrent_User = new QAction(MainWindow);
        actionCurrent_User->setObjectName(QString::fromUtf8("actionCurrent_User"));
        Body = new QWidget(MainWindow);
        Body->setObjectName(QString::fromUtf8("Body"));
        Body->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(Body);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        TopView = new QWidget(Body);
        TopView->setObjectName(QString::fromUtf8("TopView"));
        TopView->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(TopView);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(TopView);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_2->addWidget(widget_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(TopView, 0, 0, 1, 2);

        widget = new QWidget(Body);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(200, 200));
        tree_leftTreePanel = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(tree_leftTreePanel);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        tree_leftTreePanel->setObjectName(QString::fromUtf8("tree_leftTreePanel"));
        tree_leftTreePanel->setGeometry(QRect(10, 0, 180, 100));
        tree_leftTreePanel->setMinimumSize(QSize(0, 0));
        tree_leftTreePanel->setMaximumSize(QSize(180, 100));
        tree_leftTreePanel->setStyleSheet(QString::fromUtf8(""));
        tree_leftTreePanel->header()->setVisible(false);

        gridLayout_3->addWidget(widget, 3, 0, 1, 1);

        stackedWidget = new QStackedWidget(Body);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_4 = new QGridLayout(page);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(6, 0, -1, 0);
        btn_serach = new QPushButton(page);
        btn_serach->setObjectName(QString::fromUtf8("btn_serach"));
        btn_serach->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/search_white_48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_serach->setIcon(icon1);
        btn_serach->setIconSize(QSize(18, 18));
        btn_serach->setAutoRepeat(false);
        btn_serach->setAutoExclusive(false);
        btn_serach->setAutoDefault(false);
        btn_serach->setFlat(false);

        gridLayout_4->addWidget(btn_serach, 0, 12, 1, 1);

        btn_simulation = new QPushButton(page);
        btn_simulation->setObjectName(QString::fromUtf8("btn_simulation"));

        gridLayout_4->addWidget(btn_simulation, 3, 18, 1, 1);

        cbox_checkAll = new QCheckBox(page);
        cbox_checkAll->setObjectName(QString::fromUtf8("cbox_checkAll"));

        gridLayout_4->addWidget(cbox_checkAll, 3, 17, 1, 1);

        btn_modify = new QPushButton(page);
        btn_modify->setObjectName(QString::fromUtf8("btn_modify"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/modify_white_48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_modify->setIcon(icon2);

        gridLayout_4->addWidget(btn_modify, 0, 18, 1, 1);

        btn_remove = new QPushButton(page);
        btn_remove->setObjectName(QString::fromUtf8("btn_remove"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/remove_white_48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_remove->setIcon(icon3);

        gridLayout_4->addWidget(btn_remove, 0, 21, 1, 1);

        ld_serach = new QLineEdit(page);
        ld_serach->setObjectName(QString::fromUtf8("ld_serach"));
        ld_serach->setMinimumSize(QSize(0, 0));

        gridLayout_4->addWidget(ld_serach, 0, 10, 1, 1);

        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(10, 0));
        label_5->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(label_5, 3, 1, 1, 1);

        btn_add = new QPushButton(page);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/add_white_48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_add->setIcon(icon4);

        gridLayout_4->addWidget(btn_add, 0, 17, 1, 1);

        comboBox = new QComboBox(page);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_4->addWidget(comboBox, 0, 1, 1, 1);

        tableWidget = new QTableWidget(page);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(0, 7, __qtablewidgetitem16);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setLineWidth(1);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setSortingEnabled(false);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        gridLayout_4->addWidget(tableWidget, 2, 1, 1, 21);

        btn_clearUpStudent = new QPushButton(page);
        btn_clearUpStudent->setObjectName(QString::fromUtf8("btn_clearUpStudent"));

        gridLayout_4->addWidget(btn_clearUpStudent, 3, 21, 1, 1);

        lb_totalCount = new QLabel(page);
        lb_totalCount->setObjectName(QString::fromUtf8("lb_totalCount"));
        lb_totalCount->setMinimumSize(QSize(50, 0));

        gridLayout_4->addWidget(lb_totalCount, 3, 2, 1, 1);

        comboBox_2 = new QComboBox(page);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_4->addWidget(comboBox_2, 0, 2, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout_3->addWidget(stackedWidget, 3, 1, 1, 1);

        MainWindow->setCentralWidget(Body);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 940, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuExport = new QMenu(menuFile);
        menuExport->setObjectName(QString::fromUtf8("menuExport"));
        menuOption = new QMenu(menubar);
        menuOption->setObjectName(QString::fromUtf8("menuOption"));
        menuUser = new QMenu(menubar);
        menuUser->setObjectName(QString::fromUtf8("menuUser"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOption->menuAction());
        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuUser->menuAction());
        menuFile->addAction(menuExport->menuAction());
        menuExport->addAction(actionexport_as_a_excel);
        menuOption->addAction(actionExit);
        menuUser->addAction(actionCurrent_User);

        retranslateUi(MainWindow);

        btn_serach->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "StudentInfoManager", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QCoreApplication::translate("MainWindow", " Student Information Management System", nullptr));
#endif // QT_CONFIG(tooltip)
        actionexport_as_a_excel->setText(QCoreApplication::translate("MainWindow", "export as a excel", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionCurrent_User->setText(QCoreApplication::translate("MainWindow", "Current User", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tree_leftTreePanel->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Page", nullptr));

        const bool __sortingEnabled = tree_leftTreePanel->isSortingEnabled();
        tree_leftTreePanel->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = tree_leftTreePanel->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "New Item", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "New Subitem", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "New Subitem", nullptr));
        tree_leftTreePanel->setSortingEnabled(__sortingEnabled);

        btn_serach->setText(QString());
        btn_simulation->setText(QCoreApplication::translate("MainWindow", "Sim", nullptr));
        cbox_checkAll->setText(QCoreApplication::translate("MainWindow", "Check All", nullptr));
        btn_modify->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        btn_remove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Total :", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Type", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Res", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Cap", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\344\272\214\346\236\201\347\256\241", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\344\270\211\346\236\201\347\256\241", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "\347\272\277\346\200\247\347\250\263\345\216\213\347\256\241", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "\347\224\265\346\272\220\347\256\241\347\220\206", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Class", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "SID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Wechat", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "1", nullptr));

        const bool __sortingEnabled1 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Liu", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "24", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "004", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(0, 5);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "170403122", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(0, 6);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "18848362737", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(0, 7);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "mliu2013", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled1);

        btn_clearUpStudent->setText(QCoreApplication::translate("MainWindow", "ClearUp", nullptr));
        lb_totalCount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Footprint", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "0402", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "0603", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "0805", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "SOP-23", nullptr));

        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuExport->setTitle(QCoreApplication::translate("MainWindow", "Export", nullptr));
        menuOption->setTitle(QCoreApplication::translate("MainWindow", "Option", nullptr));
        menuUser->setTitle(QCoreApplication::translate("MainWindow", "User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
