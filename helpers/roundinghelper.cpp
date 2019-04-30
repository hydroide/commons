#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "roundinghelper.h"

#include <QtCore>

#include <iostream>
using namespace std;

string RoundingHelper::roundStage(cpp_dec_float_50 value)
{
    //    return value.str(2, std::ios_base::fixed);
    value = round_towards_nearest_even<2>(value);
    return value.str();
}

string RoundingHelper::roundStage(string value)
{
    return roundStage(cpp_dec_float_50(value));
}

QString RoundingHelper::roundStage(qreal value)
{
    auto stage = QString::fromStdString(roundStage(cpp_dec_float_50(value)));
    auto splitted = stage.split('.');
    if (splitted.size() > 1)
    {
        auto decimal = splitted[1];
        if (decimal.size() == 0)
        {
            stage += "00";
        }
        else if (decimal.size() == 1)
        {
            stage += "0";
        }
    }
    else
    {
        stage += ".00";
    }
    return stage;
}

string RoundingHelper::roundDischarge(cpp_dec_float_50 value)
{
    value = get_significant_digits<3>(value);
    if (value < cpp_dec_float_50(1))
    {
        value = round_towards_nearest_even<3>(value);
    }
    else if (value < cpp_dec_float_50(10))
    {
        value = round_towards_nearest_even<2>(value);
    }
    else if (value < cpp_dec_float_50(100))
    {
        value = round_towards_nearest_even<1>(value);
    }
    return value.str();
}

string RoundingHelper::roundDischarge(string value)
{
    return roundDischarge(cpp_dec_float_50(value));
}

QString RoundingHelper::roundDischarge(qreal value)
{
    return QString::fromStdString(roundDischarge(cpp_dec_float_50(value)));
}

string RoundingHelper::roundSediment(cpp_dec_float_50 value)
{
    return roundDischarge(value);
}

string RoundingHelper::roundSediment(string value)
{
    return roundSediment(cpp_dec_float_50(value));
}

QString RoundingHelper::roundSediment(qreal value)
{
    return QString::fromStdString(roundSediment(cpp_dec_float_50(value)));
}
