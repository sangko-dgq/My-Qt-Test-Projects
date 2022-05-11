/********************************************************************************
** Form generated from reading UI file 'filesync.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESYNC_H
#define UI_FILESYNC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileSync
{
public:
    QTextBrowser *TBrwDebug;

    void setupUi(QWidget *FileSync)
    {
        if (FileSync->objectName().isEmpty())
            FileSync->setObjectName(QString::fromUtf8("FileSync"));
        FileSync->resize(800, 600);
        TBrwDebug = new QTextBrowser(FileSync);
        TBrwDebug->setObjectName(QString::fromUtf8("TBrwDebug"));
        TBrwDebug->setGeometry(QRect(30, 40, 571, 501));

        retranslateUi(FileSync);

        QMetaObject::connectSlotsByName(FileSync);
    } // setupUi

    void retranslateUi(QWidget *FileSync)
    {
        FileSync->setWindowTitle(QCoreApplication::translate("FileSync", "FileSync", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileSync: public Ui_FileSync {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESYNC_H
