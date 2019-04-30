#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SDRCURVENODE_H
#define SDRCURVENODE_H

#include <QtCore>

struct SDRCurveNode
{
public:
    QString _stcd;
    int _year;
    int _curve_id;
    int _node_id;
    QString _stage;
    QString _discharge;
};

#endif // SDRCURVENODE_H
