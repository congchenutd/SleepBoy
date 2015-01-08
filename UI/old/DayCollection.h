#ifndef DAYS_H
#define DAYS_H

#include <QMap>
#include <QList>
#include <QDate>

class Day;

/**
 * A collection of Days
 * Provides lookup (via a map) and index based fetch (via a list)
 */
class DayCollection
{
public:
    typedef QMap<QDate, Day*> DayMap;
    typedef QList<Day*>       DayList;

public:
    void insert(Day* day);
    Day* get(int index)         const;
    Day* get(const QDate& date) const;
    int  size() const;
    void clear();

private:
    DayMap  _map;
    DayList _list;
};

#endif // DAYS_H
