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

private:
private:
};

Float operator+(const float &value1, const Float &value2);
Float operator-(const float &value1, const Float &value2);
Float operator*(const float &value2, const Float &value1);
Float operator/(const float &value1, const Float &value2);

}

#endif /* !MY_LIBCPP_FLOAT_HPP */
