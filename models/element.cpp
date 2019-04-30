#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "element.h"

Element::Element()
{
    setType("Element");
}

Element::~Element()
{

}

QString Element::type() const
{
    return _type;
}

void Element::setType(const QString &type)
{
    _type = type;
}

QPointF Element::location() const
{
    return _location;
}

void Element::setLocation(const QPointF &location)
{
    _location = location;
}
QSizeF Element::size() const
{
    return _size;
}

void Element::setSize(const QSizeF &size)
{
    _size = size;
}




