#include "pch.h"
#include "CppUnitTest.h"

#include "../ExternalSort/Record.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExternalSortTest
{
    TEST_CLASS(RecordTest)
    {
    public:
        TEST_METHOD(CreateAndGet)
        {
            const int key = 6;
            const std::string data = "Hello world!";

            auto r = Record(key, data.c_str());
            Assert::AreEqual(key, r.getKey());
            Assert::AreEqual(data, r.getStrData());
        }

        TEST_METHOD(Compare)
        {
            Record r1 = { 1, "abc" },
                r11 = { 1, "abcd" },
                r2 = { 2,"abc" };

            Assert::IsTrue(r1 == r11);
            Assert::IsTrue(r1 <= r11);
            Assert::IsTrue(r1 < r2);
            Assert::IsTrue(r1 <= r2);
            Assert::IsFalse(r1 > r2);
            Assert::IsFalse(r11 > r2);
            Assert::IsFalse(r1 >= r2);
        }

        TEST_METHOD(Assign)
        {
            Record r1 = { 1, "abc" },
                r2 = { 2, "abcd" };

            r2 = r1;
            Assert::AreEqual(r1.getKey(), r2.getKey());
            Assert::AreEqual(r1.getStrData(), r2.getStrData());
        }
    };
}
