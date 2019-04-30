#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SDRCURVEPERIOD_H
#define SDRCURVEPERIOD_H

#include <QtCore>

struct SDRCurvePeriod
{
public:
    QString _stcd;
    int _year;
    int _period_id;
    QDateTime _start_time;
    QDateTime _end_time;
    int _method_id;
    int _curve_id;
};

#endif // SDRCURVEPERIOD_H
