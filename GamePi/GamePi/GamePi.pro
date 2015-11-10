#-------------------------------------------------
#
# Project created by QtCreator 2015-11-09T20:09:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GamePi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    thread.cpp

HEADERS  += mainwindow.h \
    thread.h

FORMS    += mainwindow.ui
