#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "project.h"

#include "models/treemodel.h"

//#include "globals.h"

Project::Project(const QString &projPath)
{
    _projDir = projPath;
    _pProjectItem = new QStandardItem();
    auto ppiFont = _pProjectItem->font();
    ppiFont.setBold(true);
    _pProjectItem->setFont(ppiFont);
    {
        _pDbItem = new QStandardItem();
        _pDataItem = new QStandardItem(QObject::tr("数据"));
        _pSeriesItem = new QStandardItem(QObject::tr("系列"));
        _pProcessItem = new QStandardItem(QObject::tr("过程图"));
        _pRelationItem = new QStandardItem(QObject::tr("关系图"));
        _pCrossSectionItem = new QStandardItem(QObject::tr("大断面图"));

        _pProjectItem->appendRow(_pDbItem);
        _pProjectItem->appendRow(_pDataItem);
        _pProjectItem->appendRow(_pSeriesItem);
        _pProjectItem->appendRow(_pProcessItem);
        _pProjectItem->appendRow(_pRelationItem);
        _pProjectItem->appendRow(_pCrossSectionItem);
    }


}

Project::~Project()
{
    delete _pProjectItem;
}

void Project::open()
{

}

void Project::save()
{

}

bool Project::getChanged() const
{
    return changed;
}

void Project::setChanged(bool value)
{
    changed = value;
}

bool Project::getSaved() const
{
    return saved;
}

void Project::setSaved(bool value)
{
    saved = value;
}

QVector<Chart> &Project::vCharts()
{
    return _vCharts;
}

void Project::setVCharts(const QVector<Chart> &vCharts)
{
    _vCharts = vCharts;
}

QHash<QUuid, Chart> &Project::mCharts()
{
    return _mCharts;
}

QVector<QString> Project::vLinkedFiles() const
{
    return _vLinkedFiles;
}

void Project::setVLinkedFiles(const QVector<QString> &vLinkedFiles)
{
    _vLinkedFiles = vLinkedFiles;
}

QString Project::projName() const
{
    return _projName;
}

void Project::setProjName(const QString &projName)
{
    _projName = projName;
    _pProjectItem->setText(_projName);
    _pDbItem->setText(_projName + "." + PROJECT_DB_EXT);
}

QString Project::projDir() const
{
    return _projDir;
}

void Project::setProjPath(const QString &projPath)
{
    _projDir = projPath;
}

QAbstractItemModel *Project::getTreeModel(QObject *parent)
{
    QString str = projName() + "\n";
    for (const auto& chart: vCharts())
    {
        str += "    " + chart.chartName() + "\n";
    }
    return new TreeModel(str, parent);

}
QStandardItem *Project::getPProjectItem() const
{
    return _pProjectItem;
}

void Project::setPProjectItem(QStandardItem *pProjectItem)
{
    _pProjectItem = pProjectItem;
}
QStandardItem *Project::getPProcessItem() const
{
    return _pProcessItem;
}

void Project::setPProcessItem(QStandardItem *pProcessItem)
{
    _pProcessItem = pProcessItem;
}

std::shared_ptr<DataProviderInterface> Project::dataProvider() const
{
    return _dataProvider;
}

void Project::setDataProvider(const std::shared_ptr<DataProviderInterface> &dataProvider)
{
    _dataProvider = dataProvider;
}


