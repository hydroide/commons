#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "text.h"

Text::Text()
{

}

Text::~Text()
{

}
QString Text::string() const
{
    return _string;
}

void Text::setString(const QString &string)
{
    _string = string;
}


