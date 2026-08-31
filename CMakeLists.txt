cmake_minimum_required(VERSION 4.4)
project(cpp_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_project src/bin/main.cpp)

add_executable(hello src/bin/hello.cpp)

add_library(tools src/tools/tools.cpp src/tools/tools.hpp
        src/data_structure/inc/Node.hpp)

target_link_libraries(cpp_project
        PRIVATE tools
)
add_executable(node src/bin/node_example.cpp)
