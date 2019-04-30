#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef STAGERECORD_H
#define STAGERECORD_H

#include "record.h"

#include <boost/multiprecision/cpp_dec_float.hpp>
using boost::multiprecision::cpp_dec_float_50;

/**
 * @brief The StageRecord class, Stage Record 水位记录
 */
class StageRecord : Record
{
public:

    /**
     * @brief stcd 1. 站号
     */
    QString _stcd;

    /**
     * @brief year 2. 年份
     */
    int _year;

    /**
     * @brief id 3. 序号
     */
    int _id;

    /**
     * @brief datetime 4. 时间
     */
    QString _datetime;

    /**
     * @brief stage 5. 水位
     */
    QString _stage;

    /**
     * @brief unamed 6. 未知
     */
    QString _unamed;

    /**
     * @brief datetimeRaw 7.时间原始输入
     */
    QString _datetimeRaw;

    /**
     * @brief stageRaw 8. 水位原始输入
     */
    QString _stageRaw;

    /**
     * @brief getStage_qreal 得到近似水位
     * @return 水位（近似值）
     */
    qreal getStage_qreal();

    /**
     * @brief getHour_qreal 得到自1970年1月1日0时的小时数
     * @return 距离1970年1月1日0时的小时数
     */
    qreal getHour_qreal();
};
QDataStream &operator<<(QDataStream &, const StageRecord &);
QDataStream &operator>>(QDataStream &, StageRecord &);
#endif // STAGERECORD_H
