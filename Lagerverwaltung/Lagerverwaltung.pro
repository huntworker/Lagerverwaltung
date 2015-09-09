#-------------------------------------------------
#
# Project created by QtCreator 2015-08-31T12:27:06
#
#-------------------------------------------------

QT       += core gui serialport widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lagerverwaltung
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settingsdialog.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    settingsdialog.h \
    database.h

FORMS    += mainwindow.ui \
    settingsdialog.ui
