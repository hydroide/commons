#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef MEASUREDSEDIMENTDISCHARGERECORD_H
#define MEASUREDSEDIMENTDISCHARGERECORD_H

#include "record.h"

struct MeasuredSedimentDischargeRecord : public Record
{
    QString stcd;
    QString sn;
    QString zqmmsn;
    QString discharge;
    QString sedimentDischarge;
    QString crossSectionalMeanSedimentConcentration;
    QString singleSampleSedimentConcentration;
    QString singleSampleMethod;
    QString annotation;
    QString equipmentType;
    QString points;
    QString method;
    QDateTime averageDateTime;
    QDateTime startDateTime;
    QDateTime endDateTime;
};

//Q_DECLARE_METATYPE(MeasuredSedimentDischargeRecord)

//void operator <<(QVariant &data, const MeasuredDischargeRecord &context)
//{
//    QVariantMap map;
//    map["stcd"] << context.stcd;
//    map["sn"] << context.sn;
//    map["zqmmsn"] << context.zqmmsn;
//    map["discharge"] << context.discharge;
//    map["sedimentDischarge"] << context.sedimentDischarge;
//    map["crossSectionalMeanSedimentConcentration"] << context.crossSectionalMeanSedimentConcentration;
//    map["singleSampleSedimentConcentration"] << context.singleSampleSedimentConcentration;
//    map["singleSampleMethod"] << context.singleSampleMethod;
//    map["annotation"] << context.annotation;
//    map["equipmentType"] << context.equipmentType;
//    map["points"] << context.points;
//    map["method"] << context.method;
//    map["averageDateTime"] << context.averageDateTime;
//    map["startDateTime"] << context.startDateTime;
//    map["endDateTime"] << context.endDateTime;
//    data = map;
//}

//void operator >>(const QVariant &data, MeasuredDischargeRecord &context)
//{
//    auto map = QJsonDocument::fromVariant(data).object().toVariantMap();
//    map["stcd"] >> context.stcd;
//    map["sn"] >> context.sn;
//    map["zqmmsn"] >> context.zqmmsn;
//    map["discharge"] >> context.discharge;
//    map["sedimentDischarge"] >> context.sedimentDischarge;
//    map["crossSectionalMeanSedimentConcentration"] >> context.crossSectionalMeanSedimentConcentration;
//    map["singleSampleSedimentConcentration"] >> context.singleSampleSedimentConcentration;
//    map["singleSampleMethod"] >> context.singleSampleMethod;
//    map["annotation"] >> context.annotation;
//    map["equipmentType"] >> context.equipmentType;
//    map["points"] >> context.points;
//    map["method"] >> context.method;
//    map["averageDateTime"] >> context.averageDateTime;
//    map["startDateTime"] >> context.startDateTime;
//    map["endDateTime"] >> context.endDateTime;
//}

#endif // MEASUREDSEDIMENTDISCHARGERECORD_H
