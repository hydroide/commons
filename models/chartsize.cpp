#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "chartsize.h"

bool ChartSize::operator ==(const ChartSize &ref) const
{
    return this->type() == ref.type()
            && this->name() == ref.name()
            && this->unit() == ref.unit()
            && this->horizontalUnitCounts() == ref.horizontalUnitCounts()
            && this->verticalUnitCounts() == ref.verticalUnitCounts()
            && this->cellWidth() == ref.cellWidth()
            && this->cellHeight() == ref.cellHeight()
            && this->borderLeft() == ref.borderLeft()
            && this->borderRight() == ref.borderRight()
            && this->borderTop() == ref.borderTop()
            && this->borderBottom() == ref.borderBottom();
}

qreal ChartSize::getContentWidth() const
{
    return _horizontalUnitCounts * _cellWidth;
}

qreal ChartSize::getContentHeight() const
{
    return _verticalUnitCounts * _cellHeight;
}

qreal ChartSize::getPaperWidth() const
{
    return _borderLeft + getContentWidth() + _borderRight;
}

qreal ChartSize::getPaperHeight() const
{
    return _borderTop + getContentHeight() + _borderBottom;
}

QMarginsF ChartSize::margins() const
{
    return QMarginsF(borderLeft(),
                     borderTop(),
                     borderRight(),
                     borderBottom());
}

QSizeF ChartSize::paperSize() const
{
    return QSizeF(getPaperWidth(), getPaperHeight());
}

QSizeF ChartSize::sizeInUnit() const
{
    return QSizeF(getContentWidth(), getContentHeight());
}

QString ChartSize::name() const
{
    return _name;
}

void ChartSize::setName(const QString &name)
{
    _name = name;
}

QString ChartSize::unit() const
{
    return _unit;
}

void ChartSize::setUnit(const QString &unit)
{
    _unit = unit;
}

int ChartSize::horizontalUnitCounts() const
{
    return _horizontalUnitCounts;
}

void ChartSize::setHorizontalUnitCounts(int horizontalUnitCounts)
{
    _horizontalUnitCounts = horizontalUnitCounts;
}

int ChartSize::verticalUnitCounts() const
{
    return _verticalUnitCounts;
}

void ChartSize::setVerticalUnitCounts(int verticalUnitCounts)
{
    _verticalUnitCounts = verticalUnitCounts;
}

qreal ChartSize::cellWidth() const
{
    return _cellWidth;
}

void ChartSize::setCellWidth(const qreal &cellWidth)
{
    _cellWidth = cellWidth;
}

qreal ChartSize::cellHeight() const
{
    return _cellHeight;
}

void ChartSize::setCellHeight(const qreal &cellHeight)
{
    _cellHeight = cellHeight;
}

qreal ChartSize::borderLeft() const
{
    return _borderLeft;
}

void ChartSize::setBorderLeft(const qreal &borderLeft)
{
    _borderLeft = borderLeft;
}

qreal ChartSize::borderRight() const
{
    return _borderRight;
}

void ChartSize::setBorderRight(const qreal &borderRight)
{
    _borderRight = borderRight;
}

qreal ChartSize::borderTop() const
{
    return _borderTop;
}

void ChartSize::setBorderTop(const qreal &borderTop)
{
    _borderTop = borderTop;
}

qreal ChartSize::borderBottom() const
{
    return _borderBottom;
}

void ChartSize::setBorderBottom(const qreal &borderBottom)
{
    _borderBottom = borderBottom;
}

QString ChartSize::type() const
{
    return _type;
}

void ChartSize::setType(const QString &type)
{
    _type = type;
}


void ChartSize::read(const QJsonObject &json)
{
    _type = json["type"].toString();
    _name = json["name"].toString();
    _unit = json["unit"].toString();
    _horizontalUnitCounts = json["horizontalUnitCounts"].toInt();
    _verticalUnitCounts = json["verticalUnitCounts"].toInt();
    _cellWidth = json["cellWidth"].toDouble();
    _cellHeight = json["cellHeight"].toDouble();
    _borderLeft = json["borderLeft"].toDouble();
    _borderRight = json["borderRight"].toDouble();
    _borderTop = json["borderTop"].toDouble();
    _borderBottom = json["borderBottom"].toDouble();
}

void ChartSize::write(QJsonObject &json) const
{
    json["type"] = _type;
    json["name"] = _name;
    json["unit"] = _unit;
    json["horizontalUnitCounts"] = _horizontalUnitCounts;
    json["verticalUnitCounts"] = _verticalUnitCounts;
    json["cellWidth"] = _cellWidth;
    json["cellHeight"] = _cellHeight;
    json["borderLeft"] = _borderLeft;
    json["borderRight"] = _borderRight;
    json["borderTop"] = _borderTop;
    json["borderBottom"] = _borderBottom;
}


QDataStream &operator<<(QDataStream &stream, const ChartSize &context)
{
    return stream << context._type
                  << context._name
                  << context._unit
                  << context._horizontalUnitCounts
                  << context._verticalUnitCounts
                  << context._cellWidth
                  << context._cellHeight
                  << context._borderLeft
                  << context._borderTop
                  << context._borderRight
                  << context._borderBottom;
}


QDataStream &operator>>(QDataStream &stream, ChartSize &context)
{
    return stream >> context._type
                  >> context._name
                  >> context._unit
                  >> context._horizontalUnitCounts
                  >> context._verticalUnitCounts
                  >> context._cellWidth
                  >> context._cellHeight
                  >> context._borderLeft
                  >> context._borderTop
                  >> context._borderRight
                  >> context._borderBottom;
}
