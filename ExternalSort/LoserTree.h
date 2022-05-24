#pragma once

#include "PopOnlyStack.h"
#include "Record.h"
#include "IterableBlock.h"

class LoserTree :public PopOnlyStack<Record>
{
public:
    /// <summary>
    /// 创建一棵败者树
    /// </summary>
    /// <param name="k">归并段数</param>
    /// <param name="ib_array">各归并段组成的数组</param>
    LoserTree(int k, IterableBlock* ib_array[]);

    ~LoserTree();

    virtual Record top() override;
    virtual void pop() override;
    virtual bool empty() override;

private:
    /// <summary>
    /// 建立败者树
    /// </summary>
    void build();

    /// <summary>
    /// 从指定归并段开始调整败者树
    /// </summary>
    /// <param name="b_index">起始归并段</param>
    void adjust(int b_index);

    static inline int father(int index);

private:
    /// <summary>
    /// 归并段数
    /// </summary>
    const int m_k;

    /// <summary>
    /// 败者树,[0]存放胜者归并段，其余存放败者归并段
    /// -1表示绝对胜者，m_k表示绝对败者
    /// </summary>
    int* m_tree;

    /// <summary>
    /// 各归并段
    /// </summary>
    IterableBlock** m_ib_array;

    /// <summary>
    /// 绝对赢的归并段
    /// </summary>
    const int m_WIN;
};

