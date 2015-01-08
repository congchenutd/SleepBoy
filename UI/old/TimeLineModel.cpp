#include "MotionReader.h"
#include "TimeLine.h"
#include "TimeLineModel.h"
#include "Day.h"
#include "Sleep.h"

TimeLineModel::TimeLineModel(QObject* parent)
    : QStandardItemModel(parent)
{
    setColumnCount(COL_COUNT);
    setHeaderData(COL_DAY,          Qt::Horizontal, tr("Day"));
    setHeaderData(COL_NAP,          Qt::Horizontal, tr("Nap"));
    setHeaderData(COL_NAP_SCORE,    Qt::Horizontal, tr("Nap score"));
    setHeaderData(COL_SLEEP,        Qt::Horizontal, tr("Sleep"));
    setHeaderData(COL_SLEEP_SCORE,  Qt::Horizontal, tr("Sleep score"));

    _timeLine = new TimeLine();
    _timeLine->setStartDate(QDate::fromString("12/01/2014", "MM/dd/yyyy"));
    _timeLine->setEndDate  (QDate::fromString("12/08/2014", "MM/dd/yyyy"));
    MotionReader::read("objdb2", _timeLine);

    setRowCount(_timeLine->getDayCount());
}

QVariant TimeLineModel::data(const QModelIndex& idx, int role) const
{
    if(!idx.isValid())
        return QStandardItemModel::data(idx, role);

    if(role == Qt::DisplayRole)
    {
        int row = idx.row();
        int col = idx.column();
        Day* day = _timeLine->getDay(row);
        if(col == COL_DAY)
            return day->getDate().toString("MM/dd/yyyy");
        else if(col == COL_NAP_SCORE)
            return day->getNoonSleep()->getScore();
        else if(col == COL_SLEEP_SCORE)
            return day->getNightSleep()->getScore();
        else if(col == COL_NAP)
            return QVariant::fromValue(*(day->getNoonSleep()));
        else if(col == COL_SLEEP)
            return QVariant::fromValue(*(day->getNightSleep()));
    }

    return QStandardItemModel::data(idx, role);
}

int TimeLineModel::rowCount(const QModelIndex&) const {
    return _timeLine->getDayCount();
}

int TimeLineModel::columnCount(const QModelIndex&) const {
    return COL_COUNT;
}


