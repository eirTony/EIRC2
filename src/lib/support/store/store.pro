#-------------------------------------------------
#
# Project created by QtCreator 2015-12-01T02:41:14
#
#-------------------------------------------------

QT       += network sql xml

QT       -= gui

TARGET = eirStore
TEMPLATE = lib

DEFINES += STORELIB_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase
#LIBS *= -leirType
#LIBS *= -leirCfg
#LIBS *= -leirVar
#LIBS *= -leirRes

SOURCES += StoreLib.cpp \
    StoreInterface.cpp

HEADERS += StoreLib.h\
        store_global.h \
    StoreInterface.h \
    Version.h \
    Version.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    WinRes.rc \
    WinRes.rc \
    WinRes.rc
