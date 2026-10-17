cmake_minimum_required(VERSION 3.10)
project(trae_createdds VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# Find Fast DDS (fastrtps)
find_package(fastrtps REQUIRED)

# Generated type support files (from fastddsgen)
set(TYPE_SRCS
    HelloWorld.cxx
    HelloWorldPubSubTypes.cxx
)

# Publisher executable
add_executable(trae_publisher
    src/HelloWorldPublisher.cpp
    ${TYPE_SRCS}
)
target_include_directories(trae_publisher PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(trae_publisher fastrtps)

# Subscriber executable
add_executable(trae_subscriber
    src/HelloWorldSubscriber.cpp
    ${TYPE_SRCS}
)
target_include_directories(trae_subscriber PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(trae_subscriber fastrtps)
