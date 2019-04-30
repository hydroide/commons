#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "stagerecord.h"
#include "../helpers/datetimehelper.h"

qreal StageRecord::getStage_qreal()
{
    if (typeid(qreal) == typeid(double))
    {
        return (qreal)_stage.toDouble(); // 可以用double吗？
    }
    else
    {
        return (qreal)_stage.toFloat();
    }
}

qreal StageRecord::getHour_qreal()
{
    QDateTime dt = DateTimeHelper::fromShortFormat(_datetime, _year);
    qint64 msec = dt.toMSecsSinceEpoch();
    return msec/3600000;
}



QDataStream &operator<<(QDataStream &out, const StageRecord &r)
{
    out << r._stcd << r._year << r._id << r._datetime << r._stage
        << r._unamed << r._datetimeRaw << r._stageRaw;
    return out;
}


QDataStream &operator>>(QDataStream &in, StageRecord &r)
{
    r = StageRecord();
    in >> r._stcd >> r._year >> r._id >> r._datetime >> r._stage
        >> r._unamed >> r._datetimeRaw >> r._stageRaw;
    return in;
}
