#pragma once

#include <string>
#include "Serializable.h"

/// <summary>
/// 一条记录
/// </summary>
class Record :public Serializable
{
private:
    static const size_t data_len = 12; // 数据字段字节数

public:
    Record() = default;

    /// <summary>
    /// 创建一条新记录
    /// </summary>
    /// <param name="key">索引字段</param>
    /// <param name="data">数据字段，12字节字符数组</param>
    Record(const int key, const char data[data_len]);

    /// <summary>
    /// 获取索引值
    /// </summary>
    /// <returns>该条记录的索引值</returns>
    int getKey() const;

    /// <summary>
    /// 获取数据字段对应的字符串表示
    /// </summary>
    /// <returns>数据字段对应的字符串</returns>
    std::string getStrData() const;

    /// <summary>
    /// 从流中载入记录
    /// </summary>
    /// <param name="stream">输入流</param>
    /// <returns>成功返回0，失败返回-1</returns>
    virtual int load(std::istream& stream) override;

    /// <summary>
    /// 将记录输出至流中
    /// </summary>
    /// <param name="stream">输出流</param>
    /// <returns>成功返回0，失败返回-1</returns>
    virtual int dump(std::ostream& stream) override;

    Record& operator=(const Record& other);
    bool operator==(const Record& other) const;
    bool operator!=(const Record& other) const;
    bool operator<(const Record& other) const;
    bool operator<=(const Record& other) const;
    bool operator>(const Record& other) const;
    bool operator>=(const Record& other) const;

private:
    int m_key; // A属性
    char m_data[12]; // B属性，12字节字符数组
};
