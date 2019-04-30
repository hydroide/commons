#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "dischargecurve.h"



DischargeCurve::DischargeCurve()
{
    _pFormats = new DischargeCurveFormats;
}

DischargeCurve::~DischargeCurve()
{

}

void
DischargeCurve::generateRealWorldPoints()
{

}

QSizeF
DischargeCurve::size()
const
{
    qreal width = (_maxHour - _minHour)/pFormats()->hourPerUnit();
    qreal height = (_maxValue - _minValue)/pFormats()->dischargePerUnit();
    return QSizeF(width, height);
}

QVector<DischargeCurveNode>
DischargeCurve::vReckonedDischargeNodes()
const
{
    return _vReckonedDischargeNodes;
}

void
DischargeCurve::setVReckonedDischargeNodes(
        const QVector<DischargeCurveNode> &reckonedDischargeNodes)
{
    _vReckonedDischargeNodes = reckonedDischargeNodes;
}

QVector<DischargeCurveNode>
DischargeCurve::vMeasuredDischargeNodes()
const
{
    return _vMeasuredDischargeNodes;
}

void
DischargeCurve::setVMeasuredDischargeNodes(
        const QVector<DischargeCurveNode> &measuredDischargeNodes)
{
    _vMeasuredDischargeNodes = measuredDischargeNodes;
}

DischargeCurveFormats *
DischargeCurve::pFormats()
const
{
    return dynamic_cast<DischargeCurveFormats *>(_pFormats);
}








qreal
DischargeCurveFormats::dischargePerUnit()
const
{
    return _dischargePerUnit;
}

void
DischargeCurveFormats::setDischargePerUnit(const qreal &dischargePerUnit)
{
    _dischargePerUnit = dischargePerUnit;
}

QColor
DischargeCurveFormats::curveColor()
const
{
    return _curveColor;
}

void
DischargeCurveFormats::setCurveColor(
        const QColor &curveColor)
{
    _curveColor = curveColor;
}

qreal
DischargeCurveFormats::pointDiameter()
const
{
    return _pointDiameter;
}

void
DischargeCurveFormats::setPointDiameter(
        const qreal &pointDiameter)
{
    _pointDiameter = pointDiameter;
}

QColor
DischargeCurveFormats::pointColor()
const
{
    return _pointColor;
}

void
DischargeCurveFormats::setPointColor(
        const QColor &pointColor)
{
    _pointColor = pointColor;
}

QString DischargeCurveNode::stage() const
{
    return _stage;
}

void DischargeCurveNode::setStage(const QString &stage)
{
    _stage = stage;
}
QString DischargeCurveNode::discharge() const
{
    return _discharge;
}

void DischargeCurveNode::setDischarge(const QString &discharge)
{
    _discharge = discharge;
}

