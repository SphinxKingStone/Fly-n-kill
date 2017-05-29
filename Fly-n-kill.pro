#-------------------------------------------------
#
# Project created by QtCreator 2017-05-26T15:01:08
#
#-------------------------------------------------

QT       += core gui \
         multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fly-n-kill
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


SOURCES += main.cpp \
    game.cpp \
    enemy.cpp \
    bullet.cpp \
    player.cpp \
    score.cpp \
    health.cpp \
    healthpack.cpp \
    healthpack_blue.cpp \
    healthpack_yellow.cpp

HEADERS  += \
    game.h \
    enemy.h \
    bullet.h \
    player.h \
    score.h \
    health.h \
    healthpack.h \
    healthpack_blue.h \
    healthpack_yellow.h

FORMS    +=

RESOURCES += \
    res.qrc
