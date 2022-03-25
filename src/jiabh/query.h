#ifndef QUERY_H
#define QUERY_H

#include <QString>
#include "jiabh/sql.h"
#include "jiabh/table.h"
#include "jiabh/filter.h"

namespace Jiabh {
    /**
    * @brief SQL查询语句
    */
    class Query : public SQL
    {
    public:
        /**
         * @brief 生成一个查询类
         * @param table Jiabh::Table类
         */
        Query(const Table &table);

        QString getRawStr() override;

        /**
         * @brief 添加过滤条件
         * @param filter 条件
         * @return 当前对象的引用
         */
        Query &filterBy(const Filter &filter);

        // TODO 完成查询函数
        // QSqlQuery all(QSqlDatabase db);
    };
}

#endif // QUERY_H
