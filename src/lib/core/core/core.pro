
QT       -= gui

TARGET = eirCore
TEMPLATE = lib

DEFINES += CORE_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase
#LIBS *= -leirType
#LIBS *= -leirData
#LIBS *= -leirKii

SOURCES += CoreLib.cpp

HEADERS += CoreLib.h \
    Version.h \
    ../../../Common/CommonVersion.h \
    core_global.h \
    Singleton.h \
    @hold/Singleton.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
