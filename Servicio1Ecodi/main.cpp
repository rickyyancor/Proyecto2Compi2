#include "mainwindow.h"
#include <QApplication>

int mainqq(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
