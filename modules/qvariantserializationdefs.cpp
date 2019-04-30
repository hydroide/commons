#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "qvariantserializationdefs.h"

void operator <<(QVariant &data, const QPoint &context)
{
    QJsonObject obj;
    obj["x"] = context.x();
    obj["y"] = context.y();
    data = QJsonDocument(obj).toVariant();
}

void operator <<(QVariant &data, const QPointF &context)
{
    QJsonObject obj;
    obj["x"] = context.x();
    obj["y"] = context.y();
    data = QJsonDocument(obj).toVariant();
}

void operator <<(QVariant &data, const QSize &context)
{
    QJsonObject obj;
    obj["width"] = context.width();
    obj["height"] = context.height();
    data = QJsonDocument(obj).toVariant();
}

void operator <<(QVariant &data, const QSizeF &context)
{
    QJsonObject obj;
    obj["width"] = context.width();
    obj["height"] = context.height();
    data = QJsonDocument(obj).toVariant();
}

void operator <<(QVariant &data, const QRect &context)
{
    QJsonObject obj;
    obj["left"] = context.left();
    obj["right"] = context.right();
    obj["top"] = context.top();
    obj["bottom"] = context.bottom();
    data = QJsonDocument(obj).toVariant();
}

void operator <<(QVariant &data, const QRectF &context)
{
    QJsonObject obj;
    obj["left"] = context.left();
    obj["right"] = context.right();
    obj["top"] = context.top();
    obj["bottom"] = context.bottom();
    data = QJsonDocument(obj).toVariant();
}

void operator <<(QVariant &data, const QMargins &context)
{
    QJsonObject obj;
    obj["left"] = context.left();
    obj["right"] = context.right();
    obj["top"] = context.top();
    obj["bottom"] = context.bottom();
    data = QJsonDocument(obj).toVariant();
}

void operator <<(QVariant &data, const QMarginsF &context)
{
    QJsonObject obj;
    obj["left"] = context.left();
    obj["right"] = context.right();
    obj["top"] = context.top();
    obj["bottom"] = context.bottom();
    data = QJsonDocument(obj).toVariant();
}

void operator >>(const QVariant &data, QPoint &context)
{
    auto obj = QJsonDocument::fromVariant(data).object();
    context.setX(obj["x"].toInt());
    context.setY(obj["y"].toInt());
}

void operator >>(const QVariant &data, QPointF &context)
{
    auto obj = QJsonDocument::fromVariant(data).object();
    context.setX(obj["x"].toDouble());
    context.setY(obj["y"].toDouble());
}

void operator >>(const QVariant &data, QSize &context)
{
    auto obj = QJsonDocument::fromVariant(data).object();
    context.setWidth(obj["width"].toInt());
    context.setHeight(obj["height"].toInt());
}

void operator >>(const QVariant &data, QSizeF &context)
{
    auto obj = QJsonDocument::fromVariant(data).object();
    context.setWidth(obj["width"].toDouble());
    context.setHeight(obj["height"].toDouble());
}

void operator >>(const QVariant &data, QRect &context)
{
    auto obj = QJsonDocument::fromVariant(data).object();
    context.setLeft(obj["left"].toInt());
    context.setRight(obj["right"].toInt());
    context.setTop(obj["top"].toInt());
    context.setBottom(obj["bottom"].toInt());
}

void operator >>(const QVariant &data, QRectF &context)
{
    auto obj = QJsonDocument::fromVariant(data).object();
    context.setLeft(obj["left"].toDouble());
    context.setRight(obj["right"].toDouble());
    context.setTop(obj["top"].toDouble());
    context.setBottom(obj["bottom"].toDouble());
}

void operator >>(const QVariant &data, QMargins &context)
{
    auto obj = QJsonDocument::fromVariant(data).object();
    context.setLeft(obj["left"].toInt());
    context.setRight(obj["right"].toInt());
    context.setTop(obj["top"].toInt());
    context.setBottom(obj["bottom"].toInt());
}

void operator >>(const QVariant &data, QMarginsF &context)
{
    auto obj = QJsonDocument::fromVariant(data).object();
    context.setLeft(obj["left"].toDouble());
    context.setRight(obj["right"].toDouble());
    context.setTop(obj["top"].toDouble());
    context.setBottom(obj["bottom"].toDouble());
}
