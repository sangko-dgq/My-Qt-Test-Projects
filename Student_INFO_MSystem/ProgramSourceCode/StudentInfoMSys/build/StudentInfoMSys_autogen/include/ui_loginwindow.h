/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *le_password;
    QLineEdit *le_username;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btn_login;
    QPushButton *btn_exit;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(400, 250);
        LoginWindow->setMaximumSize(QSize(400, 250));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code"));
        LoginWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        LoginWindow->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(LoginWindow);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 60));
        label_3->setMaximumSize(QSize(16777215, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Fira Code"));
        font1.setPointSize(18);
        label_3->setFont(font1);
        label_3->setTextFormat(Qt::AutoText);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(false);

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        widget_2 = new QWidget(LoginWindow);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Fira Code"));
        font2.setPointSize(14);
        font2.setKerning(true);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        le_password = new QLineEdit(widget_2);
        le_password->setObjectName(QString::fromUtf8("le_password"));
        le_password->setMaxLength(8);
        le_password->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(le_password, 1, 1, 1, 1);

        le_username = new QLineEdit(widget_2);
        le_username->setObjectName(QString::fromUtf8("le_username"));
        le_username->setMaxLength(8);

        gridLayout_2->addWidget(le_username, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);

        widget = new QWidget(LoginWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 40));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 0, 2, 0);
        btn_login = new QPushButton(widget);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(btn_login, 0, 0, 1, 1);

        btn_exit = new QPushButton(widget);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(btn_exit, 0, 1, 1, 1);


        gridLayout_3->addWidget(widget, 2, 0, 1, 1);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Login", nullptr));
#if QT_CONFIG(tooltip)
        LoginWindow->setToolTip(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("LoginWindow", "StudentInfoManager", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "username", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "password", nullptr));
        le_password->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Please enter the password...", nullptr));
        le_username->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Please enter the usename...", nullptr));
        btn_login->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        btn_exit->setText(QCoreApplication::translate("LoginWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
