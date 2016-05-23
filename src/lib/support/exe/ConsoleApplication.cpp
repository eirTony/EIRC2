#include "ConsoleApplication.h"

#include <QCoreApplication>
#include <QTimer>

#include "ExecutableInitialization.h"
#include "StandardStream.h"

ConsoleApplication::ConsoleApplication(ExecutableInitialization
                                            initialization)
    : SerialExecutable(new StandardStream,
                       initialization)
{
    setObjectName("ConsoleApplication");
}

ConsoleApplication::~ConsoleApplication()
{
    NEEDDO("Kill children and clean up mess");
}
