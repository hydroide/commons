#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef TEXT_H
#define TEXT_H

#include "element.h"

class Text : public Element
{
public:
    Text();
    ~Text();

    QString string() const;
    void setString(const QString &string);

private:
    QString _string;
};

typedef QSharedPointer<Text> SpText;

#endif // TEXT_H
