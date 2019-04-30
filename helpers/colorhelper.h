#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef COLORHELPER_H
#define COLORHELPER_H

#include <QColor>

class ColorHelper
{
public:
    ColorHelper();
    static QColor random();
};

#endif // COLORHELPER_H
