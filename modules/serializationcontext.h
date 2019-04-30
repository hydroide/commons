#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SERIALIZATIONCONTEXT_H
#define SERIALIZATIONCONTEXT_H

#include <QtCore>

#include "objectfactory.h"

template<class O = QObject, class P = QObject>
class SerializationContext;

template<class O = QObject, class P = QObject>
class Serializable
{
public:
    virtual void serialize(QVariantMap &data,
                           SerializationContext<O, P> *context) const = 0;

    virtual void deserialize(const QVariantMap &data,
                             SerializationContext<O, P> *context) = 0;
};

template<class O, class P>
class SerializationContext
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

        auto *is = dynamic_cast<Serializable<O, P> *>(p);
        QVariantMap data;
        is->serialize(data, this);

        _records[i]._data = data;
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
                auto *is = dynamic_cast<Serializable<O, P> *>(p);

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
                                   const SerializationContext<O, P> &context)
    {
        return stream << context._records;
    }

    friend QDataStream &operator>>(QDataStream &stream,
                                   SerializationContext<O, P> &context)
    {
        return stream >> context._records;
    }

    struct Record
    {
        O* _po{nullptr};
        QByteArray _type;
        QVariantMap _data;

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

private:
    QList<Record> _records;
    QHash<O *, int> _map;
};

//template<class O = QObject, class P = QObject>
//QDataStream &operator<<(
//        QDataStream &stream, const SerializationContext<O, P> &context)
//{
//    return stream << context._lRecords;
//}

//template<class O = QObject, class P = QObject>
//QDataStream &operator>>(
//        QDataStream &stream, SerializationContext<O, P> &context)
//{
//    return stream >> context._lRecords;
//}

//QDataStream &operator<<(QDataStream &stream,
//                        const SerializationContext::Record &context)
//{
//    return stream << context._type << context._vmData;
//}

//QDataStream &operator>>(QDataStream &stream,
//                        SerializationContext::Record &context)
//{
//    return stream >> context._type >> context._vmData;
//}

#endif // SERIALIZATIONCONTEXT_H
