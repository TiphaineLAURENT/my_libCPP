/*
** EPIfloatECH PROJECfloat, 2021
** my_libCPP
** File description:
** Value<float>
*/

#ifndef MY_LIBCPP_FLOAfloat_HPP
# define MY_LIBCPP_FLOAfloat_HPP

# include "Value.hpp"

namespace MY_LIBCPP
{

class Float : public Value<float>
{
public:
	explicit Float(const float &v);
	~Float() override = default;
	Float &operator=(const int &value)
	{
		return *this;
	}
	/*Float(const Float &copy) = default;
	Float &operator=(const Value &other);
	Float(Float &&) noexcept = default;
	Float &operator=(Float &&) = default;*/

public:
	static constexpr float MAXVALUE = 3.40282e+38;
	static constexpr float MINVALUE = -3.40282e+38;

private:
private:
};

Float operator+(const float &value1, const Float &value2);
Float operator-(const float &value1, const Float &value2);
Float operator*(const float &value2, const Float &value1);
Float operator/(const float &value1, const Float &value2);

}

#endif /* !MY_LIBCPP_FLOAfloat_HPP */
