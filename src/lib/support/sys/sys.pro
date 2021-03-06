
QT       -= gui

TARGET = eirSys
TEMPLATE = lib

DEFINES += SYS_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase

SOURCES += SysLib.cpp

HEADERS += SysLib.h \
    sys_global.h \
    Version.h \
    ../../../common/CommonVersion.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
