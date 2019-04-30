#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef PROCESSINGDATA_H
#define PROCESSINGDATA_H

#include "stagerecord.h"
#include "sdrcurverecord.h"
#include "sdrcnoderecord.h"
#include "sdrperiodrecord.h"

#include "indexsedimentrecord.h"
#include "imsrcnoderecord.h"
#include "imsrperiodrecord.h"

#include "dmeasurementrecord.h"
#include "sdmeasurementrecord.h"
#include "sdmeasurementrecord.h"

#include <memory>
#include <vector>
using namespace std;

#include <QtCore>

/**
 * @brief The ProcessingData class 整编数据
 */
class ProcessingData
{
public:
    ProcessingData();

    /**
     * @brief _fileName
     */
    QString _fileName;

    /**
     * @brief _vZQ_PROCESS 水位记录
     */
    vector<StageRecord> _vZQ_PROCESS;

    /**
     * @brief _vSdrCurves 水位流量关系线
     */
    vector<SDRCurveRecord> _vSdrCurves;

    /**
     * @brief _vZQ_CURVE_NODE 水位流量关系线结点记录
     */
    vector<SDRCNodeRecord> _vZQ_CURVE_NODE;

    /**
     * @brief _vZQ_PERIOD 水位流量关系时段记录
     */
    vector<SDRPeriodRecord> _vZQ_PERIOD;

    /**
     * @brief _vSQ_PROCESS 单沙记录
     */
    vector<IndexSedimentRecord> _vSQ_PROCESS;

    /**
     * @brief _vSQ_CURVE_NODE 单断沙关系节点记录
     */
    vector<IMSRCNodeRecord> _vSQ_CURVE_NODE;

    /**
     * @brief _vSQ_PERIOD 单断沙关系时段记录
     */
    vector<IMSRPeriodRecord> _vSQ_PERIOD;

    /**
     * @brief _vDMeasurementRecords 流量测验记录
     */
    vector<DMeasurementRecord> _vDMeasurementRecords;

    /**
     * @brief _vSDMeasurementRecords 实测输沙率
     */
    vector<SDMeasurementRecord> _vSDMeasurementRecords;
};

typedef shared_ptr<ProcessingData> SpProcessingData;

#endif // PROCESSINGDATA_H
