#include <cstring>
#include "Record.h"

Record::Record() :m_key(-1), m_data{ '\0' }
{}

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
    if (!stream.good())
        return -1;
    stream.read((char*)&m_key, sizeof(int));

    // 读取数据字段
    if (!stream.good())
        return -1;
    stream.read(m_data, this->data_len);

    return 0;
}

int Record::dump(std::ostream& stream)
{
    // 输出索引字段
    if (!stream.good())
        return -1;
    stream.write((char*)&m_key, sizeof(int));

    // 输出数据字段
    if (!stream.good())
        return -1;
    stream.write(m_data, this->data_len);

    return 0;
}

Record& Record::operator=(const Record& other)
{
    m_key = other.m_key;
    memcpy(m_data, other.m_data, data_len);
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
