/*
** EPIintECH PROJECint, 2021
** my_libCPP
** File description:
** Value<int>
*/

#ifndef MY_LIBCPP_INT_HPP
# define MY_LIBCPP_INT_HPP

# include "Value.hpp"

namespace MY_LIBCPP
{

class Int : public Value<int>
{
public:
	Int(const int &v);
	~Int() override = default;
	Int(const Int &copy) = default;
	Int &operator=(const int &other);
	Int(Int &&) noexcept = default;
	Int &operator=(Int &&) = default;

public:
	// https://en.cppreference.com/w/cpp/language/types
	static constexpr int MAXVALUE = +2147483647;
	static constexpr int MINVALUE = -2147483647;

	static Int randomInt(const Int &min = MINVALUE,
	                     const Int &max = MAXVALUE);
	static std::vector<Int> primeNumber(const Int &min = 2,
	                                    const Int &max = 100);

private:
private:
};

Int operator+(const int &value1, const Int &value2);
Int operator-(const int &value1, const Int &value2);
Int operator*(const int &value2, const Int &value1);
Int operator/(const int &value1, const Int &value2);

bool operator<=(const int &value1, const Int &value2);
bool operator>=(const int &value1, const Int &value2);
bool operator<(const int &value1, const Int &value2);
bool operator>(const int &value1, const Int &value2);

}

#endif /* !MY_LIBCPP_INT_HPP */
