#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef CURVESTRUCTS_H
#define CURVESTRUCTS_H

#include <QtCore>
#include <QColor>

struct RelationCurveNode
{
    QString x;
    QString y;

    friend void operator <<(QVariant &data, const RelationCurveNode &context);
    friend void operator >>(const QVariant &data, RelationCurveNode &context);
};
Q_DECLARE_METATYPE(RelationCurveNode)

void operator <<(QVariant &data, const RelationCurveNode &context);
void operator >>(const QVariant &data, RelationCurveNode &context);


struct RelationCurve
{
    QString stcd;
    QString type;
    QString method;
    int year;
    int curve_id;
    QColor color;
    QList<RelationCurveNode> nodes;

    friend void operator <<(QVariant &data, const RelationCurve &context);
    friend void operator >>(const QVariant &data, RelationCurve &context);
};
Q_DECLARE_METATYPE(RelationCurve)

void operator <<(QVariant &data, const RelationCurve &context);
void operator >>(const QVariant &data, RelationCurve &context);


struct DGMeasuredDischarge
{
    QString stcd;
    QString sn;
    QString stage;
    QString discharge;
    QDateTime averageDateTime;
    QDateTime startDateTime;
    QDateTime endDateTime;
};
Q_DECLARE_METATYPE(DGMeasuredDischarge)

void operator <<(QVariant &data, const DGMeasuredDischarge &context);
void operator >>(const QVariant &data, DGMeasuredDischarge &context);


struct DGMeasuredSedimentDischarge
{
    QString stcd;
    QString sn;
    QString discharge;
    QString sedimentDischarge;
    QString crossSectionalMeanSedimentConcentration;
    QString singleSampleSedimentConcentration;
    QDateTime averageDateTime;
    QDateTime startDateTime;
    QDateTime endDateTime;
};
Q_DECLARE_METATYPE(DGMeasuredSedimentDischarge)

void operator <<(QVariant &data, const DGMeasuredSedimentDischarge &context);
void operator >>(const QVariant &data, DGMeasuredSedimentDischarge &context);


struct AxisGroup
{
    QString type;
    QString unit;

    double valuePerUnit    {1};

    double minValue        {std::numeric_limits<double>::max()};
    double maxValue        {std::numeric_limits<double>::min()};

    double alignedMinValue {std::numeric_limits<double>::max()};
    double alignedMaxValue {std::numeric_limits<double>::min()};
};

Q_DECLARE_METATYPE(AxisGroup)

void operator <<(QVariant &data, const AxisGroup &context);
void operator >>(const QVariant &data, AxisGroup &context);


struct DGSYSDRCurves
{
    QString stcd;
    int year;
    QList<RelationCurve> curves;
};


struct DGSDRPeriod
{
//    QString end_time;
    QDateTime end_timestamp;
    int period_id;
    int curve_id;
    int method_id;
    RelationCurve *curve;
};

struct DGSYSDRPeriods
{
    QString stcd;
    int year;
    QList<DGSDRPeriod> periods;
};

#endif // CURVESTRUCTS_H
