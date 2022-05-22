#include "Block.h"

Block::Block(const size_t size) :m_size(size)
{
    m_record_array = new Record[size];
}

Block::~Block()
{
    delete[] m_record_array;
}

int Block::load(std::istream& stream)
{
    for (size_t i = 0; i < m_size; i++)
    {
        if (m_record_array[i].load(stream) == -1)
            return i; // EOF����ֹ
    }
    return 0;
}

int Block::dump(std::ostream& stream)
{
    for (size_t i = 0; i < m_size; i++)
    {
        if (m_record_array[i].dump(stream) == -1)
            return -1;
    }
    return 0;
}