cmake_minimum_required(VERSION 3.0.0)
project(cpprobot)
set(CMAKE_CXX_STANDARD 11)



include_directories(
${PROJECT_SOURCE_DIR}/include 
)



link_directories(


)
FILE (GLOB ROBOT_LIBRARIES "${PROJECT_SOURCE_DIR}/lib/*.so*")
add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)
TARGET_LINK_LIBRARIES(main  ${ROBOT_LIBRARIES} pthread)

