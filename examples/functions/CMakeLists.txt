add_executable(functions_example main.cpp add.cpp)

if(BUILD_TESTING)
    add_test(NAME functions_example COMMAND functions_example)
endif()
