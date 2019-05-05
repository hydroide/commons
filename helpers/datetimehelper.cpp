#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "datetimehelper.h"

QDateTime DateTimeHelper::fromShortFormat(const QString &qstr, int year)
{
    // str like "010108.20" represents January 1st 08:20
    // so the string needs to be splitted by the dot.
    // note that "010124.00" is "010200.00" actually
    // and "123124.00" represents the start of next year

    QDateTime qdt;
    string str = qstr.toStdString();
    QStringList qstrList = qstr.split(".");

    if (qstrList.size() > 0)
    {
        if (qstrList[0].size() == 5)
        {
            str = QString("0" + qstr).toStdString();
        }
    }

    string strMM = str.substr(0,2);
    int intMM{0};

    istringstream (strMM) >> intMM;

    string strDD = str.substr(2,2);
    int intDD{0};
    istringstream(strDD) >> intDD;

    qdt.setDate(QDate(year, intMM, intDD));

    string strHH = str.substr(4,2);
    int intHH{0};
    istringstream(strHH) >> intHH;

    int intmm{0};
    if (qstrList.size() > 1)
    {
        string strmm = qstrList[1].toStdString();
        istringstream(strmm) >> intmm;
    }

    qdt.setTime(QTime(intHH, intmm));
    if (intHH == 24)
    {
        qdt = qdt.addDays(1);
    }
    return qdt;
}

QString DateTimeHelper::toShortFormat(const QDateTime &qdt)
{
    return qdt.toString("MMddhh.mm");
}

QTime DateTimeHelper::fromMMSS(const QString &qstr)
{
    if (qstr.length() == 3)
    {
        return QTime(qstr.left(1).toInt(), qstr.right(2).toInt());
    }
    else if (qstr.length() == 4)
    {
        return QTime(qstr.left(2).toInt(), qstr.right(2).toInt());
    }
    return QTime(); // 默认返回0点
}

QTime DateTimeHelper::fromMdotSS(const QString &qstr)
{
    auto list = qstr.split(".");
    if (list.count() > 1)
    {
        return QTime(list[0].toInt(), list[1].toInt());
    }
    return QTime(); // 默认返回0点
}

QDate DateTimeHelper::fromMMDD(const QString &qstr, int year)
{
    if (qstr.length() == 3)
    {
        return QDate(year, qstr.left(1).toInt(), qstr.right(2).toInt());
    }
    else if (qstr.length() == 4)
    {
        return QDate(year, qstr.left(2).toInt(), qstr.right(2).toInt());
    }
    return QDate(year, 1, 1); // 默认返回1月1日
}

QDateTime
DateTimeHelper::averageDT(const QDateTime &startDT, const QDateTime &endDT)
{
    return startDT.addMSecs(
                (endDT.toMSecsSinceEpoch() - startDT.toMSecsSinceEpoch())/2);
}

bool DateTimeHelper::sameYear(const QDateTime &dt1, const QDateTime &dt2)
{
    auto d1 = dt1.date();
    auto d2 = dt2.date();

    auto t2 = dt2.time();

    auto y1 = d1.year();
    auto y2 = d2.year();

    if (y1 == y2)
    {
        return true;
    }
    return y2 == y1 + 1 && d2.month() == 1 && d2.day() == 1 &&
            t2 == QTime(0, 0);
}

bool DateTimeHelper::sameYearMonth(const QDateTime &dt1, const QDateTime &dt2)
{
    auto d1 = dt1.date();
    auto d2 = dt2.date();

    auto t2 = dt2.time();

    auto y1 = d1.year();
    auto y2 = d2.year();

    auto m1 = d1.month();
    auto m2 = d2.month();

    auto d3 = d1.addMonths(1);

    if (y1 == y2 && m1 == m2)
    {
        return true;
    }
    return y2 == d3.year() && m2 == d3.month() && d2.day() == 1 &&
            t2 == QTime(0, 0);
}
