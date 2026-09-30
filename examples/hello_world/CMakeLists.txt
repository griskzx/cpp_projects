add_executable(hello_world_example main.cpp)

if(BUILD_TESTING)
    add_test(NAME hello_world_example COMMAND hello_world_example)
endif()
