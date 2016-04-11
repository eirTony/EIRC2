#include "AbstractStateMachine.h"

AbstractStateMachine::AbstractStateMachine(QObject * parent)
    : QStateMachine(parent)    // virtual protected
{
}

Boolean AbstractStateMachine::initialize(const BasicName::VariantMap & init)
{                               // virtual protected
    mInitNameMap = init;
    return true;
}

Boolean AbstractStateMachine::configure(const Configuration & config)
{                               // virtual protected
    mConfig = config;
    return true;
}
