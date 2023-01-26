#ifndef LAB_02_ITERATOR_REALIZE_H
#define LAB_02_ITERATOR_REALIZE_H

#include "Iterator.h"

template <typename Type>
Iterator<Type>& Iterator<Type>::operator =(const Iterator<Type>& iter)
{
    _data = iter._data;
    _index = iter._index;

    _rows = iter._rows;
    _cols = iter._cols;

    return *this;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator ++()
{
    if (_index < _cols * _rows)
    {
        ++_index;
    }

    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator ++(int)
{
    Iterator<Type> iter(*this);
    ++(*this);
    return iter;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator +(const int value) const
{
    Iterator<Type> iter(*this);

    if (value < 0 && iter._index < static_cast<size_t>(-value))
    {
        iter._index = 0;
    }
    else
    {
        iter._index += value;
    }

    if (iter._index > _rows * _cols)
    {
        iter._index = _rows * _cols;
    }

    return iter;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator +=(const size_t value)
{
    _index += value;
    return *this;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator --()
{
    if (_index < _cols * _rows)
    {
        --_index;
    }

    return *this;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator --(int)
{
    Iterator<Type> iter(*this);
    --(*this);
    return iter;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator -(const int value) const
{
    return operator +(-value);
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator -=(const size_t value)
{
    _index -= value;
    return *this;
}

template <typename Type>
Type& Iterator<Type>::operator *()
{
    check_valid(__LINE__);
    check_index(__LINE__);

    std::shared_ptr<Type[]> ptr_cpy = _data.lock();
    return *(ptr_cpy.get() + _index);
}

template <typename Type>
const Type& Iterator<Type>::operator *() const
{
    check_valid(__LINE__);
    check_index(__LINE__);

    std::shared_ptr<Type[]> ptr_cpy = _data.lock();
    return *(ptr_cpy.get() + _index);
}

template <typename Type>
Type& Iterator<Type>::operator ->()
{
    check_valid(__LINE__);
    check_index(__LINE__);

    std::shared_ptr<Type[]> ptr_cpy = _data.lock();
    return ptr_cpy.get() + _index;
}

template <typename Type>
const Type& Iterator<Type>::operator ->() const
{
    check_valid(__LINE__);
    check_index(__LINE__);

    std::shared_ptr<Type[]> ptr_cpy = _data.lock();
    return ptr_cpy.get() + _index;
}

template <typename Type>
void Iterator<Type>::check_valid(size_t line)
{
    time_t err_time = time(nullptr);

    if (this->is_valid())
    {
        throw NullPointerIteratorException(__FILE__, typeid(*this).name(), line - 4, err_time, "Pointer is null");
    }
}

template <typename Type>
void Iterator<Type>::check_index(size_t line)
{
    time_t err_time = time(nullptr);

    if (_index > _rows * _cols)
    {
        throw IndexIteratorException(__FILE__, typeid(*this).name(), line - 4, err_time, "Index error");
    }
}


#endif //LAB_02_ITERATOR_REALIZE_H
