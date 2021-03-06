﻿#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef PROJECTINTERFACE_H
#define PROJECTINTERFACE_H

#include <QtCore>

#include "models/project.h"


class ProjectInterface
{
public:
    virtual ~ProjectInterface() {}
    virtual void setProject(SpProject) = 0;
};

#define ProjectInterface_iid "org.hwsdsw.HydroCurve.ProjectInterface"

Q_DECLARE_INTERFACE(ProjectInterface, ProjectInterface_iid)

#endif // PROJECTINTERFACE_H
