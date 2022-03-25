#ifndef COLUMN_H
#define COLUMN_H

#include <QString>
#include "jiabh/filter.h"

namespace Jiabh {
    /**
     * @brief 数据库表中的一列
     */
    template <class T>
    class Column
    {
    public:
        /**
         * @param name 列名
         */
        Column(const QString &name);

        /**
         * @brief 获取列名
         */
        QString getName() const;

        /**
         * @brief like 模糊匹配
         * @param str 匹配字符串
         * @return 生成的过滤条件
         */
        Filter like(const QString &str) const;

        Filter operator==(const T &other) const;
        Filter operator>(const T &other) const;
        Filter operator<(const T &other) const;
        Filter operator>=(const T &other) const;
        Filter operator<=(const T &other) const;
        Filter operator!=(const T &other) const;
    };
}

#endif // COLUMN_H
