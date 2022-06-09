#ifndef DIALOG_ADDSTUDENT_H
#define DIALOG_ADDSTUDENT_H

#include <QDialog>
#include "SQL/studentsql.h"

namespace Ui {
class Dialog_AddStudent;
}

class Dialog_AddStudent : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddStudent(QWidget *parent = nullptr);
    ~Dialog_AddStudent();

    void setType(bool isAdd, StudentInfo info ={});

private slots:
    void on_btn_saveAdd_clicked();
    void on_btn_cancelAdd_clicked();

private:
    Ui::Dialog_AddStudent *ui;

    bool m_isAdd;
    StudentInfo m_studentInfo;
};

#endif // DIALOG_ADDSTUDENT_H
