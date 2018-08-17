/*
** EPITECH PROJECT, 2017
** my_libCPP
** File description:
** test.cpp
*/

#include <iostream>

#include "src/library.hpp"

static void my_exec()
{
	std::cout << "exec" << std::endl;
}

static void my_repeat()
{
	std::cerr << "repeat" << std::endl;
}

static void my_until()
{
	std::cout << "until" << std::endl;
}

int main()
{
	MY_LIBCPP::Value<int>::initRandom();

	/*MY_LIBCPP::Timer<std::chrono::seconds> timer;

	std::cout << timer << std::endl;
	timer.start(2);

	std::cout << timer.ended() << std::endl;
	timer.wait();
	std::cout << timer.ended() << std::endl;
	std::cout << timer << std::endl;

	timer.exec(my_exec, 1);
	timer.wait();

	timer.repeat(my_repeat, 5);
	timer.wait();

	timer.repeat_until(my_until, 1, 10);
	timer.wait();*/

	/*MY_LIBCPP::String str("42.42");
	std::cout << str.to_int() << std::endl;
	std::cout << str.to_float() << std::endl;*/

	/*std::cout << MY_LIBCPP::Math::map<int>(300, 0, 600, 255, 0) <<
	        std::endl;
	std::cout << MY_LIBCPP::Math::map<float>(10.1, 10, 20, 0, 10) <<
	        std::endl;*/

	/*srandom(time(nullptr));
	MY_LIBCPP::Math::Vector2D vector =
		MY_LIBCPP::Math::Vector2D::random2D();
	std::cout << vector << std::endl;
	std::cout << MY_LIBCPP::Math::Vector2D(vector) << std::endl;

	vector.set(10, 100);
	vector.setMag(23);
	std::cout << vector.mag() << std::endl;
	std::cout << vector.normalize() << std::endl;*/


	/*MY_LIBCPP::Float v = 3;
	v *= 5;
	v /= 2;
	v += 3;
	v -= 2;
	std::cout << v << std::endl;

	std::cout << MY_LIBCPP::Float(MY_LIBCPP::Value(v)) << std::endl;

	std::cout << 0 + MY_LIBCPP::Float(5.0) + 0 << std::endl;
	std::cout << 0 - MY_LIBCPP::Float(5.0) - 0 << std::endl;
	std::cout << 0 * MY_LIBCPP::Float(5.0) * 0 << std::endl;
	std::cout << 0 / MY_LIBCPP::Float(5.0) / 0 << std::endl;
	std::cout << MY_LIBCPP::Float(0) * MY_LIBCPP::Float(5.0) *
	MY_LIBCPP::Float(0) << std::endl;
	std::cout << MY_LIBCPP::Float(0) / MY_LIBCPP::Float(5.0) /
	MY_LIBCPP::Float(0) << std::endl;

	if (MY_LIBCPP::Float(2.0) != 3)
		std::cout << "False" << std::endl;
	std::cout << "Test " + MY_LIBCPP::Float::getRandomFloat() << std::endl;*/

	/*MY_LIBCPP::Int v = 3;
	v *= 5;
	v /= 2;
	v += 3;
	v -= 2;
	std::cout << v << std::endl;

	std::cout << MY_LIBCPP::Int(MY_LIBCPP::Value(v)) << std::endl;

	std::cout << 0 + MY_LIBCPP::Int(5) + 0 << std::endl;
	std::cout << 0 - MY_LIBCPP::Int(5) - 0 << std::endl;
	std::cout << 0 * MY_LIBCPP::Int(5) * 0 << std::endl;
	std::cout << 0 / MY_LIBCPP::Int(5) / 0 << std::endl;

	std::cout << MY_LIBCPP::Int(0) * MY_LIBCPP::Int(5) *
	             MY_LIBCPP::Int(0) << std::endl;
	std::cout << MY_LIBCPP::Int(0) / MY_LIBCPP::Int(5) /
	             MY_LIBCPP::Int(0) << std::endl;

	if (MY_LIBCPP::Int(2) != 3)
		std::cout << "False" << std::endl;
	std::cout << "Test " + MY_LIBCPP::Int::getRandomInt() << std::endl;*/

	MY_LIBCPP::Int i = 4;
	std::cout << i.getOpposite() << std::endl;
	std::cout << i.getInverse() << std::endl;
	if (i == 0)
		std::cout << "True" << std::endl;

	for (auto &p : i.getPrimeNumbers(10, 100))
		std::cout << p + ",";
	std::cout << std::endl;

	std::cout << i.square() << std::endl;
	std::cout << i.squareRoot() << std::endl;
	std::cout << i.floor() << std::endl;
	std::cout << i.truncate() << std::endl;

	return 0;
}
