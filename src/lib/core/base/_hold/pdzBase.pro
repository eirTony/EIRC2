#-------------------------------------------------
#
# Project created by QtCreator 2016-01-08T18:48:59
#
#-------------------------------------------------

##PDZ## Need gui module for QIcon in VersionInfo
#QT       -= gui

TARGET = pdzBase
TEMPLATE = lib

DEFINES += PDZBASE_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

SOURCES += pdzBase.cpp \
    VersionInfo.cpp \
    LibraryInfo.cpp \
    BasicId.cpp \
    BasicKey.cpp \
    BasicKeyManager.cpp \
    BasicKeySegment.cpp \
    BasicName.cpp \
    AbstractPlugin.cpp \
    PluginObject.cpp \
    _internal/DiagnosticItem.cpp \
    MetaName.cpp

HEADERS += pdzBase.h\
        pdzbase_global.h \
    LibraryVersion.h \
    VersionInfo.h \
    LibraryInfo.h \
    ../../../BranchVersion.h \
    ../../../Common/CommonVersion.h \
    BasicSingleton.h \
    BasicId.h \
    BasicKey.h \
    BasicKeyManager.h \
    BasicKeySegment.h \
    BasicName.h \
    AbstractPlugin.h \
    Diagnostic.h \
    PluginObject.h \
    _internal/DiagnosticItem.h \
    DualMap.h \
    MetaName.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../Common.ico \
    ../../../CommonWinRes.rc \
    ../../../README.rst \
    ../../README.md
