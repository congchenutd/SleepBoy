#ifndef TIMELINE_H
#define TIMELINE_H

#include "DayCollection.h"
#include <QMap>
#include <QDate>

class Day;
class Motion;

/**
 * A timeline contains a list of motions and a list of days
 * The days and motions can be retrieved using 0-based index
 * When a new motion is added, a new day may be added, too,
 * and _startDate and _endDate may be updated
 */
class TimeLine
{
public:
    typedef QList<Motion*> Motions;

public:
    TimeLine();
    void setStartDate(const QDate& start);
    void setEndDate  (const QDate& end);

    QDate   getStartDate()          const;
    QDate   getEndDate  ()          const;
    Day*    getDay   (int index)    const;
    Motion* getMotion(int index)    const;
    int     getDayCount()           const;

    void addMotion(Motion* motion, int* index);
    void clear();

//public:
//    TimeLine* getInstance();
//private:
//    static TimeLine* _instance;

private:
    DayCollection   _days;
    Motions         _motions;
    QDate           _startDate;
    QDate           _endDate;
};

#endif // TIMELINE_H
