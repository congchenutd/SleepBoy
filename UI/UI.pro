QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
TEMPLATE = app

INCLUDEPATH += C:\\PortableProgram\\Develop\\opencv\\build\\include
LIBS += -LC:\\PortableProgram\\Develop\\opencv\\build\\x86\\vc12\\lib \
	-lopencv_ts300d \
	-lopencv_world300d

win32 {
	RC_FILE = Resources.rc
}

SOURCES +=\
        MainWindow.cpp \
    SettingsPage.cpp \
    Main.cpp \
    FrameHandler.cpp \
    MotionDetecter.cpp \
    PipeLine.cpp \
    VideoSaver.cpp \
    VideoViewer.cpp \
    MySettings.cpp \
    CameraPage.cpp

HEADERS  += MainWindow.h \
    SettingsPage.h \
    FrameHandler.h \
    MotionDetecter.h \
    PipeLine.h \
    VideoSaver.h \
    VideoViewer.h \
    MySettings.h \
    CameraPage.h

FORMS    += MainWindow.ui \
    SettingsPage.ui \
    CameraPage.ui

RESOURCES += \
    Resources.qrc

QMAKE_LFLAGS += /ignore:4819
