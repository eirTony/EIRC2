#include "EclipseWorkMessageMachine.h"
#if 0
#include <state/EclipseStateMachine.h>
#include <msg/EclipseMessageQueue.h>

EclipseWorkMessageMachine::EclipseWorkMessageMachine(QObject * parent)
    : QObject(parent)
    , cmpMachine(new EclipseStateMachine(this))
    , cmpQueue(new EclipseMessageQueue(this))

{
    Q_ASSERT(cmpMachine);
    Q_ASSERT(cmpQueue);
}

bool EclipseWorkMessageMachine::initialize(const BasicName::VariantMap & init)
{
    bool success = true;
    // success |= mpMachine->initialize(init);
    // success |= mpQueue->initialize(init);
    return success;
}

bool EclipseWorkMessageMachine::configure(const Configuration & config)
{
    bool success = true;
    Configuration cfg(config);
    // success |= mpMachine->configure(cfg);
    // success |= mpQueue->configure(config);
    return success;
}

const EclipseStateMachine * EclipseWorkMessageMachine::machine(void) const
{
    return cmpMachine;
}

const EclipseMessageQueue * EclipseWorkMessageMachine::queue(void) const
{
    return cmpQueue;
}

void EclipseWorkMessageMachine::start(void)
{
    // mpMachine->start();
}
#endif
