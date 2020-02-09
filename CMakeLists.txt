# 加入 其他模块

cmake_minimum_required(VERSION 3.15)
project(TestCpp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp test.cpp test.h)

include_directories ("${PROJECT_SOURCE_DIR}/Tool02")
add_subdirectory (Tool02)

add_executable(TestCpp ${SOURCE_FILES})

target_link_libraries(TestCpp Tool02)
