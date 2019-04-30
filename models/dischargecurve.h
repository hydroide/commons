#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef DISCHARGECURVE_H
#define DISCHARGECURVE_H

#include "processcurve.h"

class DischargeCurveNode : public ProcessCurveNode
{
public:
    QString stage() const;
    void setStage(const QString &stage);

    QString discharge() const;
    void setDischarge(const QString &discharge);

protected:
    QString _stage;
    QString _discharge;
};

class DischargeCurveFormats : public ProcessCurveFormats
{
public:
    virtual qreal dischargePerUnit() const;
    virtual void setDischargePerUnit(const qreal &dischargePerUnit);

    virtual QColor curveColor() const;
    virtual void setCurveColor(const QColor &curveColor);

    virtual qreal pointDiameter() const;
    virtual void setPointDiameter(const qreal &pointDiameter);

    QColor pointColor() const;
    void setPointColor(const QColor &pointColor);

protected:
    qreal _dischargePerUnit{10.f};

    QColor _curveColor{Qt::darkCyan};
    qreal _pointDiameter{0.2f};
    QColor _pointColor{Qt::darkBlue};
};

class DischargeCurve : public ProcessCurve
{
public:
    DischargeCurve();
    ~DischargeCurve();

    virtual void generateRealWorldPoints() Q_DECL_OVERRIDE;
    virtual QSizeF size() const Q_DECL_OVERRIDE;


    QVector<DischargeCurveNode> vReckonedDischargeNodes() const;
    void setVReckonedDischargeNodes(const QVector<DischargeCurveNode> &vReckonedDischargeNodes);

    QVector<DischargeCurveNode> vMeasuredDischargeNodes() const;
    void setVMeasuredDischargeNodes(const QVector<DischargeCurveNode> &vMeasuredDischargeNodes);

protected:

    QVector<DischargeCurveNode> _vReckonedDischargeNodes;
    QVector<DischargeCurveNode> _vMeasuredDischargeNodes;


    // ProcessCurve interface
public:
    DischargeCurveFormats *pFormats() const;
};

typedef QSharedPointer<DischargeCurve> SpDischargeCurve;

#endif // DISCHARGECURVE_H
