/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Float
*/

#include "Float.hpp"

namespace MY_LIBCPP
{

Float::Float(const float &v)
	: Value<float>(v)
{
	_type = "Float";
}

Float &Float::operator=(const float &other)
{
	_v = other;
	return *this;
}

Float operator+(const float &value1, const Float &value2)
{
	return Float(value1 + value2.value());
}

Float operator-(const float &value1, const Float &value2)
{
	return Float(value1 - value2.value());
}

Float operator*(const float &value1, const Float &value2)
{
	return Float(value1 * value2.value());
}

Float operator/(const float &value1, const Float &value2)
{
	if (value2 == 0)
		return Float(INFINITY);
	return Float(value1 / value2.value());
}

}
