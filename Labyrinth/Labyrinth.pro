#-------------------------------------------------
#
# Project created by QtCreator 2016-04-09T18:23:39
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Labyrinth
TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    maze.cpp \
    key.cpp \
    door.cpp \
    line.cpp

HEADERS  += \
    player.h \
    maze.h \
    key.h \
    door.h \
    line.h \
    game.h

FORMS    +=

RESOURCES += \
    res.qrc
