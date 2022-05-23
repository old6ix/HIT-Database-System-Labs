#include "pch.h"
#include "CppUnitTest.h"

#include <sstream>
#include "Block.h"
#include "IterableBlock.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExternalSortTest
{
    TEST_CLASS(IterableBlockTest)
    {
    private:
        std::string dumped = {
            1, 0, 0, 0,
            'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!',
            2, 0, 0, 0,
            'a', 'b', 'c', 'd', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
        };

    public:
        TEST_METHOD(StackOpts)
        {
            std::istringstream input(this->dumped);

            // ≥ı ºªØBlock
            Block b = { 2 };
            AbstractBlock& ab = { b };
            ab.load(input);

            IterableBlock ib = { ab };

            Assert::IsFalse(ib.empty());
            
            Assert::AreEqual(1, ib.top().getKey());
            Assert::IsFalse(ib.empty());

            ib.pop();
            Assert::AreEqual((size_t)1, ib.count());

            Assert::AreEqual(2, ib.top().getKey());
            Assert::IsFalse(ib.empty());

            ib.pop();
            Assert::AreEqual((size_t)0, ib.count());
            Assert::IsTrue(ib.empty());
        }
    };
}
