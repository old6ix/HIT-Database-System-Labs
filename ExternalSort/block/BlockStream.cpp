#include "BlockStream.h"

BlockStream::BlockStream(AbstractBlock& block, std::istream& in)
    :IterableBlock(block), m_in(in)
{
    m_block.load(m_in); // 载入第一个内存块
}

void BlockStream::pop()
{
    m_top_index++; // 弹出栈顶
    
    // 若当前内存块迭代完
    if (this->empty())
    {
        m_block.load(m_in); // 载入下一个内存块
        m_top_index = 0; // 重置栈状态
    }
}
