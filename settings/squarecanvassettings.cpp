#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "squarecanvassettings.h"

#include "../modules/qvariantserializationdefs.h"

SquareCanvasSettings::SquareCanvasSettings()
//    :
//      _unitLineColor(QColor(Qt::red)),
//      _tenthLineColor(QColor(Qt::red)),
//      _fiftiethLineColor(QColor(Qt::red))
{

}

bool SquareCanvasSettings::drawUnitLine() const
{
    return _drawUnitLine;
}

void SquareCanvasSettings::drawUnitLine(bool value)
{
    _drawUnitLine = value;
}


bool SquareCanvasSettings::drawTenthLine() const
{
    return _drawTenthLine;
}

void SquareCanvasSettings::setDrawTenthLine(bool value)
{
    _drawTenthLine = value;
}


bool SquareCanvasSettings::drawFiftiethLine() const
{
    return _drawFiftiethLine;
}

void SquareCanvasSettings::setDrawFiftiethLine(bool value)
{
    _drawFiftiethLine = value;
}


qreal SquareCanvasSettings::unitLineWidth() const
{
    return _unitLineWidth;
}

void SquareCanvasSettings::setUnitLineWidth(const qreal &value)
{
    _unitLineWidth = value;
}


qreal SquareCanvasSettings::tenthLineWidth() const
{
    return _tenthLineWidth;
}

void SquareCanvasSettings::setTenthLineWidth(const qreal &value)
{
    _tenthLineWidth = value;
}


qreal SquareCanvasSettings::fiftiethLineWidth() const
{
    return _fiftiethLineWidth;
}

void SquareCanvasSettings::setFiftiethLineWidth(const qreal &value)
{
    _fiftiethLineWidth = value;
}
QColor SquareCanvasSettings::unitLineColor() const
{
    return _unitLineColor;
}

void SquareCanvasSettings::setUnitLineColor(const QColor &value)
{
    _unitLineColor = value;
}
QColor SquareCanvasSettings::tenthLineColor() const
{
    return _tenthLineColor;
}

void SquareCanvasSettings::setTenthLineColor(const QColor &value)
{
    _tenthLineColor = value;
}
QColor SquareCanvasSettings::fiftiethLineColor() const
{
    return _fiftiethLineColor;
}

void SquareCanvasSettings::setFiftiethLineColor(const QColor &value)
{
    _fiftiethLineColor = value;
}

bool SquareCanvasSettings::loadFromSettings(QSettings *settings)
{
    if (settings->childGroups().contains("SquareCanvasSettings"))
    {
        settings->beginGroup("SquareCanvasSettings");
        settings->value("drawUnitLine") >> _drawUnitLine;
        settings->value("drawTenthLine") >> _drawTenthLine;
        settings->value("drawFiftiethLine") >> _drawFiftiethLine;

        settings->value("unitLineWidth") >> _unitLineWidth;
        settings->value("tenthLineWidth") >> _tenthLineWidth;
        settings->value("fiftiethLineWidth") >> _fiftiethLineWidth;

        settings->value("unitLineColor") >> _unitLineColor;
        settings->value("tenthLineColor") >> _tenthLineColor;
        settings->value("fiftiethLineColor") >> _fiftiethLineColor;
        settings->endGroup();
        return true;
    }
    return false;
}

void SquareCanvasSettings::saveToSettings(QSettings *settings)
{
    settings->beginGroup("SquareCanvasSettings");
    settings->setValue("drawUnitLine", _drawUnitLine);
    settings->setValue("drawTenthLine", _drawTenthLine);
    settings->setValue("drawFiftiethLine", _drawFiftiethLine);

    settings->setValue("unitLineWidth", _unitLineWidth);
    settings->setValue("tenthLineWidth", _tenthLineWidth);
    settings->setValue("fiftiethLineWidth", _fiftiethLineWidth);

    settings->setValue("unitLineColor", _unitLineColor);
    settings->setValue("tenthLineColor", _tenthLineColor);
    settings->setValue("fiftiethLineColor", _fiftiethLineColor);
    settings->endGroup();
}




