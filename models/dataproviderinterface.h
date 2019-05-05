#ifndef DATAPROVIDERINTERFACE_H
#define DATAPROVIDERINTERFACE_H

#include <QtCore>

class DataProviderInterface
{
public:
    virtual ~DataProviderInterface() {}

    virtual QList<int> zqs_process_year_list() = 0;
    virtual QStringList zq_process_stcd_list() = 0;
};

#endif // DATAPROVIDERINTERFACE_H
