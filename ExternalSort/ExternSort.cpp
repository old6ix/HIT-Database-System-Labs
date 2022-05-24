#include <iostream>
#include <fstream>
#include <random>
#include <cassert>
#include "Block.h"
#include "SortableBlock.h"
#include "BlockStream.h"
#include "LoserTree.h"


// 参数设置
const int MEMORY_MAX = 1024 * 1024; // 内存限制为1MB
const int N = 1000000; // 总数据一百万条

const int K = 20; // 归并段个数
const int N_EACH = MEMORY_MAX / (K + 1) / sizeof(Record); // 每段记录个数，即每个归并段的大小

const std::string SRC_FILENAME = "data.in"; // 原数据文件名
const std::string TAR_FILENAME = "data.out"; // 排序后数据文件名
const std::string TMP_PREFIX = "tmp"; // 临时文件名前缀，将以后面+%d的形式生成临时文件

/// <summary>
/// 生成随机记录数据
/// </summary>
/// <param name="filename">输出文件名</param>
/// <param name="n">记录个数</param>
void generateRandomData()
{
    std::ofstream fout(SRC_FILENAME, std::fstream::out | std::fstream::binary);

    for (size_t i = 0; i < N; i++)
    {
        // 随机生成索引值
        int key = rand() % N;
        fout.write((char*)&key, 4);

        // 生成数据段
        char data[13] = "Hello world!";
        fout.write(data, 12); // 数据段共12byte
    }

    std::cout << "Generated " << N << " records." << std::endl;
}

std::vector<std::string> firstSort()
{
    std::ifstream fin(SRC_FILENAME, std::fstream::in | std::fstream::binary); // 打开原始文件

    int load_total = 0; // 共载入的记录条数，方便输出
    std::vector<std::string> tmp_namelist; // 临时文件名，将被返回

    Block b{ N_EACH };
    SortableBlock sort_b{ b };
    for (int i = 0; i < K; i++) // 归并至K个文件中
    {
        std::string tmp_filename{ TMP_PREFIX + std::to_string(i) };
        tmp_namelist.emplace_back(tmp_filename);
        std::ofstream fout(tmp_filename, std::fstream::out | std::fstream::binary); // 打开临时文件

        int tmp_total = 0; // 当前临时文件共载入的记录条数
        while (tmp_total < N / 20)
        {
            int cnt = sort_b.load(fin);
            if (cnt == 0)
                break;

            load_total += cnt;
            tmp_total += cnt;
            sort_b.sort();
            sort_b.dump(fout);
        }

        std::cout << "Temp file \"" << tmp_filename << "\" loaded " << tmp_total << " records." << std::endl;
    }

    std::cout << "First sort finished." << "(" << load_total << " records total)" << std::endl;
    return tmp_namelist;
}

void mergeSort(std::vector<std::string>& tmp_namelist)
{
    assert(tmp_namelist.size() == K);

    /* 准备数据 */
    // 打开K路文件
    std::ifstream tmp_stream[K];
    for (size_t i = 0; i < K; i++)
        tmp_stream[i].open(tmp_namelist[i], std::fstream::in | std::fstream::binary);

    // 装载K个记录块流
    std::allocator<Block> alloc; // 首先生成基本内存块
    Block* b_array = alloc.allocate(K);
    for (size_t i = 0; i < K; i++)
        alloc.construct(b_array + i, N_EACH);

    IterableBlock* sb_array[K]; // 装饰基本内存块
    for (size_t i = 0; i < K; i++)
        sb_array[i] = new BlockStream{ b_array[i], tmp_stream[i] };

    // 设置输出块
    std::ofstream fout(TAR_FILENAME, std::fstream::out | std::fstream::binary);
    Block output_block{ N_EACH };
    size_t ob_cnt = 0; // 输出块的记录个数

    /* 开始归并 */
    LoserTree ltree{ K, sb_array };
    while (!ltree.empty())
    {
        // 取出当前记录，放入输出块中
        output_block.setCount(ob_cnt + 1);
        output_block[ob_cnt] = ltree.top();
        ob_cnt++;

        if (ob_cnt == N_EACH) // 若输出块满，则输出
        {
            output_block.dump(fout);
            ob_cnt = 0;
        }

        ltree.pop();
    }
    output_block.dump(fout); // 将输出块中剩余记录输出

    // 关闭K路文件
    for (size_t i = 0; i < K; i++)
        tmp_stream[i].close();

    // 关闭输出文件
    fout.close();
}

int main()
{
    // 生成随机数据
    generateRandomData();

    // 第一趟排序
    auto tmp_namelist = firstSort();

    // 第二趟排序
    mergeSort(tmp_namelist);

    return 0;
}
