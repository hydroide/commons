#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "measureddischarge.h"



void
MeasuredDischarge::addInModel(QAbstractItemModel *pModel, const MeasuredDischarge &md)
{
    int r = pModel->rowCount();
    pModel->insertRow(r);
    pModel->setData(pModel->index(r, 0), md._stcd);
    pModel->setData(pModel->index(r, 1), md._dateTime);
    pModel->setData(pModel->index(r, 2), md._stageValue);
    pModel->setData(pModel->index(r, 3), md._dischargeValue);
}

QAbstractItemModel *
MeasuredDischarge::createModel(QObject *parent, QVector<MeasuredDischarge> vMds)
{
    QStandardItemModel *pModel = new QStandardItemModel(0, 4, parent);

    pModel->setHorizontalHeaderLabels(QStringList()
                                      << QObject::tr("站点")
                                      << QObject::tr("时间")
                                      << QObject::tr("水位")
                                      << QObject::tr("流量")
                                      );
    for (auto md : vMds)
    {
        addInModel(pModel, md);
    }
    return pModel;
}


MeasuredDischargeSortFilterProxyModel::MeasuredDischargeSortFilterProxyModel(QObject *parent)
{

}
