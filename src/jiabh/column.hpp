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
         * @param converter 数据类型T到QString的转换器
         */
        Column(const QString &name, QString (*converter)(T)) : m_name(name), m_converter(converter)
        {}

        Column(const Column &obj) : m_name(obj.m_name), m_converter(obj.m_converter)
        {}

        /**
         * @brief 获取列名
         */
        QString getName() const
        {
            return m_name;
        }

        /**
         * @brief like 模糊匹配
         * @param str 匹配字符串
         * @return 生成的过滤条件
         */
        Filter like(const QString &str) const
        {
            return Filter(QString("%1 LIKE '%2'").arg(m_name, str));
        }

        Filter operator==(const T &other) const
        {
            QString q = m_converter(other);
            return Filter(QString("%1 = %2").arg(m_name, q));
        }

#define COLUMN_OPERATOR_DEF(OPT)                                 \
    Filter operator OPT(const T &other) const                    \
    {                                                            \
        QString q = m_converter(other);                          \
        return Filter(QString("%1 " #OPT " %2").arg(m_name, q)); \
    }

        COLUMN_OPERATOR_DEF(>)
        COLUMN_OPERATOR_DEF(<)
        COLUMN_OPERATOR_DEF(>=)
        COLUMN_OPERATOR_DEF(<=)
        COLUMN_OPERATOR_DEF(!=)

    private:
        QString m_name; // 列名
        QString (*m_converter)(T); // 转换器
    };


    /**
     * @brief int类型的字段
     */
    class IntColumn : public Column<int>
    {
    public:
        /**
         * @param name 列名
         */
        IntColumn(const QString &name) : Column<int>(name, intConverter)
        {}

    private:
        static QString intConverter(int num)
        {
            return QString::number(num);
        }
    };


    /**
     * @brief string类型的字段
     */
    class StrColumn : public Column<QString>
    {
    public:
        /**
         * @param name 列名
         */
        StrColumn(const QString &name) : Column<QString>(name, strConverter)
        {}

    private:
        static QString strConverter(QString str)
        {
            return QString("'%1'").arg(str);
        }
    };
}

#endif // COLUMN_H
