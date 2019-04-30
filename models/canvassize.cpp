#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "canvassize.h"

CanvasSize::CanvasSize()
{

}

CanvasSize::CanvasSize(const QString &name, const QSizeF &size)
{
    _name = name;
    _size = size;
}

void CanvasSize::read(const QJsonObject &json)
{
    _name = json["name"].toString();
    _size.setWidth(json["width"].toDouble());
    _size.setHeight(json["height"].toDouble());
}

void CanvasSize::write(QJsonObject &json) const
{
    json["name"] = _name;
    json["width"] = _size.width();
    json["height"] = _size.height();
}
