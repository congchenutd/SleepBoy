#include "DayCollection.h"
#include "Day.h"

void DayCollection::insert(Day* day)
{
    _list.append(day);
    _map.insert(day->getDate(), day);
}

Day* DayCollection::get(int index) const
{
    if(size() == 0 || index < 0 || index >= size())
        return 0;
    return _list.at(index);
}

Day* DayCollection::get(const QDate& date) const
{
    DayMap::const_iterator it = _map.find(date);
    return it == _map.end() ? 0 : it.value();
}

int DayCollection::size() const {
    return _list.size();
}

void DayCollection::clear()
{
    _list.clear();
    _map.clear();
}


