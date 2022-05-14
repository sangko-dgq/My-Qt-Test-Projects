/*
 * @FilePath: \FileBase\main.cpp
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
