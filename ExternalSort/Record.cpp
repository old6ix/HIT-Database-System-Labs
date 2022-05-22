#include <cstring>
#include "Record.h"

Record::Record(const int key, const char data[data_len]) :m_key(key)
{
    memcpy(m_data, data, data_len * sizeof(char));
}

int Record::getKey() const
{
    return m_key;
}

std::string Record::getStrData() const
{
    char buf[data_len + 1];

    memcpy(buf, m_data, data_len);
    buf[data_len] = '\0';

    return std::string(buf);
}

int Record::load(std::istream& stream)
{
    // 读取索引字段
    char* key_ptr = (char*)&m_key; // 用于逐位读取int
    for (size_t i = 0; i < sizeof(int); i++)
    {
        if (!stream.good())
            return -1;
        *(key_ptr + i) = stream.get();
    }

    // 读取数据字段
    for (size_t i = 0; i < data_len; i++)
    {
        if (!stream.good())
            return -1;
        *(m_data + i) = stream.get();
    }

    return 0;
}

int Record::dump(std::ostream& stream)
{
    // 输出索引字段
    char* key_ptr = (char*)&m_key;
    for (size_t i = 0; i < sizeof(int); i++)
    {
        if (!stream.good())
            return -1;
        stream.put(*(key_ptr + i));
    }

    // 输出数据字段
    for (size_t i = 0; i < data_len; i++)
    {
        if (!stream.good())
            return -1;
        stream.put(*(m_data + i));
    }

    return 0;
}

Record& Record::operator=(const Record& other)
{
    m_key = other.m_key;
    memcpy(m_data, other.m_data, data_len * sizeof(char));
    return *this;
}

bool Record::operator==(const Record& other) const
{
    return m_key == other.m_key;
}

bool Record::operator!=(const Record& other) const
{
    return m_key != other.m_key;
}

bool Record::operator<(const Record& other) const
{
    return m_key < other.m_key;
}

bool Record::operator<=(const Record& other) const
{
    return m_key <= other.m_key;
}

bool Record::operator>(const Record& other) const
{
    return m_key > other.m_key;
}

bool Record::operator>=(const Record& other) const
{
    return m_key >= other.m_key;
}
