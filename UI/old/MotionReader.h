#ifndef MOTIONREADER_H
#define MOTIONREADER_H

#include <QDateTime>
#include <QString>

class TimeLine;

class MotionReader
{
public:
    static void read(const QString& dbFileName, TimeLine* timeLine);

private:
    static bool openDB(const QString& name);
};

#endif // MOTIONREADER_H
