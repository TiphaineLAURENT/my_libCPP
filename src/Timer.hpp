/*
** EPITECH PROJECT, 2017
** my_libCPP
** File description:
** Timer.hpp
*/

#ifndef MY_LIBCPP_TIMER_HPP
# define MY_LIBCPP_TIMER_HPP

#include <iostream>
#include <chrono>
#include <thread>
#include <condition_variable>

namespace MY_LIBCPP
{

void exec_thread_function(void (*function)(), const
std::chrono::time_point<std::chrono::system_clock>
&end
)
{
	std::this_thread::sleep_until(end);
	function();
}

void repeat_thread_function(void (*function)(), int *iterations)
{
	for (; *iterations > 0; --*iterations)
		function();
}

void repeat_until_thread_function(void (*function)(), const
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

template <class T>
class Timer
{
public:
	Timer()
		: _end(std::chrono::system_clock::now()), _execThread(),
		  _repeatThread(), _iterations(0), _repeatUntilThread(),
		  _condition()
	{}
	~Timer() noexcept = default;
	Timer(const Timer &) = default;
	Timer &operator=(const Timer &) = default;
	Timer(Timer &&) noexcept = default;
	Timer &operator=(Timer &&) noexcept = default;

public:
	void    start(int duration)
	{
		_end = std::chrono::system_clock::now()
		       + T(duration);
	}

	void    exec(void (*function)(), int after,
	             int function_duration = 1)
	{
		start(after);
		_execThread = std::thread(exec_thread_function, function,
		                          _end - T(function_duration));
		_execThread.detach();
	}

	void    repeat(void (*function)(), int iterations)
	{
		_iterations = iterations;
		_repeatThread = std::thread(repeat_thread_function, function, &_iterations);
		_repeatThread.detach();
	}

	void    repeat_until(void (*function)(), int duration,
	                     int iterations = -1)
	{
		start(duration);
		_iterations = iterations;
		_repeatUntilThread = std::thread(repeat_until_thread_function,
		                                 function, _end, &_iterations);
		_repeatUntilThread.detach();
	}

bool    ended()
	{
		return _end <= std::chrono::system_clock::now()
		       && _iterations == 0;
	}

	void    wait()
	{
		/*
		std::mutex mutex;
		std::unique_lock<std::mutex> lock(mutex);
		_condition.wait(lock, [this]{return ended();});
		 */
		while (!ended());
	}

private:
	std::chrono::time_point<std::chrono::system_clock>      _end;
	std::thread     _execThread;
	std::thread     _repeatThread;
	int     _iterations;
	std::thread     _repeatUntilThread;
	std::condition_variable _condition;

private:
};

template <class T>
std::ostream &operator<<(std::ostream &out, const Timer<T> &timer)
{
	out << std::chrono::system_clock::to_time_t
		(std::chrono::system_clock::now());
	/*out << std::chrono::system_clock::to_time_t(
	std::chrono::time_point_cast<T>
	        (std::chrono::system_clock::now()));*/
	return out;
}

}

#endif //MY_LIBCPP_TIMER_HPP
