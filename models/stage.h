#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef STAGE_H
#define STAGE_H

#include "modelbase.h"

class StageItem
{
public:
    QString _stcd;
    QDateTime _dateTime;
    QString _stageValue;

};

class StageSortFilterProxyModel : public ProcessingSortFilterProxyModel
{
    Q_OBJECT
public:
    StageSortFilterProxyModel(QObject *parent = nullptr);
};

#endif // STAGE_H
