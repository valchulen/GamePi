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
    thread.cpp \
    PPU.cpp \
    Input.cpp \
    RAM.cpp \
    VRAM.cpp \
    Pines.cpp \
    Sprite.cpp \
    NES.cpp \
    Types.cpp \
    MenuPrincipal.cpp \
    MenuBiblioteca.cpp \
    MenuOpciones.cpp \
    MenuInformacion.cpp

HEADERS  += \
    thread.h \
    PPU.h \
    Input.h \
    RAM.h \
    VRAM.h \
    Pines.h \
    Sprite.h \
    NES.h \
    Types.h \
    MenuInformacion.h \
    MenuBiblioteca.h \
    MenuOpciones.h \
    MenuPrincipal.h

FORMS    += \
    MenuPrincipal.ui \
    MenuBiblioteca.ui \
    MenuOpciones.ui \
    MenuInformacion.ui

DISTFILES += \
    dk.nes

RESOURCES += \
    resource.qrc \
    resourceopciones.qrc \
    resourceinformacion.qrc
