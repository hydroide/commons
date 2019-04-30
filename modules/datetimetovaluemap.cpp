#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "datetimetovaluemap.h"

#include <QtCore>
#include "../globaldefines.h"
#include "qvariantserializationdefs.h"

DateTimeToValueMap::DateTimeToValueMap()
{

}

void DateTimeToValueMap::setData(QMap<QDateTime, QString> data)
{
    this->_data = data;
}


void DateTimeToValueMap::clear()
{
    return this->_data.clear();
}

QString &DateTimeToValueMap::operator[](const QDateTime &key)
{
    return this->_data[key];
}

const QString DateTimeToValueMap::operator[](const QDateTime &key) const
{
    return this->_data[key];
}

QMap<QDateTime, QString> DateTimeToValueMap::data() const
{
    return _data;
}

//QDataStream &operator <<(QDataStream &stream, const DateTimeToValueMap &context)
//{
//    QJsonObject object;

//    QJsonArray array;

//    for (auto key : context._data.keys())
//    {
//        auto value = context._data[key];
//        QJsonObject record;
//        record["k"] = key.toString(PROCESS_DATETIME_FORMAT);
//        record["v"] = value;
//        array.append(record);
//    }

//    object["array"] = array;

//    QJsonDocument document(object);

//    return stream << document.toJson();
//}

//QDataStream &operator >>(QDataStream &stream, DateTimeToValueMap &context)
//{
//    context.clear();

//    QByteArray data;
//    stream >> data;

//    auto document = QJsonDocument::fromJson(data);

//    auto object = document.object();
//    auto array = object["array"].toArray();

//    for (auto ref: array)
//    {
//        auto record = ref.toObject();
//        auto key = QDateTime::fromString(record["k"].toString(), PROCESS_DATETIME_FORMAT);
//        context._data.insert(key, record["v"].toString());
//    }
//}

void operator <<(QVariant &data, const DateTimeToValueMap &context)
{
    QJsonArray array;

    for (auto key : context._data.keys())
    {
        auto value = context._data[key];
        QVariantMap record;
        record["d"] << key;
        record["v"] << value;
        array.append(QJsonObject::fromVariantMap(record));
    }

    data = QJsonDocument(array).toVariant();
}

void operator >>(const QVariant &data, DateTimeToValueMap &context)
{
    context.clear();

    auto array = QJsonDocument::fromVariant(data).array();

    for (auto ref: array)
    {
        auto record = ref.toObject().toVariantMap();
        QDateTime key;
        QString value;
        record["d"] >> key;
        record["v"] >> value;
        context._data.insert(key, value);
    }
}
