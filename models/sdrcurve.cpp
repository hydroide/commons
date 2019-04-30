#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "sdrcurve.h"

SDRCurve::SDRCurve()
{

}

SDRCurve::~SDRCurve()
{

}

QPointF SDRCurve::getRealWorldCoord(const QPointF &point)
{
    _size.setWidth((_maxPoint.y() - _minPoint.y()) / _formats._unitLengthIndicatesDischarge);
    _size.setHeight((_maxPoint.x() - _minPoint.x()) / _formats._unitLengthIndicatesStage);
    auto x = point.x() / _formats._unitLengthIndicatesStage;
    auto y = point.y() / _formats._unitLengthIndicatesDischarge;
    return QPointF(y, _size.height() - x);
}
