cmake_minimum_required(VERSION 3.10)


project(my_libCPP)

set(CMAKE_CXX_STANDARD 17)


add_library(my_libCPP SHARED src/library.hpp src/Timer.hpp src/String.cpp
        src/String.hpp src/Math.hpp src/Vector2D.cpp src/Vector2D.hpp
        src/Vector3D.cpp src/Vector3D.hpp
        src/Math.cpp src/Value.cpp src/Value.hpp src/Float.cpp src/Float.hpp
        src/Int.cpp src/Int.hpp src/Matrix.cpp src/Matrix.hpp)

find_package(Threads)


add_executable(my_test src/library.hpp test.cpp)

target_link_libraries(my_test
        my_libCPP
        ${CMAKE_THREAD_LIBS_INIT}
        )

set_target_properties(my_libCPP PROPERTIES LINKER_LANGUAGE CXX)
