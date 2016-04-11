QT += core
QT -= gui

TARGET = HelloCloudConsole
TEMPLATE = app
CONFIG   += console
CONFIG   -= app_bundle

include (../common.pri)

win32:RC_FILE = WinRes.rc

TEMPLATE = app

LIBS *= -leirBase
LIBS *= -leirType
LIBS *= -leirVar
LIBS *= -leirKii
LIBS *= -leirCfg
LIBS *= -leirExe
LIBS *= -leirMsg
LIBS *= -leirState
LIBS *= -leirWork

SOURCES += main.cpp \
    HelloCloudConsole.cpp

HEADERS += \
    HelloCloudConsole.h \
    WinRes.rc \
    Version.h \
    Version.h \
    WinRes.rc

DISTFILES += \
    Next.txt

