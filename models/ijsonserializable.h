#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef IJSONSERIALIZABLE_H
#define IJSONSERIALIZABLE_H

#include <QJsonObject>

struct IJsonSerializable
{
    virtual void read(const QJsonObject &json) = 0;
    virtual void write(QJsonObject &json) const = 0;
};

#endif // IJSONSERIALIZABLE_H
