/*
** EPITECH PROJECT, 2021
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

	static Int getRandomInt(const Int &min = MINVALUE,
	                        const Int &max = MAXVALUE
	);
	static std::vector<Int> getPrimeNumbers(const Int &min = 2,
	                                        const Int &max = 100
	);

	operator int() const
	{
		return this->_v;
	}

	Int operator+(const Int &value) const
	{
		return _v + value.value();
	}

	Int operator-(const Int &value) const
	{
		return _v - value.value();
	}

	Int operator*(const Int &value) const
	{
		return _v * value.value();
	}

	Int operator/(const Int &value) const
	{
		return _v / value.value();
	}

	template <class T>
	Int operator+(const T &value) const
	{
		return _v + value;
	}

	template <class T>
	Int operator-(const T &value) const
	{
		return _v - value;
	}

	template <class T>
	Int operator*(const T &value) const
	{
		return _v * value;
	}

	template <class T>
	Int operator/(const T &value) const
	{
		return _v / value;
	}

	bool operator<=(const Int &other) const
	{
		return this->_v <= other.value();
	}

	bool operator>=(const Int &other) const
	{
		return this->_v >= other.value();
	}

	bool operator<(const Int &other) const
	{
		return this->_v < other.value();
	}

	bool operator>(const Int &other) const
	{
		return this->_v > other.value();
	}

	template <class T>
	bool operator<(const T &other) const
	{
		return this->_v < other;
	}

	template <class T>
	bool operator>(const T &other) const
	{
		return this->_v > other;
	}

private:
private:
};

Int operator+(const int &value1, const Int &value2);
Int operator-(const int &value1, const Int &value2);
Int operator*(const int &value2, const Int &value1);
Int operator/(const int &value1, const Int &value2);

template <class T>
bool operator<=(const T &value1, const Int &value2)
{
	return value1 <= value2.value();
}
template <class T>
bool operator>=(const T &value1, const Int &value2)
{
	return value1 >= value2.value();
}
template <class T>
bool operator<(const T &value1, const Int &value2)
{
	return value1 < value2.value();
}
template <class T>
bool operator>(const T &value1, const Int &value2)
{
	return value1 > value2.value();
}

}

#endif /* !MY_LIBCPP_INT_HPP */
