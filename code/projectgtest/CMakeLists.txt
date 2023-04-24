cmake_minimum_required(VERSION 3.9) #最低版本

project(projectGOOGLETEST VERSION 1.0) #项目名称及自定义版本号
#add_executable(gtestdiana src/main.cpp   src/init.cpp src/test_base.cpp src/move3plus3.cpp src/fixturetest.cpp src/onlytest.cpp  src/SRZX/srzx7.cpp  src/SRZX/srzx6.cpp) #添加生成可执行文件

set(SOURCE
        src/main.cpp
        src/init.cpp
        src/test_base.cpp
        src/move3plus3.cpp
        src/fixturetest.cpp
        src/onlytest.cpp
        src/SRZX/srzx7.cpp
        src/SRZX/srzx6.cpp    
)

file(GLOB SOURCES "src/*.cpp"
                  "src/SRZX/*.cpp"
)
#add_executable(${PROJECT_NAME} ${SOURCE})   notwork
#add_executable(gtestdiana ${SOURCE})
add_executable(gtestdiana ${SOURCES})


set(CMAKE_BUILD_TYPE "Debug")




include_directories(${workspaceFolder}/include)
include_directories(/home/wupei/gtest/googletest/include)

include_directories(/home/wupei/Desktop/CASE_REPO/repository/test-general/Environment/include)

#not use original test_base.h
#include_directories(/home/wupei/Desktop/CASE_REPO/repository/test-general/Environment/base)

target_link_libraries(gtestdiana  gtest DianaApi -pthread)   

