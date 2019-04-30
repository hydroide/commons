#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SDMEASUREMENTRECORD_H
#define SDMEASUREMENTRECORD_H

#include "record.h"

/**
 * @brief The SDMeasurementRecord class, Sediment Discharge Measurement Record 实测输沙率记录
 */
class SDMeasurementRecord : public Record
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
     * @brief _measurementId 4. 测次
     */
    QString _measurementId;

    /**
     * @brief _dischargeMeasurementId 5. 流量测次
     */
    QString _dischargeMeasurementId;

    /**
     * @brief _month 6. 月
     */
    int _month;

    /**
     * @brief _day 7. 日
     */
    int _day;

    /**
     * @brief _start_time 8. 开始时间
     */
    QString _start_time;

    /**
     * @brief _end_time 9. 结束时间
     */
    QString _end_time;

    /**
     * @brief _discharge 10. 流量
     */
    QString _discharge;

    /**
     * @brief _cssqr 11. 断面输沙率
     */
    QString _cssqr;

    /**
     * @brief _csmsc 12. 断面平均含沙量
     */
    QString _csmsc;

    /**
     * @brief _sssc 13. 单样含沙量
     */
    QString _sssc;

    /**
     * @brief _sssm 14. 单样测法
     */
    QString _sssm;

    /**
     * @brief _annotation 15. 附注
     */
    QString _annotation;

    /**
     * @brief _meanSedimentMethod 16. 断沙测法
     */
    QString _meanSedimentMethod;
};

#endif // SDMEASUREMENTRECORD_H
