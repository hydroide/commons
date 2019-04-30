#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef HOURCANVASSETTINGS_H
#define HOURCANVASSETTINGS_H

#include "globaldefines.h"

class HourCanvasSettings
{
    Q_GADGET
public:
    HourCanvasSettings();

    bool drawUnitLine() const;
    void setDrawUnitLine(bool value);

    bool drawHorizontalTenthLine() const;
    void setDrawHorizontalTenthLine(bool value);

    bool drawHorizontalFiftiethLine() const;
    void setDrawHorizontalFiftiethLine(bool value);

    bool drawVerticalTwelfthLine() const;
    void setDrawVerticalTwelfthLine(bool value);

    bool drawVerticalTwentyForthLine() const;
    void setDrawVerticalTwentyForthLine(bool value);

    qreal unitLineWidth() const;
    void setUnitLineWidth(const qreal &value);

    qreal horizontalTenthLineWidth() const;
    void setHorizontalTenthLineWidth(const qreal &value);

    qreal horizontalFiftiethLineWidth() const;
    void setHorizontalFiftiethLineWidth(const qreal &value);

    qreal verticalTwelfthLineWidth() const;
    void setVerticalTwelfthLineWidth(const qreal &value);

    qreal verticalTwentyForthLineWidth() const;
    void setVerticalTwentyForthLineWidth(const qreal &value);

    QColor unitLineColor() const;
    void setUnitLineColor(const QColor &value);

    QColor horizontalTenthLineColor() const;
    void setHorizontalTenthLineColor(const QColor &value);

    QColor horizontalFiftiethLineColor() const;
    void setHorizontalFiftiethLineColor(const QColor &value);

    QColor verticalTwelfthLineColor() const;
    void setVerticalTwelfthLineColor(const QColor &value);

    QColor verticalTwentyForthLineColor() const;
    void setVerticalTwentyForthLineColor(const QColor &value);

    bool loadFromSettings(QSettings *settings);
    void saveToSettings(QSettings *settings);

    friend QDataStream &operator <<(QDataStream &, const HourCanvasSettings &);
    friend QDataStream &operator >>(QDataStream &, HourCanvasSettings &);

    friend void operator <<(QVariant &data, const HourCanvasSettings &context);
    friend void operator >>(const QVariant &data, HourCanvasSettings &context);

private:
    bool _drawUnitLine = true;
    bool _drawHorizontalTenthLine = true;
    bool _drawHorizontalFiftiethLine = true;
    bool _drawVerticalTwelfthLine = true;
    bool _drawVerticalTwentyForthLine = true;

    qreal _unitLineWidth = 0.1f;
    qreal _horizontalTenthLineWidth = 0.25f;
    qreal _horizontalFiftiethLineWidth = 0.4f;
    qreal _verticalTwelfthLineWidth = 0.25f;
    qreal _verticalTwentyForthLineWidth = 0.4f;

    QColor _unitLineColor{HOUR_CANVAS_DEFAULT_COLOR};
    QColor _horizontalTenthLineColor{HOUR_CANVAS_DEFAULT_COLOR};
    QColor _horizontalFiftiethLineColor{HOUR_CANVAS_DEFAULT_COLOR};
    QColor _verticalTwelfthLineColor{HOUR_CANVAS_DEFAULT_COLOR};
    QColor _verticalTwentyForthLineColor{HOUR_CANVAS_DEFAULT_COLOR};
};

Q_DECLARE_METATYPE(HourCanvasSettings)

QDataStream &operator <<(QDataStream &stream, const HourCanvasSettings &context);
QDataStream &operator >>(QDataStream &stream, HourCanvasSettings &context);

void operator <<(QVariant &data, const HourCanvasSettings &context);
void operator >>(const QVariant &data, HourCanvasSettings &context);

#endif // HOURCANVASSETTINGS_H
