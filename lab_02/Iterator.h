#ifndef ITERATOR_BASE_H
#define ITERATOR_BASE_H

#include <memory>
#include <string>

#include "matrix_base_exception.h"

template <typename Type>
class Matrix;

template <typename Type>
class Iterator : public std::iterator<std::input_iterator_tag, Type>
{
public:
    Iterator(const Matrix<Type>& mtrx, const size_t index = 0)
		: _data(mtrx.data), _index(index), _rows(mtrx.get_n()), _cols(mtrx.get_m()) {  }

	Iterator(const Iterator& iter) = default;

	// Equals
	bool operator !=(Iterator const& other) const { return _index != other._index; }
	bool operator ==(Iterator const& other) const { return _index == other._index; }

	Iterator<Type>& operator =(const Iterator<Type>& iter);

	// Addition
	Iterator<Type>& operator ++();
	Iterator<Type> operator ++(int);
	Iterator<Type> operator +(const int value) const;
    Iterator<Type>& operator +=(const size_t value);

	// Substraction
	Iterator<Type>& operator --();
	Iterator<Type>& operator --(int);
	Iterator<Type> operator -(const int value) const;
    Iterator<Type>& operator -=(const size_t value);

	// Pointers
	Type& operator *();
	const Type& operator *() const;

	Type& operator ->();
	const Type& operator ->() const;

	// Other methods
	operator bool() const { return _data.expired(); }
	bool is_end() const { return _index == _rows * _cols; }
	bool is_valid() const { return _data.expired(); }
	Iterator<Type>& next() { return operator ++(); }

private:
    std::weak_ptr<Type[]> _data = nullptr;
	size_t _index = 0;
	size_t _rows = 0;
	size_t _cols = 0;

	void check_valid(size_t line);
	void check_index(size_t line);
};

#endif //!ITERATOR_BASE_H
