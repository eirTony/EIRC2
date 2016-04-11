
QT       -= gui

TARGET = eirKii
TEMPLATE = lib

DEFINES += KII_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase
LIBS *= -leirData
LIBS *= -leirType

SOURCES += KiiLib.cpp \
    BaseNameIdBehavior.cpp \
    UniversalKey.cpp \
    BaseKiiItem.cpp \
    BaseKeyBehavior.cpp \
    BaseIdBehavior.cpp \
    BaseInfoBehavior.cpp \
    Key.cpp \
    Id.cpp \
    Info.cpp \
    KiiRing.cpp \
    Name.cpp \
    Kii.cpp \
    KiiManager.cpp \
    KiiTaxonomy.cpp \
    KiiCutter.cpp \
    KiiClassification.cpp \
    KiiClassId.cpp \
    KiiClassKey.cpp \
    KiiClassName.cpp \
    KiiInfo.cpp \
    KeySegment.cpp \
    KeyBuilder.cpp \
    KiiRingPlugin.cpp \
    KiiRingInterface.cpp \
    KiiRingBuiltin.cpp

HEADERS += KiiLib.h \
    Version.h \
    ../../../Common/CommonVersion.h \
    BaseNameIdBehavior.h \
    UniversalKey.h \
    kii_global.h \
    BaseKiiItem.h \
    BaseKeyBehavior.h \
    BaseIdBehavior.h \
    BaseInfoBehavior.h \
    Key.h \
    Id.h \
    Info.h \
    KiiRing.h \
    Name.h \
    Kii.h \
    KiiManager.h \
    KiiTaxonomy.h \
    KiiCutter.h \
    KiiClassification.h \
    KiiClassId.h \
    KiiClassKey.h \
    KiiClassName.h \
    KiiInfo.h \
    KeySegment.h \
    KeyBuilder.h \
    KiiRingPlugin.h \
    KiiRingInterface.h \
    KiiRingBuiltin.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
