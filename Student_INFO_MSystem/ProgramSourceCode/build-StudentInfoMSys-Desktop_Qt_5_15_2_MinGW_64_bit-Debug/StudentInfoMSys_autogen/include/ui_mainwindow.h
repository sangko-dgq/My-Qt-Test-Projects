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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *Body;
    QGridLayout *gridLayout_3;
    QTreeWidget *tree_leftTreePanel;
    QWidget *TopView;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *btn_exit;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *user;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_4;
    QPushButton *btn_serach;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *tableWidget;
    QPushButton *btn_modify;
    QLineEdit *ld_serach;
    QLabel *label_5;
    QCheckBox *cbox_checkAll;
    QPushButton *btn_add;
    QLabel *lb_totalCount;
    QPushButton *btn_remove;
    QPushButton *btn_simulation;
    QPushButton *btn_clearUpStudent;
    QWidget *page_2;
    QMenuBar *menubar;
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
        Body = new QWidget(MainWindow);
        Body->setObjectName(QString::fromUtf8("Body"));
        Body->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(Body);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tree_leftTreePanel = new QTreeWidget(Body);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(tree_leftTreePanel);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        tree_leftTreePanel->setObjectName(QString::fromUtf8("tree_leftTreePanel"));
        tree_leftTreePanel->setMaximumSize(QSize(180, 16777215));
        tree_leftTreePanel->setStyleSheet(QString::fromUtf8(""));
        tree_leftTreePanel->header()->setVisible(false);

        gridLayout_3->addWidget(tree_leftTreePanel, 1, 0, 1, 1);

        TopView = new QWidget(Body);
        TopView->setObjectName(QString::fromUtf8("TopView"));
        TopView->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(TopView);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(104, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        widget_2 = new QWidget(TopView);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_exit = new QPushButton(widget_2);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/exit_48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_exit->setIcon(icon1);

        gridLayout->addWidget(btn_exit, 0, 4, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        user = new QLabel(widget_2);
        user->setObjectName(QString::fromUtf8("user"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Fira Code"));
        font1.setBold(true);
        user->setFont(font1);

        gridLayout->addWidget(user, 0, 1, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(48, 48));
        label_2->setMaximumSize(QSize(48, 48));
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/user.png")));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label = new QLabel(TopView);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Fira Code"));
        font2.setPointSize(14);
        font2.setBold(true);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);


        gridLayout_3->addWidget(TopView, 0, 0, 1, 2);

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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/search_white_48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_serach->setIcon(icon2);
        btn_serach->setIconSize(QSize(18, 18));
        btn_serach->setAutoRepeat(false);
        btn_serach->setAutoExclusive(false);
        btn_serach->setAutoDefault(false);
        btn_serach->setFlat(false);

        gridLayout_4->addWidget(btn_serach, 0, 6, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 7, 1, 1);

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

        gridLayout_4->addWidget(tableWidget, 1, 0, 1, 11);

        btn_modify = new QPushButton(page);
        btn_modify->setObjectName(QString::fromUtf8("btn_modify"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/modify_white_48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_modify->setIcon(icon3);

        gridLayout_4->addWidget(btn_modify, 0, 9, 1, 1);

        ld_serach = new QLineEdit(page);
        ld_serach->setObjectName(QString::fromUtf8("ld_serach"));
        ld_serach->setMinimumSize(QSize(0, 0));

        gridLayout_4->addWidget(ld_serach, 0, 2, 1, 4);

        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 2, 2, 1, 1);

        cbox_checkAll = new QCheckBox(page);
        cbox_checkAll->setObjectName(QString::fromUtf8("cbox_checkAll"));

        gridLayout_4->addWidget(cbox_checkAll, 0, 0, 1, 1);

        btn_add = new QPushButton(page);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/add_white_48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_add->setIcon(icon4);

        gridLayout_4->addWidget(btn_add, 0, 8, 1, 1);

        lb_totalCount = new QLabel(page);
        lb_totalCount->setObjectName(QString::fromUtf8("lb_totalCount"));

        gridLayout_4->addWidget(lb_totalCount, 2, 3, 1, 1);

        btn_remove = new QPushButton(page);
        btn_remove->setObjectName(QString::fromUtf8("btn_remove"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/remove_white_48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_remove->setIcon(icon5);

        gridLayout_4->addWidget(btn_remove, 0, 10, 1, 1);

        btn_simulation = new QPushButton(page);
        btn_simulation->setObjectName(QString::fromUtf8("btn_simulation"));

        gridLayout_4->addWidget(btn_simulation, 2, 0, 1, 1);

        btn_clearUpStudent = new QPushButton(page);
        btn_clearUpStudent->setObjectName(QString::fromUtf8("btn_clearUpStudent"));

        gridLayout_4->addWidget(btn_clearUpStudent, 2, 10, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout_3->addWidget(stackedWidget, 1, 1, 1, 1);

        MainWindow->setCentralWidget(Body);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 940, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

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

        btn_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "admin", nullptr));
        user->setText(QCoreApplication::translate("MainWindow", "user :", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", " Student Information Management System", nullptr));
        btn_serach->setText(QString());
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

        btn_modify->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Total :", nullptr));
        cbox_checkAll->setText(QCoreApplication::translate("MainWindow", "Check All", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        lb_totalCount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn_remove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        btn_simulation->setText(QCoreApplication::translate("MainWindow", "Sim", nullptr));
        btn_clearUpStudent->setText(QCoreApplication::translate("MainWindow", "ClearUp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
