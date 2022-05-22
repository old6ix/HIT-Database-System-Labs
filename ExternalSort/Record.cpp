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
