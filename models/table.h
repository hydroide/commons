#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef TABLE_H
#define TABLE_H

#include <QtCore>

class Table
{
public:
    Table(const QString &tableName);
    ~Table();

    QString getDisplayName() const;

    QString tableName() const;
    void setTableName(const QString &tableName);

private:
    QString _tableName;

};

#endif // TABLE_H
