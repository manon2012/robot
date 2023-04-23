#1. Specify the minimum version of cmake
cmake_minimum_required(VERSION 2.4)
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

#2. Specify the project name
PROJECT(RemoteApiExample)

#3. Containing agile cmake configuration
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}"
    "$ENV{GENERIC_DEVELOPMENT_ENVIRONMENT_ROOT}"
)
include(Generic)

#4. Specify the head file directories
include_directories(
    ${GENERIC_INCLUDE_DIRECTORIES}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
#    "/home/developer/02-pass-through/RemoteApi/include"
    "/home/wupei/Sdk-x86_64-x64-linux/Sdk/Development_Env/include/BasicSdk"
    "/home/wupei/Desktop/03-freedriving/RemoteApi/include"
    "/home/wupei/Sdk-x86_64-x64-linux/Sdk/Development_Env/include/BasicSdk/OS/"

)

#5. Specify the library directories
link_directories(
    ${GENERIC_LIB_DIRECTORIES}
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
#    "/home/developer/02-pass-through/RemoteApi/lib"
)

#6. Specify the library will be linked
link_libraries(${GENERIC_LINK_LIBRARIES} BasicSdk)
link_libraries(${GENERIC_LINK_LIBRARIES} DianaApi)
link_libraries(${GENERIC_LINK_LIBRARIES} GenericAlgorithm)


#7. Specify the source file
set(BASE_DEMO_SRC
    base_demo.cpp
)

#9. ouput executable
add_executable(base_demo ${BASE_DEMO_SRC})
set_target_properties(base_demo PROPERTIES DEBUG_POSTFIX d)
set_target_properties(base_demo PROPERTIES RELWITHDEBINFO_POSTFIX rd)
set_target_properties(base_demo PROPERTIES MINSIZEREL_POSTFIX s)

#10. install executable
install(TARGETS base_demo DESTINATION ${PROJECT_SOURCE_DIR}/bin/${GENERIC_PROCESSOR_ARCHITECTURE}/${GENERIC_TARGET_PLATFORM})
