#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef VIEWERINTERFACE_H
#define VIEWERINTERFACE_H

#include <QtCore>
#include <QtWidgets>

class ViewerInterface
{
public:
    virtual ~ViewerInterface() {}
    virtual QWidget *create(QWidget *parent) = 0;
    virtual QString name() = 0;
};

#define ViewerInterface_iid "org.hwsdsw.HydroCurve.ViewerInterface"

Q_DECLARE_INTERFACE(ViewerInterface, ViewerInterface_iid)

#endif // ViewerINTERFACE_H
