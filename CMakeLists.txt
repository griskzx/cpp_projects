cmake_minimum_required(VERSION 3.25)

project(MyProject CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB MAIN_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
if(NOT MAIN_SOURCES)
    message(FATAL_ERROR "No .cpp files found under src/.")
endif()

set(ENTRY_MAIN_FILES "")
set(SHARED_SOURCES "")
foreach(source_file IN LISTS MAIN_SOURCES)
    file(READ "${source_file}" source_content)
    string(REGEX REPLACE "//[^\n\r]*" "" source_without_line_comments "${source_content}")
    string(REGEX MATCH "(^|[\r\n])[ \t]*int[ \t\r\n]+main[ \t\r\n]*\\(" has_main "${source_without_line_comments}")
    if(has_main)
        get_filename_component(file_name "${source_file}" NAME)
        list(APPEND ENTRY_MAIN_FILES "${file_name}")
    else()
        list(APPEND SHARED_SOURCES "${source_file}")
    endif()
endforeach()

if(NOT ENTRY_MAIN_FILES)
    message(FATAL_ERROR "No source file with int main(...) found under src/.")
endif()

set(AVAILABLE_MAIN_FILES ${ENTRY_MAIN_FILES})

set(DEFAULT_MAIN_FILE "")
foreach(file_name IN LISTS AVAILABLE_MAIN_FILES)
    if(file_name STREQUAL "main.cpp")
        set(DEFAULT_MAIN_FILE "${file_name}")
        break()
    endif()
endforeach()

if(DEFAULT_MAIN_FILE STREQUAL "")
    list(GET AVAILABLE_MAIN_FILES 0 DEFAULT_MAIN_FILE)
endif()

set(MAIN_FILE "${DEFAULT_MAIN_FILE}" CACHE STRING "Main source file under src/ to build, e.g. main.cpp")
set_property(CACHE MAIN_FILE PROPERTY STRINGS ${AVAILABLE_MAIN_FILES})

if(NOT MAIN_FILE IN_LIST AVAILABLE_MAIN_FILES)
    list(JOIN AVAILABLE_MAIN_FILES ", " AVAILABLE_MAIN_FILES_TEXT)
    message(FATAL_ERROR "MAIN_FILE='${MAIN_FILE}' is invalid. Available files: ${AVAILABLE_MAIN_FILES_TEXT}")
endif()

set(SELECTED_MAIN_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/${MAIN_FILE}")
get_filename_component(TARGET_NAME "${MAIN_FILE}" NAME_WE)
set(APP_TARGET_NAME "${TARGET_NAME}")
if(TARGET_NAME STREQUAL "main")
    set(APP_TARGET_NAME "${PROJECT_NAME}_${TARGET_NAME}")
endif()

add_executable(${APP_TARGET_NAME} "${SELECTED_MAIN_SOURCE}" ${SHARED_SOURCES})
if(NOT APP_TARGET_NAME STREQUAL TARGET_NAME)
    set_target_properties(${APP_TARGET_NAME} PROPERTIES OUTPUT_NAME "${TARGET_NAME}")
endif()
