#include <QtTest>

#include "jiabh/column.hpp"
#include "jiabh/filter.h"

class TestColumn : public QObject
{
    Q_OBJECT

public:
    TestColumn();

private:
    Jiabh::IntColumn col_int;
    Jiabh::StrColumn col_str;

private slots:
    void test_getName();
    void test_like();
    void test_operators();
};

TestColumn::TestColumn() : col_int("col1"), col_str("col2")
{}

void TestColumn::test_getName()
{
    QVERIFY(col_int.getName() == "col1");
    QVERIFY(col_str.getName() == "col2");
}

void TestColumn::test_like()
{
    auto f1 = col_int.like("1%");
    QVERIFY(f1.getRawStr() == "col1 LIKE '1%'");

    auto f2 = col_str.like("string");
    QVERIFY(f2.getRawStr() == "col2 LIKE 'string'");

    auto f3 = col_int.like("_5");
    QVERIFY(f3.getRawStr() == "col1 LIKE '_5'");
}

void TestColumn::test_operators()
{
    QVERIFY((col_int == 1).getRawStr() == "col1 = 1");
    QVERIFY((col_int >= -1).getRawStr() == "col1 >= -1");
    QVERIFY((col_int < 1).getRawStr() == "col1 < 1");
    QVERIFY((col_str > "str1").getRawStr() == "col2 > 'str1'");
    QVERIFY((col_str <= "str2").getRawStr() == "col2 <= 'str2'");
    QVERIFY((col_str != "333").getRawStr() == "col2 != '333'");
}

QTEST_APPLESS_MAIN(TestColumn)

#include "tst_testcolumn.moc"
