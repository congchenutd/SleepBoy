#ifndef SLEEPITEMEDITOR_H
#define SLEEPITEMEDITOR_H

#include <QWidget>
#include <QTime>

class SleepItemEditor : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QTime startTime READ getStartTime WRITE setStartTime USER true)
    Q_PROPERTY(QTime endTime   READ getEndTime   WRITE setEndTime   USER true)

public:
    explicit SleepItemEditor(QWidget* parent = 0);

public:
    QTime getStartTime() const;
    QTime getEndTime()   const;
    void  setStartTime(const QTime& time);
    void  setEndTime  (const QTime& time);

private:
    QTime _startTime;
    QTime _endTime;
};

#endif // SLEEPITEMEDITOR_H
