add_executable(const_example main.cpp)

if(BUILD_TESTING)
    add_test(NAME const_example COMMAND const_example)
endif()
