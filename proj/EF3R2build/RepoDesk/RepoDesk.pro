#-------------------------------------------------
#
# Project created by QtCreator 2016-06-10T00:55:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS *= -std=c++11

TARGET = RepoDesk
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
        MiscActions.cpp \
        MenuBar.cpp \
    RepositoryMenu.cpp \
    CentralWidget.cpp \
    DashboardTabPage.cpp \
    StatusBar.cpp \
    StatusPage.cpp \
    Dashboard/DashboardFilesWidget.cpp \
    ViewMenu.cpp \
    Dashboard/Settings.cpp \
    Dashboard/DirWidget.cpp

HEADERS  += MainWindow.h \
        MiscActions.h \
        MenuBar.h \
    RepositoryMenu.h \
    CentralWidget.h \
    DashboardTabPage.h \
    StatusBar.h \
    StatusPage.h \
    Dashboard/DashboardFilesWidget.h \
    ViewMenu.h \
    Dashboard/Settings.h \
    Dashboard/DirWidget.h
