#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <QtCore>

#include "../models/point.h"

/**
 * @brief The MathHelper class 数学辅助类
 */
class MathHelper
{
public:
    MathHelper() = delete;

    /**
     * @brief Lagrange Polynomial Interpolation n阶拉格朗日抛物线插值 （拉格朗日插值多项式）
     * @param points 所有已知结点（使用Point<T>点类型的QVector）
     * @param x 线上点的一个坐标值
     * @return y 线上点的另一坐标值
     */
    template<typename T>
    static T LPI(const QVector<Point<T>> &points, T x)
    {
        T tmp{1}, ret{0};
        for (auto it = points.cbegin(); it != points.cend(); ++it)
        {
            tmp = 1;
            for (auto jt = points.cbegin(); jt != points.cend(); ++jt)
            {
                if (it == jt)
                {
                    continue;
                }
                else
                {
                    tmp = tmp*(x - (*jt).x())/((*it).x() - (*jt).x());
                }
            }
            ret = ret + tmp*(*it).y();
        }
        return ret;
    }

    /**
     * @brief Lagrange Polynomial Interpolation n阶拉格朗日抛物线插值 （拉格朗日插值多项式）
     * @param points
     * @param x 线上点的一个坐标值
     * @return y 线上点的另一坐标值
     */
    template<typename T>
    static T LPI(const QVector<QPointF> &points, T x)
    {
        T tmp{1}, ret{0};
        for (auto it = points.cbegin(); it != points.cend(); ++it)
        {
            tmp = 1;
            for (auto jt = points.cbegin(); jt != points.cend(); ++jt)
            {
                if (it == jt)
                {
                    continue;
                }
                else
                {
                    tmp = tmp*(x - (*jt).x())/((*it).x() - (*jt).x());
                }
            }
            ret = ret + tmp*(*it).y();
        }
        return ret;
    }

    /**
     * @brief LPI2, Lagrange Polynomial Interpolation 2 2次拉格朗日插值（抛物线插值）
     * @param points 所有已知结点（使用Point<T>点类型的QVector）
     * @param x 线上点的一个坐标值
     * @return y 线上点的另一坐标值
     */
    template<typename T>
    static T LPI2(const QVector<Point<T>> &points, T x)
    {
        Q_ASSERT(points.count() = 3);
        auto x1 = points[0].x();
        auto x2 = points[1].x();
        auto x3 = points[2].x();
        auto y1 = points[0].y();
        auto y2 = points[1].y();
        auto y3 = points[2].y();

        auto pn1 = (x1 - x2)*(x1 - x3);
        auto pn2 = (x2 - x1)*(x2 - x3);
        auto pn3 = (x3 - x1)*(x3 - x2);

        auto term2 = 2*(y1/pn1 + y2/pn2 + y3/pn3);
        auto term1 = -(
                    (x2 + x3)*y1/pn1 +
                    (x1 + x3)*y2/pn2 +
                    (x1 + x2)*y3/pn3
                    );
        auto ret = term2*x + term1;
        return ret;
    }

    /**
     * @brief PLPI_MPS, Piecewise Lagrange Parabolic Interpolation, mid-point separated
     *  分段拉格朗日抛物线插值 中点分隔
     * @param points 所有已知结点（使用Point<T>点类型的QVector）
     * @param x 线上点的一个坐标值
     * @return y 线上点的另一坐标值
     */
    template<typename T>
    static T PLPI_MPS(const QVector<Point<T>> &points, T x)
    {
        T tmp{1}, ret{0};
        int k{0};
        if (x <= points[1].x())
        {
            k = 0;
        }
        else if (x >= points[points.size() - 1 - 1].x())
        {
            k = points.size() - 2 - 1;
        }
        else
        {
            for (auto s = 1; s != points.size() - 1; ++s)
            {
                if (x > points[s].x() && x <= points[s + 1].x()) // 在这个区间内
                {
                    if (x - points[s].x() < points[s + 1].x() - x)
                    {
                        k = s - 1;
                    }
                    else
                    {
                        k = s;
                    }
                    break;
                }
            }
        }
        for (int i = k; i <= k + 2; ++i)
        {
            tmp = 1;
            for (int j = k; j <= k + 2; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    tmp = tmp*(x - points[j].x())/(points[i].x() - points[j].x());
                }
            }
            ret = ret + tmp*points[i].y();
        }
        return ret;
    }

    /**
     * @brief PLPI_MPS, Piecewise Lagrange Parabolic Interpolation, mid-point separated
     *  分段拉格朗日抛物线插值 中点分隔
     * @param points 所有已知结点（使用QPointF点类型的QVector）
     * @param x 线上点的一个坐标值
     * @return y 线上点的另一坐标值
     */
    template<typename T>
    static T PLPI_MPS(const QVector<QPointF> &points, T x)
    {
        T tmp{1}, ret{0};
        int k{0};
        if (x <= points[1].x())
        {
            k = 0;
        }
        else if (x >= points[points.size() - 1 - 1].x())
        {
            k = points.size() - 2 - 1;
        }
        else
        {
            for (auto s = 1; s != points.size() - 1; ++s)
            {
                if (x > points[s].x() && x <= points[s + 1].x()) // 在这个区间内
                {
                    if (x - points[s].x() < points[s + 1].x() - x)
                    {
                        k = s - 1;
                    }
                    else
                    {
                        k = s;
                    }
                    break;
                }
            }
        }
        for (int i = k; i <= k + 2; ++i)
        {
            tmp = 1;
            for (int j = k; j <= k + 2; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    tmp = tmp*(x - points[j].x())/(points[i].x() - points[j].x());
                }
            }
            ret = ret + tmp*points[i].y();
        }
        return ret;
    }

    /**
     * @brief PLPI_TPA, Piecewise Lagrange Parabolic Interpolation, two pieces averaged
     *  分段拉格朗日抛物线插值 结点分隔——中间平均值
     * @param points 所有已知结点（使用Point<T>点类型的QVector）
     * @param x 线上点的一个坐标值
     * @return y 线上点的另一坐标值
     */
    template<typename T>
    static T PLPI_TPA(const QVector<Point<T>> &points, T x)
    {
        T tmp{1}, ret{0}, ret2{0};
        int k{0};
        bool firstOrLast{false};
        if (x <= points[1].x())
        {
            k = 0;
            firstOrLast = true;
        }
        else if (x >= points[points.size() - 1 - 1].x())
        {
            k = points.size() - 2 - 1;
            firstOrLast = true;
        }
        else
        {
            for (auto s = 1; s != points.size() - 1; ++s)
            {
                if (x > points[s].x() && x <= points[s + 1].x()) // 在这个区间内
                {
                    k = s - 1;
                }
            }
        }
        for (int i = k; i <= k + 2; ++i)
        {
            tmp = 1;
            for (int j = k; j <= k + 2; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    tmp = tmp*(x - points[j].x())/(points[i].x() - points[j].x());
                }
            }
            ret = ret + tmp*points[i].y();
        }
        if (!firstOrLast)
        {
            k++;
            for (int i = k; i <= k + 2; ++i)
            {
                tmp = 1;
                for (int j = k; j <= k + 2; ++j)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    else
                    {
                        tmp = tmp*(x - points[j].x())/(points[i].x() - points[j].x());
                    }
                }
                ret2 = ret2 + tmp*points[i].y();
            }
            ret = (ret + ret2)/2;
        }
        return ret;
    }

    /**
     * @brief PLPI_TPA, Piecewise Lagrange Parabolic Interpolation, two pieces averaged
     *  分段拉格朗日抛物线插值 结点分隔——中间平均值
     * @param points 所有已知结点（使用QPointF点类型的QVector）
     * @param x 线上点的一个坐标值
     * @return y 线上点的另一坐标值
     */
    template<typename T>
    static T PLPI_TPA(const QVector<QPointF> &points, T x)
    {
        T tmp{1}, ret{0}, ret2{0};
        int k{0};
        bool firstOrLast{false};
        if (x <= points[1].x())
        {
            k = 0;
            firstOrLast = true;
        }
        else if (x >= points[points.size() - 1 - 1].x())
        {
            k = points.size() - 2 - 1;
            firstOrLast = true;
        }
        else
        {
            for (auto s = 1; s != points.size() - 1; ++s)
            {
                if (x > points[s].x() && x <= points[s + 1].x()) // 在这个区间内
                {
                    k = s - 1;
                }
            }
        }
        for (int i = k; i <= k + 2; ++i)
        {
            tmp = 1;
            for (int j = k; j <= k + 2; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    tmp = tmp*(x - points[j].x())/(points[i].x() - points[j].x());
                }
            }
            ret = ret + tmp*points[i].y();
        }
        if (!firstOrLast)
        {
            k++;
            for (int i = k; i <= k + 2; ++i)
            {
                tmp = 1;
                for (int j = k; j <= k + 2; ++j)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    else
                    {
                        tmp = tmp*(x - points[j].x())/(points[i].x() - points[j].x());
                    }
                }
                ret2 = ret2 + tmp*points[i].y();
            }
            ret = (ret + ret2)/2;
        }
        return ret;
    }

    /**
     * @brief PLPI_TPA, Piecewise Lagrange Parabolic Interpolation, Linear Weighted Sum
     *  分段拉格朗日抛物线插值 线性加权合成
     * @param points 所有已知结点（使用Point<T>点类型的QVector）
     * @param x 线上点的一个坐标值
     * @return y 线上点的另一坐标值
     */
    template<typename T>
    static T PLPI_LWS(const QVector<Point<T>> &points, T x)
    {
        T tmp{1}, ret{0}, ret2{0};
        int k{0};
        bool firstOrLast{false};
        if (x <= points[1].x())
        {
            k = 0;
            firstOrLast = true;
        }
        else if (x >= points[points.size() - 1 - 1].x())
        {
            k = points.size() - 2 - 1;
            firstOrLast = true;
        }
        else
        {
            for (auto s = 1; s != points.size() - 1; ++s)
            {
                if (x > points[s].x() && x <= points[s + 1].x()) // 在这个区间内
                {
                    k = s - 1;
                }
            }
        }
        for (int i = k; i <= k + 2; ++i)
        {
            tmp = 1;
            for (int j = k; j <= k + 2; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    tmp = tmp*(x - points[j].x())/(points[i].x() - points[j].x());
                }
            }
            ret = ret + tmp*points[i].y();
        }
        if (!firstOrLast)
        {
            k++;
            for (int i = k; i <= k + 2; ++i)
            {
                tmp = 1;
                for (int j = k; j <= k + 2; ++j)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    else
                    {
                        tmp = tmp*(x - points[j].x())/(points[i].x() - points[j].x());
                    }
                }
                ret2 = ret2 + tmp*points[i].y();
            }
            auto lx = points[k - 1].x();
            auto rx = points[k + 1].x();
            auto lh = lx > rx ? lx - rx : rx - lx;
            auto ll = lx > x ? lx - x : x - lx;
            auto rl = rx > x ? rx - x : x - rx;
            if (lh > 0)
            {
                auto lp = ll / lh;
                auto rp = rl / lh;
                ret = ret * rp + ret2 * lp;
            }
            else
            {
                ret = (ret + ret2)/2;
            }
        }
        return ret;
    }

    /**
     * @brief PLPI_TPA, Piecewise Lagrange Parabolic Interpolation, Linear Weighted Sum
     *  分段拉格朗日抛物线插值 线性加权合成
     * @param points 所有已知结点（使用QPointF点类型的QVector）
     * @param x 线上点的一个坐标值
     * @return y 线上点的另一坐标值
     */
    template<typename T>
    static T PLPI_LWS(const QVector<QPointF> &points, T x)
    {
        T tmp{1}, ret{0}, ret2{0};
        int k{0};
        bool firstOrLast{false};
        if (x <= points[1].x())
        {
            k = 0;
            firstOrLast = true;
        }
        else if (x >= points[points.size() - 1 - 1].x())
        {
            k = points.size() - 2 - 1;
            firstOrLast = true;
        }
        else
        {
            for (auto s = 1; s != points.size() - 1; ++s)
            {
                if (x > points[s].x() && x <= points[s + 1].x()) // 在这个区间内
                {
                    k = s - 1;
                }
            }
        }
        for (int i = k; i <= k + 2; ++i)
        {
            tmp = 1;
            for (int j = k; j <= k + 2; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    tmp = tmp*(x - points[j].x())/(points[i].x() - points[j].x());
                }
            }
            ret = ret + tmp*points[i].y();
        }
        if (!firstOrLast)
        {
            k++;
            for (int i = k; i <= k + 2; ++i)
            {
                tmp = 1;
                for (int j = k; j <= k + 2; ++j)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    else
                    {
                        tmp = tmp*(x - points[j].x())/(points[i].x() - points[j].x());
                    }
                }
                ret2 = ret2 + tmp*points[i].y();
            }
            auto lx = points[k - 1].x();
            auto rx = points[k + 1].x();
            auto lh = lx > rx ? lx - rx : rx - lx;
            auto ll = lx > x ? lx - x : x - lx;
            auto rl = rx > x ? rx - x : x - rx;
            if (lh > 0)
            {
                auto lp = ll / lh;
                auto rp = rl / lh;
                ret = ret * rp + ret2 * lp;
            }
            else
            {
                ret = (ret + ret2)/2;
            }
        }
        return ret;
    }


    /**
     * @brief QBCCP Quadratic Bézier Curve Control Point 得到二阶贝塞尔曲线控制点
     * @param p1 第一个已知点
     * @param p2 第二个已知点
     * @param p3 第三个已知点
     * @param t  调节系数
     * @return   控制点
     */
    template<typename T>
    static T QBCCP(const T &p1, const T &p2, const T &p3, double t = 0.5)
    {
        auto x1 = p1.x();
        auto x2 = p2.x();
        auto x3 = p3.x();
        auto y1 = p1.y();
        auto y2 = p2.y();
        auto y3 = p3.y();

        auto denominator = 2 * t * (1 - t);
        auto one_minus_t = 1 - t;
        auto numerator_x = x2 - one_minus_t * one_minus_t * x1 - t * t * x3;
        auto numerator_y = y2 - one_minus_t * one_minus_t * y1 - t * t * y3;
        auto x = numerator_x / denominator;
        auto y = numerator_y / denominator;
        return T(x, y);
    }

};

#endif // MATHHELPER_H
