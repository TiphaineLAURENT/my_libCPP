/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Vector2D
*/

#include <cmath>
#include "Vector2D.hpp"
#include "Value.hpp"
#include "Math.hpp"
#include "Float.hpp"

namespace MY_LIBCPP
{

namespace Math
{

Vector2D::Vector2D(float x, float y)
	: _x(x), _y(y)
{}

Vector2D::Vector2D(float angle)
	: _x(cosf(angle)), _y(sinf(angle))
{}

std::string Vector2D::to_string() const
{
	return std::string("Vector2D : [" + std::to_string(_x) + ", "
	                   + std::to_string(_y) + "]");
}

void Vector2D::set(float x, float y) noexcept
{
	_x = x;
	_y = y;
}

void Vector2D::set(const Vector2D &other)
{
	std::array<float, 2> otherArray = other.array();
	_x = otherArray[0];
	_y = otherArray[1];
}

Vector2D::Vector2D(const Vector2D &copy)
{
	std::array<float, 2> copyArray = copy.array();
	_x = copyArray[0];
	_y = copyArray[1];
}

Vector2D &Vector2D::operator+=(const Vector2D &other)
{
	std::array<float, 2> otherArray = other.array();
	_x += otherArray[0];
	_y += otherArray[1];
	return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &other)
{
	std::array<float, 2> otherArray = other.array();
	_x -= otherArray[0];
	_y -= otherArray[1];
	return *this;
}

Vector2D &Vector2D::operator*=(const Vector2D &other)
{
	std::array<float, 2> otherArray = other.array();
	_x *= otherArray[0];
	_y *= otherArray[1];
	return *this;
}

Vector2D &Vector2D::operator/=(const Vector2D &other)
{
	std::array<float, 2> otherArray = other.array();
	_x /= otherArray[0];
	_y /= otherArray[1];
	return *this;
}

float Vector2D::mag() const
{
	return sqrtf(magSq());
}

float Vector2D::magSq() const
{
	return _x * _x + _y * _y;
}

float Vector2D::dot(float x, float y) const
{
	return _x * x + _y * y;
}

float Vector2D::dot(const Vector2D &other) const
{
	return other.dot(_x, _y);
}

float Vector2D::dist(const Vector2D &other) const
{
	Vector2D newVector(other - *this);
	return newVector.mag();
}

Vector2D &Vector2D::normalize()
{
	float len = mag();
	if (len != 0)
		*this *= 1/len;
	return *this;
}

Vector2D &Vector2D::operator+=(float value)
{
	_x += value;
	_y += value;
	return *this;
}

Vector2D &Vector2D::operator-=(float value)
{
	_x -= value;
	_y -= value;
	return *this;
}

Vector2D &Vector2D::operator*=(float value)
{
	_x *= value;
	_y *= value;
	return *this;
}

Vector2D &Vector2D::operator/=(float value)
{
	_x /= value;
	_y /= value;
	return *this;
}

Vector2D &Vector2D::limit(float max)
{
	float mSq = magSq();
	if (mSq > max * max) {
		*this /= sqrtf(mSq) * max;
	}
	return *this;
}

Vector2D &Vector2D::setMag(float mag)
{
	return this->normalize() *= mag;
}

float Vector2D::heading()
{
	return from_radians(atan2f(_x , _y));
}

Vector2D &Vector2D::rotate(float angle)
{
	float newHeading = to_radians(heading() + angle);
	float magnitude = mag();
	_x = cosf(newHeading) * magnitude;
	_y = sinf(newHeading) * magnitude;
	return *this;
}

float Vector2D::angleBetween(const Vector2D &other)
{
	float dotmagmag = dot(other) / (mag() * other.mag());
	float angle = acosf(fmin(1, fmax(-1, dotmagmag)));
	return from_radians(angle);
}

Vector2D &Vector2D::lerp(float x, float y, float amt)
{
	_x += (x - _x) * amt;
	_y += (y - _y) * amt;
	return *this;
}

Vector2D &Vector2D::lerp(const Vector2D &, float amt)
{
	return lerp(_x , _y, amt);
}

std::array<float, 2> Vector2D::array() const
{
	return std::array<float, 2>{_x, _y};
}

bool Vector2D::operator==(const Vector2D &other) const
{
	std::array<float, 2> otherArray = other.array();
	return _x == otherArray[0] && _y == otherArray[1];
}

Vector2D Vector2D::random2D()
{
	return Vector2D((float)MY_LIBCPP::Float::randomValue() * TWO_PI);
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

Vector2D operator+(const Vector2D &vector, float value)
{
	Vector2D add(vector);
	return add += value;
}

Vector2D operator-(const Vector2D &vector, float value)
{
	Vector2D sub(vector);
	return sub -= value;
}

Vector2D operator*(const Vector2D &vector, float value)
{
	Vector2D mul(vector);
	return mul *= value;
}

Vector2D operator/(const Vector2D &vector, float value)
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
