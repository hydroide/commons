#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef CURVE_H
#define CURVE_H

#include "element.h"

class Curve : public Element
{
public:
    Curve();
    ~Curve();

};

typedef QSharedPointer<Curve> SpCurve;

#endif // CURVE_H
