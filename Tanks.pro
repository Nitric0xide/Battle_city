#-------------------------------------------------
#
# Project created by QtCreator 2017-07-16T15:14:31
#
#-------------------------------------------------

QT       += core gui \
          multimedia



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tanks
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    player.cpp \
    main.cpp \
    mainwindow.cpp \
    bricks.cpp \
    moveable.cpp \
    mapbuilder.cpp \
    bullet.cpp \
    steelblock.cpp \
    enemyh.cpp \
    explosion.cpp \
    enemym.cpp \
    enemyl.cpp \
    bush.cpp \
    eaglebase.cpp

HEADERS += \
    player.h \
    mainwindow.h \
    bricks.h \
    object.h \
    moveable.h \
    mapbuilder.h \
    bullet.h \
    steelblock.h \
    enemyh.h \
    explosion.h \
    stdafx.h \
    object.h \
    enemym.h \
    enemyl.h \
    bush.h \
    entity.h \
    eaglebase.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    maps.qrc \
    images.qrc

LIBS += -loleaut32
