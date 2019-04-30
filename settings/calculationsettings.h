#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef CALCULATIONSETTINGS_H
#define CALCULATIONSETTINGS_H

#include "../models/ijsonserializable.h"

class CalculationSettings : public IJsonSerializable
{
public:
    CalculationSettings();
    ~CalculationSettings();

    /**
     * @brief The DischargeReckonMethod enum 分段拉格朗日抛物线插值方法类型
     */
    enum PlpiMethod {
        PLPI_MPS, PLPI_TPA, PLPI_LM, PLPI_RM, PLPI_LP, PLPI_UP
    };

    PlpiMethod plpiMethod() const;
    void setPlpiMethod(const PlpiMethod &plpiMethod);

private:
    /**
     * @brief _plpiMethod 分段拉格朗日抛物线插值方法
     */
    PlpiMethod _plpiMethod{PLPI_MPS};

    // IJsonSerializable interface
public:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
};

#endif // CALCULATIONSETTINGS_H
