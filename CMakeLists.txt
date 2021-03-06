cmake_minimum_required(VERSION 3.10)

# Citrus
project(Citrus VERSION 0.0.1)

aux_source_directory(src SOURCE)
add_library(${PROJECT_NAME} STATIC ${SOURCE})

configure_file(include/citrusConfig.h.in citrusConfig.h)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(${PROJECT_NAME} PUBLIC include)

target_compile_options(${PROJECT_NAME} PRIVATE 
    "-Wall"
    "-Werror"    
)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    target_compile_options(${PROJECT_NAME} PRIVATE "-g")
    add_compile_definitions(DEBUG_ON)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE "-O2")
endif()

message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")

# Citrus Tests
project(CitrusTests)

add_executable(${PROJECT_NAME} test/src/main.c)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} Citrus)
target_link_libraries(${PROJECT_NAME} cmocka)

target_compile_options(${PROJECT_NAME} PRIVATE 
    "-Wall"
    "-Werror"    
)

# Sandbox
project(Sandbox)

add_executable(${PROJECT_NAME} sandbox/src/main.c)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} Citrus)

target_compile_options(${PROJECT_NAME} PRIVATE 
    "-Wall"
    "-Werror"    
)

