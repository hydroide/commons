#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SDRCURVERECORD_H
#define SDRCURVERECORD_H

#include "record.h"

/**
 * @brief The StageDischargeRelationCurve class, Stage-discharge Relation Curve 推流线
 */
class SDRCurveRecord : public Record
{
public:
    SDRCurveRecord();
};

#endif // SDRCURVERECORD_H
