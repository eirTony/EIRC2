#include "EclipseStateMachine.h"

const BasicKeyManager::KeyIdPairList stateKeyIdList
        = BasicKeyManager::KeyIdPairList()
            << BasicKeyManager::KeyIdPair(0x0000000000000201,
                         "Super/Standby")
            << BasicKeyManager::KeyIdPair(0x0000040300000201,
                         "Super/Standby/Sub/Born")
            << BasicKeyManager::KeyIdPair(0x0000040300000201,
                         "Super/Standby/Sub/Provisioning")
            << BasicKeyManager::KeyIdPair(0x0000050300000201,
                         "Super/Standby/Sub/Initializing")
            << BasicKeyManager::KeyIdPair(0x0000060300000201,
                         "Super/Standby/Sub/Configuring")
            << BasicKeyManager::KeyIdPair(0x0000070300000201,
                         "Super/Standby/Sub/Idle")
            << BasicKeyManager::KeyIdPair(0x0000000000000801,
                         "Super/Running")
            << BasicKeyManager::KeyIdPair(0x0000070300000801,
                         "Super/Running/Sub/Ready")
            << BasicKeyManager::KeyIdPair(0x0000080300000801,
                         "Super/Running/Sub/Working")
            << BasicKeyManager::KeyIdPair(0x0000090300000801,
                         "Super/Running/Sub/Busy")
            << BasicKeyManager::KeyIdPair(0x00000A0300000801,
                         "Super/Running/Sub/Paused")
            << BasicKeyManager::KeyIdPair(0x00000B0300000801,
                         "Super/Running/Sub/RunningError")
            << BasicKeyManager::KeyIdPair(0x0000000000000C01,
                         "Super/Exiting")
            << BasicKeyManager::KeyIdPair(0x00000D0300000C01,
                         "Super/Exiting/Sub/Exiting")
            << BasicKeyManager::KeyIdPair(0x00000E0300000C01,
                         "Super/Exiting/Sub/ErrorExit")
            << BasicKeyManager::KeyIdPair(0x00000F0300000C01,
                         "Super/Exiting/Sub/AboutQuit")
            << BasicKeyManager::KeyIdPair(0x0000100300000C01,
                         "Super/Exiting/Sub/Quiting")
               ;


BaseMachine::IdInterfacePairList idInterfaceList
    = BaseMachine::IdInterfacePairList()
        << BaseMachine::IdInterfacePair("Super/Standby",
                                        "BaseInterface")
        << BaseMachine::IdInterfacePair("Super/Running",
                                        "BaseInterface")
        << BaseMachine::IdInterfacePair("Super/Exiting",
                                        "BaseInterface")
           ;

BaseMachine::SourceTargetStateList stateList
    = BaseMachine::SourceTargetStateList()
        << BaseMachine::SourceTargetStatePair("Super/Standby",
                                              "Super/Running")
           ;

BaseMachine::SignalTransitionList signalList
    = BaseMachine::SignalTransitionList()
        << BaseMachine::SignalTransitionPair(
               BaseMachine::SourceTargetStatePair("Super/Running",
                                                  "Super/Standby"),
               BaseMachine::StateIdSignalPair("Super/Standby",
                                              "stop"))
           ;

EclipseStateMachine::EclipseStateMachine(QObject * parent)
    : BaseMachine(stateKeyIdList,
                  idInterfaceList,
                  stateList,
                  signalList,
                  parent) {;}

// slot
void EclipseStateMachine::initializeMachine(void) {;}
