#pragma once

#include "Serializable.h"
#include "Record.h"

class AbstractBlock :public Serializable
{
public:
    /// <summary>
    /// 从流中读入记录块，返回读入的条数
    /// </summary>
    /// <param name="stream">输入流</param>
    /// <returns>读入记录的个数</returns>
    virtual int load(std::istream& stream) override = 0;

    /// <summary>
    /// 将当前记录块输出到流中
    /// </summary>
    /// <param name="stream">输出流</param>
    /// <returns>输出成功返回0，失败返回-1</returns>
    virtual int dump(std::ostream& stream) override = 0;

    /// <summary>
    /// 获取块中记录个数
    /// </summary>
    /// <returns>记录个数</returns>
    virtual size_t count() = 0;

    /// <summary>
    /// 设置块中有效记录个数
    /// </summary>
    /// <returns>成功返回0，失败返回-1</returns>
    virtual int setCount(size_t num) = 0;

    /// <summary>
    /// 获取块的可容纳记录个数
    /// </summary>
    /// <returns>可容纳记录个数</returns>
    virtual size_t size() = 0;

    /// <summary>
    /// 获取块中指定位置的记录
    /// </summary>
    /// <param name="i">偏移量</param>
    /// <returns>块内第i条记录</returns>
    virtual Record& operator[](int i) = 0;
};
