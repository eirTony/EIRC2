#include "BaseStateBehavior.h"

#include <QMetaObject>
#include <QMetaType>

#include "BaseMachine.h"
#include "BaseState.h"

StateInterface::StateInterface(QObject * parent)
    : QObject(parent)
{
}

StateInterface::StateInterface(BaseMachine * machine,
                                     BaseState * state)
    : QObject(state)
    , mpMachine(machine)
    , mpState(state)
{
}

StateInterface * StateInterface::fromName(MetaTypeName metaName,
                                                BaseMachine * machine,
                                                BaseState * state) // static
{
    StateInterface * behavior = 0;
    int metaType = QMetaType::type(metaName);
    if ( !! metaType) return behavior;
    const QMetaObject * metaObject
            = QMetaType::metaObjectForType(metaType);
    if ( ! metaObject) return behavior;
    QObject * object = metaObject->newInstance(Q_ARG(BaseMachine *, machine),
                                               Q_ARG(BaseState *, state));
    if ( ! object) return behavior;
    behavior = qobject_cast<StateInterface *>(object);
    return behavior;
}
