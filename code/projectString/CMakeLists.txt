cmake_minimum_required(VERSION 3.9) #最低版本

project(projectString VERSION 1.0) #项目名称及自定义版本号
add_executable(NewString src/main.cpp  src/NewString.cpp) #添加生成可执行文件

set(CMAKE_BUILD_TYPE "Debug")

include_directories(${workspaceFolder}/include)

target_link_libraries(NewString pthread)   

