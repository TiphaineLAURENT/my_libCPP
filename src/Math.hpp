/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Math
*/

#ifndef MY_LIBCPP_MATH_HPP
#define MY_LIBCPP_MATH_HPP

#include <string>
#include <array>
#include <cmath>
#include "Vector2D.hpp"

namespace MY_LIBCPP
{

namespace Math
{

const double HALF_PI = 1.57079632679489661923;
const double PI = 3.14159265358979323846;
const double QUARTER_PI = 0.7853982;
const double TWO_PI = 6.28318530717958647693;
const double TAU = TWO_PI;

const double DEG_TO_RAD = PI / 180.0;
const double RAD_TO_DEG = 180.0 / PI;

template<class T>
T map(T value, T frommin, T frommax, T tomin, T tomax)
{
	return (value - frommin) * (tomax - tomin) / (frommax - frommin)
	       + tomin;
}

float to_degrees(float angle);
float from_degrees(float angle);
float to_radians(float angle);
float from_radians(float angle);

class Vector2D
{
public:
	Vector2D(float x, float y);
	explicit Vector2D(float angle);
	~Vector2D() = default;
	Vector2D(const Vector2D &copy);
	Vector2D &operator=(const Vector2D &other) = default;
	Vector2D(Vector2D &&) = default;
	Vector2D &operator=(Vector2D &&) = default;

public:
	std::string to_string() const;
	void set(float x, float y) noexcept;
	void set(const Vector2D &other);
	float mag() const;
	float magSq() const;
	float dot(float x, float y) const;
	float dot(const Vector2D&) const;
	float dist(const Vector2D&) const;
	Vector2D &normalize();
	Vector2D &limit(float max);
	Vector2D &setMag(float mag);
	float heading();
	Vector2D &rotate(float angle);
	float angleBetween(const Vector2D&);
	Vector2D &lerp(float x, float y, float amt);
	Vector2D &lerp(const Vector2D&, float amt);
	std::array<float, 2> array() const;

	bool operator==(const Vector2D&) const;

	Vector2D &operator+=(const Vector2D&);
	Vector2D &operator+=(float value);
	Vector2D &operator-=(const Vector2D&);
	Vector2D &operator-=(float value);
	Vector2D &operator*=(const Vector2D&);
	Vector2D &operator*=(float value);
	Vector2D &operator/=(const Vector2D&);
	Vector2D &operator/=(float value);

	static Vector2D random2D();

private:
	float _x;
	float _y;


private:
};

Vector2D &operator+(const Vector2D&, const Vector2D&);
Vector2D &operator-(const Vector2D&, const Vector2D&);
Vector2D &operator*(const Vector2D&, const Vector2D&);
Vector2D &operator/(const Vector2D&, const Vector2D&);

}

}

#endif //MY_LIBCPP_MATH_HPP
