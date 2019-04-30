#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "modelbase.h"

ModelBase::ModelBase()
{

}

ModelBase::~ModelBase()
{

}

ProcessingSortFilterProxyModel::ProcessingSortFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{

}

QDateTime
ProcessingSortFilterProxyModel::filterMinDateTime() const
{
    return _minDateTime;
}

void
ProcessingSortFilterProxyModel::setFilterMinDateTime(
        const QDateTime &minDateTime)
{
    _minDateTime = minDateTime;
    invalidateFilter();
}

QDateTime
ProcessingSortFilterProxyModel::filterMaxDateTime() const
{
    return _maxDateTime;
}

void
ProcessingSortFilterProxyModel::setFilterMaxDateTime(
        const QDateTime &maxDateTime)
{
    _maxDateTime = maxDateTime;
    invalidateFilter();
}

QList<QString> ProcessingSortFilterProxyModel::getSTCDs() const
{
    QList<QString> list;

    return list;
}

bool ProcessingSortFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex index0 = sourceModel()->index(sourceRow, 0, sourceParent);
    QModelIndex index1 = sourceModel()->index(sourceRow, 1, sourceParent);

    return (sourceModel()->data(index0).toString().contains(filterRegExp()) &&
            dateTimeInRange(sourceModel()->data(index1).toDateTime()));
}

bool ProcessingSortFilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QVariant leftData = sourceModel()->data(left);
    QVariant rightData = sourceModel()->data(right);

    if (leftData.type() == QVariant::DateTime)
    {
        return leftData.toDateTime() < rightData.toDateTime();
    }
    else
    {
//        QRegExp *emailPattern = new QRegExp("([\\w\\.]*@[\\w\\.]*)");

//        QString leftString = leftData.toString();
////        if(left.column() == 1 && emailPattern->indexIn(leftString) != -1)
////            leftString = emailPattern->cap(1);

//        QString rightString = rightData.toString();
////        if(right.column() == 1 && emailPattern->indexIn(rightString) != -1)
////            rightString = emailPattern->cap(1);

//        return QString::localeAwareCompare(leftString, rightString) < 0;
        return false; // 只比较时间
    }
}

bool ProcessingSortFilterProxyModel::dateTimeInRange(const QDateTime &dateTime) const
{
    return (!_minDateTime.isValid() || dateTime >= _minDateTime)
            && (!_maxDateTime.isValid() || dateTime <= _maxDateTime);
}

