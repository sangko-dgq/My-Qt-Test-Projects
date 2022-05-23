#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_btn_login_clicked()
{
    //数据库查找用户名和密码


    //失败就提示


    //成功进入主界面
    emit sg_sendLoginSuccess();
}


void LoginWindow::on_btn_exit_clicked()
{
    exit(0);
}

