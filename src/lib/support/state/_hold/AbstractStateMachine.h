#ifndef ABSTRACTSTATEMACHINE_H
#define ABSTRACTSTATEMACHINE_H

#include <QStateMachine>

#include <base/BasicName.h>
#include <type/Boolean.h>
#include <cfg/Configuration.h>
class KiiManager;

#include "StateId.h"
#include "StateKey.h"

class AbstractStateMachine : public QStateMachine
{
    Q_OBJECT
public:
    StateKey currentKey(void) const;
    StateId currentId(void) const;
    QState * currentState(void) const;
    QState * state(const StateKey key) const;
    QState * state(const StateId & id) const;
    Boolean is(const StateKey key) const;
    Boolean is(const StateId & id) const;
    StateKey key(const StateId & id) const;
    StateId id(const StateKey key) const;
    Boolean contains(const StateId & id) const;
    Boolean contains(const StateKey key) const;
    StateKey::Vector keys(void) const;
    StateId::Vector ids(void) const;

protected:
    AbstractStateMachine(QObject * parent=0);
    virtual Boolean initialize(const BasicName::VariantMap & init);
    virtual Boolean configure(const Configuration & config);

signals:
    void stateChanged(StateKey toKey, StateKey fromKey);
    void stateChanged(StateId toId, StateId fromId);

public slots:

private:
//    KiiManager * mpKiiManager = 0;
    BasicName::VariantMap mInitNameMap;
    Configuration mConfig;
};

#endif // ABSTRACTSTATEMACHINE_H
