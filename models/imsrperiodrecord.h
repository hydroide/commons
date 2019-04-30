#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef IMSRPERIODRECORD_H
#define IMSRPERIODRECORD_H

#include "record.h"

/**
 * @brief The IMSRPeriodRecord class, Index-mean Sediment Relation Period Record 推沙时段
 */
class IMSRPeriodRecord : public Record
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
     * @brief _start_time 4. 始时
     */
    QString _start_time;

    /**
     * @brief _end_time 5. 止时
     */
    QString _end_time;

    /**
     * @brief _method_id 6. 推沙方法
     */
    int _method_id;

    /**
     * @brief _curve_id 7. 推沙线号
     */
    int _curve_id;

    /**
     * @brief _unamed 8. 未知
     */
    QString _unamed;
};

#endif // IMSRPERIODRECORD_H
