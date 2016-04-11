#include "BaseState.h"

#include <base/Diagnostic.h>

#include "BaseMachine.h"
#include "BaseStateBehavior.h"

BaseState::BaseState(const BasicId id,
                     StateInterface * interface,
                     BaseMachine * machine,
                     QState * parent)
    : QState(parent ? (QState *)(machine) : parent)
    , mId(id)
    , mpInterface(interface)
    , mpMachine(machine)
{
    FATALNOT(mpInterface);
    FATALNOT(mpMachine);
    mKey = mpMachine->addKey(id, this);
    WARNIF(mKey.isNull());
    setObjectName("BaseState:" + id());

    setupConnections();

    onCreate();
}

BaseState::~BaseState()
{
    onDestroy();
}

void BaseState::setupConnections(void)
{
    WARNNOT(connect(this, SIGNAL(creating(BaseState*,BasicKey)),
                    mpMachine, SLOT(createState(BaseState*,BasicKey))));
    WARNNOT(connect(this, SIGNAL(entering(BaseState*,BasicKey)),
                    mpMachine, SLOT(enterState(BaseState*,BasicKey))));
    WARNNOT(connect(this, SIGNAL(doing(BaseState*,BasicKey)),
                    mpMachine, SLOT(doState(BaseState*,BasicKey))));
    WARNNOT(connect(this, SIGNAL(done(BaseState*,BasicKey)),
                    mpMachine, SLOT(dontState(BaseState*,BasicKey))));
    WARNNOT(connect(this, SIGNAL(leaving(BaseState*,BasicKey)),
                    mpMachine, SLOT(leaving(BaseState*,BasicKey))));
    WARNNOT(connect(this, SIGNAL(terminating(BaseState*,BasicKey)),
                    mpMachine, SLOT(terminateState(BaseState*,BasicKey))));
    WARNNOT(connect(this, SIGNAL(destroying(BaseState*,BasicKey)),
                    mpMachine, SLOT(destroyState(BaseState*,BasicKey))));
    WARNNOT(connect(this, SIGNAL(error(BaseState*,BasicKey,Result)),
                    mpMachine, SLOT(handleError(BaseState*,BasicKey,Result))));
    WARNNOT(connect(this, SIGNAL(message(BaseState*,BasicKey,QString)),
                    mpMachine, SLOT(handleMessage(BaseState*,BasicKey,QString))));
}

/*---------- ACCESS -----------*/

BasicKey BaseState::key(void) const
{
    return mKey;
}

BasicId BaseState::id(void) const
{
    return mId;
}


/*---------- SLOTS ----------*/

void BaseState::onCreate(void)
{
    CRITNOT(mpInterface);
    emit creating(this, mKey);
    mpInterface->doCreate();
}

void BaseState::onEnter(void)
{
    emit entering(this, mKey);
    mpInterface->doEnter();
}

void BaseState::onWork(void)
{
    emit doing(this, mKey);
    mpInterface->doState();
    emit done(this, mKey);
}

void BaseState::onLeave(void)
{
    emit leaving(this, mKey);
    mpInterface->doExit();
}

void BaseState::onTerminate(void)
{
    emit terminating(this, mKey);
    mpInterface->doTerminate();
}

void BaseState::onDestroy(void)
{
    emit destroying(this, mKey);
    mpInterface->doDestroy();
}

void BaseState::handleError(const Result result)
{
    emit error(this, mKey, result);
    mpInterface->doError(result);
}

void BaseState::handleMessage(const QString & string)
{
    emit message(this, mKey, string);
    mpInterface->doMessage(string);
}
