#ifndef FILEIMPORTINTERFACE_H
#define FILEIMPORTINTERFACE_H

#include <QtCore>

class FileImportInterface
{
public:
    virtual ~FileImportInterface() {}
    virtual QStringList extensions() = 0;
    virtual QString description() = 0;
    virtual void import(const QString &filepath) = 0;
};

#define FileImportInterface_iid "org.hwsdsw.HydroCurve.FileImportInterface"

Q_DECLARE_INTERFACE(FileImportInterface, FileImportInterface_iid)

#endif // FILEIMPORTINTERFACE_H
