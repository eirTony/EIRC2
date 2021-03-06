
QT       -= gui

TARGET = eirRes
TEMPLATE = lib

DEFINES += RES_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase

SOURCES += ResLib.cpp \
    Result.cpp

HEADERS += ResLib.h \
    res_global.h \
    Version.h \
    ../../../common/CommonVersion.h \
    Result.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
