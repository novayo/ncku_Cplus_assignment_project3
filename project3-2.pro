#-------------------------------------------------
#
# Project created by QtCreator 2018-06-03T19:30:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project3-2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    score.cpp \
    human.cpp \
    human_enemy.cpp \
    bullet_enemy.cpp \
    bullet_player.cpp \
    human_player.cpp \
    dialoggameover.cpp \
    trump.cpp \
    dialogabout.cpp \
    bullet.cpp \
    mushroom.cpp \
    addplayerhealth.cpp

HEADERS += \
        mainwindow.h \
    score.h \
    human.h \
    human_enemy.h \
    bullet_enemy.h \
    bullet_player.h \
    human_player.h \
    dialoggameover.h \
    trump.h \
    dialogabout.h \
    bullet.h \
    mushroom.h \
    addplayerhealth.h

FORMS += \
        mainwindow.ui \
    dialoggameover.ui \
    dialogabout.ui

RESOURCES += \
    resources.qrc
