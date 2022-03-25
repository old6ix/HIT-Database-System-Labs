#include "jiabh/table.h"
#include "jiabh/query.h"

namespace Jiabh {
    Table::Table(const QString &name) : m_name(name)
    {}

    QString Table::getName() const
    {
        return m_name;
    }

    Query Table::query() const
    {
        auto q = Query(*this);
        return q;
    }
}
