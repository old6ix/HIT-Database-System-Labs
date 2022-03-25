#ifndef FILTER_H
#define FILTER_H

#include "jiabh/sql.h"

namespace Jiabh {

    template <class T>
    class Column;

     /**
     * @brief SQL过滤条件
     */
    class Filter : public SQL
    {
    protected:
        template<class T> friend class Column;
        Filter(const QString &sqlStr); // 只有Column类能创建Filter

    public:
        Filter(const Filter &obj);

        QString getRawStr() const override;

        Filter operator&&(const Filter &other);
        Filter operator||(const Filter &other);
        Filter operator!();

    private:
        QString m_sqlStr;
    };
}

#endif // FILTER_H
