#include "MainWindow.h"
#include "MotionReader.h"
#include "Day.h"
#include "SleepItemEditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Day::setNoonStartTime (QTime::fromString("12:30", "hh:mm"));
    Day::setNoonEndTime   (QTime::fromString("16:30", "hh:mm"));
    Day::setNightStartTime(QTime::fromString("19:30", "hh:mm"));
    Day::setNightEndTime  (QTime::fromString("09:00", "hh:mm"));

    QApplication app(argc, argv);
    MainWindow windows;
    windows.showMaximized();
//    SleepItemEditor editor;
//    editor.show();
    return app.exec();
}
