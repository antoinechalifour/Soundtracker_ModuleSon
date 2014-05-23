#-------------------------------------------------
#
# Project created by QtCreator 2014-05-21T11:55:58
#
#-------------------------------------------------

QT       += core gui\
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ModuleSon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Tests.cpp \
    StValueException.cpp \
    StNullException.cpp \
    StException.cpp \
    StDivision.cpp \
    StMorceau.cpp \
    StPattern.cpp \
    StPosition.cpp \
    StSample.cpp \
    StPiste.cpp

HEADERS  += mainwindow.h \
    Tests.h \
    StValueException.h \
    StNullException.h \
    StException.h \
    StDebug.h \
    StDivision.h \
    StMorceau.h \
    StPattern.h \
    StPiste.h \
    StPosition.h \
    StSample.h
