#ifndef TABLE_H
#define TABLE_H

#include <QString>
#include "jiabh/query.h"

namespace Jiabh {
    /**
     * @brief 数据库中的一张表
     */
    class Table
    {
    public:
        /**
         * @param name 表名
         */
        Table(const QString &name);

        /**
         * @brief 获取表名
         */
        QString getName() const;

        /**
         * @brief 选出表中的所有字段
         * @return 生成的查询类
         */
        Query query() const;

    private:
        QString m_name; // 表名
    };
}


#endif // TABLE_H
