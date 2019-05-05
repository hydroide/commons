#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef PROJECT_H
#define PROJECT_H

//#include "ijsonserializable.h"

#include "chart.h"

#include "dataproviderinterface.h"

#include <QStandardItem>

class Project
{
public:
    Project(const QString &projDir);
    ~Project();

    void open();
    void save();

    bool getChanged() const;
    void setChanged(bool value);

    bool getSaved() const;
    void setSaved(bool value);

    QVector<Chart> &vCharts();
    void setVCharts(const QVector<Chart> &vCharts);

    QHash<QUuid, Chart> &mCharts();

    QVector<QString> vLinkedFiles() const;
    void setVLinkedFiles(const QVector<QString> &vLinkedFiles);

    QString projName() const;
    void setProjName(const QString &projName);

    QString projDir() const;
    void setProjPath(const QString &projDir);

    QAbstractItemModel *getTreeModel(QObject *parent);

    QStandardItem *getPProjectItem() const;
    void setPProjectItem(QStandardItem *pProjectItem);

    QStandardItem *getPProcessItem() const;
    void setPProcessItem(QStandardItem *pProcessItem);

    DataProviderInterface *dataProvider() const;
    void setDataProvider(DataProviderInterface *dataProvider);

private:
    DataProviderInterface *_dataProvider{nullptr};
    bool changed{false};

    bool saved{true};

    QString _projDir;
    QString _projName;

    QVector<Chart> _vCharts;
    QHash<QUuid, Chart> _mCharts;
    QHash<QUuid, ProcessSeries> _hSeries;

    QVector<QString> _vLinkedFiles;

    QStandardItem *_pProjectItem{nullptr};
    QStandardItem *_pDbItem{nullptr};
    QStandardItem *_pDataItem{nullptr};
    QStandardItem *_pSeriesItem{nullptr};
    QStandardItem *_pProcessItem{nullptr};
    QStandardItem *_pRelationItem{nullptr};
    QStandardItem *_pCrossSectionItem{nullptr};

};

typedef std::shared_ptr<Project> SpProject;

#endif // PROJECT_H
