/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Value
*/

#ifndef MY_LIBCPP_VALUE_HPP
# define MY_LIBCPP_VALUE_HPP

# include <cmath>
# include <ostream>
# include <random>

namespace MY_LIBCPP
{

template <class T>
class Value
{
public:
	explicit Value(const T &v)
		: _v(v), _type("Value")
	{}
	virtual ~Value() = default;
	Value(const Value &copy) = default;
	Value<T> &operator=(const Value &other)
	{
		this->_v = other.value();
		return *this;
	}
	Value(Value &&) noexcept = default;
	Value &operator=(Value &&) noexcept = default;

public:
	const T &value() const noexcept
	{
		return this->_v;
	}

	const std::string &type() const noexcept
	{
		return this->_type;
	}

	std::string to_string() const
	{
		return std::to_string(this->_v);
	}

	bool operator==(const Value &other) const
	{
		return this->_v == other.value();
	}

	bool operator==(const T &other) const
	{
		return this->_v == other;
	}

	bool operator!=(const Value &other) const
	{
		return !(*this == other);
	}

	bool operator!=(const T &other) const
	{
		return !(this->_v == other);
	}

	bool operator<=(const Value &other) const
	{
		return this->_v <= other.value();
	}

	bool operator<=(const T &other) const
	{
		return this->_v <= other;
	}

	bool operator>=(const Value &other) const
	{
		return this->_v >= other.value();
	}

	bool operator>=(const T &other) const
	{
		return this->_v >= other;
	}

	bool operator>(const Value &other) const
	{
		return this->_v > other.value();
	}

	bool operator>(const T &other) const
	{
		return this->_v > other;
	}

	bool operator<(const Value &other) const
	{
		return this->_v < other.value();
	}

	bool operator<(const T &other) const
	{
		return this->_v < other;
	}

	Value<T> &operator+=(const Value &other)
	{
		this->_v += other.value();
		return *this;
	}

	Value<T> &operator-=(const Value &other)
	{
		this->_v -= other.value();
		return *this;
	}

	Value<T> &operator*=(const Value &other)
	{
		this->_v *= other.value();
		return *this;
	}

	Value<T> &operator/=(const Value &other)
	{
		if (other.value() == 0)
			this->_v = INFINITY;
		else
			this->_v /= other.value();
		return *this;
	}

	Value<T> &operator+=(const T &other)
	{
		this->_v += other;
		return *this;
	}

	Value<T> &operator-=(const T &other)
	{
		this->_v -= other;
		return *this;
	}

	Value<T> &operator*=(const T &other)
	{
		this->_v *= other;
		return *this;
	}

	Value<T> &operator/=(const T &other)
	{
		if (other == 0)
			this->_v = INFINITY;
		else
			this->_v /= other;
		return *this;
	}

	Value<T> operator+(const Value &other)
	{
		return Value<T>(this->_v + other.value());
	}

	Value<T> operator-(const Value &other)
	{
		return Value<T>(this->_v - other.value());
	}

	Value<T> operator*(const Value &other)
	{
		return Value<T>(this->_v * other.value());
	}

	Value<T> operator/(const Value &other)
	{
		if (other == 0)
			return Value<T>(INFINITY);
		return Value<T>(this->_v / other.value());
	}

	Value<T> operator+(const T &other)
	{
		return Value<T>(this->_v + other);
	}

	Value<T> operator-(const T &other)
	{
		return Value<T>(this->_v - other);
	}

	Value<T> operator*(const T &other)
	{
		return Value<T>(this->_v * other);
	}

	Value<T> operator/(const T &other)
	{
		if (other == 0)
			return Value<T>(INFINITY);
		return Value<T>(this->_v / other);
	}

	Value<T> operator%(const Value &other)
	{
		if (other == 0)
			return Value<T>(other);
		return Value<T>(this->_v % other.value());
	}

	Value<T> operator%(const T &other)
	{
		if (other == 0)
			return Value<T>(other);
		return Value<T>(this->_v % other);
	}

	const Value<T> &operator++()
	{
		this->_v++;
		return *this;
	}

	const Value<T> &operator--()
	{
		this->_v--;
		return *this;
	}

	const Value<T> operator++(int val)
	{
		++this->_v;
		return *this;
	}

	const Value<T> operator--(int val)
	{
		--this->_v;
		return *this;
	}

	static void initRandom()
	{
		srandom(time(nullptr));
	}

	static Value<T> getRandomValue()
	{
		return Value<T>(random() / static_cast<T>(RAND_MAX));
	}

	explicit operator T() const
	{
		return this->_v;
	}

	Value<T> getOpposite() const
	{
		return Value<T>(-this->_v);
	}

	Value<T> getInverse() const
	{
		if (this->_v == 0)
			return Value<T>(0);
		return Value<T>(1 / this->_v);
	}

	Value<T> &square()
	{
		this->_v *= this->_v;
		return *this;
	}

	Value<T> &squareRoot()
	{
		this->_v = sqrt(this->_v);
		return *this;
	}

	Value<T> &floor()
	{
		this->_v = std::floor(this->_v);
		return *this;
	}

	Value<T> &truncate()
	{
		this->_v = std::trunc(this->_v);
		return *this;
	}

protected:
	T _v;
	std::string _type;

private:
};

template <class T>
std::string operator+(const std::string &str, const Value<T> &v)
{
	return str + v.to_string();
}
template <class T>
std::string operator+(const Value<T> &v, const std::string &str)
{
	return v.to_string() + str;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const Value<T> &v)
{
	out << v.value();
	return out;
}

}

#endif /* !MY_LIBCPP_VALUE_HPP */
