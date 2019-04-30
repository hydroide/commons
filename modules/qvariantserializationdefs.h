#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef QVARIANTSERIALIZATIONDEFS
#define QVARIANTSERIALIZATIONDEFS

#endif // QVARIANTSERIALIZATIONDEFS

#include <QtCore>


template<typename T>
void operator <<(QVariant &data, const T &context)
{
    data = QVariant::fromValue<T>(context);
}

template<typename T>
void operator >>(const QVariant &data, T &context)
{
    context = data.value<T>();
}

void operator <<(QVariant &data, const QPoint &context);
void operator <<(QVariant &data, const QPointF &context);
void operator >>(const QVariant &data, QPoint &context);
void operator >>(const QVariant &data, QPointF &context);

void operator <<(QVariant &data, const QSize &context);
void operator <<(QVariant &data, const QSizeF &context);
void operator >>(const QVariant &data, QSize &context);
void operator >>(const QVariant &data, QSizeF &context);

void operator <<(QVariant &data, const QRect &context);
void operator <<(QVariant &data, const QRectF &context);
void operator >>(const QVariant &data, QRect &context);
void operator >>(const QVariant &data, QRectF &context);

Q_DECLARE_METATYPE(QMargins)
void operator <<(QVariant &data, const QMargins &context);
void operator <<(QVariant &data, const QMarginsF &context);
void operator >>(const QVariant &data, QMargins &context);
void operator >>(const QVariant &data, QMarginsF &context);
