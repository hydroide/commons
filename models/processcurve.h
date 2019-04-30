#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef PROCESSCURVE_H
#define PROCESSCURVE_H

#include "curve.h"
#include <QColor>

class ProcessCurveNode
{
public:
    virtual QDateTime dateTime() const;
    virtual void setDateTime(const QDateTime &dateTime);

protected:
    QDateTime _dateTime;
};

class ProcessCurveFormats
{
public:
    virtual qreal curveWidth() const;
    virtual void setCurveWidth(const qreal &curveWidth);

    virtual QColor curveColor() const;
    virtual void setCurveColor(const QColor &curveColor);

    virtual qreal pointDiameter() const;
    virtual void setPointDiameter(const qreal &pointDiameter);

    virtual qreal hourPerUnit() const;
    virtual void setHourPerUnit(const qreal &hourPerUnit);

    virtual bool plotMeasuredPoint() const;
    virtual void setPlotMeasuredPoint(bool plotMeasuredPoint);

    virtual QColor pointColor() const;
    virtual void setPointColor(const QColor &pointColor);

protected:
    qreal _curveWidth{0.3f};
    QColor _curveColor{Qt::black};
    qreal _pointDiameter{0.4f};
    QColor _pointColor{Qt::black};
    qreal _hourPerUnit{1.0f};

    bool _plotMeasuredPoint{false};
};

class ProcessCurve : public Curve
{
public:
    ProcessCurve();
    ~ProcessCurve();

    virtual QSizeF size() const;

    QVector<QPointF> _vRealWorldPoints;
    QVector<QPointF> _vMeasuredPoints;

    virtual void generateRealWorldPoints();

    virtual ProcessCurveFormats *pFormats() const;

    qreal minValue() const;
    void setMinValue(const qreal &minValue);

    qreal maxValue() const;
    void setMaxValue(const qreal &maxValue);

    qreal minHour() const;
    void setMinHour(const qreal &minHour);

    qreal maxHour() const;
    void setMaxHour(const qreal &maxHour);

protected:
    QRectF _boundingRect;
    ProcessCurveFormats *_pFormats;

    qreal _minValue;
    qreal _maxValue;
    qreal _minHour;
    qreal _maxHour;

};

typedef QSharedPointer<ProcessCurve> SpProcessCurve;

#endif // PROCESSCURVE_H
