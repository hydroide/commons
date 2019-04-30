#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef DATETIMETOVALUEMAP_H
#define DATETIMETOVALUEMAP_H

#include <QtCore>

class DateTimeToValueMap
{
public:
    DateTimeToValueMap();

    QMap<QDateTime, QString> data() const;
    void setData(QMap<QDateTime, QString> data);

    void clear();
    QString &operator[](const QDateTime &key);
    const QString operator[](const QDateTime &key) const;

    friend void operator <<(QVariant &data, const DateTimeToValueMap &context);
    friend void operator >>(const QVariant &data, DateTimeToValueMap &context);

//    friend QDataStream &operator <<(QDataStream &stream, const DateTimeToValueMap &context);
//    friend QDataStream &operator >>(QDataStream &stream, DateTimeToValueMap &context);

private:
    QMap<QDateTime, QString> _data;

};

Q_DECLARE_METATYPE(DateTimeToValueMap)

void operator <<(QVariant &data, const DateTimeToValueMap &context);
void operator >>(const QVariant &data, DateTimeToValueMap &context);

#endif // DATETIMETOVALUEMAP_H
