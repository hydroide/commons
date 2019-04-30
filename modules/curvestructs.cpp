#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "curvestructs.h"
#include "qvariantserializationdefs.h"

void operator <<(QVariant &data, const RelationCurveNode &context)
{
    QVariantMap map;
     map["x"] << context.x;
     map["y"] << context.y;
    data =  map;
}

void operator >>(const QVariant &data, RelationCurveNode &context)
{
    auto map = QJsonDocument::fromVariant(data).object().toVariantMap();
    map["x"] >> context.x;
    map["y"] >> context.y;
}


void operator <<(QVariant &data, const RelationCurve &context)
{
    QVariantMap map;
    map["stcd"] << context.stcd;
    map["year"] << context.year;
    map["curve_id"] << context.curve_id;
    map["color"] << context.color;
    QVariantList list;
    for (auto node: context.nodes)
    {
        QVariant data;
        data << node;
        list.append(data);
    }
    map["nodes"] << list;
    data = map;
}

void operator >>(const QVariant &data, RelationCurve &context)
{
    context.nodes.clear();

    auto map = QJsonDocument::fromVariant(data).object().toVariantMap();
    map["stcd"] >> context.stcd;
    map["year"] >> context.year;
    map["curve_id"] >> context.curve_id;
    map["color"] >> context.color;
    auto list = map["nodes"].toList();
    for (auto variant: list)
    {
        RelationCurveNode node;
        variant >> node;
        context.nodes.append(node);
    }
}

void operator <<(QVariant &data, const DGMeasuredDischarge &context)
{
    QVariantMap map;
    map["stcd"] << context.stcd;
    map["sn"] << context.sn;
    map["stage"] << context.stage;
    map["discharge"] << context.discharge;
    map["averageDateTime"] << context.averageDateTime;
    map["startDateTime"] << context.startDateTime;
    map["endDateTime"] << context.endDateTime;
    data = map;
}

void operator >>(const QVariant &data, DGMeasuredDischarge &context)
{
    auto map = QJsonDocument::fromVariant(data).object().toVariantMap();
    map["stcd"] >> context.stcd;
    map["sn"] >> context.sn;
    map["stage"] >> context.stage;
    map["discharge"] >> context.discharge;
    map["averageDateTime"] >> context.averageDateTime;
    map["startDateTime"] >> context.startDateTime;
    map["endDateTime"] >> context.endDateTime;
}

void operator <<(QVariant &data, const AxisGroup &context)
{
    QVariantMap map;
    map["type"] << context.type;
    map["unit"] << context.unit;
    map["valuePerUnit"] << context.valuePerUnit;
    map["minValue"] << context.minValue;
    map["maxValue"] << context.maxValue;
    map["alignedMinValue"] << context.alignedMinValue;
    map["alignedMaxValue"] << context.alignedMaxValue;
    data = map;
}

void operator >>(const QVariant &data, AxisGroup &context)
{
    auto map = QJsonDocument::fromVariant(data).object().toVariantMap();
    map["type"] >> context.type;
    map["unit"] >> context.unit;
    map["valuePerUnit"] >> context.valuePerUnit;
    map["minValue"] >> context.minValue;
    map["maxValue"] >> context.maxValue;
    map["alignedMinValue"] >> context.alignedMinValue;
    map["alignedMaxValue"] >> context.alignedMaxValue;
}

void operator <<(QVariant &data, const DGMeasuredSedimentDischarge &context)
{
    QVariantMap map;
    map["stcd"] << context.stcd;
    map["sn"] << context.sn;
    map["discharge"] << context.discharge;
    map["sedimentDischarge"] << context.sedimentDischarge;
    map["crossSectionalMeanSedimentConcentration"] << context.crossSectionalMeanSedimentConcentration;
    map["singleSampleSedimentConcentration"] << context.singleSampleSedimentConcentration;
    map["averageDateTime"] << context.averageDateTime;
    map["startDateTime"] << context.startDateTime;
    map["endDateTime"] << context.endDateTime;
    data = map;
}

void operator >>(const QVariant &data, DGMeasuredSedimentDischarge &context)
{
    auto map = QJsonDocument::fromVariant(data).object().toVariantMap();
    map["stcd"] >> context.stcd;
    map["sn"] >> context.sn;
    map["discharge"] >> context.discharge;
    map["sedimentDischarge"] >> context.sedimentDischarge;
    map["crossSectionalMeanSedimentConcentration"] >> context.crossSectionalMeanSedimentConcentration;
    map["singleSampleSedimentConcentration"] >> context.singleSampleSedimentConcentration;
    map["averageDateTime"] >> context.averageDateTime;
    map["startDateTime"] >> context.startDateTime;
    map["endDateTime"] >> context.endDateTime;
}
