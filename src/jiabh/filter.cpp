#include <QString>
#include "jiabh/filter.h"

namespace Jiabh {
    Filter::Filter(const QString &sqlStr) : m_sqlStr(sqlStr)
    {}

    Filter::Filter(const Filter &obj) : m_sqlStr(obj.m_sqlStr)
    {}

    QString Filter::getRawStr() const
    {
        return QString(m_sqlStr);
    }

    Filter Filter::operator&&(const Filter &other)
    {
        return Filter(QString("(%1) AND (%2)").arg(m_sqlStr, other.m_sqlStr));
    }

    Filter Filter::operator||(const Filter &other)
    {
        return Filter(QString("(%1) OR (%2)").arg(m_sqlStr, other.m_sqlStr));
    }

    Filter Filter::operator!()
    {
        return Filter(QString("NOT (%1)").arg(m_sqlStr));
    }
}





