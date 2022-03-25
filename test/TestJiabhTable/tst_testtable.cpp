#include <QtTest>

#include "jiabh/table.h"
#include "jiabh/query.h"

class TestTable : public QObject
{
    Q_OBJECT

public:
    TestTable();

private slots:
    void test_getName();
    void test_query();

private:
    Jiabh::Table t1;
};

TestTable::TestTable() : t1(QString("table1"))
{}

void TestTable::test_getName()
{
    t1.getName() = "t-1";
    QString a = t1.getName();
    QVERIFY(a == "table1");
}

void TestTable::test_query()
{
    auto q = t1.query();
    QVERIFY(q.getRawStr() == "SELECT * FROM table1;");
}

QTEST_APPLESS_MAIN(TestTable)

#include "tst_testtable.moc"
