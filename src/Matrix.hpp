/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Matrix
*/

#ifndef MY_LIBCPP_MATRIX_HPP
# define MY_LIBCPP_MATRIX_HPP

# include <array>
# include "Float.hpp"
# include "Int.hpp"
# include "Vector2D.hpp"
# include "Vector3D.hpp"

namespace MY_LIBCPP
{

class Matrix
{
public:
	explicit Matrix(const Int &n);
	Matrix(const Int &m, const Int &n);
	explicit Matrix(const std::vector<std::vector<Float>> &array);
	explicit Matrix(const Math::Vector2D&);
	explicit Matrix(const Math::Vector3D&);
	~Matrix() = default;
	Matrix(const Matrix &copy) = default;
	Matrix &operator=(const Matrix &other) = default;
	Matrix(Matrix &&) noexcept = default;
	Matrix &operator=(Matrix &&) = default;

public:
	Matrix add(const Matrix&) const;
	Matrix sub(const Matrix&) const;
	Matrix mul(const Matrix&) const;
	Matrix div(const Matrix&) const;

	Matrix &operator+(const Matrix &);
	Matrix &operator-(const Matrix &);
	Matrix &operator*(const Matrix &);
	Matrix &operator/(const Matrix &);

	Matrix add(const Float&) const;
	Matrix sub(const Float&) const;
	Matrix mul(const Float&) const;
	Matrix div(const Float&) const;

	Matrix &operator+(const Float &);
	Matrix &operator-(const Float &);
	Matrix &operator*(const Float &);
	Matrix &operator/(const Float &);

	Float determinant() const;
	Matrix transpose() const;
	Matrix cofactor() const;
	Matrix inverse() const;

	Matrix power(const Int&) const;

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
