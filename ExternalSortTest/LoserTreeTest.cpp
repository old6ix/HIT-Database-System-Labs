#include "pch.h"
#include "CppUnitTest.h"

#include <memory>
#include <sstream>
#include <ctime>
#include "Record.h"
#include "Block.h"
#include "IterableBlock.h"
#include "LoserTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExternalSortTest
{
    TEST_CLASS(LoserTreeTest)
    {
    public:
        TEST_METHOD(Main)
        {
            srand((int)time(NULL));

            const int K = 5; // 归并段数
            const int N = 100; // 记录总个数
            std::string data = "Hello world!";

            // 申请内存块数组
            std::allocator<Block> a1;
            Block* b_array = a1.allocate(K);
            for (size_t i = 0; i < K; i++)
                a1.construct(b_array + i, N);

            std::allocator<IterableBlock> a2;
            IterableBlock* ib_array = a2.allocate(K);
            for (size_t i = 0; i < K; i++)
                a2.construct(ib_array + i, b_array[i]);


            // 初始化各内存块中的数据
            // 每次随机选择一个归并段插入记录
            for (int key = 1; key <= N; key++)
            {
                Block& b = b_array[rand() % K]; // 随机选择一个归并段

                size_t cnt = b.count();
                b.setCount(cnt + 1);
                b[cnt] = { key, data.c_str() };
            }

            // 归并并检查是否正确
            LoserTree ltree{ K, ib_array };
            int key_prev = 0;
            while (!ltree.empty())
            {
                int key_curr = ltree.top().getKey();
                Assert::AreEqual(key_prev + 1, key_curr);

                key_prev = key_curr;
                ltree.pop();
            }

            // 释放各内存块
            for (size_t i = 0; i < K; i++)
                a2.destroy(ib_array + i);
            a2.deallocate(ib_array, K);
            for (size_t i = 0; i < K; i++)
                a1.destroy(b_array + i);
            a1.deallocate(b_array, K);
        }
    };
}
