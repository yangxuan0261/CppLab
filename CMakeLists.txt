# 加入 其他模块

cmake_minimum_required(VERSION 3.15)
project(TestCpp)

file(GLOB SOURCES_H_CPP # glob 匹配导入
        */*.h
         */*.cpp
        )
set(SOURCE_FILES ${SOURCES_H_CPP})


set(CMAKE_CXX_STANDARD 14)

#set(SOURCE_FILES main.cpp test.cpp test.h) # 指定文件


include_directories("${PROJECT_SOURCE_DIR}/Tool02" "${PROJECT_SOURCE_DIR}")
add_subdirectory(Tool02)

add_executable(TestCpp ${SOURCE_FILES})

target_link_libraries(TestCpp Tool02)
