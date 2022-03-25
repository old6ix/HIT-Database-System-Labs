#include <QtTest>

#include "jiabh/table.h"
#include "jiabh/query.h"
#include "jiabh/column.hpp"
#include "jiabh/filter.h"

class TestQuery : public QObject
{
    Q_OBJECT

private slots:
    void test_getRawStr();
    void test_getRawStrWithFilter();
    void test_multiFilterBy();
};

void TestQuery::test_getRawStr()
{
    auto t1 = Jiabh::Table("t1");
    auto q1 = Jiabh::Query(t1);
    QVERIFY(q1.getRawStr() == "SELECT * FROM t1;");
}

void TestQuery::test_getRawStrWithFilter()
{
    auto t1 = Jiabh::Table("t1");
    auto q1 = Jiabh::Query(t1);

    auto c1 = Jiabh::IntColumn("num");
    Jiabh::Filter f1 = c1 >= 10;

    q1.filterBy(f1);

    QVERIFY(q1.getRawStr() == "SELECT * FROM t1 WHERE (num >= 10);");
}

void TestQuery::test_multiFilterBy()
{
    auto t1 = Jiabh::Table("table");

    Jiabh::IntColumn c1{"num1"}, c2{"num2"};
    Jiabh::StrColumn c3{"name"};

    QString sql = t1.query()
            .filterBy(c1 == 1)
            .filterBy(c2.like("12%"))
            .getRawStr();

    QVERIFY(sql == "SELECT * FROM table WHERE (num1 = 1) AND (num2 LIKE '12%');");
}

QTEST_APPLESS_MAIN(TestQuery)

#include "tst_testquery.moc"
