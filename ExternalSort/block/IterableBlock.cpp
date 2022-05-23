#include "IterableBlock.h"

IterableBlock::IterableBlock(AbstractBlock& block)
    :BlockDecorator(block)
{
    m_top_index = 0;
}

Record IterableBlock::top()
{
    if (this->empty())
        return Record();
    else
        return m_block[m_top_index];
}

void IterableBlock::pop()
{
    m_top_index++;
}

bool IterableBlock::empty()
{
    return this->count() == 0;
}

size_t IterableBlock::count()
{
    return m_block.count() - m_top_index;
}
