#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Pomodoro");
    w.resize(400,100);
    w.show();
    return a.exec();
}
