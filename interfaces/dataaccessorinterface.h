#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef DATAACCESSORINTERFACE_H
#define DATAACCESSORINTERFACE_H

#include <QtCore>

#include "dataproviderinterface.h"

class DataAccessorInterface
{
public:
    virtual ~DataAccessorInterface() {}

    virtual void setDataProvider(SpDataProviderInterface) = 0;
};

#define DataAccessorInterface_iid "org.hwsdsw.HydroCurve.DataAccessorInterface"

Q_DECLARE_INTERFACE(DataAccessorInterface, DataAccessorInterface_iid)

typedef std::shared_ptr<DataAccessorInterface> SpDataAccessorInterface;

#endif // DATAACCESSORINTERFACE_H
