#ifndef MATRIX_REALIZATION_H
#define MATRIX_REALIZATION_H

#include "Matrix.h"

#include <iostream>
#include <cstdlib>
#include <ctime>


// Constructors
template<typename Type>
Matrix<Type>::Matrix()
{
	this->data = nullptr;

	this->element_numb = 0;
	this->n = 0;
	this->m = 0;
}

template<typename Type>
Matrix<Type>::Matrix(size_t n, size_t m)
{
	time_t err_time = time(nullptr);

	if ((n == 0) || (m == 0))
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Incorrect matrix size");
	}

	this->element_numb = n * m;
	this->n = n;
	this->m = m;

	try
	{
        this->data = std::shared_ptr<Type[]>(new Type[element_numb]);
	}

	catch (std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}
}

template<typename Type>
Matrix<Type>::Matrix(const Matrix<Type>& mtrx) : MatrixBase()
{
	time_t err_time = time(nullptr);

	this->n = mtrx.get_n();
	this->m = mtrx.get_m();
	this->element_numb = mtrx.size();

	try
	{
        this->data = std::shared_ptr<Type[]>(new Type[element_numb]);
	}

	catch (std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}

	for (size_t i = 0; i < this->n; i++)
	{
		for (size_t j = 0; j < this->m; j++)
		{
			this->data.get()[i * m + j] = mtrx.data.get()[i * m + j];
		}
	}
}

template<typename Type>
Matrix<Type>::Matrix(Matrix<Type>&& mtrx) noexcept
{
	this->n = mtrx.get_n();
	this->m = mtrx.get_m();
	this->element_numb = mtrx.size();
    this->data = mtrx.data;
}

template<typename Type>
Matrix<Type>::Matrix(std::initializer_list<std::initializer_list<Type>> list)
{
	time_t err_time = time(nullptr);

	this->n = list.size();
	this->m = list.begin()->size();
	this->element_numb = n * m;

	try
	{
        this->data = std::shared_ptr<Type[]>(new Type[element_numb]);
	}

	catch (std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}

	auto iter_i = list.begin();

	for (size_t i = 0; iter_i != list.end(); i++, iter_i++)
	{
		if (this->m != iter_i->size())
		{
			throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
		}
		else
		{
			auto iter_j = iter_i->begin();

			for (size_t j = 0; iter_j != iter_i->end(); j++, iter_j++)
			{
				this->data.get()[i * this->m + j] = *iter_j;
			}
		}
	}
}

template <typename Type>
Matrix<Type>::Matrix(Type** m, size_t row, size_t clm)
{
    this->n = row;
    this->m = clm;
    this->element_numb = row * clm;

    if (m == nullptr)
    {
        throw NullPtrException(__FILE__, typeid(*this).name(), __LINE__,
                               time(nullptr),
                               "Pointer to matrix is null");
    }
    try
    {
        this->data = std::shared_ptr<Type>(new Type[this->elem_num]);
    }
    catch (std::bad_alloc&)
    {
        throw BadAllocException(__FILE__, typeid(*this).name(), __LINE__, time(nullptr),"Bad alloc");
    }

    auto dst_ptr = data.get();

    for (size_t i = 0; i < rows; i++) {

        if (m[i] == nullptr)
            throw NullPtrException(__FILE__, typeid(*this).name(), __LINE__,
                                   time(nullptr),
                                   "Pointer to matrix is null");

        for (size_t j = 0; j < clm; j++) {
            dst_ptr[i * columns + j] = m[i][j];
        }
    }
}

// Destructor
template<typename Type>
Matrix<Type>::~Matrix()
{
	this->data.reset();
	this->n = 0;
	this->m = 0;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator =(const Matrix<Type>& mtrx)
{
	time_t err_time = time(nullptr);

	size_t n_mtrx = mtrx.get_n();
	size_t m_mtrx = mtrx.get_m();

	this->n = n_mtrx;
	this->m = m_mtrx;
	this->element_numb = mtrx.element_numb;

	try
	{
        this->data = std::shared_ptr<Type[]>(new Type[element_numb]);
	}

	catch(std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}

	if ((this->m == m_mtrx) && (this->n == n_mtrx))
	{
		for (size_t i = 0; i < n_mtrx; i++)
		{
			for (size_t j = 0; j < m_mtrx; j++)
			{
				this->data.get()[i * m + j] = mtrx.data.get()[i * m + j];
			}
		}
	}
	else
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator =(Matrix<Type>&& mtrx)
{
	time_t err_time = time(nullptr);

	size_t n_mtrx = mtrx.get_n();
	size_t m_mtrx = mtrx.get_m();

	this->n = n_mtrx;
	this->m = m_mtrx;
	this->element_numb = mtrx.element_numb;

	try
	{
        this->data = std::shared_ptr<Type[]>(new Type[element_numb]);
	}

	catch (std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}

	if ((this->m == m_mtrx) && (this->n == n_mtrx))
	{
		for (size_t i = 0; i < n_mtrx; i++)
		{
			for (size_t j = 0; j < m_mtrx; j++)
			{
				this->data.get()[i * m + j] = mtrx.data.get()[i * m + j];
			}
		}
	}
	else
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator =(std::initializer_list<std::initializer_list<Type>> list)
{
	time_t err_time = time(nullptr);

	this->n = list.size();
	this->m = list.begin()->size();
	this->element_numb = n * m;

	try
	{
        this->data = std::shared_ptr<Type[]>(new Type[element_numb]);
	}

	catch (std::bad_alloc)
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
	}

	auto iter_i = list.begin();

	for (size_t i = 0; iter_i != list.end(); i++, iter_i++)
	{
		if (this->m != iter_i->size())
		{
			throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
		}
		else
		{
			auto iter_j = iter_i->begin();

			for (size_t j = 0; iter_j != iter_i->end(); j++, iter_j++)
			{
				this->data.get()[i * this->m + j] = *iter_j;
			}
		}
	}

	return *this;
}

// Private methods
template<typename Type>
void Matrix<Type>::addition(const Matrix<Type>& mtrx) const
{
	for (size_t i = 0; i < this->get_n(); i++)
	{
		for (size_t j = 0; j < this->get_m(); j++)
		{
			this->data.get()[i * this->get_m() + j] += mtrx[i][j];
		}
	}
}

template<typename Type>
void Matrix<Type>::addition(const Type& value) const
{
	for (size_t i = 0; i < this->get_n(); i++)
	{
		for (size_t j = 0; j < this->get_m(); j++)
		{
			this->data.get()[i * this->get_m() + j] += value;
		}
	}
}


// Public methods
template<typename Type>
Matrix<Type> Matrix<Type>::operator +(const Matrix<Type>& mtrx1) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty() || mtrx1.is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}

	if ((mtrx1.get_n() != this->n) && (mtrx1.get_m() != this->m))
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}
	else
	{
		Matrix<Type> result(*this);
		result.addition(mtrx1);
		return result;
	}
}

template<typename Type>
Matrix<Type> Matrix<Type>::operator +(const Type& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}
	else
	{
		Matrix<Type> result(*this);
		result.addition(value);
		return result;
	}
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator +=(const Matrix<Type>& mtrx)
{
	time_t err_time = time(nullptr);

	if ((this->m == mtrx.get_m()) && (this->n == mtrx.get_n()))
	{
		this->addition(mtrx);
	}
	else
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}

	return *this;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator +=(const Type& value)
{

    time_t err_time = time(nullptr);

    if (this->is_empty())
    {
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
    }
    else
    {
        this->addition(value);
    }

    return *this;
}

template<typename Type>
void Matrix<Type>::add(const Matrix<Type>& mtrx) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty() || mtrx.is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}

	if ((this->get_n() != mtrx.get_n()) || (this->get_m() != mtrx.get_m()))
	{
        throw IsNotEqualException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Matrixes is not equal.");
	}

	this->addition(mtrx);
}

template<typename Type>
void Matrix<Type>::add(const Type& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}

	this->addition(value);
}

// Private methods
template<typename Type>
void Matrix<Type>::subtraction(const Matrix<Type>& mtrx) const
{
	for (size_t i = 0; i < this->get_n(); i++)
	{
		for (size_t j = 0; j < this->get_m(); j++)
		{
			this->data.get()[i * this->get_m() + j] -= mtrx[i][j];
		}
	}
}

template<typename Type>
void Matrix<Type>::subtraction(const Type& value) const
{
	for (size_t i = 0; i < this->get_n(); i++)
	{
		for (size_t j = 0; j < this->get_m(); j++)
		{
			this->data.get()[i * this->get_m() + j] -= value;
		}
	}
}


// Public methods
template<typename Type>
Matrix<Type> Matrix<Type>::operator -(const Matrix<Type>& mtrx1) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty() || mtrx1.is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}

	if ((mtrx1.get_n() != this->n) && (mtrx1.get_m() != this->m))
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}
	else
	{
		Matrix<Type> result(*this);
		result.subtraction(mtrx1);
		return result;
	}
}

template<typename Type>
Matrix<Type> Matrix<Type>::operator -(const Type& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}
	else
	{
		Matrix<Type> result(*this);
		result.subtraction(value);
		return result;
	}
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator -=(const Matrix<Type>& mtrx)
{
	time_t err_time = time(nullptr);

	size_t n_mtrx = mtrx.get_n();
	size_t m_mtrx = mtrx.get_m();

	if ((this->m == m_mtrx) && (this->n == n_mtrx))
	{
		this->subtraction(mtrx);
	}
	else
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}

	return *this;
}


template<typename Type>
Matrix<Type>& Matrix<Type>::operator -=(const Type& value)
{
    time_t err_time = time(nullptr);

    if (this->is_empty())
    {
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
    }
    else
    {
        this->substraction(value);
    }

    return *this;
}

template<typename Type>
void Matrix<Type>::sub(const Matrix<Type>& mtrx) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty() || mtrx.is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}

	if ((this->get_n() != mtrx.get_n()) || (this->get_m() != mtrx.get_m()))
	{
        throw IsNotEqualException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Matrixes is not equal.");
	}

	this->subtraction(mtrx);
}

template<typename Type>
void Matrix<Type>::sub(const Type& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}
	else
	{
		this->subtraction(value);
	}
}

// Private method
template<typename Type>
void Matrix<Type>::multiplicate(const Type& value) const
{
	size_t n = this->n;
	size_t m = this->m;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			this->data.get()[i * m + j] *= value;
		}
	}
}

template<typename Type>
Matrix<Type> Matrix<Type>::multiplicate(const Matrix<Type>& mtrx) const
{
    size_t n = this->get_n();
    size_t m = mtrx.get_m();
    size_t k = this->get_m();

    Matrix<Type> result = Matrix<Type>(n, m);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            double temp = 0;
            for (size_t g = 0; g < k; g++)
            {
                temp += mtrx.data.get()[g * m + j] * this->data.get()[i * k + g];
            }
            result.data.get()[i * m + j] = temp;
        }
    }

    return result;
}


// Public methods
template<typename Type>
Matrix<Type> Matrix<Type>::operator *(const Matrix<Type>& mtrx1) const
{
	time_t err_time = time(nullptr);

	if (this->n != mtrx1.get_m())
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}
	else
	{
        Matrix<Type> result = this->multiplicate(mtrx1);
		return result;
	}
}

template<typename Type>
Matrix<Type> Matrix<Type>::operator *(const Type& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}
	else
	{
		Matrix<Type> result(*this);
		result.multiplicate(value);
		return result;
	}
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator *=(const Matrix<Type>& mtrx)
{
	time_t err_time = time(nullptr);

	if (this->n != mtrx.get_m())
	{
		throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Size should be equal");
	}
	else
	{
        this = this->multiplicate(mtrx);
        return *this;
	}
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator *=(const Type& value)
{
    time_t err_time = time(nullptr);

    if (this->is_empty())
    {
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
    }
    else
    {
        this->multiplicate(value);
    }

    return *this;
}

template<typename Type>
Matrix<Type> Matrix<Type>::mult(const Matrix<Type>& mtrx) const
{
    time_t err_time = time(nullptr);

    if (this->is_empty())
    {
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
    }
    else
    {
        return this->multiplicate(mtrx);
    }
}

template<typename Type>
void Matrix<Type>::mult(const Type& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}
	else
	{
		this->multiplicate(value);
    }
}

// Private method
template<typename Type>
Matrix<Type> Matrix<Type>::division(const Matrix<Type>& mtrx) const
{
    auto inv_m = mtrx.inverted();
    return this->multiplicate(inv_m);
}

template<typename Type>
void Matrix<Type>::division(const Type& value) const
{
	size_t n = this->n;
	size_t m = this->m;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			this->data.get()[i * m + j] /= value;
		}
	}
}


// Public methods
template<typename Type>
Matrix<Type> Matrix<Type>::operator /(const Matrix<Type>& mtrx) const
{
    time_t err_time = time(nullptr);

    if (this->is_empty())
    {
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
    }
    else if (mtrx->get_n() != mtrx->get_m())
    {
        throw IsNotEqualException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Matrix is not square.");
    }
    else
    {
        Matrix<Type> result = this->division(mtrx);
        return result;
    }
}

template<typename Type>
Matrix<Type> Matrix<Type>::operator /(const Type& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}
	else
	{
		Matrix<Type> result(*this);
		result.division(value);
		return result;
	}
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator /=(const Matrix<Type>& mtrx)
{
    time_t err_time = time(nullptr);

    if (this->is_empty())
    {
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
    }
    else if (mtrx->get_n() != mtrx->get_m())
    {
        throw IsNotEqualException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Matrix is not square.");
    }
    else
    {
        return this->division(mtrx);
    }
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator /=(const Type& value)
{
    time_t err_time = time(nullptr);

    if (this->is_empty())
    {
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
    }
    else
    {
        this->division(value);
    }

    return *this;
}

template<typename Type>
Matrix<Type> Matrix<Type>::divide(const Matrix<Type>& mtrx) const
{
    time_t err_time = time(nullptr);

    if (this->is_empty())
    {
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
    }
    else if (mtrx.get_n() != mtrx.get_m())
    {
        throw IsNotEqualException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Matrix is not square.");
    }
    else
    {
        return this->division(mtrx);
    }
}

template<typename Type>
void Matrix<Type>::divide(const Type& value) const
{
	time_t err_time = time(nullptr);

	if (this->is_empty())
	{
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
	}
	else
	{
		this->division(value);
	}
}

// Private method
template <class Type>
Matrix<Type> Matrix<Type>::matrix_det(size_t count, size_t exclude_row, size_t exclude_column) const
{
    Matrix<Type> new_matrix(count - 1, count - 1);
    size_t ki = 0, kj = 0;
    for (size_t i = 0; i < count - 1; ++i)
    {
        if (i == exclude_row)
            ki = 1;
        for (size_t j = 0; j < count - 1; ++j)
        {
            if (j == exclude_column)
                kj = 1;
            new_matrix[i][j] = this->get_value(i + ki, j + kj);
        }
    }
    return new_matrix;
}

template <class Type>
Type Matrix<Type>::determinant_value(const size_t count) const
{
    size_t sign = 1, new_count = count - 1;
    Type det = 0;
    if (count == 1)
        return this->get_value(0, 0);
    if (count == 2)
        return ((this->get_value(0, 0) * this->get_value(1, 1)) - (this->get_value(1, 0) * this->get_value(0, 1)));
    if (count > 2)
        for (size_t i = 0; i < count; ++i)
        {
            Matrix<Type> new_matrix = this->matrix_det(count, i, 0);
            det = det + sign * this->get_value(i, 0) * new_matrix.determinant_value(new_count);
            sign = -sign;
        }
    return det;
}

// Public methods
template <class Type>
Type Matrix<Type>::determinant()
{
    time_t err_time = time(nullptr);

    if (this->is_empty())
    {
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
    }
    else if (this->get_n() != this->get_m())
    {
        throw MatrixDetException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Matrix is not square.");
    }

    Type det = this->determinant_value(this->get_n());
    return det;
}

// Public
template <class Type>
Matrix<Type> Matrix<Type>::transpose() const
{
    time_t err_time = time(nullptr);

    if (this->is_empty())
    {
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "One of the matrixes is empty.");
    }
    Matrix<Type> res(this->get_m(), this->get_n());
    for (size_t i = 0; i < res.get_n(); ++i)
        for (size_t j = 0; j < res.get_m(); ++j)
            res[i][j] = (*this)[j][i];
    return res;
}

// Private
template <typename Type>
size_t Matrix<Type>::ref()
{
    size_t perm = 0;

    for (size_t row = 0, lead = 0; row < this->get_n() && lead < this->get_m(); ++row, ++lead) {
        size_t i = row;
        while (this->get_value(i, lead) == 0) {
            if (++i == this->get_n()) {
                i = row;
                if (++lead == this->get_m())
                    return 0;
            }
        }

        swap_rows(i, row);

        perm += i != row;

        if (this->get_value(row, lead) != 0) {
            Type f = this->get_value(row, lead);

            for (size_t clm = 0; clm < this->get_m(); clm++)
                this->get_value(row, clm) /= f;
        }

        for (size_t j = 0; j < this->get_n(); j++) {
            if (j != row) {
                Type f = this->get_value(j, lead);

                for (size_t clm = 0; clm < this->get_m(); clm++)
                    this->get_value(j, clm) -= f * this->get_value(row, clm);
            }
        }
    }

    return perm;
}


// Public
template <typename Type>
Matrix<Type> Matrix<Type>::inverted() const
{
    time_t err_time = time(nullptr);

    if (this->get_n() != this->get_m())
    {
        throw MatrixDetException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Matrix is not square.");
    }

    Matrix<Type> tmp(this->get_n(), 2 * this->get_n());

    for (size_t row = 0; row < tmp.get_n(); ++row) {
        for (size_t clm = 0; clm < tmp.get_n(); ++clm) {
            tmp.get_value(row, clm) = this->get_value(row, clm);
        }
        tmp.get_value(row, row + tmp.get_n()) = 1;
    }

    tmp.ref();

    Matrix<Type> inv(this->get_n(), this->get_n());

    for (size_t row = 0; row < this->get_n(); row++) {
        for (size_t clm = 0; clm < this->get_n(); clm++)
            inv.get_value(row, clm) = tmp(row, clm + this->get_n());
    }

    return inv;
}


template<typename Type>
Type& Matrix<Type>::operator ()(size_t i, size_t j)
{
	time_t err_time = time(nullptr);

	if ((this->n <= i) || (this->m <= j))
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}

	return this->data.get()[i * this->m + j];
}

template<typename Type>
const Type& Matrix<Type>::operator ()(size_t i, size_t j) const
{
	time_t err_time = time(nullptr);

	if ((this->n <= i) || (this->m <= j))
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}

	return this->data.get()[i * this->m + j];
}


// Output matrix
template<typename _Type>
std::ostream& operator <<(std::ostream& ostream, const Matrix<_Type>& mtrx)
{
	for (size_t i = 0; i < mtrx.get_n(); i++)
	{
		for (size_t j = 0; j < mtrx.get_m(); j++)
		{
            ostream << mtrx.data.get()[i * mtrx.get_m() + j] << " ";
		}
		ostream << std::endl;
	}

	ostream << std::endl;
	return ostream;
}

template<typename Type>
Iterator<Type> Matrix<Type>::begin()
{
	Iterator<Type> iter(*this, 0);
	return iter;
}

template<typename Type>
Iterator<Type> Matrix<Type>::end()
{
	Iterator<Type> iter(*this, this->n * this->m);
	return iter;
}

template<typename Type>
IteratorConst<Type> Matrix<Type>::begin() const
{
	IteratorConst<Type> iter(*this->data, 0);
	return iter;
}

template<typename Type>
IteratorConst<Type> Matrix<Type>::end() const
{
	IteratorConst<Type> iter(*this->data, this->n * this->m);
	return iter;
}

template <typename Type>
IteratorConst<Type> Matrix<Type>::cbegin() const
{
    IteratorConst<Type> iter((*this), 0);
    return iter;
}

template <typename Type>
IteratorConst<Type> Matrix<Type>::cend() const
{
    IteratorConst<Type> iter((*this), this->n * this->m);
    return iter;
}

template<typename Type>
size_t Matrix<Type>::get_n() const
{
	return this->n;
}

template<typename Type>
size_t Matrix<Type>::get_m() const
{
	return this->m;
}

template<typename Type>
const Type& Matrix<Type>::get_value(size_t i, size_t j) const
{
	time_t err_time = time(nullptr);

	if ((i >= this->n) || (j >= this->m))
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}
	else
	{
		if (this->data)
		{
			return data.get()[i * this->m + j];
		}
		else
		{
			throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
		}
	}
}

template<typename Type>
Type& Matrix<Type>::get_value(size_t i, size_t j)
{
    time_t err_time = time(nullptr);

    if ((i >= this->n) || (j >= this->m))
    {
        throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
    }
    else
    {
        if (this->data)
        {
            return data.get()[i * this->m + j];
        }
        else
        {
            throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
        }
    }
}

template<typename Type>
void Matrix<Type>::set_value(size_t i, size_t j, const Type& value)
{
	time_t err_time = time(nullptr);

	if ((i >= this->n) || (j >= this->m))
	{
		throw IndexException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Index out of range");
	}
	else
	{
		if (this->data)
		{
			this->data.get()[i * this->m + j] = value;
		}
		else
		{
			throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, err_time, "Allocation error");
		}
	}
}

template <typename Type>
void Matrix<Type>::swap_rows(size_t i, size_t j)
{
    if (i != j) {
        for (size_t clm = 0; clm < get_m(); clm++) {
            std::swap(get_value(i, clm), get_value(j, clm));
        }
    }
}

template<typename Type>
void Matrix<Type>::fill_zero()
{
	for (size_t i = 0; i < this->n; i++)
	{
		for (size_t j = 0; j < this->m; j++)
		{
			this->data.get()[i * this->m + j] = 0;
		}
	}
}

template<typename Type>
void Matrix<Type>::identity_matrix()
{
	for (size_t i = 0; i < this->n; i++)
	{
		for (size_t j = 0; j < this->m; j++)
		{
			if (i != j)
			{
				this->data.get()[i * this->m + j] = 0;
			}
			else
			{
				this->data.get()[i * this->m + j] = 1;
			}
		}
	}
}


#endif // !MATRIX_REALIZATION_H
