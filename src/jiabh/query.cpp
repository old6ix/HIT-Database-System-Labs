#include "jiabh/query.h"
#include "jiabh/table.h"
#include "jiabh/filter.h"

namespace Jiabh {
    Query::Query(const Table &table) : m_filtered(false)
    {
        m_sqlStr = "SELECT * FROM " + table.getName();
    }

    Query::Query(const Query &obj) : m_filtered(obj.m_filtered)
    {
        m_sqlStr = QString(obj.m_sqlStr);
    }

    QString Query::getRawStr() const
    {
        return m_sqlStr + ";";
    }

    Query &Query::filterBy(const Filter &filter)
    {
        if (!m_filtered)
        {
            m_filtered = true;
            m_sqlStr += QString(" WHERE (%1)").arg(filter.getRawStr());
        }
        else
        {
            m_sqlStr += QString(" AND (%1)").arg(filter.getRawStr());
        }

        return *this;
    }
}
