#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef INDEXSEDIMENT_H
#define INDEXSEDIMENT_H

#include "modelbase.h"

class IndexSediment
{
public:
    QString _stcd;
    QDateTime _dateTime;
    QString _sedimentValue;

    static void addInModel(QAbstractItemModel *pModel, const IndexSediment &is);

    static QAbstractItemModel *createModel(QObject *parent, QVector<IndexSediment> vIses);
};

class IndexSedimentSortFilterProxyModel
        : public ProcessingSortFilterProxyModel
{
    Q_OBJECT
public:
    IndexSedimentSortFilterProxyModel(QObject *parent = nullptr);
};

#endif // INDEXSEDIMENT_H
