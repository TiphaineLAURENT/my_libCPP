/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Math
*/

#ifndef MY_LIBCPP_MATH_HPP
# define MY_LIBCPP_MATH_HPP

# include "Vector2D.hpp"
# include "Vector3D.hpp"
# include "Matrix.hpp"

namespace MY_LIBCPP
{

namespace Math
{

const double HALF_PI = 1.57079632679489661923;
const double PI = 3.14159265358979323846;
const double QUARTER_PI = 0.7853982;
const double TWO_PI = 6.28318530717958647693;
const double TAU = TWO_PI;

const double DEG_TO_RAD = PI / 180.0;
const double RAD_TO_DEG = 180.0 / PI;

template<class T>
T map(T value, T frommin, T frommax, T tomin, T tomax)
{
	return (value - frommin) * (tomax - tomin) / (frommax - frommin)
	       + tomin;
}

float to_degrees(float angle);
float from_degrees(float angle);
float to_radians(float angle);
float from_radians(float angle);

}

}

#endif //MY_LIBCPP_MATH_HPP
