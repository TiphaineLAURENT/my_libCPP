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

Float Float::randomFloat(const Float &min, const Float &max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(min.value(), max.value());
	return dis(gen);
}

Float operator+(const float &value1, const Float &value2)
{
return value1 + value2.value();
}

Float operator-(const float &value1, const Float &value2)
{
return value1 - value2.value();
}

Float operator*(const float &value1, const Float &value2)
{
return value1 * value2.value();
}

Float operator/(const float &value1, const Float &value2)
{
if (value2 == 0)
return INFINITY;
return value1 / value2.value();
}

}
