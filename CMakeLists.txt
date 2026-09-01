cmake_minimum_required(VERSION 4.4)
project(cpp_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_project src/bin/main.cpp)
target_link_libraries(cpp_project
        PRIVATE tools
)

add_executable(hello src/bin/hello.cpp)

add_library(tools
        src/tools/src/tools.cpp
        src/tools/inc/tools.hpp
        src/data_structure/inc/Node.hpp
        src/data_structure/inc/list.hpp
        src/data_structure/src/list.cpp
        src/tools/inc/result.hpp
        src/tools/inc/macro.hpp)


add_executable(node src/bin/node_example.cpp)
target_link_libraries(node
        PRIVATE tools
)

add_executable(const_example src/bin/const_exampl.cpp)
target_link_libraries(const_example
        PRIVATE tools
)