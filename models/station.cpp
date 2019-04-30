#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "station.h"

Station::Station(const QString &stcd)
{
    _stcd = stcd;
}

Station::~Station()
{

}

QString Station::getDisplayName() const
{
    if (MAP_STATION_DISPLAY_NAMES.contains(_stcd)) {
        return MAP_STATION_DISPLAY_NAMES.value(_stcd);
    }
    return _stcd;
}

bool Station::compareIdOrName(const QString &idOrName) const
{
    QString displayName;
    if (MAP_STATION_DISPLAY_NAMES.contains(_stcd)) {
        displayName == MAP_STATION_DISPLAY_NAMES.value(_stcd);
    }
    return _stcd == idOrName || displayName == idOrName;
}

QString Station::stcd() const
{
    return _stcd;
}

void Station::setSTCD(const QString &stcd)
{
    _stcd = stcd;
}
