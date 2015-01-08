#include "SleepItemDelegate.h"
#include "Sleep.h"
#include "TimeLine.h"

#include <QPainter>

SleepItemDelegate::SleepItemDelegate(QObject* parent)
    : QStyledItemDelegate(parent)
{
}

void SleepItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option,
                             const QModelIndex& index) const
{
    if(index.data().canConvert<Sleep>())
    {
        Sleep sleep = qvariant_cast<Sleep>(index.data());

        if(option.state & QStyle::State_Selected)
            painter->fillRect(option.rect, option.palette.highlight());

        // visualize the sleep
        sleep.paint(painter, option.rect, option.palette);
    }
    else
        QStyledItemDelegate::paint(painter, option, index);
}

QSize SleepItemDelegate::sizeHint(const QStyleOptionViewItem& option,
                                  const QModelIndex& index) const
{
//    if (index.data().canConvert<Sleep>())
//    {
//        QRect r = option.rect;
//    }
    return QStyledItemDelegate::sizeHint(option, index);
}


