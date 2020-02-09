cmake_minimum_required(VERSION 3.15)
project(TestCpp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp test.cpp test.h)

set(INC_DIR E:/ws_cpp/Tool)
set(LINK_DIR E:/ws_cpp/TestCpp/cmake-build-debug)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})

add_executable(TestCpp ${SOURCE_FILES})

target_link_libraries(TestCpp Tool)
