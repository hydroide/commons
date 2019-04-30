#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef RECKENEDMEANSEDIMENT_H
#define RECKENEDMEANSEDIMENT_H

#include "modelbase.h"

class ReckenedMeanSediment
{
public:
    QString stcd;
    QDateTime datetime;
    QString sedimentValue;
};

class ReckenedMeanSedimentSortFilterProxyModel
        : public ProcessingSortFilterProxyModel
{
    Q_OBJECT
public:
    ReckenedMeanSedimentSortFilterProxyModel(QObject *parent = nullptr);
};

#endif // RECKENEDMEANSEDIMENT_H
