# Install script for directory: /home/wupei/Desktop/03-freedriving/RemoteApi

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/wupei/Desktop/03-freedriving/RemoteApi/bin/x86_64/x64/base_demo" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/wupei/Desktop/03-freedriving/RemoteApi/bin/x86_64/x64/base_demo")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/wupei/Desktop/03-freedriving/RemoteApi/bin/x86_64/x64/base_demo"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/wupei/Desktop/03-freedriving/RemoteApi/bin/x86_64/x64/base_demo")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/wupei/Desktop/03-freedriving/RemoteApi/bin/x86_64/x64" TYPE EXECUTABLE FILES "/home/wupei/Desktop/03-freedriving/RemoteApi/build/base_demo")
  if(EXISTS "$ENV{DESTDIR}/home/wupei/Desktop/03-freedriving/RemoteApi/bin/x86_64/x64/base_demo" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/wupei/Desktop/03-freedriving/RemoteApi/bin/x86_64/x64/base_demo")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/wupei/Desktop/03-freedriving/RemoteApi/bin/x86_64/x64/base_demo"
         OLD_RPATH "/home/wupei/Desktop/03-freedriving/RemoteApi:/home/wupei/Sdk-x86_64-x64-linux/Sdk/Development_Env/lib/3dParty/linux/x86_64/x64:/home/wupei/Sdk-x86_64-x64-linux/Sdk/Development_Env/lib/BasicSdk/linux/x86_64/x64:/home/wupei/Sdk-x86_64-x64-linux/Sdk/Development_Env/lib/ToolSdk/linux/x86_64/x64:/home/wupei/Sdk-x86_64-x64-linux/Sdk/Development_Env/lib/Components/linux/x86_64/x64:/home/wupei/Sdk-x86_64-x64-linux/Sdk/Development_Env/lib/HAL/linux/x86_64/x64:/home/wupei/Sdk-x86_64-x64-linux/Sdk/Development_Env/lib/Plugins/linux/x86_64/x64:/home/wupei/Desktop/03-freedriving/RemoteApi/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/wupei/Desktop/03-freedriving/RemoteApi/bin/x86_64/x64/base_demo")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/wupei/Desktop/03-freedriving/RemoteApi/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
