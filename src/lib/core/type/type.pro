#-------------------------------------------------
#
# Project created by QtCreator 2014-10-01T21:39:05
#
#-------------------------------------------------

QT       -= gui

TARGET = eirType
TEMPLATE = lib

DEFINES += TYPE_LIBRARY

include (../common.pri)

LIBS *= -leirBase

SOURCES += TypeLib.cpp \
    MillisecondTime.cpp \
    StringPair.cpp \
    Success.cpp \
    Boolean.cpp \
    NibbleArray.cpp \
    QQBitArray.cpp

HEADERS += TypeLib.h\
    type_global.h \
    MillisecondTime.h \
    CProperty.h \
    DProperty.h \
    CharCode.h \
    StringPair.h \
    CharCode.h \
    Unsigned.h \
    Success.h \
    Boolean.h \
    QQMap.h \
    NibbleArray.h \
    QQBitArray.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
