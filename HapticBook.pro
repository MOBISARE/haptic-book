#-------------------------------------------------
#
# Project created by QtCreator 2023-12-13T18:33:40
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HapticBook
TEMPLATE = app
CONFIG += resources_big
INCLUDEPATH += "C:\Program Files\Immersion Corporation\IFC23\inc"
LIBS += "C:\Program Files\Immersion Corporation\IFC23\lib\IFC23.lib"

SOURCES += main.cpp\
        mainwindow.cpp \
        asset.cpp \
        book.cpp \
        displaymanager.cpp \
        page.cpp \
        player.cpp \
        soundmanager.cpp \
        hapticmanager.cpp

HEADERS  += mainwindow.h \
    asset.h \
    book.h \
    displaymanager.h \
    page.h \
    player.h \
    soundmanager.h \
    hapticmanager.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
