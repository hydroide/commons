#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "graphicssettings.h"

GraphicsSettings::GraphicsSettings()
{

}

GraphicsSettings::~GraphicsSettings()
{

}

bool GraphicsSettings::enableAcceleration() const
{
    return _enableAcceleration;
}

void GraphicsSettings::setEnableAcceleration(bool enableAcceleration)
{
    _enableAcceleration = enableAcceleration;
}

bool GraphicsSettings::enableSurfaceFormat() const
{
    return _enableSurfaceFormat;
}

void GraphicsSettings::setEnableSurfaceFormat(bool enableSurfaceFormat)
{
    _enableSurfaceFormat = enableSurfaceFormat;
}

void GraphicsSettings::read(const QJsonObject &json)
{
    _enableAcceleration = json["enableAcceleration"].toBool();
    _enableSurfaceFormat = json["enableSurfaceFormat"].toBool();
}

void GraphicsSettings::write(QJsonObject &json) const
{
    json["enableAcceleration"] = _enableAcceleration;
    json["enableSurfaceFormat"] = _enableSurfaceFormat;
}
