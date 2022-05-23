#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "SQL/studentsql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QTranslator translator;
    // const QStringList uiLanguages = QLocale::system().uiLanguages();
    // for (const QString &locale : uiLanguages) {
    //     const QString baseName = "StudentInfoMSys_" + QLocale(locale).name();
    //     if (translator.load(":/i18n/" + baseName)) {
    //         a.installTranslator(&translator);
    //         break;
    //     }
    // }


    MainWindow w;
//    w.show(); //    /*Built but not to show MainWindw(To show LoginWindow)*/

   StudentSQL sql;

    return a.exec();
}
