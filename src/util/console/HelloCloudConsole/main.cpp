#include <QCoreApplication>

#include "HelloCloudConsole.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    HelloCloudConsole console;
    return a.exec();
}

