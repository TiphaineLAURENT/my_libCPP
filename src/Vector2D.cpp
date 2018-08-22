/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Vector2D
*/

#include <cmath>
#include "Vector2D.hpp"
#include "Math.hpp"

namespace MY_LIBCPP
{

namespace Math
{

Vector2D::Vector2D()
	: _x(0), _y(0)
{}

Vector2D::Vector2D(const Float &x, const Float &y)
	: _x(x), _y(y)
{}

Vector2D::Vector2D(const Float &angle)
	: _x(cosf(angle)), _y(sinf(angle))
{}

std::string Vector2D::to_string() const
{
	return std::string("Vector2D : [" + this->_x.to_string() + ", "
	                   + this->_y.to_string() + "]");
}

void Vector2D::set(const Float &x, const Float &y) noexcept
{
	this->_x = x;
	this->_y = y;
}

void Vector2D::set(const Vector2D &other)
{
	std::array<Float, 2> otherArray = other.array();
	this->_x = otherArray[0];
	this->_y = otherArray[1];
}

Vector2D::Vector2D(const Vector2D &copy)
	: _x(0), _y(0)
{
	std::array<Float, 2> copyArray = copy.array();
	this->_x = copyArray[0];
	this->_y = copyArray[1];
}

Vector2D &Vector2D::operator+=(const Vector2D &other)
{
	std::array<Float, 2> otherArray = other.array();
	this->_x += otherArray[0];
	this->_y += otherArray[1];
	return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &other)
{
	std::array<Float, 2> otherArray = other.array();
	this->_x -= otherArray[0];
	this->_y -= otherArray[1];
	return *this;
}

Vector2D &Vector2D::operator*=(const Vector2D &other)
{
	std::array<Float, 2> otherArray = other.array();
	this->_x *= otherArray[0];
	this->_y *= otherArray[1];
	return *this;
}

Vector2D &Vector2D::operator/=(const Vector2D &other)
{
	std::array<Float, 2> otherArray = other.array();
	this->_x /= otherArray[0];
	this->_y /= otherArray[1];
	return *this;
}

Float Vector2D::mag() const
{
	return sqrtf(magSq());
}

Float Vector2D::magSq() const
{
	return this->_x * this->_x + this->_y * this->_y;
}

Float Vector2D::dot(const Float &x, const Float &y) const
{
	return this->_x * x + this->_y * y;
}

Float Vector2D::dot(const Vector2D &other) const
{
	return other.dot(this->_x, this->_y);
}

Float Vector2D::dist(const Vector2D &other) const
{
	Vector2D newVector(other - *this);
	return newVector.mag();
}

Vector2D &Vector2D::normalize()
{
	Float len = mag();
	if (len != 0)
		*this *= 1 / len;
	return *this;
}

Vector2D &Vector2D::operator+=(const Float &value)
{
	this->_x += value;
	this->_y += value;
	return *this;
}

Vector2D &Vector2D::operator-=(const Float &value)
{
	this->_x -= value;
	this->_y -= value;
	return *this;
}

Vector2D &Vector2D::operator*=(const Float &value)
{
	this->_x *= value;
	this->_y *= value;
	return *this;
}

Vector2D &Vector2D::operator/=(const Float &value)
{
	this->_x /= value;
	this->_y /= value;
	return *this;
}

Vector2D &Vector2D::limit(const Float &max)
{
	Float mSq = magSq();
	if (mSq > max * max) {
		*this /= sqrtf(mSq) * max;
	}
	return *this;
}

Vector2D &Vector2D::setMag(const Float &mag)
{
	return this->normalize() *= mag;
}

Float Vector2D::heading() const
{
	return from_radians(atan2f(this->_x , this->_y));
}

Vector2D &Vector2D::rotate(const Float &angle)
{
	Float newHeading = to_radians(heading() + angle);
	Float magnitude = mag();
	this->_x = cosf(newHeading) * magnitude;
	this->_y = sinf(newHeading) * magnitude;
	return *this;
}

Float Vector2D::angleBetween(const Vector2D &other) const
{
	Float dotmagmag = dot(other) / (mag() * other.mag());
	Float angle = acosf(fmin(1, fmax(-1, dotmagmag)));
	return from_radians(angle);
}

Vector2D &Vector2D::lerp(const Float &x, const Float &y, const Float &amt)
{
	this->_x += (x - this->_x) * amt;
	this->_y += (y - this->_y) * amt;
	return *this;
}

Vector2D &Vector2D::lerp(const Vector2D &other, const Float &amt)
{
	std::array<Float, 2> otherArray = other.array();
	return lerp(otherArray[0], otherArray[1], amt);
}

std::array<Float, 2> Vector2D::array() const
{
	return std::array<Float, 2>{this->_x, this->_y};
}

bool Vector2D::operator==(const Vector2D &other) const
{
	std::array<Float, 2> otherArray = other.array();
	return this->_x == otherArray[0] && this->_y == otherArray[1];
}

Vector2D Vector2D::random2D()
{
	return Vector2D(MY_LIBCPP::Float::getRandomFloat(-1, 1),
	                MY_LIBCPP::Float::getRandomFloat(-1, 1));
}

Vector2D operator+(const Vector2D &vector1, const Vector2D &vector2)
{
	Vector2D add(vector1);
	return add += vector2;
}

Vector2D operator-(const Vector2D &vector1, const Vector2D &vector2)
{
	Vector2D sub(vector1);
	return sub -= vector2;
}

Vector2D operator*(const Vector2D &vector1, const Vector2D &vector2)
{
	Vector2D mul(vector1);
	return mul *= vector2;
}

Vector2D operator/(const Vector2D &vector1, const Vector2D &vector2)
{
	Vector2D div(vector1);
	return div /= vector2;
}

Vector2D operator+(const Vector2D &vector, const Float &value)
{
	Vector2D add(vector);
	return add += value;
}

Vector2D operator-(const Vector2D &vector, const Float &value)
{
	Vector2D sub(vector);
	return sub -= value;
}

Vector2D operator*(const Vector2D &vector, const Float &value)
{
	Vector2D mul(vector);
	return mul *= value;
}

Vector2D operator/(const Vector2D &vector, const Float &value)
{
	Vector2D div(vector);
	return div /= value;
}


std::ostream &operator<<(std::ostream &out, const Vector2D &vector)
{
	out << vector.to_string();
	return out;
}

}

}

