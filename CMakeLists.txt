cmake_minimum_required(VERSION 4.4)
project(cpp_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_project bin/main.cpp
        tools/tools.cpp
        tools/tools.hpp)

add_executable(hello bin/hello.cpp)

add_library(tools tools/tools.cpp tools/tools.hpp)
