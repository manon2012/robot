cmake_minimum_required(VERSION 3.9) #最低版本

project(helloworld VERSION 1.0) #项目名称及自定义版本号
add_executable(clientexe src/client.cpp) #添加生成可执行文件

set(CMAKE_BUILD_TYPE "Debug")
include_directories(/usr/include/python3.6m)  #srccode里颜色不提示  make时提示找不到Python.h
target_link_libraries(clientexe python3.6m pthread gtest)   #when link,undefined reference to `Py_Initialize'

#CXXFLAGS += -I/usr/include/python3.6

#LDLIBS += -lpython3.6m

target_link_libraries(clientexe pthread)    #make ok
#target_link_libraries( ${CMAKE_PROJECT_NAME}  Threads::Threads) 
#target_link_libraries( hello_cmake  Threads::Threads) 


##find_package(Threads)
##target_link_libraries(hello_cmake ${CMAKE_THREAD_LIBS_INIT})




#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")   #make ok