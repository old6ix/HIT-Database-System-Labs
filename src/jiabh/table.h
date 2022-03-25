#ifndef TABLE_H
#define TABLE_H

#include <QString>

namespace Jiabh {

    class Query;

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
         * @brief 查询语句
         * @return 生成的查询对象
         */
        Query query() const;

    private:
        QString m_name; // 表名
    };
}


#endif // TABLE_H
