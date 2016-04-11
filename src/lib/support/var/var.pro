#-------------------------------------------------
#
# Project created by QtCreator 2016-02-02T00:14:33
#
#-------------------------------------------------

QT       -= gui

TARGET = eirVar
TEMPLATE = lib

DEFINES += VAR_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase

SOURCES += VarLib.cpp \
#    VariableMap.cpp \
#    VariablePack.cpp

HEADERS += VarLib.h\
        var_global.h \
#    VariableMap.h \
#    VariablePack.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
