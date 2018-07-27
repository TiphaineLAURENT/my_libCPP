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
namespace MY_LIBCPP
{

namespace Math
{

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
	float dot(const Vector2D &) const;
	float dist(const Vector2D &) const;
	Vector2D &normalize();
	Vector2D &limit(float max);
	Vector2D &setMag(float mag);
	float heading();
	Vector2D &rotate(float angle);
	float angleBetween(const Vector2D &);
	Vector2D &lerp(float x, float y, float amt);
	Vector2D &lerp(const Vector2D &, float amt);
	std::array<float, 2> array() const;

	bool operator==(const Vector2D &) const;

	Vector2D &operator+=(const Vector2D &);
	Vector2D &operator+=(float value);
	Vector2D &operator-=(const Vector2D &);
	Vector2D &operator-=(float value);
	Vector2D &operator*=(const Vector2D &);
	Vector2D &operator*=(float value);
	Vector2D &operator/=(const Vector2D &);
	Vector2D &operator/=(float value);

	static Vector2D random2D();

private:
	float _x;
	float _y;

private:
};

Vector2D &operator+(const Vector2D&, const Vector2D&);
Vector2D &operator+(const Vector2D&, float value);
Vector2D &operator-(const Vector2D&, const Vector2D&);
Vector2D &operator-(const Vector2D&, float value);
Vector2D &operator*(const Vector2D&, const Vector2D&);
Vector2D &operator*(const Vector2D&, float value);
Vector2D &operator/(const Vector2D&, const Vector2D&);
Vector2D &operator/(const Vector2D&, float value);

std::ostream &operator<<(std::ostream &out, const Vector2D&);

}

}

#endif /* !MY_LIBCPP_VECTOR2D_HPP */
