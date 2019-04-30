#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "projectssettings.h"

ProjectsSettings::ProjectsSettings()
{

}

ProjectsSettings::~ProjectsSettings()
{

}
QString ProjectsSettings::defaultProjectDirectory() const
{
    return _defaultProjectDirectory;
}

void ProjectsSettings::setDefaultProjectDirectory(const QString &defaultProjectDirectory)
{
    _defaultProjectDirectory = defaultProjectDirectory;
}


void ProjectsSettings::read(const QJsonObject &json)
{
    _defaultProjectDirectory = json["defaultProjectDirectory"].toString();
}

void ProjectsSettings::write(QJsonObject &json) const
{
    json["defaultProjectDirectory"] = _defaultProjectDirectory;
}

