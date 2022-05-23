#pragma once

#include "Record.h"

/// <summary>
/// 不能push的栈
/// </summary>
/// <typeparam name="T">栈中元素类型</typeparam>
template <class T>
class PopOnlyStack
{
public:
    /// <summary>
    /// 从栈顶弹出一个元素
    /// </summary>
    /// <returns>栈顶元素</returns>
    virtual T top() = 0;

    /// <summary>
    /// 弹出栈顶元素
    /// </summary>
    virtual void pop() = 0;

    /// <summary>
    /// 查看栈是否为空
    /// </summary>
    /// <returns>栈是否为空</returns>
    virtual bool empty() = 0;
};
