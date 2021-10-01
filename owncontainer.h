#ifndef OWNCONTAINER_H
#define OWNCONTAINER_H

#include "owniterator.h"
#include "rowniterator.h"

#include <memory>

class OwnContainer
{
public:
    typedef OwnIterator<int> iterator;
    typedef OwnIterator<const int> const_iterator;

    typedef ROwnIterator<int> riterator;
    typedef ROwnIterator<const int> const_riterator;

    OwnContainer(std::initializer_list<int> values);

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    riterator rbegin();
    riterator rend();

    const_riterator rbegin() const;
    const_riterator rend() const;
private:
    const size_t size;
    std::unique_ptr<int[]> data;
};

#endif // OWNCONTAINER_H
