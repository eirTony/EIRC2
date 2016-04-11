
QT      -= gui
QT      += xml

TARGET = eirData
TEMPLATE = lib

DEFINES += DATA_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase
LIBS *= -leirType

SOURCES += DataLib.cpp \
    DataType.cpp \
    StringBehavior.cpp \
    TypeBehavior.cpp

HEADERS += DataLib.h \
    Version.h \
    ../../../CommonVersion.h \
    data_global.h \
    DataType.h \
    StringBehavior.h \
    TypeBehavior.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
