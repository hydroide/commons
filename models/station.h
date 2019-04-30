#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef STATION_H
#define STATION_H

#include <QtCore>
#include "../globaldefines.h"

class Station
{
public:
    Station(const QString &stcd);
    ~Station();

    QString getDisplayName() const;

    bool compareIdOrName(const QString &idOrName) const;

    QString stcd() const;
    void setSTCD(const QString &stcd);

private:
    QString _stcd;
};

#endif // STATION_H
