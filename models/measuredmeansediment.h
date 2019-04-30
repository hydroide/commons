#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef MEASUREDMEANSEDIMENT_H
#define MEASUREDMEANSEDIMENT_H

#include "modelbase.h"

class MeasuredMeanSediment
{
public:
    QString _stcd;
    QDateTime _dateTime;
    QString _indexSedimentValue;
    QString _meanSedimentValue;

    static void addInModel(QAbstractItemModel *pModel,
                           const MeasuredMeanSediment &mms);

    static QAbstractItemModel *createModel(QObject *parent,
                const QVector<MeasuredMeanSediment> &vMms);
};

class MeasuredMeanSedimentSortFilterProxyModel
        : public ProcessingSortFilterProxyModel
{
    Q_OBJECT
public:
    MeasuredMeanSedimentSortFilterProxyModel(QObject *parent = nullptr);
};


#endif // MEASUREDMEANSEDIMENT_H
