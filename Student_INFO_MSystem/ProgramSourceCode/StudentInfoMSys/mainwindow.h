#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QFile>
#include <QCoreApplication>
#include <QIODevice>
#include <QApplication>
#include "loginwindow.h"
#include "dialog_addstudent.h"

#include "SQL/studentsql.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void keyPressEvent(QKeyEvent *e) override;

private slots:
    void on_btn_exit_clicked();

    void on_btn_simulation_clicked();

    void on_btn_add_clicked();

    void on_btn_clearUpStudent_clicked();

    void on_btn_remove_clicked();

    void on_btn_modify_clicked();

    void on_btn_serach_clicked();

private:
    void updateTable(); //刷新Table

private:
    Ui::MainWindow *ui;
    LoginWindow loginWindow;
    Dialog_AddStudent m_dialog_AddStudent;

    StudentSQL *m_ptrStudentSQL;
};
#endif // MAINWINDOW_H
