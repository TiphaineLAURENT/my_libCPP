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

	return 0;
}
