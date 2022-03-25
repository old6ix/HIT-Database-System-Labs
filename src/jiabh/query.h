#ifndef QUERY_H
#define QUERY_H

#include <QString>
#include "jiabh/sql.h"

namespace Jiabh {

    class Table;
    class Filter;

    /**
    * @brief SQL查询语句
    */
    class Query : public SQL
    {
    public:
        /**
         * @param table Jiabh::Table类
         */
        Query(const Table &table);

        Query(const Query &obj);

        QString getRawStr() const override;

        /**
         * @brief 添加过滤条件
         * @param filter 条件
         * @return 当前对象的引用
         */
        Query &filterBy(const Filter &filter);

        // TODO 完成查询函数
        // QSqlQuery all(QSqlDatabase db);
    private:
        QString m_sqlStr; // 生成的SQL语句
        bool m_filtered; // 是否添加过WHERE条件
    };
}

#endif // QUERY_H
