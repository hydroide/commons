#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "table.h"

Table::Table(const QString &tableName)
{
    _tableName = tableName;
}

Table::~Table()
{

}

QString Table::getDisplayName() const
{
    if (MAP_TABLE_DISPLAY_NAMES.contains(_tableName)) {
        return MAP_TABLE_DISPLAY_NAMES.value(_tableName);
    }
    return _tableName;
}
QString Table::tableName() const
{
    return _tableName;
}

void Table::setTableName(const QString &tableName)
{
    _tableName = tableName;
}


