#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef CHARTSIZE_H
#define CHARTSIZE_H

#include <QtCore>
#include "ijsonserializable.h"

class ChartSize : public IJsonSerializable
{
public:
    ChartSize() = default;
    ~ChartSize() = default;
    ChartSize(QString type,
              QString name,
              QString unit,
              int horizontalUnitCounts,
              int verticalUnitCounts,
              qreal cellWidth,
              qreal cellHeight,
              qreal borderLeft,
              qreal borderRight,
              qreal borderTop,
              qreal borderBottom)
        :_type{type},
          _name{name},
          _unit{unit},
          _horizontalUnitCounts{horizontalUnitCounts},
          _verticalUnitCounts{verticalUnitCounts},
          _cellWidth{cellWidth},
          _cellHeight{cellHeight},
          _borderLeft{borderLeft},
          _borderRight{borderRight},
          _borderTop{borderTop},
          _borderBottom{borderBottom} {}

    bool operator == (const ChartSize &ref) const;

    qreal getContentWidth() const;
    qreal getContentHeight() const;

    qreal getPaperWidth() const;
    qreal getPaperHeight() const;

    QMarginsF margins() const;
    QSizeF paperSize() const;
    QSizeF sizeInUnit() const;

    QString type() const;
    void setType(const QString &type);
    QString name() const;
    void setName(const QString &name);
    QString unit() const;
    void setUnit(const QString &unit);
    int horizontalUnitCounts() const;
    void setHorizontalUnitCounts(int horizontalUnitCounts);
    int verticalUnitCounts() const;
    void setVerticalUnitCounts(int verticalUnitCounts);
    qreal cellWidth() const;
    void setCellWidth(const qreal &cellWidth);
    qreal cellHeight() const;
    void setCellHeight(const qreal &cellHeight);
    qreal borderLeft() const;
    void setBorderLeft(const qreal &borderLeft);
    qreal borderRight() const;
    void setBorderRight(const qreal &borderRight);
    qreal borderTop() const;
    void setBorderTop(const qreal &borderTop);
    qreal borderBottom() const;
    void setBorderBottom(const qreal &borderBottom);

    friend QDataStream &operator<<(QDataStream &, const ChartSize &);
    friend QDataStream &operator>>(QDataStream &, ChartSize &);

private:
    /**
     * @brief _type 用于标记只适用于某种类型图的纸张，比如逐时
     */
    QString _type;
    QString _name{QObject::tr("[自定义尺寸]")};
    QString _unit{QObject::tr("mm")};
    int _horizontalUnitCounts{};
    int _verticalUnitCounts{};
    qreal _cellWidth{1.f};
    qreal _cellHeight{1.f};
    qreal _borderLeft{};
    qreal _borderRight{};
    qreal _borderTop{};
    qreal _borderBottom{};


    // IJsonSerializable interface
public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
};

Q_DECLARE_METATYPE(ChartSize)

QDataStream &operator<<(QDataStream &stream, const ChartSize &context);
QDataStream &operator>>(QDataStream &stream, ChartSize &context);

#endif // CHARTSIZE_H
