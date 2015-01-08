#include "MotionReader.h"
#include "TimeLine.h"
#include "Motion.h"
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

bool MotionReader::openDB(const QString& name)
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(name);
    return database.open();
}

void MotionReader::read(const QString& dbFileName, TimeLine* timeLine)
{
    if(!openDB(dbFileName))
        return;

    QSqlQuery query;
    query.exec(QObject::tr("SELECT timeStart, timeStop from objects "
                           "WHERE timeStart BETWEEN %1 and %2 "
                           "ORDER BY timeStart")
                           .arg(QDateTime(timeLine->getStartDate()).toMSecsSinceEpoch())
                           .arg(QDateTime(timeLine->getEndDate  ()).toMSecsSinceEpoch()));

    timeLine->clear();
    int index = 0;
    while(query.next())
    {
        Motion* motion = new Motion(query.value(0).toLongLong(),
                                    query.value(1).toLongLong());
        timeLine->addMotion(motion, &index);
    }
}
