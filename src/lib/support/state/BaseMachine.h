#ifndef BASEMACHINE_H
#define BASEMACHINE_H

#include <QStateMachine>

#include <QList>
//#include <QMap>
#include <QPair>

#include <base/BasicId.h>
#include <base/BasicKey.h>
#include <base/BasicKeyManager.h>
#include <core/DualMap.h>
#include <base/MetaName.h>
#include <type/Success.h>

#include <res/Result.h>
//#include <var/VariablePack.h>

class BaseState;
class StateInterface;

class BaseMachine : public QStateMachine
{
    Q_OBJECT
public:
    typedef QPair<BasicId, MetaName> IdInterfacePair;
    typedef QList<IdInterfacePair> IdInterfacePairList;
    typedef QPair<BasicId, BasicId> SourceTargetStatePair;
    typedef QPair<BasicId, QString> StateIdSignalPair;
    typedef QPair<SourceTargetStatePair,
                  StateIdSignalPair> SignalTransitionPair;
    typedef QList<SourceTargetStatePair> SourceTargetStateList;
    typedef QList<SignalTransitionPair> SignalTransitionList;

public:
    explicit BaseMachine(QObject * parent=0);
    BasicKey key(const BasicId & id) const;
    BasicId id(const BasicKey key) const;
    BaseState * state(const BasicKey key) const;
    BaseState * state(const BasicId id) const;
    Success overrideInterface(const BasicKey key,
                              StateInterface * interface);

signals:
    void startingMachine(void);
    void stopingMachine(void);
    void terminatingMachine(void);
    void errorMachine(Result result);
    void messageMachine(QString message);

    void creatingState(BaseState * p, BasicKey key);
    void enteringState(BaseState * p, BasicKey key);
    void doingState(BaseState * p, BasicKey key);
    void doneState(BaseState * p, BasicKey key);
    void leavingState(BaseState * p, BasicKey key);
    void terminatingState(BaseState * p, BasicKey key);
    void destroyingState(BaseState * p, BasicKey key);
    void errorState(BaseState * p, BasicKey key, Result result);
    void messageState(BaseState * p, BasicKey key, QString message);

public slots:
    void start(void);
    void stop(void);
    void terminate(void);

public: // pseudo-private (called by child state)
    BasicKey addKey(const BasicId & stateId,
                    BaseState * state);

protected:
    BaseMachine(const IdInterfacePairList & idInterfacePairList,
                const SourceTargetStateList & stateList
                                        =SourceTargetStateList(),
                const SignalTransitionList & signalList
                                        =SignalTransitionList(),
                QObject * parent=0);



private:
    void setupKeys(void);
    Success addAllStates(void);
    Success addSuperState(const BasicName & superState);
    BaseState * addState(const BasicId & id,
                         const MetaName & interfaceName);
    Success addUnconditionalTransitions(void);
    Success addStateSignalTransitions(void);

private slots:
    void createState(BaseState * state, BasicKey key);
    void enterState(BaseState * state, BasicKey key);
    void doState(BaseState * state, BasicKey key);
    void dontState(BaseState * state, BasicKey key);
    void leaveState(BaseState * state, BasicKey key);
    void terminateState(BaseState * state, BasicKey key);
    void destroyState(BaseState * state, BasicKey key);
    void handleError(BaseState * state, BasicKey key, Result result);
    void handleMessage(BaseState * state, BasicKey key, QString message);

private:
    const IdInterfacePairList cmIdBehaviorPairList;
    const SourceTargetStateList cmUndonditionalTransitionList;
    const SignalTransitionList cmSignalTransitionList;
    BasicKeyManager mKeys;
    DualMap<BasicKey, BaseState *> mKeyStateMap;
};

#endif // BASEMACHINE_H
