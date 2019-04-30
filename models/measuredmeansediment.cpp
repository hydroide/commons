#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "measuredmeansediment.h"



void
MeasuredMeanSediment::addInModel(
        QAbstractItemModel *pModel, const MeasuredMeanSediment &mms)
{
    int r = pModel->rowCount();
    pModel->insertRow(r);
    pModel->setData(pModel->index(r, 0), mms._stcd);
    pModel->setData(pModel->index(r, 1), mms._dateTime);
    pModel->setData(pModel->index(r, 2), mms._indexSedimentValue);
    pModel->setData(pModel->index(r, 3), mms._meanSedimentValue);
}

QAbstractItemModel *
MeasuredMeanSediment::createModel(
        QObject *parent, const QVector<MeasuredMeanSediment> &vMms)
{
    QStandardItemModel *pModel = new QStandardItemModel(0, 4, parent);

    pModel->setHorizontalHeaderLabels(QStringList()
                                      << QObject::tr("站点")
                                      << QObject::tr("时间")
                                      << QObject::tr("单沙")
                                      << QObject::tr("断沙")
                                      );
    for (auto mms: vMms)
    {
        addInModel(pModel, mms);
    }
    return pModel;
}


MeasuredMeanSedimentSortFilterProxyModel::MeasuredMeanSedimentSortFilterProxyModel(QObject *parent)
{

}
