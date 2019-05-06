#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SQUARECANVASSETTINGS_H
#define SQUARECANVASSETTINGS_H

#include "hcglobaldefs.h"

class SquareCanvasSettings
{
    Q_GADGET
public:
    SquareCanvasSettings();


    bool drawUnitLine() const;
    void drawUnitLine(bool value);

    bool drawTenthLine() const;
    void setDrawTenthLine(bool value);

    bool drawFiftiethLine() const;
    void setDrawFiftiethLine(bool value);

    qreal unitLineWidth() const;
    void setUnitLineWidth(const qreal &value);

    qreal tenthLineWidth() const;
    void setTenthLineWidth(const qreal &value);

    qreal fiftiethLineWidth() const;
    void setFiftiethLineWidth(const qreal &value);


    QColor unitLineColor() const;
    void setUnitLineColor(const QColor &value);

    QColor tenthLineColor() const;
    void setTenthLineColor(const QColor &value);

    QColor fiftiethLineColor() const;
    void setFiftiethLineColor(const QColor &value);

    bool loadFromSettings(QSettings *settings);
    void saveToSettings(QSettings *settings);

private:
    bool _drawUnitLine = true;
    bool _drawTenthLine = true;
    bool _drawFiftiethLine = true;

    qreal _unitLineWidth = 0.1f;
    qreal _tenthLineWidth = 0.2f;
    qreal _fiftiethLineWidth = 0.3f;

    QColor _unitLineColor{SQUARE_CANVAS_DEFAULT_COLOR};
    QColor _tenthLineColor{SQUARE_CANVAS_DEFAULT_COLOR};
    QColor _fiftiethLineColor{SQUARE_CANVAS_DEFAULT_COLOR};
};

#endif // SQUARECANVASSETTINGS_H
