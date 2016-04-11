#include "ConsoleUno.h"
#include "Version.h"
#include <CommonVersion.h>
#ifdef MODULE_NAME
# undef MODULE_NAME
#endif
#define MODULE_NAME "ConsoleUno"

#include <QTimer>

#include <msg/EclipseMessage.h>
#include <msg/EclipseMessageQueue.h>
#include <state/EclipseStateMachine.h>
#include <work/EclipseWorkMessageMachine.h>

ConsoleUno::ConsoleUno(void)
    : mpEWMM(new EclipseWorkMessageMachine(this))
{
    setVersion();
    QObject::setObjectName("ConsoleUno");
}

void ConsoleUno::doInitialize(BasicName::VariantMap init)
{
    mpEWMM->initialize(init);
    connect(this, SIGNAL(send(const EclipseMessage &)),
            mpEWMM->queue(), SLOT(incoming(const EclipseMessage &)));
    connect(mpEWMM->queue(), SIGNAL(outgoing(const EclipseMessage &)),
            this, SLOT(receive(const EclipseMessage &)));
}

void ConsoleUno::doSetup(BasicId::VariantMap config)
{
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