#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef DMEASUREMENTRECORD_H
#define DMEASUREMENTRECORD_H

#include <string>
using namespace std;

#include "record.h"

/**
 * @brief The DMeasurementRecord class, Discharge Measurement Record 实测流量记录
 */
class DMeasurementRecord : public Record
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
     * @brief _measurementId 4. 施测号数
     */
    QString _measurementId;

    /**
     * @brief _month 5. 月
     */
    int _month;

    /**
     * @brief _day 6. 日
     */
    int _day;

    /**
     * @brief _start_time 7. 开始时间
     */
    QString _start_time;

    /**
     * @brief _end_time 8. 结束时间
     */
    QString _end_time;

    /**
     * @brief _location 9. 测验位置
     */
    QString _location;

    /**
     * @brief _stage 10. 测时水位
     */
    QString _stage;

    /**
     * @brief _discharge 11. 流量
     */
    QString _discharge;

    /**
     * @brief _area 12. 面积
     */
    QString _area;

    /**
     * @brief _avg_v 13. 平均流速
     */
    QString _avg_v;

    /**
     * @brief _max_v 14. 最大流速
     */
    QString _max_v;

    /**
     * @brief _stream_w 15. 水面宽
     */
    QString _stream_w;

    /**
     * @brief _avg_depth 16. 平均水深
     */
    QString _avg_depth;

    /**
     * @brief _max_depth 17. 最大水深
     */
    QString _max_depth;

    /**
     * @brief _surface_slope 18. 水面比降
     */
    QString _surface_slope;

    /**
     * @brief _mannings_n 19. 糙率
     */
    QString _mannings_n;

    /**
     * @brief _annotation 20. 附注
     */
    QString _annotation;

    /**
     * @brief _method1 21. 测验方法 形如（流速仪、水面浮标）
     */
    QString _method1;

    /**
     * @brief _method2 22. 测验方法 形如（垂线数 / 测点数）
     */
    QString _method2;
};

#endif // DMEASUREMENTRECORD_H
