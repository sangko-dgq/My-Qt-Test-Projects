/********************************************************************************
** Form generated from reading UI file 'dialog_addstudent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADDSTUDENT_H
#define UI_DIALOG_ADDSTUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog_AddStudent
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *sid;
    QLineEdit *le_add_sid;
    QLabel *class_2;
    QLabel *name;
    QSpinBox *sbox_add_age;
    QLineEdit *le_add_class;
    QLineEdit *le_add_phone;
    QLineEdit *le_add_grade;
    QLabel *grade;
    QPushButton *btn_cancelAdd;
    QLabel *age;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *le_add_wechat;
    QLabel *wechat;
    QLineEdit *le_add_name;
    QLabel *phone;
    QPushButton *btn_saveAdd;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *Dialog_AddStudent)
    {
        if (Dialog_AddStudent->objectName().isEmpty())
            Dialog_AddStudent->setObjectName(QString::fromUtf8("Dialog_AddStudent"));
        Dialog_AddStudent->resize(300, 221);
        Dialog_AddStudent->setMinimumSize(QSize(300, 220));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code"));
        Dialog_AddStudent->setFont(font);
        gridLayout = new QGridLayout(Dialog_AddStudent);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sid = new QLabel(Dialog_AddStudent);
        sid->setObjectName(QString::fromUtf8("sid"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Fira Code"));
        font1.setPointSize(10);
        sid->setFont(font1);
        sid->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(sid, 2, 0, 1, 1);

        le_add_sid = new QLineEdit(Dialog_AddStudent);
        le_add_sid->setObjectName(QString::fromUtf8("le_add_sid"));

        gridLayout_2->addWidget(le_add_sid, 2, 1, 1, 4);

        class_2 = new QLabel(Dialog_AddStudent);
        class_2->setObjectName(QString::fromUtf8("class_2"));
        class_2->setFont(font1);
        class_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(class_2, 1, 3, 1, 1);

        name = new QLabel(Dialog_AddStudent);
        name->setObjectName(QString::fromUtf8("name"));
        name->setFont(font1);
        name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(name, 0, 0, 1, 1);

        sbox_add_age = new QSpinBox(Dialog_AddStudent);
        sbox_add_age->setObjectName(QString::fromUtf8("sbox_add_age"));

        gridLayout_2->addWidget(sbox_add_age, 0, 4, 1, 1);

        le_add_class = new QLineEdit(Dialog_AddStudent);
        le_add_class->setObjectName(QString::fromUtf8("le_add_class"));

        gridLayout_2->addWidget(le_add_class, 1, 4, 1, 1);

        le_add_phone = new QLineEdit(Dialog_AddStudent);
        le_add_phone->setObjectName(QString::fromUtf8("le_add_phone"));

        gridLayout_2->addWidget(le_add_phone, 3, 1, 1, 4);

        le_add_grade = new QLineEdit(Dialog_AddStudent);
        le_add_grade->setObjectName(QString::fromUtf8("le_add_grade"));

        gridLayout_2->addWidget(le_add_grade, 1, 1, 1, 1);

        grade = new QLabel(Dialog_AddStudent);
        grade->setObjectName(QString::fromUtf8("grade"));
        grade->setFont(font1);
        grade->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(grade, 1, 0, 1, 1);

        btn_cancelAdd = new QPushButton(Dialog_AddStudent);
        btn_cancelAdd->setObjectName(QString::fromUtf8("btn_cancelAdd"));

        gridLayout_2->addWidget(btn_cancelAdd, 6, 3, 1, 2);

        age = new QLabel(Dialog_AddStudent);
        age->setObjectName(QString::fromUtf8("age"));
        age->setFont(font1);
        age->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(age, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        le_add_wechat = new QLineEdit(Dialog_AddStudent);
        le_add_wechat->setObjectName(QString::fromUtf8("le_add_wechat"));

        gridLayout_2->addWidget(le_add_wechat, 4, 1, 1, 4);

        wechat = new QLabel(Dialog_AddStudent);
        wechat->setObjectName(QString::fromUtf8("wechat"));
        wechat->setFont(font1);
        wechat->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(wechat, 4, 0, 1, 1);

        le_add_name = new QLineEdit(Dialog_AddStudent);
        le_add_name->setObjectName(QString::fromUtf8("le_add_name"));

        gridLayout_2->addWidget(le_add_name, 0, 1, 1, 1);

        phone = new QLabel(Dialog_AddStudent);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setFont(font1);
        phone->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(phone, 3, 0, 1, 1);

        btn_saveAdd = new QPushButton(Dialog_AddStudent);
        btn_saveAdd->setObjectName(QString::fromUtf8("btn_saveAdd"));

        gridLayout_2->addWidget(btn_saveAdd, 6, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_3, 5, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 1, 1, 1);

        QWidget::setTabOrder(le_add_name, sbox_add_age);
        QWidget::setTabOrder(sbox_add_age, le_add_grade);
        QWidget::setTabOrder(le_add_grade, le_add_class);
        QWidget::setTabOrder(le_add_class, le_add_sid);
        QWidget::setTabOrder(le_add_sid, le_add_phone);
        QWidget::setTabOrder(le_add_phone, le_add_wechat);
        QWidget::setTabOrder(le_add_wechat, btn_saveAdd);
        QWidget::setTabOrder(btn_saveAdd, btn_cancelAdd);

        retranslateUi(Dialog_AddStudent);

        QMetaObject::connectSlotsByName(Dialog_AddStudent);
    } // setupUi

    void retranslateUi(QDialog *Dialog_AddStudent)
    {
        Dialog_AddStudent->setWindowTitle(QCoreApplication::translate("Dialog_AddStudent", "Add Student", nullptr));
        sid->setText(QCoreApplication::translate("Dialog_AddStudent", "SID", nullptr));
        class_2->setText(QCoreApplication::translate("Dialog_AddStudent", "Class", nullptr));
        name->setText(QCoreApplication::translate("Dialog_AddStudent", "Name", nullptr));
        grade->setText(QCoreApplication::translate("Dialog_AddStudent", "Grade", nullptr));
        btn_cancelAdd->setText(QCoreApplication::translate("Dialog_AddStudent", "Cancel", nullptr));
        age->setText(QCoreApplication::translate("Dialog_AddStudent", "Age", nullptr));
        wechat->setText(QCoreApplication::translate("Dialog_AddStudent", "Wechat", nullptr));
        phone->setText(QCoreApplication::translate("Dialog_AddStudent", "Phone", nullptr));
        btn_saveAdd->setText(QCoreApplication::translate("Dialog_AddStudent", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_AddStudent: public Ui_Dialog_AddStudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDSTUDENT_H
