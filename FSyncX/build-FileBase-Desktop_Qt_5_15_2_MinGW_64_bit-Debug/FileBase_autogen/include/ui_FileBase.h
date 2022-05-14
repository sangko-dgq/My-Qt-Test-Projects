/********************************************************************************
** Form generated from reading UI file 'FileBase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEBASE_H
#define UI_FILEBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileBase
{
public:

    void setupUi(QWidget *FileBase)
    {
        if (FileBase->objectName().isEmpty())
            FileBase->setObjectName(QString::fromUtf8("FileBase"));
        FileBase->resize(800, 600);

        retranslateUi(FileBase);

        QMetaObject::connectSlotsByName(FileBase);
    } // setupUi

    void retranslateUi(QWidget *FileBase)
    {
        FileBase->setWindowTitle(QCoreApplication::translate("FileBase", "FileBase", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileBase: public Ui_FileBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEBASE_H
