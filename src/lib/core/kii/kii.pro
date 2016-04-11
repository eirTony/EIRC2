
QT       -= gui

TARGET = eirKii
TEMPLATE = lib

DEFINES += KII_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase

SOURCES += KiiLib.cpp \
    AbstractId.cpp \
    AbstractName.cpp \
    BaseNameIdBehavior.cpp \
    UniversalKey.cpp \
    BaseKiiItem.cpp \
    BaseKeyBehavior.cpp \
    BaseIdBehavior.cpp \
    BaseInfoBehavior.cpp \
    BaseKey.cpp \
    BaseId.cpp \
    BaseInfo.cpp

HEADERS += KiiLib.h \
    Version.h \
    ../../../CommonVersion.h \
    AbstractId.h \
    AbstractName.h \
    BaseNameIdBehavior.h \
    UniversalKey.h \
    kii_global.h \
    BaseKiiItem.h \
    BaseKeyBehavior.h \
    BaseIdBehavior.h \
    BaseInfoBehavior.h \
    BaseKey.h \
    BaseId.h \
    BaseInfo.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
