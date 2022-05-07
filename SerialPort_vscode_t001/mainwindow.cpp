#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //基于mainwindow.ui构造ui界面
    ui->setupUi(this);

    //代码操作
    //增加CBox_COM子选项
    // ui->CBox_COM->addItem("COM1");
    // ui->CBox_COM->addItem("COM2");
    // ui->CBox_COM->addItem("COM3");

    //默认设置（初始化）
    // serialPort = new QSerialPort(this);

    // serialPort.setPortName("COM3");
    serialPort->setBaudRate(QSerialPort::Baud115200); //必须指明是QSerialPort类里面的Baud115200成员
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setStopBits(QSerialPort::OneStop);
    // serialPort.open(QSerialPort::ReadWrite); //打开基于配置好的串

     QStringList serialNamePort;
    /* 搜索所有可用串口 */
    foreach (const QSerialPortInfo &inf0, QSerialPortInfo::availablePorts())
    {
        serialNamePort << inf0.portName();
    }
    ui->CBox_COM->addItems(serialNamePort);

 /* 打开串口提示框 */
    if (true == serialPort->open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this, "提示", "串口打开成功");  
    }
    else
    {
        QMessageBox::critical(this, "提示", "串口打开失败");
    }
}

//析构函数
MainWindow::~MainWindow()
{
    delete ui;
}
