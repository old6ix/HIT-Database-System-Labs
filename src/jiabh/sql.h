#ifndef SQL_H
#define SQL_H

#include <QString>

namespace Jiabh {
    /**
     * @brief SQL接口，表示该类可以生成一个合法的SQL语句
     */
    class SQL
    {
    public:
        /**
         * @brief 获取原始SQL查询语句
         * @return 生成的查询语句
         */
        virtual QString getRawStr() const = 0;
    };
}

#endif // SQL_H
