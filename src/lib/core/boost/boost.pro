#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T01:04:51
#
#-------------------------------------------------

TARGET = boost
TEMPLATE = lib

DEFINES += BOOST_LIBRARY

SOURCES += BoostLib.cpp

HEADERS += BoostLib.h\
        boost_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
