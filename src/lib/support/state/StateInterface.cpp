#include "StateInterface.h"

#include <QMetaObject>
#include <QMetaType>

#include <base/Diagnostic.h>
#include <base/MetaName.h>

#include "BaseMachine.h"
#include "BaseState.h"

QMap<MetaName, const QMetaObject *> StateInterface::smNameMetaObjectMap;

StateInterface::StateInterface(void)
{
}

#if 0
StateInterface::StateInterface(BaseMachine * machine,
                               BaseState * state)
    : QObject(state)
    , mpMachine(machine)
    , mpState(state)
{
}
#endif

void StateInterface::setMachine(BaseMachine * machine)
{
    WARNNOT(machine);
    mpMachine = machine;
}

void StateInterface::setState(BaseState * state)
{
    WARNNOT(state);
    mpState = state;
    QObject::setParent(state);
}

BasicId StateInterface::id(void) const
{

    CRITNOT(mpState);
    return mpState ? mpState->id() : BasicId();
}

void StateInterface::muster(void)
{
    smNameMetaObjectMap.insert(metaName(), this->metaObject());
}

// static
StateInterface * StateInterface::fromName(MetaName metaName,
                                          BaseMachine * machine,
                                          BaseState * state)
{
    StateInterface * interface = 0;
    WARNNOT(machine); WARNNOT(state);
#if 1
    const QMetaObject * metaObject
                            = smNameMetaObjectMap.value(metaName);
    WARNMSGNOT(metaObject,
               "StateInterface not recognized: "+metaName());
    if (metaObject)
    {
        interface = static_cast<StateInterface *>
                (metaObject->newInstance());
        WARNMSGNOT(interface,
                   "StateInterface unable to create interface: "
                        +metaName());
        if (interface)
        {
            interface->setMachine(machine);
            interface->setState(state);
            interface->muster();
        }
    }
#else
    int metaType = QMetaType::type(metaName);
    WARNMSGNOT(metaType, "MetaTypeName not recognized: "+metaName());
    if ( ! metaType) return interface; //----------------

    const QMetaObject * metaObject
            = QMetaType::metaObjectForType(metaType);
    if ( ! metaObject) return interface; //------------------

    QObject * object = metaObject->newInstance(Q_ARG(BaseMachine *, machine),
                                               Q_ARG(BaseState *, state));
    if ( ! object) return interface; //--------------------

    interface = qobject_cast<StateInterface *>(object);
#endif
    return interface;
}

