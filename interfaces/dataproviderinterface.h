#ifndef DATAPROVIDERINTERFACE_H
#define DATAPROVIDERINTERFACE_H

#include <QtCore>

class DataProviderInterface
{
public:
    virtual ~DataProviderInterface() {}

    virtual QString type() = 0;
    virtual QList<int> zqs_process_year_list() = 0;
    virtual QStringList zq_process_stcd_list() = 0;
};

#define DataProviderInterface_iid "org.hwsdsw.HydroCurve.DataProviderInterface"

Q_DECLARE_INTERFACE(DataProviderInterface, DataProviderInterface_iid)

#endif // DATAPROVIDERINTERFACE_H
