#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef RECORD_H
#define RECORD_H

#include <QtCore>

/**
 * @brief The Record struct, 数据库及文件记录
 */
struct Record
{
};

void operator <<(QVariant &data, const Record &context);
void operator >>(const QVariant &data, Record &context);

#endif // RECORD_H
