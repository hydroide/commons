#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef FILEEXPORTINTERFACE_H
#define FILEEXPORTINTERFACE_H

#include <QtCore>

class FileExportInterface
{
public:
    virtual ~FileExportInterface() {}
    virtual QStringList extensions() = 0;
    virtual QString description() = 0;
    virtual void export(const QString &filepath) = 0;
};

#define FileExportInterface_iid "org.hwsdsw.HydroCurve.FileExportInterface"

Q_DECLARE_INTERFACE(FileExportInterface, FileExportInterface_iid)

#endif // FILEEXPORTINTERFACE_H
