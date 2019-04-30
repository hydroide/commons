#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SETTINGS_H
#define SETTINGS_H

#include <QJsonObject>
#include <QList>

#include "graphicssettings.h"
#include "calculationsettings.h"
#include "projectssettings.h"

class Settings
{
public:
    Settings(const QString &filePath);
    ~Settings();

    void newSettings();
    bool loadSettings();
    bool saveSettings() const;

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    GraphicsSettings &graphicsSettings();

    CalculationSettings &calculationSettings();

    ProjectsSettings &projectsSettings();

private:
    ProjectsSettings _projectsSettings;
    GraphicsSettings _graphicsSettings;
    CalculationSettings _calculationSettings;
    QString _filePath;
};

#endif // SETTINGS_H
