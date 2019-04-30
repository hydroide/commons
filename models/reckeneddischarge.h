#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef RECKENEDDISCHARGE_H
#define RECKENEDDISCHARGE_H

#include "modelbase.h"

class ReckenedDischarge
{
public:
    QString _stcd;
    QDateTime _dateTime;
    QString _dischargeValue;
};

class ReckenedDischargeModel : public QStandardItemModel
{
    Q_OBJECT
};

class ReckenedDischargeSortFilterProxyModel
        : public ProcessingSortFilterProxyModel
{
    Q_OBJECT
public:
    ReckenedDischargeSortFilterProxyModel(QObject *parent = nullptr);

};

#endif // RECKENEDDISCHARGE_H
