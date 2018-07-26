/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** String
*/

#include "String.hpp"

namespace MY_LIBCPP
{

String::String(const char *str)
	: std::string(str)
{
}

int String::to_int(std::size_t *pos, int base) const
{
	return stoi(*this, pos, base);
}

long String::to_long(size_t *pos, int base) const
{
	return stol(*this, pos, base);
}

long long String::to_longlong(size_t *pos, int base) const
{
	return stoll(*this, pos, base);
}

unsigned long String::to_unsignedlong(size_t *pos, int base) const
{
	return stoul(*this, pos, base);
}

unsigned long long String::to_unsignedlonglong(size_t *pos, int base) const
{
	return stoull(*this, pos, base);
}

float String::to_float(std::size_t *pos) const
{
	return stof(*this, pos);
}

double String::to_double(size_t *pos) const
{
	return stod(*this, pos);
}

long double String::to_longdouble(size_t *pos) const
{
	return stold(*this, pos);
}

}
