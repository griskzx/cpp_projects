# Result 是模板，定义全部放在头文件中；INTERFACE 目标只传递头文件目录。
add_library(result_headers INTERFACE)
target_include_directories(result_headers INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(result_example main.cpp)
target_link_libraries(result_example PRIVATE result_headers)

if(BUILD_TESTING)
    add_test(NAME result_example COMMAND result_example)
endif()
