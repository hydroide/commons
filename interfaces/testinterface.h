#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef TESTINTERFACE_H
#define TESTINTERFACE_H

#include <QtCore>

class TestInterface
{
public:
    virtual ~TestInterface() {}
    virtual QString echo(const QString &message) = 0;
};

#define TestInterface_iid "org.hwsdsw.HydroCurve.TestInterface"

Q_DECLARE_INTERFACE(TestInterface, TestInterface_iid)

#endif // TESTINTERFACE_H
