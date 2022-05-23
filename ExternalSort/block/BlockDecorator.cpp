#include "BlockDecorator.h"

BlockDecorator::BlockDecorator(AbstractBlock& block) :m_block(block)
{}

int BlockDecorator::load(std::istream& stream)
{
    return m_block.load(stream);
}

int BlockDecorator::dump(std::ostream& stream)
{
    return m_block.dump(stream);
}

size_t BlockDecorator::size()
{
    return m_block.size();
}

Record& BlockDecorator::operator[](int i)
{
    return m_block[i];
}
