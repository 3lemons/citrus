cmake_minimum_required(VERSION 3.10)

project(Citrus VERSION 0.0.1)

add_library(${PROJECT_NAME} STATIC src/entry.c)

configure_file(include/citrusConfig.h.in citrusConfig.h)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

target_compile_options(${PROJECT_NAME} PRIVATE 
    "-Wall"
    "-Werror"    
)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    target_compile_options(${PROJECT_NAME} PRIVATE "-g")
else()
    target_compile_options(${PROJECT_NAME} PRIVATE "-O2")
endif()

add_custom_target(test ALL
    COMMAND echo "run tests"
    VERBATIM
)

message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")