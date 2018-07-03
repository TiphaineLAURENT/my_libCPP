cmake_minimum_required(VERSION 3.10)
project(my_libCPP)

set(CMAKE_CXX_STANDARD 17)

add_library(my_libCPP SHARED library.hpp Timer.cpp Timer.hpp)

find_package(Threads)

add_executable(my_test library.hpp test.cpp)

target_link_libraries(my_test
        my_libCPP
        ${CMAKE_THREAD_LIBS_INIT}
        )
