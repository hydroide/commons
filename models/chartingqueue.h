#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef CHARTINGQUEUE_H
#define CHARTINGQUEUE_H

#include <QtCore>

#include "chart.h"

class ChartingQueue
{
public:
    ChartingQueue();
    ~ChartingQueue();

    QList<Chart> lChartQueue() const;
    void setLChartQueue(const QList<Chart> &lChartQueue);

private:
    QList<Chart> _lChartQueue;
};

#endif // CHARTINGQUEUE_H
