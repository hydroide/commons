#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef CANVASSIZE_H
#define CANVASSIZE_H

#include <QtCore>
#include "ijsonserializable.h"

class CanvasSize : public IJsonSerializable
{
public:
    CanvasSize();
    CanvasSize(const QString &name, const QSizeF &size);

    QString _name;
    QSizeF _size;


    // IJsonSerializable interface
public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
};

#endif // CANVASSIZE_H
