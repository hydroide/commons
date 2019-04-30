#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "stagecurve.h"

StageCurve::StageCurve()
{
    _type = "StageCurve";
    _pFormats = new StageCurveFormats;
}

StageCurve::~StageCurve()
{

}

void
StageCurve::generateRealWorldPoints()
{
    _vRealWorldPoints.clear();
    StageRecord firstSR{_vZQ_PROCESS.first()};
    _minStage = firstSR.getStage_qreal();
    _maxStage = firstSR.getStage_qreal();
    _minHour = firstSR.getHour_qreal();
    _maxHour = firstSR.getHour_qreal();
    for (auto record : _vZQ_PROCESS)
    {
        auto stage = record.getStage_qreal();
        if (stage < _minStage)
        {
            _minStage = stage;
        }
        else if (stage > _maxStage)
        {
            _maxStage = stage;
        }
        auto hour = record.getHour_qreal();
        if (hour < _minHour)
        {
            _minHour = hour;
        }
        else if (hour > _maxHour)
        {
            _maxHour = hour;
        }
    }
    for (auto record : _vZQ_PROCESS)
    {
        qreal hourUnits = (record.getHour_qreal() - _minHour)
                /pFormats()->hourPerUnit();
        qreal stageUnits = (record.getStage_qreal() - _minStage)
                /pFormats()->stagePerUnit();
        _vRealWorldPoints.push_back(QPointF(hourUnits, stageUnits));
    }

}

void
StageCurve::generate()
{
    _vRealWorldPoints.clear();
    if (_lStageCurveNodes.isEmpty())
    {
        return;
    }
    StageCurveNode firstNode{_lStageCurveNodes.first()};
    _minStage = firstNode.stage().toDouble();
    _maxStage = _minStage;
    _minHour = firstNode.dateTime().toMSecsSinceEpoch() / 3600000.f;
    _maxHour = _minHour;
    for (auto node : _lStageCurveNodes)
    {
        auto stage = node.stage().toDouble();
        if (stage < _minStage)
        {
            _minStage = stage;
        }
        else if (stage > _maxStage)
        {
            _maxStage = stage;
        }
        auto hour = node.dateTime().toMSecsSinceEpoch() / 3600000.f;
        if (hour < _minHour)
        {
            _minHour = hour;
        }
        else if (hour > _maxHour)
        {
            _maxHour = hour;
        }
    }
    for (auto node : _lStageCurveNodes)
    {
        auto hour = node.dateTime().toMSecsSinceEpoch() / 3600000.f;
        qreal hourUnits = (hour - _minHour)/pFormats()->hourPerUnit();
         auto stage = node.stage().toDouble();
        qreal stageUnits = (stage - _minStage)/pFormats()->stagePerUnit();
        _vRealWorldPoints.push_back(QPointF(hourUnits, stageUnits));
    }
}

QSizeF
StageCurve::size()
const
{
    qreal width = (_maxHour - _minHour)/pFormats()->hourPerUnit();
    qreal height = (_maxStage - _minStage)/pFormats()->stagePerUnit();
    return QSizeF(width, height);
}

QVector<StageRecord> &StageCurve::vZQ_PROCESS()
{
    return _vZQ_PROCESS;
}

void StageCurve::setVZQ_PROCESS(const QVector<StageRecord> &vZQ_PROCESS)
{
    _vZQ_PROCESS = vZQ_PROCESS;
}

QList<StageCurveNode> &
StageCurve::lStageCurveNodes()
{
    return _lStageCurveNodes;
}

void
StageCurve::setLStageCurveNodes(
        const QList<StageCurveNode> &lStageCurveNodes)
{
    _lStageCurveNodes = lStageCurveNodes;
}


StageCurveFormats *
StageCurve::pFormats()
const
{
    return dynamic_cast<StageCurveFormats *>(_pFormats);
}


qreal
StageCurveFormats::stagePerUnit()
const
{
    return _stagePerUnit;
}

void
StageCurveFormats::setStagePerUnit(
        const qreal &stagePerUnit)
{
    _stagePerUnit = stagePerUnit;
}

QColor
StageCurveFormats::curveColor()
const
{
    return _curveColor;
}

void
StageCurveFormats::setCurveColor(
        const QColor &curveColor)
{
    _curveColor = curveColor;
}

QColor
StageCurveFormats::pointColor()
const
{
    return _pointColor;
}

void
StageCurveFormats::setPointColor(
        const QColor &pointColor)
{
    _pointColor = pointColor;
}



QDateTime
StageCurveNode::dateTime()
const
{
    return _dateTime;
}

void
StageCurveNode::setDateTime(
        const QDateTime &dateTime)
{
    _dateTime = dateTime;
}

QString
StageCurveNode::stage()
const
{
    return _stage;
}

void
StageCurveNode::setStage(
        const QString &stage)
{
    _stage = stage;
}

