#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef POINT_H
#define POINT_H

template<typename T>
class Point
{
public:
    Point()
    {

    }

    Point(T x, T y)
        : _x(x), _y(y)
    {

    }

    T x() const
    {
        return _x;
    }

    void setX(const T &x)
    {
        _x = x;
    }

    T y() const
    {
        return _y;
    }

    void setY(const T &y)
    {
        _y = y;
    }


protected:
    T _x;
    T _y;
};

#endif // POINT_H
