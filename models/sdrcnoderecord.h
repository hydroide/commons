#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SDRCNODERECORD_H
#define SDRCNODERECORD_H

#include "record.h"

#include <boost/multiprecision/cpp_dec_float.hpp>
using boost::multiprecision::cpp_dec_float_50;

/**
 * @brief The SDRCNodeRecord class, Stage-discharge Relation Curve Node Record 推流线节点
 */
class SDRCNodeRecord : public Record
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
     * @brief _curve_id 3. 线号
     */
    int _curve_id;

    /**
     * @brief _node_id 4. 节点号
     */
    int _node_id;

    /**
     * @brief _stage 5. 水位（50位有效数字的精确值）
     */
    QString _stage;

    /**
     * @brief _discharge 6. 流量（50位有效数字的精确值）
     */
    QString _discharge;

    /**
     * @brief getStage_qreal
     * @return 水位的近似值
     */
    qreal getStage_qreal();

    /**
     * @brief getDischarge_qreal
     * @return 流量的近似值
     */
    qreal getDischarge_qreal();

};

#endif // SDRCNODERECORD_H
