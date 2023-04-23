cmake_minimum_required(VERSION 3.5)

project(TestThreadCmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_BUILD_TYPE=Debug)

add_executable(TestThreadCmake main.cpp)
