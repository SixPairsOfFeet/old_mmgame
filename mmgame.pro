#-------------------------------------------------
#
# Project created by QtCreator 2012-12-09T12:09:11
#
#-------------------------------------------------

QT       += core gui opengl

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mmgame
TEMPLATE = app

SOURCES += main.cpp\
        gamewindow.cpp \
    x11_xinput2.c \
    windows_wminput.c \
    manymouse.c \
    macosx_hidutilities.c \
    macosx_hidmanager.c \
    linux_evdev.c \
    assignmentgadget.cpp \
    gameglwidget.cpp \
    gamestate.cpp \
    resourcepoint.cpp \
    playerinput.cpp \
    entity.cpp \
    voronoi.cpp \
    voronoi_map.cpp \
    playerentity.cpp \
    extractor.cpp \
    spriteentity.cpp

HEADERS  += gamewindow.h \
    manymouse.h \
    assignmentgadget.h \
    gameglwidget.h \
    gamestate.h \
    resourcepoint.h \
    playerinput.h \
    entity.h \
    voronoi-c.hpp \
    voronoi.hpp \
    voronoi_map.hpp \
    playerentity.h \
    extractor.h \
    spriteentity.h

FORMS    += gamewindow.ui \
    assignmentgadget.ui

RESOURCES += \
    guires.qrc

OTHER_FILES += \
    ressrc/window_border.xcf
