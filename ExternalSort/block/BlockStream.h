#pragma once

#include <istream>
#include "IterableBlock.h"

class BlockStream :public IterableBlock
{
public:
    BlockStream(AbstractBlock& block, std::istream& in);

    virtual void pop() override;

protected:
    std::istream& m_in;
};
