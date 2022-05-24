#include <cstring>
#include "LoserTree.h"

LoserTree::LoserTree(int k, IterableBlock* ib_array[])
    :m_k(k), m_WIN(-1)
{
    m_ib_array = new IterableBlock * [k];
    memcpy(m_ib_array, ib_array, k * sizeof(IterableBlock*));

    m_tree = new int[m_k + 1];

    this->build();
}

LoserTree::~LoserTree()
{
    delete[] m_ib_array;
    delete[] m_tree;
}

Record LoserTree::top()
{
    IterableBlock* b = m_ib_array[m_tree[0]]; // 树顶元素所在归并段
    return b->top();
}

void LoserTree::pop()
{
    int popping = m_tree[0]; // 待弹出的归并段下标
    m_ib_array[popping]->pop();
    this->adjust(popping);
}

bool LoserTree::empty()
{
    // 若所有内存块都空，就说明树空了
    bool all_empty = true;
    for (size_t i = 0; i < m_k; i++)
        all_empty &= m_ib_array[i]->empty();
    return all_empty;
}

void LoserTree::build()
{
    // 将所有节点初始化为绝对胜者
    for (int i = 1; i < m_k; i++)
        m_tree[i] = -1;

    // 调整每个归并段
    for (int i = 0; i < m_k; i++)
        this->adjust(i);

    // 此时树顶为第一个胜者
    // 原因为调整时[1]的胜者不与[0]作比较，直接覆盖
}

void LoserTree::adjust(int b_index)
{
    // 初始为待调整归并段的父节点下标
    // 始终指向当前节点的守擂者
    int t = (b_index + m_k) / 2;

    // 逐层调整直至根节点
    while (t > 0) {
        // 每次循环开始，b_index指向前来挑战的节点

        // 判断是否必赢
        bool winned = b_index == m_WIN; // 攻擂者为绝对赢者则必赢
        if (m_tree[t] != m_WIN)
            winned |= m_ib_array[m_tree[t]]->empty(); // 守擂者为空则必赢

        // 判断是否必输
        bool losed = m_tree[t] == m_WIN; // 守擂者为绝对赢者则必输
        if (b_index != m_WIN)
            losed |= m_ib_array[b_index]->empty(); // 不用比较，已经输了

        if (!winned)
        {
            if (losed)
            {
                std::swap(m_tree[t], b_index);
            }
            else
            {
                const Record& curr = m_ib_array[b_index]->top();
                const Record& father = m_ib_array[m_tree[t]]->top();
                if (curr >= father) // 当前节点输了，留在原地（t处），更新b_index
                {
                    std::swap(m_tree[t], b_index);
                }
            }
        }

        t /= 2; // 指向上一节点，继续比较
    }
    m_tree[0] = b_index; // 最终胜者
}

inline int LoserTree::father(int index)
{
    return index / 2;
}
