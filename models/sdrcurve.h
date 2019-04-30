#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SDRCURVE_H
#define SDRCURVE_H

#include <QColor>

#include "sdrcnoderecord.h"
#include "sdrperiodrecord.h"
#include "dmeasurementrecord.h"

//#include "point.h"

class SDRCurveFormats
{
public:
    qreal _curveWidth{0.2f};
    QColor _curveColor{Qt::black};
    qreal _pointDiameter{0.4f};
    qreal _pointColor{Qt::black};
    qreal _stagePerUnit{0.01f};
    qreal _dischargePerUnit{10.f};

    qreal _unitLengthIndicatesStage{0.01f};
    qreal _unitLengthIndicatesDischarge{10.0f};

    bool _drawPoint{true};
    bool _drawCurve{true};
};

class SDRCurve
{
public:
    enum CurveType{SPI, QuadraticBezier};
    SDRCurve();
    ~SDRCurve();

    QVector<SDRCNodeRecord> _vNodes;
    QVector<SDRPeriodRecord> _vPeriods;
    QVector<DMeasurementRecord> _vDMRecords;

    QPointF getRealWorldCoord(const QPointF &point);
    QPointF getDrawPoint();

    QPointF _minPoint;
    QPointF _maxPoint;

    QSizeF _size;

    QVector<QPointF> _vRealWorldPoints;

    SDRCurveFormats _formats;

};

#endif // SDRCURVE_H
