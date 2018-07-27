/*
** EPITECH PROJECT, 2021
** my_libCPP
** File description:
** Float
*/

#include <cstdlib>
#include "Float.hpp"

namespace MY_LIBCPP
{

Float::Float(float f)
	: _f(f)
{}

float Float::randomFloat()
{
	return static_cast<float>(random() / static_cast<float>(RAND_MAX));
}

}
