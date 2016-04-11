##EIRC##
## this dir from /QtC-MAR-sample/qhttpserver/src
## subdir from /QtC-MAR-sample/qhttpserver/http-parser

##EIRC## replace2
#include(../qhttpserver.pri)
include(./qhttpserver.pri)
#QHTTPSERVER_BASE = ..
QHTTPSERVER_BASE = .


TEMPLATE = lib

TARGET = qhttpserver

!win32:VERSION = 0.1.0

QT += network
QT -= gui

CONFIG += dll debug_and_release

CONFIG(debug, debug|release) {
##EIRC## replace 1
##  win32: TARGET = $$join(TARGET,,,d)
           TARGET = $$join(TARGET,,,d)
}

DEFINES += QHTTPSERVER_EXPORT

WORKERLIBDIR = ..

INCLUDEPATH += $$QHTTPSERVER_BASE/http-parser

PRIVATE_HEADERS += $$QHTTPSERVER_BASE/http-parser/http_parser.h qhttpconnection.h

PUBLIC_HEADERS += qhttpserver.h qhttprequest.h qhttpresponse.h qhttpserverapi.h qhttpserverfwd.h

HEADERS = $$PRIVATE_HEADERS $$PUBLIC_HEADERS
SOURCES = *.cpp $$QHTTPSERVER_BASE/http-parser/http_parser.c

OBJECTS_DIR = $$QHTTPSERVER_BASE/build
MOC_DIR = $$QHTTPSERVER_BASE/build
DESTDIR = $$QHTTPSERVER_BASE/lib

target.path = $$LIBDIR
headers.path = $$INCLUDEDIR
headers.files = $$PUBLIC_HEADERS
INSTALLS += target headers

##EIRC## add - overrides DESTDIR
include (../../common.pri)
DESTDIR = $$join(DESTDIR,,./,)
