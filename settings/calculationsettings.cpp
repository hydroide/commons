#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "calculationsettings.h"

CalculationSettings::CalculationSettings()
{

}

CalculationSettings::~CalculationSettings()
{

}

CalculationSettings::PlpiMethod CalculationSettings::plpiMethod() const
{
    return _plpiMethod;
}

void CalculationSettings::setPlpiMethod(const PlpiMethod &plpiMethod)
{
    _plpiMethod = plpiMethod;
}



void CalculationSettings::read(const QJsonObject &json)
{
    _plpiMethod = PlpiMethod(json["plpiMethod"].toInt());
}

void CalculationSettings::write(QJsonObject &json) const
{
    json["plpiMethod"] = _plpiMethod;
}
