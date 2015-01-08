#-------------------------------------------------
#
# Project created by QtCreator 2015-01-08T11:39:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
TEMPLATE = app

win32 {
	RC_FILE = Resources.rc
}

SOURCES += main.cpp\
        MainWindow.cpp \
    SettingsPage.cpp

HEADERS  += MainWindow.h \
    SettingsPage.h

FORMS    += MainWindow.ui \
    SettingsPage.ui

RESOURCES += \
    Resources.qrc
