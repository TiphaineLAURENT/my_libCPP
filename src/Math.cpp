/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Math
*/

#include "Math.hpp"

namespace MY_LIBCPP
{

namespace Math
{

float to_degrees(float angle)
{
	return angle * RAD_TO_DEG;
}

float from_degrees(float angle)
{
	return angle * DEG_TO_RAD;
}

float to_radians(float angle)
{
	return angle * DEG_TO_RAD;
}

float from_radians(float angle)
{
	return angle * RAD_TO_DEG;
}

}

}
