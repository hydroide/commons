#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include <QtCore>

#include "qvariantserializationdefs.h"

template<class O = QObject, class P = QObject>
class ObjectFactory
{
public:
    template<typename T>
    static void registerClass()
    {
        constructors().insert(T::staticMetaObject.className(),
                              &constructorHelper<T>);
    }

    static O *createObject(const QByteArray& className,
                           P* parent = nullptr)
    {
        auto constructor = constructors().value(className);
        if (constructor == nullptr)
        {
            return nullptr;
        }
        return (*constructor)(parent);
    }

private:
    typedef O *(*Constructor)(P* parent);

    template<typename T>
    static O *constructorHelper(P *parent)
    {
        return new T(parent);
    }

    static QHash<QByteArray, Constructor> &constructors()
    {
        static QHash<QByteArray, Constructor> instance;
        return instance;
    }
};

#endif // OBJECTFACTORY_H
