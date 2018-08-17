/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Int
*/

#include <iostream>
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

Int Int::getRandomInt(const Int &min, const Int &max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(min.value(), max.value());
	return dis(gen);
}

std::vector<Int> Int::getPrimeNumbers(const Int &min, const Int &max)
{
	std::vector<Int> primes;
	bool isPrime = false;

	for (Int n = min; n < max; ++n) {
		isPrime = true;

		Int fs = std::floor(sqrt(n.value()));
		for (Int i = 2; i <= fs; ++i) {
			if (n % i == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime)
			primes.push_back(n);
	}
	return primes;
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

bool operator<=(const int &value1, const Int &value2)
{
	return value1 <= value2.value();
}

bool operator>=(const int &value1, const Int &value2)
{
	return value1 >= value2.value();
}

bool operator<(const int &value1, const Int &value2)
{
	return value1 < value2.value();
}

bool operator>(const int &value1, const Int &value2)
{
	return value1 > value2.value();
}

}
