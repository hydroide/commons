#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "sdrcnoderecord.h"

qreal SDRCNodeRecord::getStage_qreal()
{
    return (qreal)_stage.toDouble();
}

qreal SDRCNodeRecord::getDischarge_qreal()
{
    return (qreal)_discharge.toDouble();
}
