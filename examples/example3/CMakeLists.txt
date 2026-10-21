add_executable(example3 main.cpp
    lib.cpp
)

target_sources(example3
    PRIVATE
    FILE_SET CXX_MODULES FILES
        lib.cppm
)
