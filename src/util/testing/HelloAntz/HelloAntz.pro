#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T20:37:02
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = HelloAntz
CONFIG   += console
CONFIG   -= app_bundle

include (../common.pri)

win32:RC_FILE = WinRes.rc

TEMPLATE = app

LIBS    *= -leirBase
LIBS    *= -leirType
LIBS    *= -leirKii
LIBS    *= -leirVar
LIBS    *= -leirCfg
LIBS    *= -leirExe
LIBS    *= -leirMsg
LIBS    *= -leirState

SOURCES += main.cpp \
    AntzConsole.cpp

HEADERS += \
    AntzConsole.h \
    Version.h \
    ../../../Common/CommonVersion.h

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
