#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef IMSRCNODERECORD_H
#define IMSRCNODERECORD_H

#include "record.h"

/**
 * @brief The IMSRCNodeRecord class, Index-mean Sediment Relation Curve Node Record 推沙节点
 */
class IMSRCNodeRecord : public Record
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
     * @brief _sssc 5. 单样含沙量
     */
    QString _sssc;

    /**
     * @brief _csmsc 6. 断面平均含沙量
     */
    QString _csmsc;

    /**
     * @brief _unamed 7. 未知
     */
    QString _unamed;
};

#endif // IMSRCNODERECORD_H
