#pragma once
#include "BlockDecorator.h"

class SortableBlock :public BlockDecorator
{
public:
    SortableBlock(AbstractBlock& block);

    /// <summary>
    /// 为该内存块中的记录排序
    /// </summary>
    void sort();

private:
    void qsort(size_t begin, size_t end);
};
