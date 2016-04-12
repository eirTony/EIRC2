
QT       -= gui

TARGET = eirState
TEMPLATE = lib

DEFINES += STATE_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

#LIBS *= -leirQuick
LIBS *= -leirBase
LIBS *= -leirType
#LIBS *= -leirKii
LIBS *= -leirVar
LIBS *= -leirCfg

SOURCES += StateLib.cpp \
    EclipseStateMachine.cpp \
    StateMachineConfiguration.cpp \
    AbstractStateMachine.cpp \
    StateId.cpp \
    StateKey.cpp

HEADERS += StateLib.h \
    Version.h \
    ../../../Common/CommonVersion.h \
    state_global.h \
    EclipseStateMachine.h \
    StateMachineConfiguration.h \
    AbstractStateMachine.h \
    StateId.h \
    StateKey.h \
    MachineBuilder.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
