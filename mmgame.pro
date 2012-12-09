#-------------------------------------------------
#
# Project created by QtCreator 2012-12-09T12:09:11
#
#-------------------------------------------------

QT       += core gui opengl

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
    playerinput.cpp

HEADERS  += gamewindow.h \
    manymouse.h \
    assignmentgadget.h \
    gameglwidget.h \
    gamestate.h \
    resourcepoint.h \
    playerinput.h

FORMS    += gamewindow.ui \
    assignmentgadget.ui

RESOURCES += \
    guires.qrc

OTHER_FILES += \
    ressrc/window_border.xcf
