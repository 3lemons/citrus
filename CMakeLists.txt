cmake_minimum_required(VERSION 3.10)

project(Citrus VERSION 0.0.1)

add_executable(citrus src/main.c)

configure_file(include/citrusConfig.h.in citrusConfig.h)

set_property(TARGET citrus PROPERTY C_STANDARD 11)

target_include_directories(citrus PUBLIC "${PROJECT_BINARY_DIR}")

target_compile_options(citrus PRIVATE 
    "-Wall"
    "-Werror"    
)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    target_compile_options(citrus PRIVATE "-g")
else()
    target_compile_options(citrus PRIVATE "-O2")
endif()

add_custom_target(lint ALL
    COMMAND echo "run linter"
    VERBATIM
)

add_custom_target(test ALL
    COMMAND echo "run tests"
    VERBATIM
)

message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")