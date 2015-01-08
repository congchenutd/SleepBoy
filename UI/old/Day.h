#include <QDate>

#ifndef DAY_H
#define DAY_H

class Sleep;
class Motion;
class TimeLine;

/**
 * A day contains a noon sleep and a night sleep
 */
class Day
{
public:
    Day(const QDate& date, TimeLine* timeLine);

    Sleep* getNoonSleep()   const;
    Sleep* getNightSleep()  const;
    int    getScore()       const;
    QDate  getDate()        const;

    void addMotion(Motion* motion);

    static void setNoonStartTime (const QTime& time);
    static void setNoonEndTime   (const QTime& time);
    static void setNightStartTime(const QTime& time);
    static void setNightEndTime  (const QTime& time);

public:
    static QTime NoonStartTime;
    static QTime NoonEndTime;
    static QTime NightStartTime;
    static QTime NightEndTime;

private:
    QDate       _date;
    Sleep*      _noon;
    Sleep*      _night;
    TimeLine*   _timeLine;
};

#endif // DAY_H
