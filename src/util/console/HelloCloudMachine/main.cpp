#include <QCoreApplication>

#include "HelloCloudMachine.h"

#include <exe/ExecutableInitialization.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#if false
    ExecutableInitialization exeInt;
    HelloCloudMachine machine(exeInt.initVarMap());
#else
    HelloCloudMachine machine();
#endif
    return a.exec();
}

