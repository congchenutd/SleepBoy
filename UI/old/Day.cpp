#include "Day.h"
#include "Sleep.h"
#include "Motion.h"
#include "TimeLine.h"

Day::Day(const QDate& date, TimeLine* timeLine)
    : _date(date), _timeLine(timeLine)
{
    _noon = new Sleep();
    _noon->setType(Sleep::NOON);
    _noon->setTimeLine(timeLine);
    _night = new Sleep();
    _night->setType(Sleep::NIGHT);
    _night->setTimeLine(timeLine);
}

Sleep* Day::getNoonSleep() const {
    return _noon;
}

Sleep* Day::getNightSleep() const {
    return _night;
}

int Day::getScore() const {
    return _noon->getScore() + _night->getScore();
}

QDate Day::getDate() const {
    return _date;
}

/**
 * Add the motion to one of the Sleeps
 * ASSUME: the motions are added in order
 */
void Day::addMotion(Motion* motion)
{
    QTime time = motion->getStart().time();
    if(NoonStartTime <= time && time <= NoonEndTime)
        _noon->addMotion(motion);
    else
        _night->addMotion(motion);
}

QTime Day::NoonStartTime;
QTime Day::NoonEndTime;
QTime Day::NightStartTime;
QTime Day::NightEndTime;

void Day::setNoonStartTime(const QTime& time) {
    NoonStartTime = time;
}

void Day::setNoonEndTime(const QTime& time) {
    NoonEndTime = time;
}

void Day::setNightStartTime(const QTime& time) {
    NightStartTime = time;
}

void Day::setNightEndTime(const QTime& time) {
    NightEndTime = time;
}
