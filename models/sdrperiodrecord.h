#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SDRPERIODRECORD_H
#define SDRPERIODRECORD_H

#include "record.h"

/**
 * @brief The SDRPeriodRecord class, Stage-discharge Relation Period Record 推流时段
 */
class SDRPeriodRecord : public Record
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
     * @brief _id 3. 时段序号
     */
    int _id;

    /**
     * @brief _unamed 4. 始时
     */
    QString _start_time;

    /**
     * @brief _end_time 5. 止时
     */
    QString _end_time;

    /**
     * @brief _method_id 6. 推流方法
     */
    int _method_id;

    /**
     * @brief _curve_id 7. 推流线号
     */
    int _curve_id;

    /**
     * @brief _annotation 8. 附注
     */
    QString _annotation;

    /**
     * @brief _end_timeRaw 9. 原始录入止时
     */
    QString _end_timeRaw;
};

#endif // SDRPERIODRECORD_H
