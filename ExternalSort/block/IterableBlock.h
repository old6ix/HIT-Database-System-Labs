#pragma once

#include "PopOnlyStack.h"
#include "BlockDecorator.h"

class IterableBlock
    :public BlockDecorator, PopOnlyStack<Record>
{
public:
    IterableBlock(AbstractBlock& block);

    virtual Record top() override;
    virtual void pop() override;
    virtual bool empty() override;

    /// <summary>
    /// 获取块中剩余记录个数
    /// </summary>
    /// <returns>剩余记录个数</returns>
    virtual size_t count() override;

protected:
    size_t m_top_index; // 栈顶指针
};
