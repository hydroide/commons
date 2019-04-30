#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "indexsediment.h"



void
IndexSediment::addInModel(QAbstractItemModel *pModel, const IndexSediment &is)
{
    int r = pModel->rowCount();
    pModel->insertRow(r);
    pModel->setData(pModel->index(r, 0), is._stcd);
    pModel->setData(pModel->index(r, 1), is._dateTime);
    pModel->setData(pModel->index(r, 2), is._sedimentValue);

}

QAbstractItemModel *
IndexSediment::createModel(QObject *parent, QVector<IndexSediment> vIses)
{
    QStandardItemModel *pModel = new QStandardItemModel(0, 3, parent);

    pModel->setHorizontalHeaderLabels(QStringList()
                                      << QObject::tr("站点")
                                      << QObject::tr("时间")
                                      << QObject::tr("单样含沙量")
                                      );
    for (auto is : vIses)
    {
        addInModel(pModel, is);
    }
    return pModel;
}


IndexSedimentSortFilterProxyModel::IndexSedimentSortFilterProxyModel(
        QObject *parent)
    : ProcessingSortFilterProxyModel(parent)
{

}
