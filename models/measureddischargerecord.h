#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef MEASUREDDISCHARGERECORD_H
#define MEASUREDDISCHARGERECORD_H

#include "record.h"

struct MeasuredDischargeRecord : public Record
{
    QString stcd;
    QString sn;
    QString location;
    QString stage;
    QString discharge;
    QString area;
    QString meanVelocity;
    QString max_v;
    QString surfaceWidth;
    QString meanDepth;
    QString max_depth;
    QString surface_slope;
    QString mannings_n;
    QString method;
    QString points;
    QDateTime startDateTime;
    QDateTime endDateTime;
    QDateTime averageDateTime;
};

//Q_DECLARE_METATYPE(MeasuredDischargeRecord)

//void operator <<(QVariant &data, const MeasuredDischargeRecord &context)
//{
//    QVariantMap map;
//    map["stcd"] << context.stcd;
//    map["sn"] << context.sn;
//    map["location"] << context.location;
//    map["stage"] << context.stage;
//    map["discharge"] << context.discharge;
//    map["area"] << context.area;
//    map["meanVelocity"] << context.meanVelocity;
//    map["max_v"] << context.max_v;
//    map["surfaceWidth"] << context.surfaceWidth;
//    map["meanDepth"] << context.meanDepth;
//    map["max_depth"] << context.max_depth;
//    map["surface_slope"] << context.surface_slope;
//    map["mannings_n"] << context.mannings_n;
//    map["method"] << context.method;
//    map["points"] << context.points;
//    map["startDateTime"] << context.startDateTime;
//    map["endDateTime"] << context.endDateTime;
//    map["averageDateTime"] << context.averageDateTime;
//    data = map;
//}

//void operator >>(const QVariant &data, MeasuredDischargeRecord &context)
//{
//    auto map = QJsonDocument::fromVariant(data).object().toVariantMap();
//    map["stcd"] >> context.stcd;
//    map["sn"] >> context.sn;
//    map["location"] >> context.location;
//    map["stage"] >> context.stage;
//    map["discharge"] >> context.discharge;
//    map["area"] >> context.area;
//    map["meanVelocity"] >> context.meanVelocity;
//    map["max_v"] >> context.max_v;
//    map["surfaceWidth"] >> context.surfaceWidth;
//    map["meanDepth"] >> context.meanDepth;
//    map["max_depth"] >> context.max_depth;
//    map["surface_slope"] >> context.surface_slope;
//    map["mannings_n"] >> context.mannings_n;
//    map["method"] >> context.method;
//    map["points"] >> context.points;
//    map["startDateTime"] >> context.startDateTime;
//    map["endDateTime"] >> context.endDateTime;
//    map["averageDateTime"] >> context.averageDateTime;
//}

#endif // MEASUREDDISCHARGERECORD_H
