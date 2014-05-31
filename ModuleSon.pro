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
    StPiste.cpp \
    controleur.cpp \
    IHMMainWindow.cpp \
    IHMMenuPanel.cpp \
    IHMPatternEditorPanel.cpp \
    IHMPiste.cpp \
    IHMSampleEditor.cpp \
    IHMSongEditorPanel.cpp \
    IHMDivision.cpp \
    controlleursongeditor.cpp \
    controlleursampleeditor.cpp \
    controlleurpatterneditor.cpp \
    controlleurdivision.cpp

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
    StSample.h \
    controleur.h \
    IHMMainWindow.h \
    IHMMenuPanel.h \
    IHMPatternEditorPanel.h \
    IHMSampleEditor.h \
    IHMPiste.h \
    IHMSongEditorPanel.h \
    IHMDivision.h \
    controlleursongeditor.h \
    controlleursampleeditor.h \
    controlleurpatterneditor.h \
    controlleurdivision.h

FORMS += \
    mainwindow.ui
