#include "dialog_addstudent.h"
#include "ui_dialog_addstudent.h"

#include <QMessageBox>
#include <QDebug>

Dialog_AddStudent::Dialog_AddStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddStudent)
{
    ui->setupUi(this);
}

Dialog_AddStudent::~Dialog_AddStudent()
{
    delete ui;
}

void Dialog_AddStudent::setType(bool isAdd, StudentInfo info)
{
    m_isAdd = isAdd;
    m_studentInfo = info;

    if(!m_isAdd) //Motify Mode
    {
        /*motify模式*/
        ui->le_add_name->setText(info.student_name);
        ui->sbox_add_age->setValue(info.student_age);
        ui->le_add_class->setText(QString::number(info.student_class));
        ui->le_add_grade->setText(QString::number(info.student_grade));
        ui->le_add_phone->setText(info.student_phoneNum);
        ui->le_add_wechat->setText(info.student_wechat);
    }
    else //ADD Mode
    {
        ui->le_add_name->setText(nullptr);
        ui->sbox_add_age->setValue(0);
        ui->le_add_class->setText(nullptr);
        ui->le_add_grade->setText(nullptr);
        ui->le_add_phone->setText(nullptr);
        ui->le_add_wechat->setText(nullptr);
    }

}

void Dialog_AddStudent::on_btn_saveAdd_clicked()
{

    QList<StudentInfo> l;
    StudentInfo info;
    auto ptr = StudentSQL::getInstance();

    info.id = m_studentInfo.id;
    info.student_name = ui->le_add_name->text();
    info.student_age = ui->sbox_add_age->text().toUInt();
    info.student_class = ui->le_add_class->text().toUInt();
    info.student_grade = ui->le_add_grade->text().toUInt();
    info.student_id = ui->le_add_sid->text().toUInt();
    info.student_phoneNum = ui->le_add_phone->text();
    info.student_wechat = ui->le_add_wechat->text();

    l.append(info);

    if(m_isAdd) //ADD
    {
        if(!ptr->addStudent(l)) //Add false
        {
            QMessageBox::warning(nullptr,"Warning", "Add Error!");
            return;
        }
        //Add Success
        QMessageBox::information(nullptr,"Information", "Add Success!");
        this->hide();
    }
    else  //Modify
    {
        if(!ptr->updateStudentInfo(info)) //Modify false
        {
            QMessageBox::warning(nullptr,"Warning", "Modify Error!");
            return;
        }
        QMessageBox::information(nullptr,"Information", "Modify Success!");
        this->hide();
    }
}


void Dialog_AddStudent::on_btn_cancelAdd_clicked()
{
    this->hide();
}

