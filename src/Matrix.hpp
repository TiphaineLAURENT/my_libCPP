/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Matrix
*/

#ifndef MY_LIBCPP_MATRIX_HPP
# define MY_LIBCPP_MATRIX_HPP

#include <array>
#include "Float.hpp"
#include "Int.hpp"

namespace MY_LIBCPP
{

class Matrix
{
public:
	explicit Matrix(const Int &n);
	Matrix(const Int &m, const Int &n);
	explicit Matrix(const std::vector<std::vector<Float>> &array);
	~Matrix() = default;
	Matrix(const Matrix &copy) = default;
	Matrix &operator=(const Matrix &other) = default;
	Matrix(Matrix &&) noexcept = default;
	Matrix &operator=(Matrix &&) = default;

public:
	Matrix add(const Matrix&);
	Matrix sub(const Matrix&);
	Matrix mul(const Matrix&);
	Matrix div(const Matrix&);

	Matrix add(const Float&);
	Matrix sub(const Float&);
	Matrix mul(const Float&);
	Matrix div(const Float&);

	Float determinant(const Matrix &matrix) const;
	Matrix transpose(const Matrix &matrix) const;
	Matrix cofactor(const Matrix &matrix) const;
	Matrix inverse(const Matrix &matrix) const;

	Int cols() const;
	Int rows() const;

	const std::vector<Float> &operator[](const Int&) const;
	std::vector<Float> &operator[](const Int&);

private:
	std::vector<std::vector<Float>> _m;

private:
};

std::ostream &operator<<(std::ostream &out, const Matrix&);

}

#endif /* !MY_LIBCPP_MATRIX_HPP */
