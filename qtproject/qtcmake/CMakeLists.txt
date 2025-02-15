cmake_minimum_required(VERSION 3.5)

project(qtcmake LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

include_directories(
    ${TEST_BASE_INCLUDE_DIRECTORIES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Environment/include
)

link_directories(
    ${TEST_BASE_LIB_DIRECTORIES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Environment/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/Environment/bin
)

link_libraries(${TEST_BASE_LIBRARIES} DianaApi ToolSdk BasicSdk)


add_executable(qtcmake main.cpp)
target_link_libraries(qtcmake Qt5::Core)

