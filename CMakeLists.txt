# 加入 其他模块

cmake_minimum_required(VERSION 3.15)
project(CppLab)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE AlgorithmTest
        AlgorithmTest/**.h
        AlgorithmTest/**.cpp
        )

file(GLOB_RECURSE SRC_ExternTest
        ExternTest/**.h
        ExternTest/**.cpp
        ExternTest/**.c
        )

file(GLOB_RECURSE SRC_OtherTest
        OtherTest/**.h
        OtherTest/**.cpp
        )

set(SOURCE_FILES main.cpp ${SRC_OtherTest} ${SRC_ExternTest} ${AlgorithmTest})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
