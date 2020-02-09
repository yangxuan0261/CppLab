cmake_minimum_required(VERSION 3.15)
project(Tool01)

set(CMAKE_CXX_STANDARD 14)

add_library(Tool01 SHARED library.cpp library.h)