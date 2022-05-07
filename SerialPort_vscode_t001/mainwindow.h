#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//引入串口模块
// #include <QSerialPort>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE
 
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
};
#endif // MAINWINDOW_H