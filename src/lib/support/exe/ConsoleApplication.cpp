#include "ConsoleApplication.h"

#include <QCoreApplication>
#include <QTimer>

#include "ExecutableInitialization.h"
#include "StandardStream.h"

ConsoleApplication::ConsoleApplication(const ExecutableInitialization &
                                            initialization)
    : SerialExecutable(new StandardStream,
                       initialization) {;}

ConsoleApplication::~ConsoleApplication()
{
    NEEDDO("Kill children and clean up mess");
}
