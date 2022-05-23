#include <algorithm>
#include "SortableBlock.h"

SortableBlock::SortableBlock(AbstractBlock& block)
    :BlockDecorator(block)
{}

void SortableBlock::sort()
{
    this->qsort(0, this->count());
}

void SortableBlock::qsort(size_t begin, size_t end)
{
    if (begin >= end)
        return;

    Record key = m_block[begin];

    size_t i = begin;
    size_t j = end;
    while (i < j) {
        while (i < j && m_block[j] > key) {
            j--;
        }
        if (i < j) {
            m_block[i] = m_block[j];
            i++;
        }
        while (i < j && m_block[i] < key) {
            i++;
        }
        if (i < j) {
            m_block[j] = m_block[i];
            j--;
        }
    }
    m_block[i] = key;

    if (i != 0) // 如果左侧还有元素
        this->qsort(begin, i - 1);
    if (i < this->count() - 1) // 如果右侧还有元素
        this->qsort(i + 1, end);
}
