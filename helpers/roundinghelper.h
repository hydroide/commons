#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef ROUNDINGHELPER_H
#define ROUNDINGHELPER_H

#include <string>
using namespace std;

#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost::multiprecision;

#include <QtCore>
/**
 * @brief The RoundingHelper class 舍入处理辅助类
 */
class RoundingHelper
{
public:
    RoundingHelper() = delete;

    /**
     * @brief round_scale<T>
     * 对T类型的数据以指定的进制阶梯（如10 100 1000）向最近的偶数舍入
     * 远离0的方向（用到负数时，需要留神）
     * 注意：只测试过 boost 十进制浮点，二进制浮点需要留神
     * @param v 原始数据
     * @param scale 阶
     * @return 舍入后的数据
     */
    template<typename T>
    static T round_scale(T const& v, T scale)
    {
        // 1.25 -> 1.2 0.625 -> 0.63 -> 0.6 -> 1.2
        // 1.35 -> 1.4 0.675 -> 0.68 -> 0.7 -> 1.4
        T temp = v*scale;
        T out = trunc(temp);
        T minus = temp - out;
        if (abs(minus) > T(0.5))
        {
            if (minus > 0)
            {
                out += T(1);
            }
            else {
                out -= T(1);
            }
        }
        else if (abs(minus) == T(0.5))
        {
            T temp2 = out / T(2);
            T out2 = trunc(temp2);
            T minus2 = temp2 - out2;
            if (abs(minus2) > T(0))
            {
                if (minus > 0)
                {
                    out += T(1);
                }
                else
                {
                    out -= T(1);
                }
            }
        }
        return out/scale;
    }

    /**
     * @brief round_towards_nearest_even<d, T>
     * 对T类型的数据以指定的位数d向最近的偶数舍入
     * 远离0的方向（用到负数时，需要留神）
     * @param v 原始数据
     * @return 舍入后的数据
     */
    template <int decimals = 0, typename T>
    static T round_towards_nearest_even(T const& v)
    {
        T scale = pow(T(10), decimals);
        return round_scale(v, scale);
    }

    /**
     * @brief get_significant_digits<d, T>
     * 对T类型的数据去指定位数有效数字，有效数字向最近的偶数舍入
     * 远离0的方向（用到负数时，需要留神）
     * @param v 原始数据
     * @return 舍入后的数据
     */
    template <int decimals = 0, typename T>
    static T get_significant_digits(T const& v)
    {
        // 0.01355 -> 0.0136 *10000 round /10000
        // 1355 -> 1360 /10 round *10
        T temp = v;
        int leadzeros{0}, intdigits{0}; // leadzeros：头0个数，intdigits整数位数
        while (abs(temp) < T(1) && temp != T(0))
        {
            temp *= T(10);
            leadzeros++;
        }
        if (leadzeros > 0)
        {
            leadzeros -= 1;
        }

        temp = v;
        while (!(abs(temp) < T(1)))
        {
            temp /= T(10);
            intdigits++;
        }

        T scale = pow(T(10), decimals + leadzeros - intdigits);

        return round_scale(v, scale);
    }

    /**
     * @brief roundStage 舍入水位
     * @param value 需要处理的水位(cpp_dec_float_50)
     * @return 舍入完成的水位字符串
     */
    static string roundStage(cpp_dec_float_50 value);
    /**
     * @brief roundStage 舍入水位
     * @param value 需要处理的水位字符串(QString)
     * @return 舍入完成的水位字符串
     */
    static string roundStage(string value);
    /**
     * @brief roundStage 舍入水位
     * @param value 需要处理的水位(double)
     * @return 舍入完成的水位字符串(QString)
     */
    static QString roundStage(qreal value);

    /**
     * @brief roundStage 舍入流量
     * @param value 需要处理的流量(cpp_dec_float_50)
     * @return 舍入完成的流量字符串
     */
    static string roundDischarge(cpp_dec_float_50 value);
    /**
     * @brief roundStage 舍入流量
     * @param value 需要处理的流量(string)
     * @return 舍入完成的流量字符串
     */
    static string roundDischarge(string value);
    /**
     * @brief roundStage 舍入流量
     * @param value 需要处理的流量(double)
     * @return 舍入完成的流量字符串(QString)
     */
    static QString roundDischarge(qreal value);

    /**
     * @brief roundStage 舍入含沙量
     * @param value 需要处理的含沙量(cpp_dec_float_50)
     * @return 舍入完成的含沙量字符串
     */
    static string roundSediment(cpp_dec_float_50 value);
    /**
     * @brief roundStage 舍入含沙量
     * @param value 需要处理的含沙量(string)
     * @return 舍入完成的含沙量字符串
     */
    static string roundSediment(string value);
    /**
     * @brief roundStage 舍入含沙量
     * @param value 需要处理的含沙量(double)
     * @return 舍入完成的含沙量字符串(QString)
     */
    static QString roundSediment(qreal value);

};

#endif // ROUNDINGHELPER_H
