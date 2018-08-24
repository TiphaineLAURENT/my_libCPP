/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Matrix
*/

#include <iostream>
#include <iomanip>
#include "Matrix.hpp"

namespace MY_LIBCPP
{

Matrix::Matrix(const Int &n)
	: _m()
{
	std::vector<Float> row;

	for (Int i = 0; i < n; i++) {
		row.emplace_back(0);
	}
	for (Int i = 0; i < n; i++) {
		this->_m.push_back(row);
		this->_m[i][i] = 1;
	}
}

Matrix::Matrix(const Int &m, const Int &n)
	: _m()
{
	std::vector<Float> row;

	for (Int i = 0; i < m; i++) {
		row.emplace_back(0);
	}
	for (Int i = 0; i < n; i++) {
		this->_m.push_back(row);
	}
}

Matrix::Matrix(const std::vector<std::vector<MY_LIBCPP::Float>> &matrix)
	: _m(matrix)
{}

Matrix::Matrix(const Math::Vector2D &vector)
	: _m({{vector.array()[0]}, {vector.array()[1]}})
{}

Matrix::Matrix(const Math::Vector3D &vector)
	: _m({{vector.array()[0]}, {vector.array()[1]}, {vector.array()[2]}})
{}

Matrix Matrix::add(const Matrix &other) const
{
	Matrix result(*this);

	Int rowsA = this->rows();
	Int colsA = this->cols();
	Int rowsB = other.rows();
	Int colsB = other.cols();

	if (colsA != colsB
	    || rowsA != rowsB)
		throw std::logic_error("Matrices are not same sizes");

	for (Int r = 0; r < rowsA; r++) {
		for (Int c = 0; c < colsB; c++) {
			result[r][c] += other[r][c];
		}
	}

	return result;
}

Matrix Matrix::sub(const Matrix &other) const
{
	Matrix result(*this);

	Int rowsA = this->rows();
	Int colsA = this->cols();
	Int rowsB = other.rows();
	Int colsB = other.cols();

	if (colsA != colsB
	    || rowsA != rowsB)
		throw std::logic_error("Matrices are not same sizes");

	for (Int r = 0; r < rowsA; r++) {
		for (Int c = 0; c < colsB; c++) {
			result[r][c] -= other[r][c];
		}
	}

	return result;
}

Matrix Matrix::mul(const Matrix &other) const
{
	Int rowsA = this->rows();
	Int colsA = this->cols();
	Int rowsB = other.rows();
	Int colsB = other.cols();

	if (rowsA != colsB)
		throw std::logic_error("Matrices are not same sizes");

	Matrix result(other);
	for (Int i = 0; i < rowsA; i++) {
		for (Int j = 0; j < colsB; j++) {
			Int sum = 0;
			for (Int k = 0; k < rowsA; k++) {
				sum += this->_m[i][k] * other[k][j];
			}
			result[i][j] = sum;
		}
	}

	return result;
}

Matrix Matrix::div(const Matrix &other) const
{
	Matrix result(*this);

	result.mul(other.inverse());
	return result;
}

Int Matrix::cols() const
{
	return this->_m[0].size();
}

Int Matrix::rows() const
{
	return this->_m.size();
}

const std::vector<Float> &Matrix::operator[](const Int &index) const
{
	return this->_m[index];
}

std::vector<Float> &Matrix::operator[](const Int &index)
{
	return this->_m[index];
}

Matrix Matrix::add(const Float &value) const
{
	Matrix result(*this);

	Int rows = result.rows();
	Int cols = result.cols();

	for (Int r = 0; r < rows; r++) {
		for (Int c = 0; c < cols; c++) {
			result[r][c] = this->_m[r][c] + value;
		}
	}
	return result;
}

Matrix Matrix::sub(const Float &value) const
{
	Matrix result(*this);

	Int rows = result.rows();
	Int cols = result.cols();

	for (Int r = 0; r < rows; r++) {
		for (Int c = 0; c < cols; c++) {
			result[r][c] = this->_m[r][c] - value;
		}
	}
	return result;
}

Matrix Matrix::mul(const Float &value) const
{
	Matrix result(*this);

	Int rows = result.rows();
	Int cols = result.cols();

	for (Int r = 0; r < rows; r++) {
		for (Int c = 0; c < cols; c++) {
			result[r][c] = this->_m[r][c] * value;
		}
	}
	return result;
}

Matrix Matrix::div(const Float &value) const
{
	Matrix result(*this);

	Int rows = result.rows();
	Int cols = result.cols();

	for (Int r = 0; r < rows; r++) {
		for (Int c = 0; c < cols; c++) {
			result[r][c] = this->_m[r][c] / value;
		}
	}
	return result;
}

Float Matrix::determinant() const
{
	Int q = this->rows();

	if(q > 2) {
		Float resultOfSubStep = 0;
		Matrix smallerMatrix(q - 1, q - 1);
		for(Int i = 0; i < q; i++) {
			for (Int j = 0; j < q - 1; j++) {
				Int counter = 0;
				for (Int k = 0; k < q; k++) {
					if(k == i)continue;
					smallerMatrix[j][counter] =
						this->_m[j+1][k];
					counter++;
				}
			}
			Float k1 = this->_m[0][i] * smallerMatrix.determinant();
			resultOfSubStep += powf(-1, i) * k1;
		}
		return resultOfSubStep;
	}
	else if(q == 2)
		return this->_m[0][0] * this->_m[1][1] - this->_m[0][1] * this->_m[1][0];
	else
		return this->_m[0][0];
}

Matrix Matrix::transpose() const
{
	Matrix result(*this);
	Int dim = this->rows();

	Matrix tmp(dim);
	for (Int i = 0; i < dim; i++)
		for (Int j = 0; j < dim; j++)
			tmp[i][j] = this->_m[j][i];
	for (Int i = 0; i < dim; i++)
		for (Int j = 0; j < dim; j++)
			result[i][j] = tmp[i][j];
	return result;
}

Matrix Matrix::cofactor() const
{
	Int n = this->rows();
	Matrix b(n), c(n);

	for (Int h = 0; h < n; h++)
		for (Int l = 0; l < n; l++) {
			Int m = 0;
			Int k = 0;
			for (Int i = 0; i < n; i++)
				for (Int j = 0; j < n; j++) {
					if (i != h && j != l) {
						b[m][k] = this->_m[i][j];
						if (k < n - 2)
							k++;
						else {
							k = 0;
							m++;
						}
					}
				}
			c[h][l] = pow(-1, h + l) * b.determinant();
		}
	return c;
}

Matrix Matrix::inverse() const
{
	Int n = this->rows();

	if(this->determinant() == 0)
		printf("\nInverse of Entered Matrix is not possible\n");
	else if(n == 1)
		return Matrix(1);
	else
		return this->cofactor().transpose().mul(1 / this->determinant());
}

Matrix Matrix::power(const Int &power) const
{
	if (power == 1)
		return *this;
	return this->mul(this->power(power - 1));
}

Matrix &Matrix::operator+(const Matrix &other)
{
	*this = this->add(other);
	return *this;
}

Matrix &Matrix::operator-(const Matrix &other)
{
	*this = this->sub(other);
	return *this;
}

Matrix &Matrix::operator*(const Matrix &other)
{
	*this = this->mul(other);
	return *this;
}

Matrix &Matrix::operator/(const Matrix &other)
{
	*this = this->div(other);
	return *this;
}

Matrix &Matrix::operator+(const Float &scalar)
{
	*this = this->add(scalar);
	return *this;
}

Matrix &Matrix::operator-(const Float &scalar)
{
	*this = this->sub(scalar);
	return *this;
}

Matrix &Matrix::operator*(const Float &scalar)
{
	*this = this->mul(scalar);
	return *this;
}

Matrix &Matrix::operator/(const Float &scalar)
{
	*this = this->div(scalar);
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Matrix &matrix)
{
	Int rows = matrix.rows();
	Int cols = matrix.cols();
	Int max = 0;

	for (Int r = 0; r < rows; r++) {
		for (Int c = 0; c < cols; c++) {
			if (matrix[r][c].absolute_length() > max)
				max = matrix[r][c].absolute_length();
		}
	} max += 1;

	out << "Matrix " << matrix.rows() << " rows by "
	    << matrix.cols() << " cols";
	for (Int r = 0; r < rows; r++) {
		out << "\n[";
		for (Int c = 0; c < cols; c++) {
			out << std::setw(max);
			out << matrix[r][c].to_string();
			out << ",";
		}
		out << "\b]";
	}

	return out;
}

}
