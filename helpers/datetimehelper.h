#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef DATETIMEHELPER_H
#define DATETIMEHELPER_H

#include <QtCore>
#include <iostream>
#include <sstream>
using namespace std;

/**
 * @brief The DateTimeHelper class 日期时间辅助类
 */
class DateTimeHelper
{
public:
    DateTimeHelper() = delete;

    /**
     * @brief fromShortFormat 从短格式转为 QDateTime 日期时间
     * @param qstr 形如010108.20
     * @param year 指定年份
     * @return 完整日期时间
     */
    static QDateTime fromShortFormat(const QString &qstr, int year);

    /**
     * @brief toShortFormat 从QDateTime转为短格式时间
     * @param qdt 完整时间
     * @return 短格式日期时间
     */
    static QString toShortFormat(const QDateTime& qdt);

    /**
     * @brief fromMMSS 从MMSS转为 QTime 时间
     * @return 时间
     */
    static QTime fromMMSS(const QString &);

    /**
     * @brief fromMdotSS 从MM.SS转为 QTime 时间
     * @param qstr
     * @return 时间
     */
    static QTime fromMdotSS(const QString &qstr);

    /**
     * @brief fromMMDD 从MMDD转为 QDate 完整日期
     * @param year 年份
     * @return 完整日期
     */
    static QDate fromMMDD(const QString &, int year);

    /**
     * @brief averageDT 计算平均日期时间
     * @param startDT 开始时间
     * @param endDT 结束时间
     * @return 平均时间
     */
    static QDateTime averageDT(const QDateTime &startDT,
                               const QDateTime &endDT);

    /**
     * @brief sameYear 判断两个日期是否同年
     * @param dt1 一个日期
     * @param dt2 另一个日期
     * @return 是/否
     */
    static bool sameYear(const QDateTime &dt1, const QDateTime &dt2);

    /**
     * @brief sameMonth 判断两个日期是否同年同月
     * @param dt1 一个日期
     * @param dt2 另一个日期
     * @return 是/否
     */
    static bool sameYearMonth(const QDateTime &dt1, const QDateTime &dt2);
};

#endif // DATETIMEHELPER_H
