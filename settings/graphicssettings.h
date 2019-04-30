#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef GRAPHICSSETTINGS_H
#define GRAPHICSSETTINGS_H

#include "../models/ijsonserializable.h"

class GraphicsSettings : public IJsonSerializable
{
public:
    GraphicsSettings();
    ~GraphicsSettings();

    bool enableAcceleration() const;
    void setEnableAcceleration(bool enableAcceleration);

    bool enableSurfaceFormat() const;
    void setEnableSurfaceFormat(bool enableSurfaceFormat);

private:
    bool _enableAcceleration{false};
    bool _enableSurfaceFormat{false};

    // IJsonSerializable interface
public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
};

#endif // GRAPHICSSETTINGS_H
