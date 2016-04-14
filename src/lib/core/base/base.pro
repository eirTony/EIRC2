#-------------------------------------------------
#
# Project created by QtCreator 2014-10-01T21:29:12
#
#-------------------------------------------------

QT       -= gui
QT       += testlib

TARGET = eirBase
TEMPLATE = lib

DEFINES += BASE_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

SOURCES += BaseLib.cpp \
    ModuleInfo.cpp \
    VersionInfo.cpp \
    BasicName.cpp \
    PluginObject.cpp \
    AbstractPlugin.cpp \
    BasicId.cpp \
    MetaName.cpp \
    BasicKey.cpp \
    ./_internal/DiagnosticItem.cpp \
    ./_internal/ModuleManager.cpp \
    BasicKeySegment.cpp \
    BasicKeyManager.cpp \
    TestObject.cpp \
    DiagnosticOutput.cpp

HEADERS += BaseLib.h\
        base_global.h \
    ModuleInfo.h \
    VersionInfo.h \
    Version.h \
    ../../../CommonVersion.h \
    ../type/CProperty.h \
    BasicName.h \
    BasicNameMap.h \
    BasicNameHash.h \
    PluginObject.h \
    AbstractPlugin.h \
    BasicId.h \
    MetaName.h \
    BasicKey.h \
    ./_internal/DiagnosticItem.h \
    Diagnostic.h \
    ./_internal/ModuleManager.h \
    BasicKeySegment.h \
    BasicKeyManager.h \
    TestObject.h \
    DiagnosticOutput.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
