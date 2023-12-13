#include "mainwindow.h"
#include <QApplication>

// Point d'entrée du programme.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
