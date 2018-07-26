/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** String
*/

#ifndef MY_LIBCPP_STRING_HPP
#define MY_LIBCPP_STRING_HPP

#include <string>

namespace MY_LIBCPP
{

class String : public std::string
{
public:
	String(const char*);
	/*~String() = default;
	String(const String &copy) = default;
	String &operator=(const String &other) = default;
	String(String &&) = default;
	String &operator=(String &&) = default;*/

public:
	int to_int(std::size_t* pos = 0, int base = 10) const;
	long to_long(std::size_t* pos = 0, int base = 10) const;
	long long to_longlong(std::size_t* pos = 0, int base = 10) const;

	unsigned long to_unsignedlong(std::size_t* pos = 0, int base = 10)
	const;
	unsigned long long to_unsignedlonglong(std::size_t* pos = 0, int base =
		10) const;

	float to_float(std::size_t* pos = 0) const;
	double to_double(std::size_t* pos = 0) const;
	long double to_longdouble(std::size_t* pos = 0) const;

private:
private:
};

}

#endif /* !MY_LIBCPP_STRING_HPP */
