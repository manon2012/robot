cmake_minimum_required(VERSION 3.9) #最低版本

project(projecttemplate VERSION 1.0) #项目名称及自定义版本号
add_executable(robotinit src/main.cpp) #添加生成可执行文件

set(CMAKE_BUILD_TYPE "Debug")



target_link_libraries(robotinit pthread DianaApi)    #make ok
#target_link_libraries( ${CMAKE_PROJECT_NAME}  Threads::Threads) 
#target_link_libraries( hello_cmake  Threads::Threads) 


include_directories(/home/wupei/Desktop/CASE_REPO/repository/test-general/Environment/2.14/include)
include_directories(/home/wupei/Desktop/CASE_REPO/repository/test-general/Environment/2.14/base)

#message(${workspaceFolder})
# include_directories(
#     "/opt/wupei/git/code/projectRobot/include"
# )


# link_directories(
# "/opt/wupei/git/code/projectRobot/lib"
# )


# link_libraries(
#     "/opt/wupei/git/code/projectRobot/lib/libDianaApi"
    
#     )

##find_package(Threads)
##target_link_libraries(hello_cmake ${CMAKE_THREAD_LIBS_INIT})




#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")   #make ok
