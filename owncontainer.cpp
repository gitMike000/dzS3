#include "owncontainer.h"

#include <algorithm>

OwnContainer::OwnContainer(std::initializer_list<int> values) :
    size(values.size()),
    data(new int[size])
{
    std::copy(values.begin(), values.end(), data.get());
}

OwnContainer::iterator OwnContainer::begin()
{
    return iterator(data.get());
}

OwnContainer::iterator OwnContainer::end()
{
    return iterator(data.get() + size);
}

OwnContainer::const_iterator OwnContainer::begin() const
{
    return const_iterator(data.get());
}

OwnContainer::const_iterator OwnContainer::end() const
{
    return const_iterator(data.get() + size);
}

OwnContainer::riterator OwnContainer::rbegin()
{
    return riterator(data.get() + size-size_t(1));
}

OwnContainer::riterator OwnContainer::rend()
{
    return riterator(data.get()-size_t(1));
}

OwnContainer::const_riterator OwnContainer::rbegin() const
{
    return const_riterator(data.get() + size-size_t(1));
}

OwnContainer::const_riterator OwnContainer::rend() const
{
    return const_riterator(data.get()-size_t(1));
}

