add_executable(linked_list_example main.cpp list.cpp)
target_link_libraries(linked_list_example PRIVATE result_headers)

if(BUILD_TESTING)
    add_test(NAME linked_list_example COMMAND linked_list_example)

    add_executable(list_insert_test insert_test.cpp list.cpp)
    target_link_libraries(list_insert_test PRIVATE result_headers)
    add_test(NAME list_insert_test COMMAND list_insert_test)
endif()
