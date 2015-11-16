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
    thread.cpp \
    PPU.cpp \
    Input.cpp \
    RAM.cpp \
    VRAM.cpp \
    Pines.cpp \
    Sprite.cpp \
    NES.cpp \
    Types.cpp

HEADERS  += mainwindow.h \
    thread.h \
    PPU.h \
    Input.h \
    RAM.h \
    VRAM.h \
    Pines.h \
    Sprite.h \
    NES.h \
    Types.h

FORMS    += mainwindow.ui

DISTFILES += \
    dk.nes
