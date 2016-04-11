#-------------------------------------------------
#
# Project created by QtCreator 2015-11-22T00:23:55
#
#-------------------------------------------------

QT       -= gui

TARGET = eirState
TEMPLATE = lib

DEFINES += STATE_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase
LIBS *= -leirType
LIBS *= -leirKii
#LIBS *= -leirCfg
LIBS *= -leirVar
LIBS *= -leirRes

SOURCES += StateLib.cpp \
    BaseState.cpp \
    BaseMachine.cpp \
    StateInterface.cpp \
    EclipseStateMachine.cpp \
    _internal/MachineInitialInterface.cpp \
    _internal/MachineErrorInterface.cpp \
    _internal/MachineFinalInterface.cpp \
    _internal/BaseTransition.cpp \
    BaseInterface.cpp

HEADERS += StateLib.h\
        state_global.h \
    Version.h \
    BaseState.h \
    BaseMachine.h \
    StateInterface.h \
    EclipseStateMachine.h \
    _internal/MachineInitialInterface.h \
    _internal/MachineErrorInterface.h \
    _internal/MachineFinalInterface.h \
    _internal/BaseTransition.h \
    BaseInterface.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc
