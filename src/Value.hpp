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
		_v = other.value();
		return *this;
	}
	Value(Value &&) noexcept = default;
	Value &operator=(Value &&) noexcept = default;

public:
	const T &value() const noexcept
	{
		return _v;
	}

	const std::string &type() const noexcept
	{
		return _type;
	}

	std::string to_string() const
	{
		return std::to_string(_v);
	}

	bool operator==(const Value &other) const
	{
		return _v == other.value();
	}

	bool operator==(const T &other) const
	{
		return _v == other;
	}

	bool operator!=(const Value &other) const
	{
		return !(*this == other);
	}

	bool operator!=(const T &other) const
	{
		return !(this->_v == other);
	}

	Value<T> &operator+=(const Value &other)
	{
		_v += other.value();
		return *this;
	}

	Value<T> &operator-=(const Value &other)
	{
		_v -= other.value();
		return *this;
	}

	Value<T> &operator*=(const Value &other)
	{
		_v *= other.value();
		return *this;
	}

	Value<T> &operator/=(const Value &other)
	{
		if (other.value() == 0)
			_v = INFINITY;
		else
			_v /= other.value();
		return *this;
	}

	Value<T> &operator+=(const T &other)
	{
		_v += other;
		return *this;
	}

	Value<T> &operator-=(const T &other)
	{
		_v -= other;
		return *this;
	}

	Value<T> &operator*=(const T &other)
	{
		_v *= other;
		return *this;
	}

	Value<T> &operator/=(const T &other)
	{
		if (other == 0)
			_v = INFINITY;
		else
			_v /= other;
		return *this;
	}

	Value<T> operator+(const Value &other)
	{
		return Value<T>(_v + other.value());
	}

	Value<T> operator-(const Value &other)
	{
		return Value<T>(_v - other.value());
	}

	Value<T> operator*(const Value &other)
	{
		return Value<T>(_v * other.value());
	}

	Value<T> operator/(const Value &other)
	{
		if (other == 0)
			return Value<T>(INFINITY);
		return Value<T>(_v / other.value());
	}

	Value<T> operator+(const float &other)
	{
		return Value<T>(_v + other);
	}

	Value<T> operator-(const float &other)
	{
		return Value<T>(_v - other);
	}

	Value<T> operator*(const float &other)
	{
		return Value<T>(_v * other);
	}

	Value<T> operator/(const float &other)
	{
		if (other == 0)
			return Value<T>(INFINITY);
		return Value<T>(_v / other);
	}

	static void initRandom()
	{
		srandom(time(nullptr));
	}

	static Value<T> randomValue()
	{
		return Value<T>(random() / static_cast<T>(RAND_MAX));
		/*
		** std::random_device rd;
		** std::mt19937 gen(rd());
		** std::uniform_int_distribution<> dis(1, 6);
		** return Value<T>(dis(gen));
		*/
	}

	explicit operator T() const
	{
		return _v;
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
std::ostream &operator<<(std::ostream &out, const Value<T> &v)
{
	out << v.value();
	return out;
}


}

#endif /* !MY_LIBCPP_VALUE_HPP */
