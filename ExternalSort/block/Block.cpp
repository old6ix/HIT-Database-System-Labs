#include "Block.h"

Block::Block(const size_t size)
    :m_size(size), m_cnt(0)
{
    m_record_array = new Record[size];
}

Block::~Block()
{
    delete[] m_record_array;
}

int Block::load(std::istream& stream)
{
    int i;
    for (i = 0; i < m_size; i++)
    {
        if (m_record_array[i].load(stream) == -1)
            break;
    }
    this->m_cnt = (size_t)i; // 存储读入记录条数
    return i;
}

int Block::dump(std::ostream& stream)
{
    for (size_t i = 0; i < m_cnt; i++)
    {
        if (m_record_array[i].dump(stream) == -1)
            return -1;
    }
    return 0;
}

size_t Block::count()
{
    return m_cnt;
}

int Block::setCount(size_t num)
{
    if (num > m_size)
        return -1;

    m_cnt = num;
    return 0;
}

size_t Block::size()
{
    return m_size;
}

Record& Block::operator[](int i)
{
    return m_record_array[i];
}
