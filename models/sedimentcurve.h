#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SEDIMENTCURVE_H
#define SEDIMENTCURVE_H

#include "processcurve.h"

class SedimentCurveNode : ProcessCurveNode
{
public:
    QString _indexConcentration;
    QString _meanCrossSectionConcentration;
};

class SedimentCurveFormats : public ProcessCurveFormats
{
public:
    qreal _curveWidth{0.2f};
    QColor _curveColor{Qt::black};
    qreal _pointDiameter{0.4f};
    qreal _pointColor{Qt::black};
    qreal stagePerUnit{0.01f};
    qreal _hourPerUnit{1.0f};
};

class SedimentCurve : public ProcessCurve
{
public:
    SedimentCurve();
    ~SedimentCurve();


};

#endif // SEDIMENTCURVE_H
