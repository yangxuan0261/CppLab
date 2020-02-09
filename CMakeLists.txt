# 加入 第三方库

cmake_minimum_required(VERSION 3.15)
project(TestCpp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp test.cpp test.h)

set(INC_DIR ${PROJECT_SOURCE_DIR}/Tool01)
set(LINK_DIR ${PROJECT_SOURCE_DIR}/Tool01/cmake-build-debug)


# 拷贝文件
configure_file(
        "${LINK_DIR}/libTool01.dll"
        "${PROJECT_BINARY_DIR}/libTool01.dll"
        COPYONLY
)

include_directories(${INC_DIR}) # 相当于gcc/clang 中的-I(i的大写字母)参数, 引入 头文件 目录
link_directories(${LINK_DIR}) # 相当于gcc 中的-L参数, 引入 库文件 目录

add_executable(TestCpp ${SOURCE_FILES})

target_link_libraries(TestCpp Tool01) # 相当于gcc中的-l(小写的l)参数, 链接 库文件

# 添加 预编译宏
add_definitions(
        -D USE_LOG=3 # 定义值
        -D USE_FILTER
)