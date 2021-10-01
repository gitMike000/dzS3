#ifndef ROWNITERATOR_H
#define ROWNITERATOR_H

#include <iterator>
#include <initializer_list>

class ROwnContainer;

template<typename ValueType>
class ROwnIterator: public std::iterator<std::input_iterator_tag, ValueType>
{
    friend class OwnContainer;
private:
    ROwnIterator(ValueType* p);
public:
    ROwnIterator(const ROwnIterator &it);

    bool operator!=(ROwnIterator const& other) const;
    bool operator==(ROwnIterator const& other) const; //need for BOOST_FOREACH
    typename ROwnIterator::reference operator*() const;
    ROwnIterator& operator++();
private:
    ValueType* p;
};

template<typename ValueType>
ROwnIterator<ValueType>::ROwnIterator(ValueType *p) :
    p(p)
{

}

template<typename ValueType>
ROwnIterator<ValueType>::ROwnIterator(const ROwnIterator& it) :
    p(it.p)
{

}

template<typename ValueType>
bool ROwnIterator<ValueType>::operator!=(ROwnIterator const& other) const
{
    return p != other.p;
}

template<typename ValueType>
bool ROwnIterator<ValueType>::operator==(ROwnIterator const& other) const
{
    return p == other.p;
}

template<typename ValueType>
typename ROwnIterator<ValueType>::reference ROwnIterator<ValueType>::operator*() const
{
    return *p;
}

template<typename ValueType>
ROwnIterator<ValueType> &ROwnIterator<ValueType>::operator++()
{
    --p;
    return *this;
}

#endif // ROWNITERATOR_H
