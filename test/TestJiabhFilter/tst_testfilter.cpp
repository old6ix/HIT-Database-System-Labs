#include <QtTest>

#include "jiabh/filter.h"
#include "jiabh/column.hpp"

class TestFilter : public QObject
{
    Q_OBJECT

public:
    TestFilter();

private:
    Jiabh::IntColumn col_int;
    Jiabh::StrColumn col_str;

private slots:
    void test_getRawStr();
    void test_logicalOpts();
};

TestFilter::TestFilter() : col_int("col1"), col_str("col2")
{}

void TestFilter::test_getRawStr()
{
    auto f1 = col_int.like("123%");
    auto f2 = col_str != "abcde";
    auto f_res = !(f1 || f2);
    QVERIFY(f_res.getRawStr() == "NOT ((col1 LIKE '123%') OR (col2 != 'abcde'))");
}

void TestFilter::test_logicalOpts()
{
    auto col3 = Jiabh::StrColumn("col3");
    auto f1 = col_int > 60;
    auto f2 = col_int <= 100;
    auto f3 = col3.like("qwerty");
    auto f4 = col_str != "col2";
    auto f_res = !(f1 && f2) && (f3 || f4);
    QVERIFY(f_res.getRawStr() == "(NOT ((col1 > 60) AND (col1 <= 100))) AND ((col3 LIKE 'qwerty') OR (col2 != 'col2'))");
}

QTEST_APPLESS_MAIN(TestFilter)

#include "tst_testfilter.moc"
