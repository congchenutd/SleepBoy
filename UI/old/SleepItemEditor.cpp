#include "SleepItemEditor.h"

SleepItemEditor::SleepItemEditor(QWidget* parent) :
    QWidget(parent)
{
}

QTime SleepItemEditor::getStartTime() const {
    return _startTime;
}

QTime SleepItemEditor::getEndTime() const {
    return _endTime;
}

void SleepItemEditor::setStartTime(const QTime& time) {
    _startTime = time;
}

void SleepItemEditor::setEndTime(const QTime& time) {
    _endTime = time;
}
