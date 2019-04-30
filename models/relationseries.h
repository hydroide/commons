#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef RELATIONSERIES_H
#define RELATIONSERIES_H

#include <QtCore>

class RelationSeries
{
public:
    RelationSeries();

private:
    QList<QString> stationYear_curve_ids;

};

#endif // RELATIONSERIES_H
