#include "Sleep.h"
#include "Motion.h"
#include "TimeLine.h"
#include "Day.h"

#include <QPainter>
#include <QPalette>

Sleep::Sleep()
    : _timeLine(0),
      _type(NOON),
      _firstMotionIndex(-1),
      _lastMotionIndex(-1)
{
}

QDateTime Sleep::getEnterRoomDateTime() const {
    return _enterRoomDateTime;
}

QDateTime Sleep::getStartDateTime() const {
    return _startDateTime;
}

QDateTime Sleep::getEndDateTime() const {
    return _endDateTime;
}

QTime Sleep::getWakeTime() const
{
    return QTime();
}

QTime Sleep::getSleepLength() const
{
    return QTime();
}

double Sleep::getWakePercentage() const
{
    return 0;
}

int Sleep::getScore() const
{
    return 0;
}

int Sleep::getFirstMotionIndex() const {
    return _firstMotionIndex;
}

int Sleep::getLastMotionIndex() const {
    return _lastMotionIndex;
}

/**
 * Update _first and _lastMotionIndex
 * ASSUME: the motions are added in order
 */
void Sleep::addMotion(Motion* motion)
{
    if(_firstMotionIndex == -1)
        _firstMotionIndex = motion->getIndex();
    _lastMotionIndex = motion->getIndex();
}

void Sleep::setTimeLine(TimeLine* timeLine) {
    _timeLine = timeLine;
}

void Sleep::setType(Sleep::Type type) {
    _type = type;
}

void Sleep::setEnterRoomDateTime(const QDateTime& time) {
    _enterRoomDateTime = time;
}

void Sleep::setStartDateTime(const QDateTime& time) {
    _startDateTime = time;
}

void Sleep::setEndDateTime(const QDateTime& time) {
    _endDateTime = time;
}

QString Sleep::toString() const {
    return _type == NOON ? "Nap" : "Night sleep";
}

void Sleep::paint(QPainter* painter, const QRect& rect, const QPalette& palette) const
{
    int startIndex = getFirstMotionIndex();
    int endIndex   = getLastMotionIndex();
    if(startIndex < 0 || endIndex < 0)
        return;

    painter->save();
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->fillRect(rect, QBrush(Qt::green));

    painter->setBrush(QColor(Qt::blue));
    painter->setPen(Qt::blue);
    painter->translate(rect.x(), rect.y());
    int totalSeconds = (_type == NOON) ? Day::NightEndTime.secsTo(Day::NightStartTime)
                                       : Day::NightEndTime.secsTo(Day::NightStartTime);
    int totalWidth = rect.width();
    int x = 0;
    for(int i = startIndex; i <= endIndex; ++i)
    {
        Motion* motion = _timeLine->getMotion(i);
        int duration = motion->getSeconds();
        int width = (double) duration * totalWidth / totalSeconds;
        if(width < 1)
            width = 1;
        painter->drawRect(x, 0, width, rect.height());
        x += width;
    }

    painter->restore();
}
