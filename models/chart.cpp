#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "chart.h"

Chart::Chart()
{
}

Chart::~Chart()
{
//    delete _rootItem;
}

QString Chart::chartName() const
{
    return _chartName;
}

void Chart::setChartName(const QString &chartName)
{
    _chartName = chartName;
}

QList<SpElement> &Chart::lspElements()
{
    return _lspElements;
}

void Chart::setLspElements(const QList<SpElement> &lspElements)
{
    _lspElements = lspElements;
}

QString Chart::chartType() const
{
    return _chartType;
}

void Chart::setChartType(const QString &chartType)
{
    _chartType = chartType;
}

QList<SpProcessSeries> &Chart::seriesList()
{
    return _seriesList;
}

ChartSize Chart::chartSize() const
{
    return _chartSize;
}

void Chart::setChartSize(const ChartSize &chartSize)
{
    _chartSize = chartSize;
}

QObject *Chart::rootItem() const
{
    return _rootItem;
}

void Chart::setRootItem(QObject *value)
{
    _rootItem = value;
}



