#include "EclipseStateMachine.h"

BaseMachine::IdInterfacePairList idInterfaceList
    = BaseMachine::IdInterfacePairList()
        << BaseMachine::IdInterfacePair("0/Standby", "BaseInterface")
        << BaseMachine::IdInterfacePair("0/Running", "BaseInterface")
        << BaseMachine::IdInterfacePair("0/Exiting", "BaseInterface")
           ;

BaseMachine::SourceTargetStateList stateList
    = BaseMachine::SourceTargetStateList()
        << BaseMachine::SourceTargetStatePair("0/Standby", "0/Running")
           ;

BaseMachine::SignalTransitionList signalList
    = BaseMachine::SignalTransitionList()
        << BaseMachine::SignalTransitionPair(
               BaseMachine::SourceTargetStatePair("0/Running", "0/Standby"),
               BaseMachine::StateIdSignalPair("0/Standby", "stop"))
           ;

EclipseStateMachine::EclipseStateMachine(QObject * parent)
    : BaseMachine(idInterfaceList,
                  stateList,
                  signalList,
                  parent)
{
}
