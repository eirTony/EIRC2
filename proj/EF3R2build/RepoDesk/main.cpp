#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
  //  w.show();
    MainWindow::pointer()->show();
    return a.exec();
}
