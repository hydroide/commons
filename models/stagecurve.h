#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef STAGECURVE_H
#define STAGECURVE_H

#include "processcurve.h"
#include "stagerecord.h"

class StageCurveNode : ProcessCurveNode
{
public:
    virtual QDateTime dateTime() const Q_DECL_OVERRIDE;
    virtual void setDateTime(const QDateTime &dateTime) Q_DECL_OVERRIDE;

    virtual QString stage() const;
    virtual void setStage(const QString &stage);

protected:
    QDateTime _dateTime;
    QString _stage;
};

class StageCurveFormats : public ProcessCurveFormats
{
public:
    virtual qreal stagePerUnit() const;
    virtual void setStagePerUnit(const qreal &stagePerUnit);

    virtual QColor curveColor() const;
    virtual void setCurveColor(const QColor &curveColor);

    virtual QColor pointColor() const;
    virtual void setPointColor(const QColor &pointColor);

protected:
    qreal _stagePerUnit{0.01f};

    QColor _curveColor{Qt::red};
    QColor _pointColor{Qt::darkRed};

};

class StageCurve : public ProcessCurve
{
public:
    StageCurve();
    ~StageCurve();

    virtual void generateRealWorldPoints() Q_DECL_OVERRIDE;
    void generate();
    virtual QSizeF size() const Q_DECL_OVERRIDE;

    QVector<StageRecord> &vZQ_PROCESS();
    void setVZQ_PROCESS(const QVector<StageRecord> &vZQ_PROCESS);

    QList<StageCurveNode> &lStageCurveNodes();
    void setLStageCurveNodes(const QList<StageCurveNode> &lStageCurveNodes);



protected:
    QPointF _minPoint;
    QPointF _maxPoint;

    qreal _minStage;
    qreal _maxStage;
    qreal _minHour;
    qreal _maxHour;

    QVector<StageRecord> _vZQ_PROCESS;
    QList<StageCurveNode> _lStageCurveNodes;

    // ProcessCurve interface
public:
    StageCurveFormats *pFormats() const;
};

typedef QSharedPointer<StageCurve> SpStageCurve;

#endif // STAGECURVE_H
