#include <QDateTime>

#ifndef MOTION_H
#define MOTION_H

class Motion
{
public:
    Motion(qint64 start, qint64 end);
    QDateTime getStart()    const;
    QDateTime getEnd  ()    const;
    QDate     getDate()     const;
    int       getIndex()    const;
    int       getSeconds()  const;

    void setIndex(int index);
    void setStart(const QDateTime& start);
    void setEnd  (const QDateTime& end);

    QString toString() const;

private:
    QDateTime _start;
    QDateTime _end;
    int    _index;
};

#endif // MOTION_H
