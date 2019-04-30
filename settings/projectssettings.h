#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef PROJECTSSETTINGS_H
#define PROJECTSSETTINGS_H

#include "../models/ijsonserializable.h"

class ProjectsSettings : public IJsonSerializable
{
public:
    ProjectsSettings();
    ~ProjectsSettings();

    QString defaultProjectDirectory() const;
    void setDefaultProjectDirectory(const QString &defaultProjectDirectory);

    QString _defaultProjectDirectory;

    // IJsonSerializable interface
public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
};

#endif // PROJECTSSETTINGS_H
