#include "TimeLine.h"
#include "Day.h"
#include "Motion.h"

//TimeLine* TimeLine::_instance = 0;

//TimeLine* TimeLine::getInstance()
//{
//    if(_instance == 0)
//        _instance = new TimeLine();
//    return _instance;
//}

TimeLine::TimeLine() {}

void TimeLine::setStartDate(const QDate& start) {
    _startDate = start;
}

void TimeLine::setEndDate(const QDate& end) {
    _endDate = end;
}

QDate TimeLine::getStartDate() const {
    return _startDate;
}

QDate TimeLine::getEndDate() const {
    return _endDate;
}

Day* TimeLine::getDay(int index) const {
    return _days.get(index);
}

Motion* TimeLine::getMotion(int index) const {
    return _motions.at(index);
}

int TimeLine::getDayCount() const {
    return _days.size();
}

/**
 * ASSUME: the motions are added in order
 */
void TimeLine::addMotion(Motion* motion, int* index)
{
    // merge two motions if they are closer than 10 seconds
    if(_motions.length() > 0)
    {
        Motion* last = _motions.last();
        if(last->getEnd().secsTo(motion->getStart()) < 60)
        {
            last->setEnd(motion->getEnd());
            return;
        }
    }

    // add the motion
    _motions.append(motion);
    motion->setIndex(*index);
    (*index) ++;

    // update the days
    QDate date = motion->getDate();
    Day* day = _days.get(date);     // find an existing day
    if(day == 0)                    // or create a new day
    {
        day = new Day(date, this);
        _days.insert(day);
    }
    day->addMotion(motion);
}

void TimeLine::clear()
{
    _days.clear();
    _motions.clear();
}
