
QT       -= gui

TARGET = eirBjut
TEMPLATE = lib

DEFINES += BJUT_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

##LIBS *= -leirXxx

SOURCES += BjutLib.cpp \
    ModuleUnitTest.cpp \
    ClassUnitTest.cpp \
    UnitTestMetaObject.cpp \
    JournalQueue.cpp \
    internal/JournalEntry.cpp \
    internal/JournalItem.cpp \
    internal/JournalWriter.cpp \
    internal/ParsedJournalEntry.cpp

HEADERS += BjutLib.h \
    Version.h \
    ../../../CommonVersion.h \
    bjut_global.h \
    ModuleUnitTest.h \
    ClassUnitTest.h \
    UnitTestMetaObject.h \
    BasicUnitTest.h \
    ./internal/UnitTestInternal.h \
    BasicJournal.h \
    JournalQueue.h \
    internal/BasicJournalInternal.h \
    internal/JournalEntry.h \
    internal/JournalItem.h \
    internal/JournalWriter.h \
    internal/ParsedJournalEntry.h \
    internal/BjutTypes.h

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc \
    ../../../../dev+00006-BranchNotes.txt
