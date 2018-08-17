/*
** EPIfloatECH PROJECfloat, 2021
** my_libCPP
** File description:
** Value<float>
*/

#ifndef MY_LIBCPP_FLOAT_HPP
# define MY_LIBCPP_FLOAT_HPP

# include "Value.hpp"

namespace MY_LIBCPP
{

class Float : public Value<float>
{
public:
	Float(const float &v);
	~Float() override = default;
	Float(const Float &copy) = default;
	Float &operator=(const Float &other)
	{
		_v = other;
		return *this;
	}
	Float &operator=(const float &other);
	Float(Float &&) noexcept = default;
	Float &operator=(Float &&) = default;

public:
	// https://en.cppreference.com/w/cpp/language/types
	static constexpr float MAXVALUE = 3.402823e+38;
	static constexpr float MINVALUE = 1.401298e-45;

	// static Float getRandomFloat(const Float &min = MINVALUE,
	//                          const Float &max = MAXVALUE);
	static Float getRandomFloat(const Float &min = 0,
	                            const Float &max = 1
	);

	operator float() const
	{
		return this->_v;
	}

	Float operator+(const Float &value) const
	{
		return _v + value;
	}
	Float operator-(const Float &value) const
	{
		return _v - value;
	}
	Float operator*(const Float &value) const
	{
		return _v * value;
	}
	Float operator/(const Float &value) const
	{
		return _v / value;
	}

	template <class T>
	Float operator*(const T &value) const
	{
		return _v * value;
	}

	template <class T>
	bool operator!=(const T &value) const
	{
		return _v != value;
	}
	template <class T>
	bool operator==(const T &value) const
	{
		return _v == value;
	}

private:
private:
};

template <class T>
Float operator+(const T &value1, const Float &value2)
{
	return value1 + value2.value();
}
template <class T>
Float operator-(const T &value1, const Float &value2)
{
	return value1 - value2.value();
}
template <class T>
Float operator*(const T &value1, const Float &value2)
{
	return value1 * value2.value();
}
template <class T>
Float operator/(const T &value1, const Float &value2)
{
	if (value2 == 0)
		return INFINITY;
	return value1 / value2.value();
}

}

#endif /* !MY_LIBCPP_FLOAT_HPP */
