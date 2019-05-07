#ifndef DATAPROVIDERINTERFACE_H
#define DATAPROVIDERINTERFACE_H

#include <QtCore>

#include "modules/curvestructs.h"

/**
 * @brief 数据提供器接口，实现该接口，从而向程序提供数据
 */
class DataProviderInterface
{
public:
    virtual ~DataProviderInterface() {}

    /**
     * @brief type 数据提供器类型
     * @return 字符串
     */
    virtual QString type() = 0;

    /**
     * @brief 可提供数据年份列表
     * @return
     */
    virtual QList<int> zqs_process_year_list() { return QList<int>(); }

    /**
     * @brief 可提供站号列表
     * @return
     */
    virtual QStringList zq_process_stcd_list() { return QStringList(); }

    /**
     * @brief 水位系列（原始）
     * @param stcd 站号
     * @param startDateTime 开始时间
     * @param endDateTime 结束时间
     * @return
     */
    virtual QMap<QDateTime, QString> z_series(
            const QString &stcd,
            const QDateTime &startDateTime,
            const QDateTime &endDateTime) { return QMap<QDateTime, QString>(); }

    /**
     * @brief 流量系列（推流）
     * @param stcd 站号
     * @param startDateTime 开始时间
     * @param endDateTime 结束时间
     * @return
     */
    virtual QMap<QDateTime, QString> rq_series(
            const QString &stcd,
            const QDateTime &startDateTime,
            const QDateTime &endDateTime) { return QMap<QDateTime, QString>(); }

    /**
     * @brief 含沙量系列（原始）
     * @param stcd 站号
     * @param startDateTime 开始时间
     * @param endDateTime 结束时间
     * @return
     */
    virtual QMap<QDateTime, QString> s_series(
            const QString &stcd,
            const QDateTime &startDateTime,
            const QDateTime &endDateTime) { return QMap<QDateTime, QString>(); }

    /**
     * @brief 含沙量系列（推沙）
     * @param stcd 站号
     * @param startDateTime 开始时间
     * @param endDateTime 结束时间
     * @return
     */
    virtual QMap<QDateTime, QString> rs_series(
            const QString &stcd,
            const QDateTime &startDateTime,
            const QDateTime &endDateTime) { return QMap<QDateTime, QString>(); }

    /**
     * @brief 实测流量系列
     * @param stcd 站号
     * @param startDateTime 开始时间
     * @param endDateTime 结束时间
     * @return
     */
    virtual QMap<QDateTime, DGMeasuredDischarge> mq_series(
            const QString &stcd,
            const QDateTime &startDateTime,
            const QDateTime &endDateTime) { return QMap<QDateTime, DGMeasuredDischarge>(); }

    /**
     * @brief 实测输沙率系列
     * @param stcd
     * @param startDateTime
     * @param endDateTime
     * @return
     */
    virtual QMap<QDateTime, DGMeasuredSedimentDischarge> msq_series(
            const QString &stcd,
            const QDateTime &startDateTime,
            const QDateTime &endDateTime) { return QMap<QDateTime, DGMeasuredSedimentDischarge>(); }

    /**
     * @brief 水位流量关系曲线
     * @param stcd 站号
     * @param year 年份
     * @param curve_id 线号
     * @return
     */
    virtual RelationCurve zq_curve(
            const QString &stcd, int year, int curve_id) { return RelationCurve(); }

    /**
     * @brief 水位流量关系曲线启用时段
     * @param stcd 站号
     * @param year 年份
     * @return
     */
    virtual QList<DGSDRPeriod> zq_curves_periods(const QString &stcd, int year) { return QList<DGSDRPeriod>(); }

};

#define DataProviderInterface_iid "org.hwsdsw.HydroCurve.DataProviderInterface"

Q_DECLARE_INTERFACE(DataProviderInterface, DataProviderInterface_iid)

typedef std::shared_ptr<DataProviderInterface> SpDataProviderInterface;

#endif // DATAPROVIDERINTERFACE_H
