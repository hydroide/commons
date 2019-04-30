#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef MODELBASE_H
#define MODELBASE_H

#include <QtCore>
#include <QStandardItemModel>

class ModelBase
{
public:
    ModelBase();
    ~ModelBase();
};

class ProcessingSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    ProcessingSortFilterProxyModel(QObject *parent = nullptr);

    QDateTime filterMinDateTime() const;
    void setFilterMinDateTime(const QDateTime &filterMinDateTime);

    QDateTime filterMaxDateTime() const;
    void setFilterMaxDateTime(const QDateTime &filterMaxDateTime);

    QList<QString> getSTCDs() const;

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent)
        const Q_DECL_OVERRIDE;
    bool lessThan(const QModelIndex &left, const QModelIndex &right)
        const Q_DECL_OVERRIDE;

private:
    QDateTime _minDateTime;
    QDateTime _maxDateTime;
    QString _stcd;

    bool dateTimeInRange(const QDateTime &dateTime) const;
};

#endif // MODELBASE_H
