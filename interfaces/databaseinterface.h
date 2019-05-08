#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QtSql>

class DatabaseInterface
{
public:
    virtual ~DatabaseInterface() {}
    virtual void setDatabase(QSqlDatabase db) = 0;
};

#define DatabaseInterface_iid "org.hwsdsw.HydroCurve.DatabaseInterface"

Q_DECLARE_INTERFACE(DatabaseInterface, DatabaseInterface_iid)

#endif // DATABASEINTERFACE_H
