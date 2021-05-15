cmake_minimum_required(VERSION 3.10)

project(Citrus VERSION 0.0.1)

add_executable(citrus src/main.c)

configure_file(include/citrusConfig.h.in citrusConfig.h)

set_property(TARGET citrus PROPERTY C99_STANDARD 11)

target_include_directories(citrus PUBLIC "${PROJECT_BINARY_DIR}")
message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")