/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Int
*/

#include "Int.hpp"

namespace MY_LIBCPP
{

Int::Int(const int &v)
	: Value<int>(v)
{
	_type = "Int";
}

Int &Int::operator=(const int &other)
{
	_v = other;
	return *this;
}

Int Int::randomInt(const Int &min, const Int &max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(min.value(), max.value());
	return dis(gen);
}

Int operator+(const int &value1, const Int &value2)
{
	return value1 + value2.value();
}

Int operator-(const int &value1, const Int &value2)
{
	return value1 - value2.value();
}

Int operator*(const int &value1, const Int &value2)
{
	return value1 * value2.value();
}

Int operator/(const int &value1, const Int &value2)
{
	return value1 / value2.value();
}

}
