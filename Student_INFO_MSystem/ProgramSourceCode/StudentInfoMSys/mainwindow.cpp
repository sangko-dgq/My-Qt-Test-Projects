#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loginWindow.show();

    auto f = [&]()
    {
        this->show();
    };
    connect(&loginWindow, &LoginWindow::sg_sendLoginSuccess, this, f);

    ui->tree_leftTreePanel->clear();
    ui->tree_leftTreePanel->setColumnCount(1); //1行
    QStringList treelist;
    treelist << "StudentInfoManagerSystem";

    QTreeWidgetItem *treeItem_A = new QTreeWidgetItem(ui->tree_leftTreePanel, QStringList("PageManagement"));
    QTreeWidgetItem *treeItem_a1 = new QTreeWidgetItem(treeItem_A, QStringList("Student"));
    QTreeWidgetItem *treeItem_a2 = new QTreeWidgetItem(treeItem_A, QStringList("Administrator"));

    ui->tree_leftTreePanel->addTopLevelItem(treeItem_A);
    treeItem_A->addChild(treeItem_a1);
    treeItem_A->addChild(treeItem_a2);
    ui->tree_leftTreePanel->expandAll();//默认展开

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_exit_clicked()
{
    exit(0);
}

