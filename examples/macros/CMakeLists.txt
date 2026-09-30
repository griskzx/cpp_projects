add_executable(macros_example main.cpp)

if(BUILD_TESTING)
    add_test(NAME macros_example COMMAND macros_example)
endif()
