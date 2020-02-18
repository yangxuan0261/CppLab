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

# 测试 gtest 的代码
file(GLOB_RECURSE SRC_GTest
        GTest/add/*.h
        GTest/add/*.cpp
        )

set(mainCpp GTest/main.cpp) # gtest 入口文件
set(SOURCE_FILES ${mainCpp} ${SRC_OtherTest} ${SRC_ExternTest} ${AlgorithmTest} ${SRC_GTest})

############# googletest module begin #############
set(gtName gtest) # gtest 库名
add_subdirectory(googletest) # gtest 目录
include_directories(googletest/googletest/include)
link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest # gtest 头文件目录
)
############# googletest module end #############

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${gtName}) # 链接 gtest

message(STATUS "--- Done!")

