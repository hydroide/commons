#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "settings.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>

Settings::Settings(const QString &filePath)
{
    _filePath = filePath;
    QFile file(_filePath);
    if (!file.exists())
    {
        newSettings();
        saveSettings();
    }
    else
    {
        loadSettings();
    }
}

Settings::~Settings()
{

}

void
Settings::newSettings()
{
    _graphicsSettings = GraphicsSettings();
}

bool
Settings::loadSettings()
{
    QFile loadFile(_filePath);
    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning() << "Couldn't load settings file: " << _filePath;
        return false;
    }

    QByteArray loadData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));

    read(loadDoc.object());

    return true;
}

bool
Settings::saveSettings()
const
{
    QFile saveFile(_filePath);
    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning() << "Couldn't save settings file: " << _filePath;
        return false;
    }

    QJsonObject saveObject;

    write(saveObject);

    QJsonDocument saveDoc(saveObject);

    saveFile.write(saveDoc.toJson());

    return true;
}

void
Settings::read(const QJsonObject &json)
{
    _projectsSettings.read(json["projects"].toObject());
    _graphicsSettings.read(json["graphics"].toObject());
    _calculationSettings.read(json["calculation"].toObject());
}

void
Settings::write(QJsonObject &json) const
{
    QJsonObject projectsSettingsObject;
    _projectsSettings.write(projectsSettingsObject);
    json["projects"] = projectsSettingsObject;
    QJsonObject graphicsSettingsObject;
    _graphicsSettings.write(graphicsSettingsObject);
    json["graphics"] = graphicsSettingsObject;
    QJsonObject calculationSettingsObject;
    _calculationSettings.write(calculationSettingsObject);
    json["calculation"] = calculationSettingsObject;
}

GraphicsSettings &
Settings::graphicsSettings()
{
    return _graphicsSettings;
}

CalculationSettings &
Settings::calculationSettings()
{
    return _calculationSettings;
}

ProjectsSettings &
Settings::projectsSettings()
{
    return _projectsSettings;
}
