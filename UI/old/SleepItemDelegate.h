#ifndef TIMELINEDELEGATE_H
#define TIMELINEDELEGATE_H

#include <QStyledItemDelegate>

class SleepItemDelegate : public QStyledItemDelegate
{
public:
    SleepItemDelegate(QObject* parent);

protected:
    void paint(QPainter* painter, const QStyleOptionViewItem& option,
               const QModelIndex& index) const;
    QSize sizeHint(const QStyleOptionViewItem& option,
                   const QModelIndex& index) const;
};

#endif // TIMELINEDELEGATE_H
