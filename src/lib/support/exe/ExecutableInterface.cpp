#include "ExecutableInterface.h"

ExecutableInterface::ExecutableInterface(
        const ExecutableInitialization  & Initialization)
    : mInitialization(Initialization)
{
    setObjectName("ExecutableInterface");
}

// protected virtual
void ExecutableInterface::doConstruct(void)
{

}


// protected virtual
void ExecutableInterface::doInitialize(void)
{

}

// protected virtual
void ExecutableInterface::doSetup(const BasicId::VariantMap  & settings)
{
    mSettings = settings;
}

// protected virtual
void ExecutableInterface::doStart(void)
{

}

// protected virtual
void ExecutableInterface::doQuit(void)
{

}

// protected virtual
void ExecutableInterface::doDestruct(void)
{

}

// protected
BasicId::VariantMap  ExecutableInterface::initialization(void) const
{
    return mInitialization;
}

// protected
BasicId::VariantMap  ExecutableInterface::settings(void) const
{
    return mSettings;
}
