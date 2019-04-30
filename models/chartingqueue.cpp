#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "chartingqueue.h"

ChartingQueue::ChartingQueue()
{

}

ChartingQueue::~ChartingQueue()
{

}

QList<Chart> ChartingQueue::lChartQueue() const
{
    return _lChartQueue;
}

void ChartingQueue::setLChartQueue(const QList<Chart> &lChartQueue)
{
    _lChartQueue = lChartQueue;
}


