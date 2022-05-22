#pragma once

#include <iostream>

class Serializable
{
public:
    /// <summary>
    /// 从流中载入类
    /// </summary>
    /// <param name="stream">输入流</param>
    virtual int load(std::istream& stream) = 0;

    /// <summary>
    /// 将类输出至流中
    /// </summary>
    /// <param name="stream">输出流</param>
    virtual int dump(std::ostream& stream) = 0;
};

