#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef MEASUREDDISCHARGE_H
#define MEASUREDDISCHARGE_H

#include "modelbase.h"

class MeasuredDischarge
{
public:
    QString _stcd;
    QDateTime _dateTime;
    QString _stageValue;
    QString _dischargeValue;

    static void addInModel(QAbstractItemModel *pModel, const MeasuredDischarge &md);

    static QAbstractItemModel *createModel(QObject *parent, QVector<MeasuredDischarge> vMds);
};

class MeasuredDischargeSortFilterProxyModel
        : public ProcessingSortFilterProxyModel
{
    Q_OBJECT
public:
    MeasuredDischargeSortFilterProxyModel(QObject *parent = nullptr);
};

#endif // MEASUREDDISCHARGE_H
