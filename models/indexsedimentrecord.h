#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef INDEXSEDIMENTRECORD_H
#define INDEXSEDIMENTRECORD_H

#include "record.h"

/**
 * @brief The IndexSedimentRecord class, Index Sediment Record 单沙记录
 */
class IndexSedimentRecord : public Record
{
public:
    /**
     * @brief _stcd 1. 站号
     */
    QString _stcd;

    /**
     * @brief _year 2. 年份
     */
    int _year;

    /**
     * @brief _id 3. 序号
     */
    int _id;

    /**
     * @brief _datetime 4. 时间
     */
    QString _datetime;

    /**
     * @brief _concentration 5. ISC 单样含沙量
     */
    QString _concentration;

    /**
     * @brief _unamed 6. 估计是 MSCAAC 断面平均含沙量
     */
    QString _unamed;

    /**
     * @brief _datetimeRaw 7. 水位原始输入
     */
    QString _datetimeRaw;

    /**
     * @brief _concentrationRaw 8. ISC 单样含沙量原始输入
     */
    QString _concentrationRaw;

};

#endif // INDEXSEDIMENTRECORD_H
