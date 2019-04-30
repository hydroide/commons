#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "hourcanvassettings.h"

#include "../modules/qvariantserializationdefs.h"

HourCanvasSettings::HourCanvasSettings()
//    :
//      _unitLineColor(HOUR_CANVAS_DEFAULT_COLOR),
//      _horizontalTenthLineColor(HOUR_CANVAS_DEFAULT_COLOR),
//      _horizontalFiftiethLineColor(HOUR_CANVAS_DEFAULT_COLOR),
//      _verticalTwelfthLineColor(HOUR_CANVAS_DEFAULT_COLOR),
//      _verticalTwentyForthLineColor(HOUR_CANVAS_DEFAULT_COLOR)
{

}

bool
HourCanvasSettings::drawUnitLine() const
{
    return _drawUnitLine;
}

void
HourCanvasSettings::setDrawUnitLine(bool value)
{
    _drawUnitLine = value;
}


bool
HourCanvasSettings::drawHorizontalTenthLine() const
{
    return _drawHorizontalTenthLine;
}

void
HourCanvasSettings::setDrawHorizontalTenthLine(bool value)
{
    _drawHorizontalTenthLine = value;
}


bool
HourCanvasSettings::drawHorizontalFiftiethLine() const
{
    return _drawHorizontalFiftiethLine;
}

void
HourCanvasSettings::setDrawHorizontalFiftiethLine(bool value)
{
    _drawHorizontalFiftiethLine = value;
}


bool
HourCanvasSettings::drawVerticalTwelfthLine() const
{
    return _drawVerticalTwelfthLine;
}

void
HourCanvasSettings::setDrawVerticalTwelfthLine(bool value)
{
    _drawVerticalTwelfthLine = value;
}


bool
HourCanvasSettings::drawVerticalTwentyForthLine() const
{
    return _drawVerticalTwentyForthLine;
}

void
HourCanvasSettings::setDrawVerticalTwentyForthLine(bool value)
{
    _drawVerticalTwentyForthLine = value;
}


qreal
HourCanvasSettings::unitLineWidth() const
{
    return _unitLineWidth;
}

void
HourCanvasSettings::setUnitLineWidth(const qreal &value)
{
    _unitLineWidth = value;
}


qreal
HourCanvasSettings::horizontalTenthLineWidth() const
{
    return _horizontalTenthLineWidth;
}

void
HourCanvasSettings::setHorizontalTenthLineWidth(const qreal &value)
{
    _horizontalTenthLineWidth = value;
}


qreal
HourCanvasSettings::horizontalFiftiethLineWidth() const
{
    return _horizontalFiftiethLineWidth;
}

void
HourCanvasSettings::setHorizontalFiftiethLineWidth(const qreal &value)
{
    _horizontalFiftiethLineWidth = value;
}


qreal
HourCanvasSettings::verticalTwelfthLineWidth() const
{
    return _verticalTwelfthLineWidth;
}

void
HourCanvasSettings::setVerticalTwelfthLineWidth(const qreal &value)
{
    _verticalTwelfthLineWidth = value;
}


qreal
HourCanvasSettings::verticalTwentyForthLineWidth() const
{
    return _verticalTwentyForthLineWidth;
}

void
HourCanvasSettings::setVerticalTwentyForthLineWidth(const qreal &value)
{
    _verticalTwentyForthLineWidth = value;
}


QColor
HourCanvasSettings::unitLineColor() const
{
    return _unitLineColor;
}

void
HourCanvasSettings::setUnitLineColor(const QColor &value)
{
    _unitLineColor = value;
}


QColor
HourCanvasSettings::horizontalTenthLineColor() const
{
    return _horizontalTenthLineColor;
}

void
HourCanvasSettings::setHorizontalTenthLineColor(const QColor &value)
{
    _horizontalTenthLineColor = value;
}


QColor
HourCanvasSettings::horizontalFiftiethLineColor() const
{
    return _horizontalFiftiethLineColor;
}

void
HourCanvasSettings::setHorizontalFiftiethLineColor(const QColor &value)
{
    _horizontalFiftiethLineColor = value;
}


QColor
HourCanvasSettings::verticalTwelfthLineColor() const
{
    return _verticalTwelfthLineColor;
}

void
HourCanvasSettings::setVerticalTwelfthLineColor(const QColor &value)
{
    _verticalTwelfthLineColor = value;
}


QColor
HourCanvasSettings::verticalTwentyForthLineColor() const
{
    return _verticalTwentyForthLineColor;
}

void
HourCanvasSettings::setVerticalTwentyForthLineColor(const QColor &value)
{
    _verticalTwentyForthLineColor = value;
}

bool HourCanvasSettings::loadFromSettings(QSettings *settings)
{
    if (settings->childGroups().contains("HourCanvasSettings"))
    {
        settings->beginGroup("HourCanvasSettings");
        settings->value("drawUnitLine") >> _drawUnitLine;
        settings->value("drawHorizontalTenthLine") >> _drawHorizontalTenthLine;
        settings->value("drawHorizontalFiftiethLine") >> _drawHorizontalFiftiethLine;
        settings->value("drawVerticalTwelfthLine") >> _drawVerticalTwelfthLine;
        settings->value("drawVerticalTwentyForthLine") >> _drawVerticalTwentyForthLine;

        settings->value("unitLineWidth") >> _unitLineWidth;
        settings->value("horizontalTenthLineWidth") >> _horizontalTenthLineWidth;
        settings->value("horizontalFiftiethLineWidth") >> _horizontalFiftiethLineWidth;
        settings->value("verticalTwelfthLineWidth") >> _verticalTwelfthLineWidth;
        settings->value("verticalTwentyForthLineWidth") >> _verticalTwentyForthLineWidth;

        settings->value("unitLineColor") >> _unitLineColor;
        settings->value("horizontalTenthLineColor") >> _horizontalTenthLineColor;
        settings->value("horizontalFiftiethLineColor") >> _horizontalFiftiethLineColor;
        settings->value("verticalTwelfthLineColor") >> _verticalTwelfthLineColor;
        settings->value("verticalTwentyForthLineColor") >> _verticalTwentyForthLineColor;
        settings->endGroup();
        return true;
    }
    return false;
}

void HourCanvasSettings::saveToSettings(QSettings *settings)
{
    settings->beginGroup("HourCanvasSettings");
    settings->setValue("drawUnitLine", _drawUnitLine);
    settings->setValue("drawHorizontalTenthLine", _drawHorizontalTenthLine);
    settings->setValue("drawHorizontalFiftiethLine", _drawHorizontalFiftiethLine);
    settings->setValue("drawVerticalTwelfthLine", _drawVerticalTwelfthLine);
    settings->setValue("drawVerticalTwentyForthLine", _drawVerticalTwentyForthLine);

    settings->setValue("unitLineWidth", _unitLineWidth);
    settings->setValue("horizontalTenthLineWidth", _horizontalTenthLineWidth);
    settings->setValue("horizontalFiftiethLineWidth", _horizontalFiftiethLineWidth);
    settings->setValue("verticalTwelfthLineWidth", _verticalTwelfthLineWidth);
    settings->setValue("verticalTwentyForthLineWidth", _verticalTwentyForthLineWidth);

    settings->setValue("unitLineColor", _unitLineColor);
    settings->setValue("horizontalTenthLineColor", _horizontalTenthLineColor);
    settings->setValue("horizontalFiftiethLineColor", _horizontalFiftiethLineColor);
    settings->setValue("verticalTwelfthLineColor", _verticalTwelfthLineColor);
    settings->setValue("verticalTwentyForthLineColor", _verticalTwentyForthLineColor);
    settings->endGroup();
}


QDataStream &operator <<(QDataStream &stream, const HourCanvasSettings &context)
{
    return stream << context._drawUnitLine
                  << context._drawHorizontalTenthLine
                  << context._drawHorizontalFiftiethLine
                  << context._drawVerticalTwelfthLine
                  << context._drawVerticalTwentyForthLine

                  << context._unitLineWidth
                  << context._horizontalTenthLineWidth
                  << context._horizontalFiftiethLineWidth
                  << context._verticalTwelfthLineWidth
                  << context._verticalTwentyForthLineWidth

                  << context._unitLineColor
                  << context._horizontalTenthLineColor
                  << context._horizontalFiftiethLineColor
                  << context._verticalTwelfthLineColor
                  << context._verticalTwentyForthLineColor;
}


QDataStream &operator >>(QDataStream &stream, HourCanvasSettings &context)
{
    return stream >> context._drawUnitLine
                  >> context._drawHorizontalTenthLine
                  >> context._drawHorizontalFiftiethLine
                  >> context._drawVerticalTwelfthLine
                  >> context._drawVerticalTwentyForthLine

                  >> context._unitLineWidth
                  >> context._horizontalTenthLineWidth
                  >> context._horizontalFiftiethLineWidth
                  >> context._verticalTwelfthLineWidth
                  >> context._verticalTwentyForthLineWidth

                  >> context._unitLineColor
                  >> context._horizontalTenthLineColor
                  >> context._horizontalFiftiethLineColor
                  >> context._verticalTwelfthLineColor
                  >> context._verticalTwentyForthLineColor;
}

void operator <<(QVariant &data, const HourCanvasSettings &context)
{
    QVariantMap map;
    map["drawUnitLine"] << context._drawUnitLine;
    map["drawHorizontalTenthLine"] << context._drawHorizontalTenthLine;
    map["drawHorizontalFiftiethLine"] << context._drawHorizontalFiftiethLine;
    map["drawVerticalTwelfthLine"] << context._drawVerticalTwelfthLine;
    map["drawVerticalTwentyForthLine"] << context._drawVerticalTwentyForthLine;

    map["unitLineWidth"] << context._unitLineWidth;
    map["horizontalTenthLineWidth"] << context._horizontalTenthLineWidth;
    map["horizontalFiftiethLineWidth"] << context._horizontalFiftiethLineWidth;
    map["verticalTwelfthLineWidth"] << context._verticalTwelfthLineWidth;
    map["verticalTwentyForthLineWidth"] << context._verticalTwentyForthLineWidth;

    map["unitLineColor"] << context._unitLineColor;
    map["horizontalTenthLineColor"] << context._horizontalTenthLineColor;
    map["horizontalFiftiethLineColor"] << context._horizontalFiftiethLineColor;
    map["verticalTwelfthLineColor"] << context._verticalTwelfthLineColor;
    map["verticalTwentyForthLineColor"] << context._verticalTwentyForthLineColor;
    data = map;
}

void operator >>(const QVariant &data, HourCanvasSettings &context)
{
    auto map = QJsonDocument::fromVariant(data).object().toVariantMap();
    map["drawUnitLine"] >> context._drawUnitLine;
    map["drawHorizontalTenthLine"] >> context._drawHorizontalTenthLine;
    map["drawHorizontalFiftiethLine"] >> context._drawHorizontalFiftiethLine;
    map["drawVerticalTwelfthLine"] >> context._drawVerticalTwelfthLine;
    map["drawVerticalTwentyForthLine"] >> context._drawVerticalTwentyForthLine;

    map["unitLineWidth"] >> context._unitLineWidth;
    map["horizontalTenthLineWidth"] >> context._horizontalTenthLineWidth;
    map["horizontalFiftiethLineWidth"] >> context._horizontalFiftiethLineWidth;
    map["verticalTwelfthLineWidth"] >> context._verticalTwelfthLineWidth;
    map["verticalTwentyForthLineWidth"] >> context._verticalTwentyForthLineWidth;

    map["unitLineColor"] >> context._unitLineColor;
    map["horizontalTenthLineColor"] >> context._horizontalTenthLineColor;
    map["horizontalFiftiethLineColor"] >> context._horizontalFiftiethLineColor;
    map["verticalTwelfthLineColor"] >> context._verticalTwelfthLineColor;
    map["verticalTwentyForthLineColor"] >> context._verticalTwentyForthLineColor;
}
