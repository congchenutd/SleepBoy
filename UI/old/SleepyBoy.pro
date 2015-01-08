QT       += core gui testlib sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SleepyBoy
TEMPLATE = app

FORMS += \
    MainWindow.ui

HEADERS += \
    Day.h \
    MainWindow.h \
    Motion.h \
    MotionReader.h \
    Sleep.h \
    TimeLine.h \
    TimeLineModel.h \
    DayCollection.h \
    SleepItemEditorFactory.h \
    SleepItemEditor.h \
    SleepItemDelegate.h

SOURCES += \
    Day.cpp \
    Main.cpp \
    MainWindow.cpp \
    Motion.cpp \
    MotionReader.cpp \
    Sleep.cpp \
    TimeLine.cpp \
    TimeLineModel.cpp \
    DayCollection.cpp \
    SleepItemEditorFactory.cpp \
    SleepItemEditor.cpp \
    SleepItemDelegate.cpp



