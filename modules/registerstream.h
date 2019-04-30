#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef REGISTERSTREAM
#define REGISTERSTREAM

#include <QtCore>

#define REGISTERSTREAM(type) qRegisterMetaTypeStreamOperators\
    <type>(type::staticMetaObject.className())

#endif // REGISTERSTREAM

