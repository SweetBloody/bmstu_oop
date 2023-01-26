#ifndef ITERATOR_CONST_H
#define ITERATOR_CONST_H

#include <memory>
#include <string>

#include "matrix_base_exception.h"
#include "iterator_exception.h"

template<typename Type>
class Matrix;

template<typename Type>
class IteratorConst : public std::iterator<std::input_iterator_tag, Type>
{
public:
	IteratorConst(const Matrix<Type>& mtrx, const size_t index = 0)
		: _data(mtrx.data), _index(index), _rows(mtrx.get_n()), _cols(mtrx.get_m()) {  }

	IteratorConst(const IteratorConst& iter) = default;

	bool operator !=(IteratorConst const& other) const { return _index != other._index; }
	bool operator ==(IteratorConst const& other) const { return _index == other._index; }

	IteratorConst<Type>& operator =(const IteratorConst<Type>& iter);

	// Addition
    IteratorConst<Type>& operator ++();
	IteratorConst<Type> operator ++(int) const;
	IteratorConst<Type> operator +(const int value) const;
    IteratorConst<Type>& operator +=(const size_t value);

	// Substraction
    IteratorConst<Type>& operator --();
	IteratorConst<Type>& operator --(int) const;
	IteratorConst<Type> operator -(const int value) const;
    IteratorConst<Type>& operator -=(const size_t value);

	// Pointers
	const Type& operator *() const;
	Type& operator ->() const;

	// Other methods
	operator bool() const { return _data.expired(); }
	bool is_end() const { return _index == _rows * _cols; }
	bool is_valid() const { return _data.expired(); }
	IteratorConst<Type>& next() const { return operator ++(); }

private:
	std::weak_ptr<Type> _data = nullptr;
	size_t _index = 0;
	size_t _rows = 0;
	size_t _cols = 0;

	void check_valid(size_t line);
	void check_index(size_t line);
};

#endif // !ITERATOR_CONST_H
