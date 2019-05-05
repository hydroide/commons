#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef COLORHELPER_H
#define COLORHELPER_H

#include <QColor>

/**
 * @brief The ColorHelper class 颜色辅助类
 */
class ColorHelper
{
public:
    ColorHelper() = delete;
    /**
     * @brief random 生成随机色
     * @return 随机色
     */
    static QColor random();
};

#endif // COLORHELPER_H
