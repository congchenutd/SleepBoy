#include <QDateTime>
#include <QMetaType>

#ifndef SLEEP_H
#define SLEEP_H

class TimeLine;
class Motion;
class QPainter;

/**
 * A sleep represents the duration of a sleep
 * The user needs to manually specify _enterRoomDateTime, _startDateTime, and _endDateTime
 */
class Sleep
{
public:
    typedef enum {NOON, NIGHT} Type;

public:
    Sleep();

    QDateTime getEnterRoomDateTime()    const;
    QDateTime getStartDateTime()        const;
    QDateTime getEndDateTime()          const;
    QTime     getTimeToSleep()          const;
    QTime     getWakeTime()             const;
    QTime     getSleepLength()          const;
    double    getWakePercentage()       const;
    int       getScore()                const;
    int       getFirstMotionIndex()     const;
    int       getLastMotionIndex()      const;

    void addMotion(Motion* motion);
    void setTimeLine(TimeLine* timeLine);
    void setType(Type type);
    void setEnterRoomDateTime(const QDateTime& time);
    void setStartDateTime    (const QDateTime& time);
    void setEndDateTime      (const QDateTime& time);

    QString toString() const;
    void paint(QPainter* painter, const QRect& rect, const QPalette& palette) const;

protected:
    TimeLine* _timeLine;
    Type      _type;
    int       _firstMotionIndex;
    int       _lastMotionIndex;
    QDateTime _enterRoomDateTime;
    QDateTime _startDateTime;
    QDateTime _endDateTime;

};

Q_DECLARE_METATYPE(Sleep)

#endif // SLEEP_H
