#-------------------------------------------------
#
# Project created by QtCreator 2012-12-10T14:43:23
#
#-------------------------------------------------

QT       += core gui debug

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HOLIDE
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    page.cpp \
    highlighter.cpp \
    holwidget.cpp \
    holmakewidget.cpp \
    project.cpp \
    projectview.cpp \
    link.cpp \
    phase.cpp \
    stateview.cpp \
    transistiondiagramwidget.cpp \
    transistionstate.cpp

HEADERS  += mainwindow.h \
    page.h \
    highlighter.h \
    holwidget.h \
    holmakewidget.h \
    project.h \
    projectview.h \
    link.h \
    phase.h \
    stateview.h \
    transistiondiagramwidget.h \
    transistionstate.h

FORMS    += mainwindow.ui \
    projectview.ui \
    stateview.ui

RESOURCES += \
    resources.qrc
