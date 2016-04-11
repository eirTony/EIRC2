#include "ConsoleUno.h"
#include "Version.h"
#include <CommonVersion.h>
#ifdef MODULE_NAME
# undef MODULE_NAME
#endif
#define MODULE_NAME "ConsoleUno"

#include <QTimer>

#include <base/Diagnostic.h>
#include <msg/EclipseMessage.h>
#include <msg/EclipseMessageQueue.h>
#include <state/EclipseStateMachine.h>
#include <work/EclipseWorkMessageMachine.h>

ConsoleUno::ConsoleUno(void)
    : mpMachine(new EclipseWorkMessageMachine(this))
{
    setVersion();
    QObject::setObjectName("ConsoleUno");
}

void ConsoleUno::doInitialize(void)
{
    TRACE("Initializing ConsoleUno %1",
          QDateTime::currentDateTime().toString());
    mpMachine->initialize(ExecutableSupport::initialization());
    CRITIF(true, "This should also show");
    connect(this, SIGNAL(send(const EclipseMessage &)),
            mpMachine->queue(), SLOT(incoming(const EclipseMessage &)));
    connect(mpMachine->queue(), SIGNAL(outgoing(const EclipseMessage &)),
            this, SLOT(receive(const EclipseMessage &)));
}

void ConsoleUno::doSetup(void)
{
    mpMachine->configure(ExecutableSupport::configuration());
}

void ConsoleUno::doStart(void)
{
    SerialExecutable::writeLine("Hello from ConsoleUno!");
    EclipseMessage msg;
    msg.insert("Message", "This is a message.");
    emit send(msg);

    QTimer::singleShot(5000, this, SLOT(quit()));
}

void ConsoleUno::receive(const EclipseMessage & msg)
{
    SerialExecutable::writeLine(msg["Message"].toString());
}
