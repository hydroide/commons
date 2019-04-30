#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef DATETIMEHELPER_H
#define DATETIMEHELPER_H

#include <QtCore>
#include <iostream>
#include <sstream>
using namespace std;


class DateTimeHelper
{
public:
    DateTimeHelper() = delete;

    static QDateTime fromShortFormat(const QString &qstr, int year);

    static QString toShortFormat(const QDateTime& qdt);

    static QTime fromMMSS(const QString &);
    static QTime fromMdotSS(const QString &qstr);

    static QDate fromMMDD(const QString &, int year);

    static QDateTime averageDT(const QDateTime &startDT,
                               const QDateTime &endDT);

    static bool sameYear(const QDateTime &dt1, const QDateTime &dt2);

    static bool sameMonth(const QDateTime &dt1, const QDateTime &dt2);
};

#endif // DATETIMEHELPER_H
