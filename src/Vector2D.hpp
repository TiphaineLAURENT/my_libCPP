/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Vector2D
*/

#ifndef MY_LIBCPP_VECTOR2D_HPP
#define MY_LIBCPP_VECTOR2D_HPP

#include <string>
#include <array>

#include "Float.hpp"

namespace MY_LIBCPP
{

namespace Math
{

class Vector2D
{
public:
	Vector2D(const Float &x, const Float &y);
	explicit Vector2D(const Float &angle);
	~Vector2D() = default;
	Vector2D(const Vector2D &copy);
	Vector2D &operator=(const Vector2D &other) = default;
	Vector2D(Vector2D &&) = default;
	Vector2D &operator=(Vector2D &&) = default;

public:
	std::string to_string() const;
	void set(const Float &x, const Float &y) noexcept;
	void set(const Vector2D &other);
	Float mag() const;
	Float magSq() const;
	Float dot(Float x, Float y) const;
	Float dot(const Vector2D &) const;
	Float dist(const Vector2D &) const;
	Vector2D &normalize();
	Vector2D &limit(Float max);
	Vector2D &setMag(Float mag);
	Float heading();
	Vector2D &rotate(Float angle);
	Float angleBetween(const Vector2D &);
	Vector2D &lerp(const Float &x, const Float &y, const Float &amt);
	Vector2D &lerp(const Vector2D &, const Float &amt);
	std::array<Float, 2> array() const;

	bool operator==(const Vector2D &) const;

	Vector2D &operator+=(const Vector2D &);
	Vector2D &operator+=(Float value);
	Vector2D &operator-=(const Vector2D &);
	Vector2D &operator-=(Float value);
	Vector2D &operator*=(const Vector2D &);
	Vector2D &operator*=(Float value);
	Vector2D &operator/=(const Vector2D &);
	Vector2D &operator/=(Float value);

	static Vector2D random2D();

private:
	Float _x;
	Float _y;

private:
};

Vector2D operator+(const Vector2D&, const Vector2D&);
Vector2D operator+(const Vector2D&, Float value);
Vector2D operator-(const Vector2D&, const Vector2D&);
Vector2D operator-(const Vector2D&, Float value);
Vector2D operator*(const Vector2D&, const Vector2D&);
Vector2D operator*(const Vector2D&, Float value);
Vector2D operator/(const Vector2D&, const Vector2D&);
Vector2D operator/(const Vector2D&, Float value);

std::ostream &operator<<(std::ostream &out, const Vector2D&);

}

}

#endif /* !MY_LIBCPP_VECTOR2D_HPP */
