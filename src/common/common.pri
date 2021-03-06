# file: ./src/common/common.pri
#message("In ./src/common/common.pri")

#SRCDIR = $$(PWD)
#BASEDIR = $$dirname($$SRCDIR)
#EXEDIR = $$BASEDIR/exe
SRCDIR = ../../..
BASEDIR = ../../../..
EXEDIR = ../../../../exe

CONFIG += debug_and_release
CONFIG(debug, debug|release) {
        QMAKE_CXXFLAGS_DEBUG *= -Og
        DESTDIR = $$EXEDIR/dbg32W
        LIBS += -L$$EXEDIR/dbg32W
}
else {
        DESTDIR = $$EXEDIR/bin32W
        LIBS += -L$$EXEDIR/bin32W
}
INCLUDEPATH *= ../../../lib/core
INCLUDEPATH *= ../../../lib/support
INCLUDEPATH *= ../../../lib/worker
INCLUDEPATH *= ../../../lib/third
INCLUDEPATH *= ../../../common
INCLUDEPATH *= ../../..

DEFINES *= QT_USE_QSTRINGBUILDER
DEFINES *= BUILD_TEST
QMAKE_CXXFLAGS *= -std=c++11

!win32:VERSION = 2.4.1
# How to set from CommonVersion.h?
