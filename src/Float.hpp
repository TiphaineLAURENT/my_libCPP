/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Float
*/

#ifndef MY_LIBCPP_FLOAT_HPP
#define MY_LIBCPP_FLOAT_HPP

namespace MY_LIBCPP
{

class Float
{
public:
	Float(float f);
	~Float() = default;
	Float(const Float &copy) = default;
	Float &operator=(const Float &other) = default;
	Float(Float &&) = default;
	Float &operator=(Float &&) = default;

public:
	static float randomFloat();

private:
	float _f;

private:
};

}

#endif /* !MY_LIBCPP_FLOAT_HPP */
