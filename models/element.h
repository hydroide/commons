#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef ELEMENT_H
#define ELEMENT_H

#include <QtCore>

class Element
{
public:
    Element();
    ~Element();

    virtual QString type() const;
    virtual void setType(const QString &type);

    QPointF location() const;
    void setLocation(const QPointF &location);

    QSizeF size() const;
    void setSize(const QSizeF &size);

protected:
    QString _type;
    QPointF _location;
    QSizeF _size;
};

typedef QSharedPointer<Element> SpElement;

#endif // ELEMENT_H
