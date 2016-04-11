#include "BaseMachine.h"

#include <QAbstractTransition>
#include <QSignalTransition>
#include <QTimer>

#include <base/BasicKey.h>
#include <base/Diagnostic.h>
#include <kii/Name.h>

#include "BaseState.h"
#include "_internal/BaseTransition.h"
#include "_internal/MachineErrorInterface.h"
#include "_internal/MachineFinalInterface.h"
#include "_internal/MachineInitialInterface.h"
#include "StateInterface.h"

/*---------- CONSTRUCTION ----------*/

BaseMachine::BaseMachine(QObject * parent)
    : QStateMachine(parent) {;}

// protected
BaseMachine::BaseMachine(const BasicKeyManager::KeyIdPairList
                                stateKeyIdList,
                         const IdInterfacePairList &
                                idInterfacePairList,
                         const SourceTargetStateList &
                                stateList,
                         const SignalTransitionList &
                                signalList,
                         QObject * parent)
    : QStateMachine(parent)
    , cmStateKeyIdList(stateKeyIdList)
    , cmIdBehaviorPairList(idInterfacePairList)
    , cmUndonditionalTransitionList(stateList)
    , cmSignalTransitionList(signalList)
{
    keys().load(cmStateKeyIdList);
    addUnconditionalTransitions();
    addStateSignalTransitions();
    QTimer::singleShot(1, this, SLOT(initialize()));
}

void BaseMachine::command(const Command cmd)
{
    switch (cmd)
    {
    case Initialize:
        QTimer::singleShot(10, this, SLOT(initialize()));
        break;

    case Start:
        QTimer::singleShot(10, this, SLOT(initialize()));
        break;

    case Stop:
        QTimer::singleShot(10, this, SLOT(initialize()));
        break;

    case Terminate:
        QTimer::singleShot(10, this, SLOT(initialize()));
        break;

    case nullCommand:   /* nada */  break;
    case sizeCommand:   /* nada */  break;
    }
}

/*---------- ACCESS ----------*/

BasicKeyManager & BaseMachine::keys(void)
{
    return mKeys;
}

BasicKey BaseMachine::key(const BasicId & id) const
{
    return mKeys.key(id);
}

BasicKey BaseMachine::key(BaseState * state) const
{
    return mKeyStateDMap.at(state);
}

BasicId BaseMachine::id(const BasicKey key) const
{
    return mKeys.id(key);
}

BaseState * BaseMachine::state(const BasicId id) const
{
    return mKeyStateDMap.at(key(id));
}

BaseState * BaseMachine::state(const BasicKey key) const
{
    return mKeyStateDMap.at((key));
}

/*---------- INITIALIZATION ----------*/

// pseudo-private public
BasicKey BaseMachine::addKey(const BasicId & stateId,
                             BaseState * state)
{
    BasicKey key;

    WARNIF(2 != stateId.size());
    BasicName superName = stateId.at(0);
    BasicName subName = stateId.at(1);
    WARNNOT(mKeys.contains(BasicId("SuperState", superName)));
    key = mKeys.add(BasicId("SuperState", superName,
                                  "SubState", subName));
    CRITMSGIF(key.isNull(), "Unable to add " + stateId());

    if (state)   mKeyStateDMap.insertUnique(key, state);

    return key;
}

// private
void BaseMachine::setupKeys(void)
{
    mKeys.add("SuperState");
    mKeys.add("SuperState/0");
    mKeys.add("SuperState/0/SubState");
    mKeys.add("SuperState/0/SubState/0");
}

// private
Success BaseMachine::addAllStates(void)
{
    Success success(true);

    addKey("0/0", (BaseState *)((QState *)(this)));
    WARNMSGNOT(addSuperState("0"), "Top-level SuperState failed");

    IdInterfacePairList pairList = cmIdBehaviorPairList;
    while ( ! pairList.isEmpty())
    {
        IdInterfacePair pair = pairList.takeFirst();
        BasicId id = pair.first;
        BasicName superName = id.at(0);
        BasicName subName = id.name();

        MetaName metaName(pair.second);
        if (metaName.isEmpty()) metaName.set(id.toString('_'));

        if ( ! mKeys.contains(BasicId("SuperState", superName)))
            WARNMSGNOT(addSuperState(superName),
                    "Adding super: " + superName());
        success.expect(addState(id, metaName));
    }

    return success;
}

// private
Success BaseMachine::addSuperState(const BasicName & superState)
{
    Success success(true);

    MachineErrorInterface errIf;
    MachineFinalInterface finIf;
    MachineInitialInterface iniIf;

    success.expect(addState(BasicId(superState, "MachineInitial"),
                            iniIf.metaName()));
    success.expect(addState(BasicId(superState, "MachineError"),
                            errIf.metaName()));
    success.expect(addState(BasicId(superState, "MichineFinal"),
                            finIf.metaName()));

    return success;
}


// private
BaseState * BaseMachine::addState(const BasicId & id,
                                  const MetaName & interfaceName)
{
    BasicId parentId = id.parents();
    BasicKey parentKey = key(parentId);
    BaseState * parentState = state(parentKey);

    //BasicName name = id.name();
    BaseState * state = 0;

    StateInterface * interface = StateInterface::fromName(interfaceName,
                                                               this,
                                                               state);
    WARNNOT(interface); if ( ! interface) return state; //----------

    state = new BaseState(id, interface, this, parentState);
    WARNNOT(state); if ( ! state) return state; //----------

    emit creatingState(state, state->key());
    WARNNOT(connectState(state));
    return state;
}

Success BaseMachine::connectState(BaseState * state)
{
    Success success;

    success.test(connect(state, SIGNAL(entered()),
                         this, SLOT(entered())));
    success.test(connect(state, SIGNAL(exited()),
                         this, SLOT(exited())));
    success.test(connect(state, SIGNAL(destroyed(QObject*)),
                         this, SLOT(destroyed(QObject*))));

    return success.tested();
}


// private
Success BaseMachine::addUnconditionalTransitions(void)
{
    Success success(true);
    foreach (SourceTargetStatePair pair,
             cmUndonditionalTransitionList)
    {
        BaseState * sourceState = state(pair.first);
        BaseState * targetState = state(pair.second);
        BaseTransition * xition = new BaseTransition(sourceState);
        xition->setTargetState(targetState);
        WARNNOT(sourceState); WARNNOT(targetState); WARNNOT(xition);
        QStateMachine::addTransition(xition);
        success.expect(sourceState && targetState && xition);
    }
    return success;
}

// private
Success BaseMachine::addStateSignalTransitions(void)
{
    Success success;
    foreach (SignalTransitionPair pair,
             cmSignalTransitionList)
    {
        SourceTargetStatePair states = pair.first;
        StateIdSignalPair signal = pair.second;
        BaseState * sourceState = state(states.first);
        BaseState * targetState = state(states.second);
        BaseState * signalState = state(signal.first);
        QSignalTransition * xition
                = new QSignalTransition(sourceState);
        xition->setTargetState(targetState);
        xition->setSenderObject(signalState);
        xition->setSignal(QByteArray(signal.second.toLocal8Bit()));
        QStateMachine::addTransition(xition);
        success.set();
    }
    return success;
}

/*---------- EMITTER SLOTS ----------*/

void BaseMachine::createState(BaseState * state, BasicKey key)
{
    emit creatingState(state, key);
}

void BaseMachine::enterState(BaseState * state, BasicKey key)
{
    emit enteringState(state, key);
}

void BaseMachine::doState(BaseState * state, BasicKey key)
{
    emit doingState(state, key);
}

void BaseMachine::dontState(BaseState * state, BasicKey key)
{
    emit doneState(state, key);
}

void BaseMachine::leaveState(BaseState * state, BasicKey key)
{
    emit leavingState(state, key);
}

void BaseMachine::terminateState(BaseState * state, BasicKey key)
{
    emit terminatingState(state, key);
}

void BaseMachine::destroyState(BaseState * state, BasicKey key)
{
    emit destroyedState(state, key);
}

void BaseMachine::handleError(BaseState * state, BasicKey key, Result result)
{
    emit stateError(state, key, result);
}

void BaseMachine::handleMessage(BaseState * state, BasicKey key, QString message)
{
    emit stateMessage(state, key, message);
}

/*---------- SLOT HANDLERS ----------*/

void BaseMachine::entered(void)
{
    BaseState * state = qobject_cast<BaseState *>(sender());
    if (state) enterState(state, key(state));
}

void BaseMachine::exited(void)
{
    BaseState * state = qobject_cast<BaseState *>(sender());
    if (state) leaveState(state, key(state));
}

void BaseMachine::destroyed(QObject * pObj)
{
    BaseState * state = qobject_cast<BaseState *>(pObj);
    if (state) destroyState(state, key(state));
}


/*---------- MACHINE SLOTS ----------*/

// virtual
void BaseMachine::initialize(void)
{
    TODO("Stuff");
    emit initializedMachine();
}

// virtual
void BaseMachine::start(void)
{
    TODO("Stuff");
    QStateMachine::start();
    emit startedMachine();
}

// virtual
void BaseMachine::stop(void)
{
    TODO("Stuff");
    QStateMachine::stop();
    emit stopedMachine();
}

// virtual
void BaseMachine::terminate(void)
{
    TODO("Stuff");
    emit terminatedMachine();
}
