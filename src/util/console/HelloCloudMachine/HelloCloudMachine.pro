QT += core
QT -= gui
QT += network

TARGET = HelloCloudMachine
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase
LIBS *= -leirType
LIBS *= -leirVar
LIBS *= -leirKii
LIBS *= -leirCfg
LIBS *= -leirExe
LIBS *= -leirMsg
LIBS *= -leirState
#LIBS *= -leirWork

CONFIG(debug, debug|release) {
    LIBS *= -lqhttpserverd
}
else {
    LIBS *= -lqhttpserver
}

SOURCES += main.cpp \
    HelloCloudMachine.cpp

HEADERS += \
    ../../../CommonVersion.h \
    Version.h \
    HelloCloudMachine.h

OTHER_FILES += \
    ../../../CommonWinRes.rc \
    WinRes.rc
