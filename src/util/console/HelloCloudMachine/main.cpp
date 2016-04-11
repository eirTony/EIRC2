#include <QCoreApplication>

#include "HelloCloudMachine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    HelloCloudMachine machine;
    return a.exec();
}

