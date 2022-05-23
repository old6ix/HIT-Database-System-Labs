#pragma once

#include "AbstractBlock.h"

class BlockDecorator :public AbstractBlock
{
public:
    BlockDecorator(AbstractBlock& block);

    virtual int load(std::istream& stream) override;
    virtual int dump(std::ostream& stream) override;
    virtual size_t count() override;
    virtual int setCount(size_t num) override;
    virtual size_t size() override;
    virtual Record& operator[](int i) override;

protected:
    AbstractBlock& m_block;
};
