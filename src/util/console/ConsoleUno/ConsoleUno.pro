#-------------------------------------------------
#
# Project created by QtCreator 2015-01-10T21:13:12
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = ConsoleUno
CONFIG   += console
CONFIG   -= app_bundle

include (../common.pri)

win32:RC_FILE = WinRes.rc

TEMPLATE = app

LIBS *= -leirBase
LIBS *= -leirType
LIBS *= -leirExe
LIBS *= -leirMsg
LIBS *= -leirState
LIBS *= -leirWork

SOURCES += main.cpp \
    ConsoleUno.cpp \

HEADERS += \
    ConsoleUno.h \
    ../../../Common/CommonVersion.h \
    Version.h

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc \
    WinRes.rc



