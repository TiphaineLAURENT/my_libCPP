/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Vector3D
*/

#ifndef MY_LIBCPP_VECTOR3D_HPP
#define MY_LIBCPP_VECTOR3D_HPP

#include <string>
#include <array>

#include "Float.hpp"

namespace MY_LIBCPP
{

namespace Math
{

class Vector3D
{
public:
	Vector3D();
	Vector3D(const Float &x, const Float &y, const Float &z);
	explicit Vector3D(const std::array<Float, 3>&);
	Vector3D(const Float &theta, const Float &phi); // fromAngles with len 1
	~Vector3D() = default;
	Vector3D(const Vector3D &copy);
	Vector3D &operator=(const Vector3D &other) = default;
	Vector3D(Vector3D &&) = default;
	Vector3D &operator=(Vector3D &&) = default;

public:
	std::string to_string() const;
	void set(const Float &x, const Float &y, const Float &z) noexcept;
	void set(const Vector3D &other);
	Float mag() const;
	Float magSq() const;
	Float dot(const Float &x, const Float &y, const Float &z) const;
	Float dot(const Vector3D&) const;
	Vector3D cross(const Vector3D &) const;
	Float dist(const Vector3D &) const;
	Vector3D &normalize();
	Vector3D &limit(const Float &max);
	Vector3D &setMag(const Float &mag);
	Float angleBetween(const Vector3D &) const;
	Vector3D &lerp(const Float &x, const Float &y, const Float &z,
	               const Float &amt);
	Vector3D &lerp(const Vector3D &, const Float &amt);
	std::array<Float, 3> array() const;

	bool operator==(const Vector3D &) const;

	Vector3D &operator+=(const Vector3D &);
	Vector3D &operator+=(const Float &value);
	Vector3D &operator-=(const Vector3D &);
	Vector3D &operator-=(const Float &value);
	Vector3D &operator*=(const Vector3D &);
	Vector3D &operator*=(const Float &value);
	Vector3D &operator/=(const Vector3D &);
	Vector3D &operator/=(const Float &value);

	static Vector3D random3D();

private:
	Float _x;
	Float _y;
	Float _z;

private:
};

Vector3D operator+(const Vector3D&, const Vector3D&);
Vector3D operator+(const Vector3D&, const Float &value);
Vector3D operator-(const Vector3D&, const Vector3D&);
Vector3D operator-(const Vector3D&, const Float &value);
Vector3D operator*(const Vector3D&, const Vector3D&);
Vector3D operator*(const Vector3D&, const Float &value);
Vector3D operator/(const Vector3D&, const Vector3D&);
Vector3D operator/(const Vector3D&, const Float &value);

std::ostream &operator<<(std::ostream &out, const Vector3D&);

}

}

#endif /* !MY_LIBCPP_VECTOR3D_HPP */
