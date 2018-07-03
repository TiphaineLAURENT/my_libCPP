/*
** EPITECH PROJECT, 2017
** my_libCPP
** File description:
** Timer.cpp
*/

#include "Timer.hpp"

namespace MY_LIBCPP
{

Timer::Timer()
	: _end(std::chrono::system_clock::now()), _execThread(),
	  _repeatThread(), _iterations(0), _repeatUntilThread(),
	  _condition()
{
}

void Timer::start(int duration)
{
	_end = std::chrono::system_clock::now()
		+ std::chrono::seconds(duration);
}

bool Timer::ended()
{
	return _end <= std::chrono::system_clock::now()
	       && _iterations == 0;
}

static void exec_thread_function(void (*function)(), const
std::chrono::time_point<std::chrono::system_clock>
&end
)
{
	std::this_thread::sleep_until(end);
	function();
}

void Timer::exec(void (*function)(), int after, int function_duration)
{
	start(after);
	_execThread = std::thread(exec_thread_function, function,
	                          _end - std::chrono::seconds(function_duration));
	_execThread.detach();
}

static void repeat_thread_function(void (*function)(), int *iterations)
{
	for (; *iterations > 0; --*iterations)
		function();
}

void Timer::repeat(void (*function)(), int iterations)
{
	_iterations = iterations;
	_repeatThread = std::thread(repeat_thread_function, function, &_iterations);
	_repeatThread.detach();
}

static void repeat_until_thread_function(void (*function)(), const
std::chrono::time_point<std::chrono::system_clock> &end, int *iterations)
{
	if (*iterations == -1) {
		while (std::chrono::system_clock::now() <= end)
			function();
		*iterations = 0;
	} else {
		for (; std::chrono::system_clock::now() <= end && *iterations
		                                                  > 0; --*iterations)
			function();
	}
}

void Timer::repeat_until(void (*function)(), int duration, int iterations)
{
	start(duration);
	_iterations = iterations;
	_repeatUntilThread = std::thread(repeat_until_thread_function,
	                                 function, _end, &_iterations);
	_repeatUntilThread.detach();
}

void Timer::wait()
{
	/*
	std::mutex mutex;
	std::unique_lock<std::mutex> lock(mutex);
	_condition.wait(lock, [this]{return ended();});
	 */
	while (!ended());
}

}
