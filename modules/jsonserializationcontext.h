#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef JSONSERIALIZATIONCONTEXT_H
#define JSONSERIALIZATIONCONTEXT_H

#include <QtCore>

#include <boost/any.hpp>

#include "objectfactory.h"

template<class O = QObject, class P = QObject>
class JsonSerializationContext;

template<class O = QObject, class P = QObject>
class JsonSerializable
{
public:
    virtual void serialize(QVariantMap &data,
                           JsonSerializationContext<O, P> *context) const = 0;

    virtual void deserialize(const QVariantMap &data,
                             JsonSerializationContext<O, P> *context) = 0;
};

template<class O, class P>
class JsonSerializationContext
{
public:
    template<typename T>
    QVariant serialize(T *p)
    {
        if (p == nullptr)
        {
            return QVariant();
        }
        O *po = static_cast<O *>(p);
        auto it = _map.find(p);

        if (it != _map.end())
        {
            return QVariant(it.value());
        }

        int i = _records.count();

        Record record;
        record._po = po;
        record._type = po->metaObject()->className();
        _records.append(record);

        _map.insert(po, i);

        auto *is = dynamic_cast<JsonSerializable<O, P> *>(p);
        if (is)
        {
            QVariantMap data;
            is->serialize(data, this);
            _records[i]._data = data;
        }
        return QVariant(i);
    }

    template<typename T>
    T *deserialize(const QVariant &v)
    {
        if (!v.isValid())
        {
            return nullptr;
        }

        int i = v.toInt();

        auto &r = _records[i];
        if (r._po != nullptr)
        {
            return static_cast<T *>(r._po);
        }

        O *po = ObjectFactory<O, P>::createObject(r._type);
        if (po)
        {
            r._po = po;
            _map.insert(po, i);

            auto *p = static_cast<T *>(po);
            if (p)
            {
                auto *is = dynamic_cast<JsonSerializable<O, P> *>(p);

                if (is)
                {
                    is->deserialize(r._data, this);
                }
            }

            return p;
        }
        return nullptr;
    }

    friend QDataStream &operator<<(QDataStream &stream,
                                   const JsonSerializationContext<O, P> &context)
    {
        return stream << context._records << context._sharedMap;
    }

    friend QDataStream &operator>>(QDataStream &stream,
                                   JsonSerializationContext<O, P> &context)
    {
        return stream >> context._records >> context._sharedMap;
    }

    QJsonObject toObject()
    {
        QJsonObject obj;
        QJsonArray array;
        for (auto record: _records)
        {
            array.append(record.toObject());
        }
        obj.insert("list", array);
        obj.insert("shared", QJsonObject::fromVariantMap(_sharedMap));
        return obj;
    }

    static JsonSerializationContext fromObject(const QJsonObject &obj)
    {
        JsonSerializationContext context;
        auto list = obj["list"].toArray();
        for (auto obj2: list)
        {
            context._records.append(Record::fromObject(obj2.toObject()));
        }
        context._sharedMap = obj["shared"].toObject().toVariantMap();
        return context;
    }

    struct Record
    {
        O* _po{nullptr};
        QByteArray _type;
        QVariantMap _data;

        QJsonObject toObject()
        {
            QJsonObject object;
            auto data = QJsonObject::fromVariantMap(_data);
            object[QString(_type)] = data;

            return object;
        }
        static Record fromObject(const QJsonObject &obj)
        {
            Record record;
            record._type = obj.keys().first().toLatin1();
            record._data = obj.value(record._type).toObject().toVariantMap();
            return record;
        }

        friend QDataStream &operator<<(QDataStream &stream,
                                       const Record& context)
        {
            return stream << context._type << context._data;
        }

        friend QDataStream &operator>>(QDataStream &stream,
                                       Record& context)
        {
            return stream >> context._type >> context._data;
        }
    };

    void setSharedData(const QString &key, const QVariant &value)
    {
        _sharedMap[key] = value;
    }

    bool sharedDataExists(const QString &key)
    {
        return _sharedMap.contains(key);
    }

    QVariant getSharedData(const QString &key)
    {
        return _sharedMap[key];
    }

    bool sharedPtrExists(const QString &key)
    {
        return _uuidToSharedPtr.contains(key);
    }

    boost::any getSharedPtr(const QString &key)
    {
        return _uuidToSharedPtr[key];
    }

    void addSharedPtr(const QString &key, const boost::any &any)
    {
        _uuidToSharedPtr[key] = any;
    }


private:
    QList<Record> _records;
    QHash<O *, int> _map;
    QHash<QString, boost::any> _uuidToSharedPtr;
    QVariantMap _sharedMap;
};

#endif // JSONSERIALIZATIONCONTEXT_H
