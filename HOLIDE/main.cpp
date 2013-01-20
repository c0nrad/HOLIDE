#include "mainwindow.h"
#include <QApplication>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


       w.resize(640, 480);
       return a.exec();
    
    //return a.exec();
}
