/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Vector3D
*/

#include <cmath>
#include "Vector3D.hpp"
#include "Math.hpp"

namespace MY_LIBCPP
{

namespace Math
{

Vector3D::Vector3D()
	: _x(0), _y(0), _z(0)
{}

Vector3D::Vector3D(const Float &x, const Float &y, const Float &z)
	: _x(x), _y(y), _z(z)
{}

Vector3D::Vector3D(const std::array<Float, 3> &array)
: _x(array[0]), _y(array[1]), _z(array[2])
{}


Vector3D::Vector3D(const Float &theta, const Float &phi)
	: _x(sinf(theta) * sinf(phi)), _y(-cosf(theta)),
	  _z(sinf(theta) * cosf(phi))
{}

std::string Vector3D::to_string() const
{
	return std::string("Vector3D : [" + this->_x.to_string() + ", "
	                   + this->_y.to_string() + "]");
}

void Vector3D::set(const Float &x, const Float &y, const Float &z) noexcept
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

void Vector3D::set(const Vector3D &other)
{
	std::array<Float, 3> otherArray = other.array();
	this->_x = otherArray[0];
	this->_y = otherArray[1];
	this->_z = otherArray[2];
}

Vector3D::Vector3D(const Vector3D &copy)
	: _x(0), _y(0), _z(0)
{
	std::array<Float, 3> copyArray = copy.array();
	this->_x = copyArray[0];
	this->_y = copyArray[1];
	this->_y = copyArray[2];
}

Vector3D &Vector3D::operator+=(const Vector3D &other)
{
	std::array<Float, 3> otherArray = other.array();
	this->_x += otherArray[0];
	this->_y += otherArray[1];
	this->_z += otherArray[2];
	return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &other)
{
	std::array<Float, 3> otherArray = other.array();
	this->_x -= otherArray[0];
	this->_y -= otherArray[1];
	this->_z -= otherArray[2];
	return *this;
}

Vector3D &Vector3D::operator*=(const Vector3D &other)
{
	std::array<Float, 3> otherArray = other.array();
	this->_x *= otherArray[0];
	this->_y *= otherArray[1];
	this->_z *= otherArray[2];
	return *this;
}

Vector3D &Vector3D::operator/=(const Vector3D &other)
{
	std::array<Float, 3> otherArray = other.array();
	this->_x /= otherArray[0];
	this->_y /= otherArray[1];
	this->_z /= otherArray[2];
	return *this;
}

Float Vector3D::mag() const
{
	return sqrtf(magSq());
}

Float Vector3D::magSq() const
{
	return this->_x * this->_x + this->_y * this->_y + this->_z * this->_z;
}

Float Vector3D::dot(const Float &x, const Float &y, const Float &z) const
{
	return this->_x * x + this->_y * y + this->_z * z;
}

Float Vector3D::dot(const Vector3D &other) const
{
	return other.dot(this->_x, this->_y, this->_z);
}

Float Vector3D::dist(const Vector3D &other) const
{
	Vector3D newVector(other - *this);
	return newVector.mag();
}

Vector3D &Vector3D::normalize()
{
	Float len = mag();
	if (len != 0)
		*this *= 1 / len;
	return *this;
}

Vector3D &Vector3D::operator+=(const Float &value)
{
	this->_x += value;
	this->_y += value;
	this->_z += value;
	return *this;
}

Vector3D &Vector3D::operator-=(const Float &value)
{
	this->_x -= value;
	this->_y -= value;
	this->_z -= value;
	return *this;
}

Vector3D &Vector3D::operator*=(const Float &value)
{
	this->_x *= value;
	this->_y *= value;
	this->_z *= value;
	return *this;
}

Vector3D &Vector3D::operator/=(const Float &value)
{
	this->_x /= value;
	this->_y /= value;
	this->_z /= value;
	return *this;
}

Vector3D &Vector3D::limit(const Float &max)
{
	Float mSq = magSq();
	if (mSq > max * max) {
		*this /= sqrtf(mSq) * max;
	}
	return *this;
}

Vector3D &Vector3D::setMag(const Float &mag)
{
	return this->normalize() *= mag;
}

Float Vector3D::angleBetween(const Vector3D &other) const
{
	Float dotmagmag = dot(other) / (mag() * other.mag());
	Float angle = acosf(fmin(1, fmax(-1, dotmagmag)));
	return from_radians(angle);
}

Vector3D &Vector3D::lerp(const Float &x, const Float &y, const Float &z,
                         const Float &amt)
{
	this->_x += (x - this->_x) * amt;
	this->_y += (y - this->_y) * amt;
	this->_z += (y - this->_z) * amt;
	return *this;
}

Vector3D &Vector3D::lerp(const Vector3D &other, const Float &amt)
{
	std::array<Float, 3> otherArray = other.array();
	return lerp(otherArray[0], otherArray[1], otherArray[3], amt);
}

std::array<Float, 3> Vector3D::array() const
{
	return std::array<Float, 3>{this->_x, this->_y, this->_z};
}

bool Vector3D::operator==(const Vector3D &other) const
{
	std::array<Float, 3> otherArray = other.array();
	return this->_x == otherArray[0]
	       && this->_y == otherArray[1]
	       && this->_z == otherArray[2];
}

Vector3D Vector3D::random3D()
{
	return Vector3D(MY_LIBCPP::Float::getRandomFloat(-1, 1),
	                MY_LIBCPP::Float::getRandomFloat(-1, 1),
	                MY_LIBCPP::Float::getRandomFloat(-1, 1));
}

Vector3D Vector3D::cross(const Vector3D &other) const
{
	std::array<Float, 3> otherArray = other.array();
	return Vector3D(this->_y * otherArray[2] - this->_z * otherArray[1],
	                this->_z * otherArray[0] - this->_x * otherArray[2],
	                this->_x * otherArray[1] - this->_y * otherArray[0]);
}

Vector3D operator+(const Vector3D &vector1, const Vector3D &vector2)
{
	Vector3D add(vector1);
	return add += vector2;
}

Vector3D operator-(const Vector3D &vector1, const Vector3D &vector2)
{
	Vector3D sub(vector1);
	return sub -= vector2;
}

Vector3D operator*(const Vector3D &vector1, const Vector3D &vector2)
{
	Vector3D mul(vector1);
	return mul *= vector2;
}

Vector3D operator/(const Vector3D &vector1, const Vector3D &vector2)
{
	Vector3D div(vector1);
	return div /= vector2;
}

Vector3D operator+(const Vector3D &vector, const Float &value)
{
	Vector3D add(vector);
	return add += value;
}

Vector3D operator-(const Vector3D &vector, const Float &value)
{
	Vector3D sub(vector);
	return sub -= value;
}

Vector3D operator*(const Vector3D &vector, const Float &value)
{
	Vector3D mul(vector);
	return mul *= value;
}

Vector3D operator/(const Vector3D &vector, const Float &value)
{
	Vector3D div(vector);
	return div /= value;
}


std::ostream &operator<<(std::ostream &out, const Vector3D &vector)
{
	out << vector.to_string();
	return out;
}

}

}
