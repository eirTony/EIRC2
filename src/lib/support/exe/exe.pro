
QT       -= gui

TARGET = eirExe
TEMPLATE = lib

DEFINES += EXE_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase
LIBS *= -leirType
LIBS *= -leirKii
LIBS *= -leirCfg

SOURCES += ExeLib.cpp \
    ConsoleApplication.cpp \
    ExecutableSupport.cpp \
    SerialExecutable.cpp \
    StandardIO.cpp \
    StandardStream.cpp \
    BaseSerialStream.cpp \
    PluginManager.cpp 

HEADERS += ExeLib.h \
    Exe_global.h \
    Version.h \
    ../../../Common/CommonVersion.h \
    ConsoleApplication.h \
    ExecutableSupport.h \
    SerialExecutable.h \
    StandardIO.h \
    StandardStream.h \
    BaseSerialStream.h \
    PluginManager.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
