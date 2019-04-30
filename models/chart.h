#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef CHART_H
#define CHART_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

#include <boost/shared_ptr.hpp>

#include "models/curve.h"
#include "models/chartsize.h"

#include "processseries.h"

class Chart
{
public:
    Chart();
    ~Chart();

    enum Type { Square, Hour, Blank };
    enum Period { Month, TenDays, Year, None };

    QString chartName() const;
    void setChartName(const QString &chartName);

    QList<SpElement> &lspElements();
    void setLspElements(const QList<SpElement> &lspElements);

    QString chartType() const;
    void setChartType(const QString &chartType);

    QList<SpProcessSeries>& seriesList();

    ChartSize chartSize() const;
    void setChartSize(const ChartSize &chartSize);

    QObject *rootItem() const;
    void setRootItem(QObject *value);

private:
    QString _chartName;
    QString _chartType;
    QList<SpElement> _lspElements;
    QList<SpProcessSeries> _seriesList;

    QObject *_rootItem {nullptr};

    ChartSize _chartSize;

    //QList<ChartItem> chartItems;
};

typedef boost::shared_ptr<Chart> SpChart;

#endif // CHART_H
