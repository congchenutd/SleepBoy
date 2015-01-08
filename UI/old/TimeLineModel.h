#ifndef TIMELINEMODEL_H
#define TIMELINEMODEL_H

#include <QStandardItemModel>

class TimeLine;

class TimeLineModel : public QStandardItemModel
{
    Q_OBJECT

public:
    TimeLineModel(QObject* parent = 0);
    QVariant data(const QModelIndex& idx, int role) const;

    int rowCount   (const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;

public:
    enum {COL_DAY, COL_NAP, COL_NAP_SCORE, COL_SLEEP, COL_SLEEP_SCORE, COL_COUNT};

private:
    TimeLine* _timeLine;
};

#endif // TIMELINEMODEL_H
