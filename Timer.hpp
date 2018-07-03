/*
** EPITECH PROJECT, 2017
** my_libCPP
** File description:
** Timer.hpp
*/

#ifndef MY_LIBCPP_TIMER_HPP
# define MY_LIBCPP_TIMER_HPP

#include <chrono>
#include <thread>
#include <condition_variable>

namespace MY_LIBCPP
{

class Timer
{
public:
	Timer();
	~Timer() = default;
	Timer(const Timer &) = default;
	Timer &operator=(const Timer &) = default;
	Timer(Timer &&) = default;
	Timer &operator=(Timer &&) = default;

public:
	void    start(int duration);
	void    exec(void (*function)(), int after,
	             int function_duration = 1);
	void    repeat(void (*function)(), int iterations);
	void    repeat_until(void (*function)(), int duration,
	                     int iterations = -1);
	bool    ended();
	void    wait();

private:
	std::chrono::time_point<std::chrono::system_clock>      _end;
	std::thread     _execThread;
	std::thread     _repeatThread;
	int     _iterations;
	std::thread     _repeatUntilThread;
	std::condition_variable _condition;

};

}

#endif //MY_LIBCPP_TIMER_HPP
