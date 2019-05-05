#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "colorhelper.h"

#include <QList>

QColor ColorHelper::random()
{
    QList<int> list;
    list.append(qrand()%255);
    list.append(qrand()%127);
    list.append(qrand()%63);
    std::random_shuffle(list.begin(), list.end());
    return QColor(list[0], list[1], list[2]);
}
