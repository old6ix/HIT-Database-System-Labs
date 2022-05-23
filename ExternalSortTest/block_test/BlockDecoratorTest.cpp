#include "pch.h"
#include "CppUnitTest.h"

#include <sstream>
#include "AbstractBlock.h"
#include "Block.h"
#include "BlockDecorator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExternalSortTest
{
    TEST_CLASS(BlockDecoratorTest)
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
            Record r1 = { 1, "data1" },
                r2 = { 2, "data2" };

            Block b = { 5 };
            BlockDecorator bd = { b };

            Assert::AreEqual((size_t)5, bd.size());

            // 测试和设置内存块的有效记录个数
            Assert::AreEqual(-1, bd.setCount(11));
            Assert::AreEqual((size_t)0, bd.count());
            Assert::AreEqual(0, bd.setCount(2));
            Assert::AreEqual((size_t)2, bd.count());

            bd[0] = r1;
            bd[1] = r2;

            Assert::IsFalse(&bd[0] == &r1);
            Assert::IsFalse(&bd[1] == &r2);

            Assert::AreEqual(r1.getKey(), bd[0].getKey());
            Assert::AreEqual(0, r2.getStrData().compare(bd[1].getStrData()));
        }

        TEST_METHOD(Load)
        {
            // Test data
            std::string dumped = simpleDumped;
            std::istringstream input(dumped);

            // Begin test
            Block b = { 2 };
            BlockDecorator bd = { b };
            AbstractBlock &ab = bd;

            Assert::AreEqual(2, ab.load(input));
            Assert::AreEqual(1, ab[0].getKey());
            Assert::AreEqual(2, ab[1].getKey());
        }

        TEST_METHOD(Dump)
        {
            Block b = { 2 };
            BlockDecorator bd = { b };
            AbstractBlock& ab = bd;
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
