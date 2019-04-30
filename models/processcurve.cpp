#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "processcurve.h"

ProcessCurve::ProcessCurve()
{
    _type = "ProcessCurve";
    _pFormats = new ProcessCurveFormats;
}

ProcessCurve::~ProcessCurve()
{

}

QSizeF
ProcessCurve::size()
const
{
    return QSizeF();
}

void
ProcessCurve::generateRealWorldPoints()
{

}

ProcessCurveFormats *
ProcessCurve::pFormats()
const
{
    return _pFormats;
}

qreal
ProcessCurve::maxHour()
const
{
    return _maxHour;
}

void
ProcessCurve::setMaxHour(
        const qreal &maxHour)
{
    _maxHour = maxHour;
}

qreal
ProcessCurve::minHour()
const
{
    return _minHour;
}

void
ProcessCurve::setMinHour(
        const qreal &minHour)
{
    _minHour = minHour;
}

qreal
ProcessCurve::maxValue()
const
{
    return _maxValue;
}

void
ProcessCurve::setMaxValue(
        const qreal &maxValue)
{
    _maxValue = maxValue;
}

qreal
ProcessCurve::minValue()
const
{
    return _minValue;
}

void
ProcessCurve::setMinValue(
        const qreal &minValue)
{
    _minValue = minValue;
}








qreal
ProcessCurveFormats::curveWidth()
const
{
    return _curveWidth;
}

void
ProcessCurveFormats::setCurveWidth(
        const qreal &curveWidth)
{
    _curveWidth = curveWidth;
}

QColor
ProcessCurveFormats::curveColor()
const
{
    return _curveColor;
}

void
ProcessCurveFormats::setCurveColor(
        const QColor &curveColor)
{
    _curveColor = curveColor;
}

qreal
ProcessCurveFormats::pointDiameter()
const
{
    return _pointDiameter;
}

void
ProcessCurveFormats::setPointDiameter(
        const qreal &pointDiameter)
{
    _pointDiameter = pointDiameter;
}

qreal
ProcessCurveFormats::hourPerUnit()
const
{
    return _hourPerUnit;
}

void
ProcessCurveFormats::setHourPerUnit(
        const qreal &hourPerUnit)
{
    _hourPerUnit = hourPerUnit;
}

bool
ProcessCurveFormats::plotMeasuredPoint()
const
{
    return _plotMeasuredPoint;
}

void
ProcessCurveFormats::setPlotMeasuredPoint(
        bool plotMeasuredPoint)
{
    _plotMeasuredPoint = plotMeasuredPoint;
}

QColor
ProcessCurveFormats::pointColor()
const
{
    return _pointColor;
}

void
ProcessCurveFormats::setPointColor(
        const QColor &pointColor)
{
    _pointColor = pointColor;
}



QDateTime ProcessCurveNode::dateTime() const
{
    return _dateTime;
}

void ProcessCurveNode::setDateTime(const QDateTime &dateTime)
{
    _dateTime = dateTime;
}
