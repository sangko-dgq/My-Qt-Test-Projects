#include "filesync.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileSync w;
    w.show();
    return a.exec();
}
