#include "pch.h"
#include "CppUnitTest.h"

#include <sstream>
#include "../ExternalSort/block/AbstractBlock.h"
#include "../ExternalSort/block/Block.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExternalSortTest
{
    TEST_CLASS(BlockTest)
    {
    private:
        std::string simpleDumped = {
            1, 0, 0, 0,
            'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!',
            2, 0, 0, 0,
            'a', 'b', 'c', 'd', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        };
    
    public:
        TEST_METHOD(CreateGetSet)
        {
            Record r1= { 1, "data1" },
                r2= { 2, "data2" };

            Block b = { 10 };

            Assert::AreEqual((size_t)10, b.size());

            // 测试和设置内存块的有效记录个数
            Assert::AreEqual(-1, b.setCount(11));
            Assert::AreEqual((size_t)0, b.count());
            Assert::AreEqual(0, b.setCount(2));
            Assert::AreEqual((size_t)2, b.count());

            // 设置记录值用于后续测试
            b[0] = r1;
            b[1] = r2;

            // 测试是否有表示暴露
            Assert::IsFalse(&b[0] == &r1);
            Assert::IsFalse(&b[1] == &r2);

            // 测试块内记录个数和块大小是否正确
            Assert::AreEqual((size_t)2, b.count());
            Assert::AreEqual((size_t)10, b.size());

            // 测试块内数据是否正确
            Assert::AreEqual(r1.getKey(), b[0].getKey());
            Assert::AreEqual(0, r2.getStrData().compare(b[1].getStrData()));
        }

        TEST_METHOD(Load)
        {
            // Test data
            std::string dumped = simpleDumped;
            std::istringstream input(dumped);

            // Begin test
            Block b = { 5 };
            AbstractBlock &ab = b;

            Assert::AreEqual(2, ab.load(input));
            Assert::AreEqual(1, ab[0].getKey());
            Assert::AreEqual(2, ab[1].getKey());
        }

        TEST_METHOD(Dump)
        {
            Block b = { 2 };
            AbstractBlock& ab = b;
            ab.setCount(2);
            ab[0] = { 1, "Hello world!" };
            ab[1] = { 2, "abcd" };

            std::ostringstream output;
            Assert::AreEqual(0, ab.dump(output));

            std::string out_str = output.str();
            Assert::AreEqual(0, simpleDumped.substr(0, 4).compare(out_str.substr(0, 4)));
            Assert::AreEqual(0, simpleDumped.substr(4, 12).compare(out_str.substr(4, 12)));
            Assert::AreEqual(0, simpleDumped.substr(12, 4).compare(out_str.substr(12, 4)));
            Assert::AreEqual(0, simpleDumped.substr(16, 12).compare(out_str.substr(16, 12)));
        }
    };
}
