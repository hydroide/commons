#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef PROCESSSERIES_H
#define PROCESSSERIES_H

#include <QtCore>
#include <QtGui>

#include <boost/shared_ptr.hpp>

#include "globaldefines.h"
#include "modules/curvestructs.h"

class ProcessMap
{
public:
    void update();

    QMap<QDateTime, QString> minValues();
    QMap<QDateTime, QString> maxValues();

    QString minValue() const;
    void setMinValue(const QString &minValue);

    QString maxValue() const;
    void setMaxValue(const QString &maxValue);


    QMap<QDateTime, QString> &data();
    void setData(const QMap<QDateTime, QString> &data);

    friend void operator <<(QVariant &data, const ProcessMap &context);
    friend void operator >>(const QVariant &data, ProcessMap &context);

private:
    QString _maxValue;
    QString _minValue;
    QMap<QDateTime, QString> _minValues;
    QMap<QDateTime, QString> _maxValues;
    QMap<QDateTime, QString> _data;
};

Q_DECLARE_METATYPE(ProcessMap)

void operator <<(QVariant &data, const ProcessMap &context);
void operator >>(const QVariant &data, ProcessMap &context);

class ProcessSeries
{
public:
    ProcessSeries();
    ~ProcessSeries();

    QDateTime startDateTime() const;
    void setStartDateTime(const QDateTime &startDateTime);

    QDateTime endDateTime() const;
    void setEndDateTime(const QDateTime &endDateTime);

    double hoursRange() const;

    QString stcd() const;
    void setSTCD(const QString &stcd);

    QString stationName() const;
    void setStationName(const QString &stationName);

    void genStageMap();
    void genDischargeMap();
    void genSedimentMap();
    void genMeasuredDischargeMap();
    void genMeasuredSedimentDischargeMap();

    void updateMaps();
//    void generateMap();

    ProcessMap &mStages();

    ProcessMap &mDischarges();

    ProcessMap &mSediments();

    QMap<QDateTime, DGMeasuredDischarge> &measuredDischargeMap();

    friend void operator <<(QVariant &data, const ProcessSeries &context);
    friend void operator >>(const QVariant &data, ProcessSeries &context);

    QMap<QDateTime, DGMeasuredSedimentDischarge> &measuredSedimentDischargeMap();

    QColor lineColor() const;
    void setLineColor(const QColor &lineColor);

protected:
    ProcessMap _mStages;
    ProcessMap _mDischarges;
    ProcessMap _mSediments;
    QMap<QDateTime, DGMeasuredDischarge> _measuredDischargeMap;
    QMap<QDateTime, DGMeasuredSedimentDischarge> _measuredSedimentDischargeMap;

    QColor _lineColor;

    QDateTime _startDateTime;
    QDateTime _endDateTime;

    QString _stcd;
    QString _stationName;

};

Q_DECLARE_METATYPE(ProcessSeries)

void operator <<(QVariant &data, const ProcessSeries &context);
void operator >>(const QVariant &data, ProcessSeries &context);

typedef boost::shared_ptr<ProcessSeries> SpProcessSeries;

#endif
