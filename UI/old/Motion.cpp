#include "Motion.h"
#include "Day.h"
#include <QObject>

Motion::Motion(qint64 start, qint64 end)
    : _start(QDateTime::fromMSecsSinceEpoch(start)),
      _end  (QDateTime::fromMSecsSinceEpoch(end)),
      _index(-1)
{
}

QDateTime Motion::getStart() const {
    return _start;
}

QDateTime Motion::getEnd() const {
    return _end;
}

QDate Motion::getDate() const
{
    QDate date = getStart().date();
    QTime time = getStart().time();
    if(QTime(0, 0, 0) <= time && time <= Day::NightEndTime)
        date = date.addDays(-1);
    return date;
}

int Motion::getIndex() const {
    return _index;
}

int Motion::getSeconds() const {
    return getEnd().secsTo(getStart());
}

void Motion::setIndex(int index) {
    _index = index;
}

void Motion::setStart(const QDateTime& start) {
    _start = start;
}

void Motion::setEnd(const QDateTime& end) {
    _end = end;
}

QString Motion::toString() const {
    return QObject::tr("Motion [%1 - %2]")
            .arg(getStart().toString())
            .arg(getStart().toString());
}
