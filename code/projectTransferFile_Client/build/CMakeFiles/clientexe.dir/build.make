# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/wupei/source/projectTransferFile_Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/wupei/source/projectTransferFile_Client/build

# Include any dependencies generated for this target.
include CMakeFiles/clientexe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/clientexe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clientexe.dir/flags.make

CMakeFiles/clientexe.dir/src/client.cpp.o: CMakeFiles/clientexe.dir/flags.make
CMakeFiles/clientexe.dir/src/client.cpp.o: ../src/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/wupei/source/projectTransferFile_Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clientexe.dir/src/client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clientexe.dir/src/client.cpp.o -c /opt/wupei/source/projectTransferFile_Client/src/client.cpp

CMakeFiles/clientexe.dir/src/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clientexe.dir/src/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/wupei/source/projectTransferFile_Client/src/client.cpp > CMakeFiles/clientexe.dir/src/client.cpp.i

CMakeFiles/clientexe.dir/src/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clientexe.dir/src/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/wupei/source/projectTransferFile_Client/src/client.cpp -o CMakeFiles/clientexe.dir/src/client.cpp.s

CMakeFiles/clientexe.dir/src/client.cpp.o.requires:

.PHONY : CMakeFiles/clientexe.dir/src/client.cpp.o.requires

CMakeFiles/clientexe.dir/src/client.cpp.o.provides: CMakeFiles/clientexe.dir/src/client.cpp.o.requires
	$(MAKE) -f CMakeFiles/clientexe.dir/build.make CMakeFiles/clientexe.dir/src/client.cpp.o.provides.build
.PHONY : CMakeFiles/clientexe.dir/src/client.cpp.o.provides

CMakeFiles/clientexe.dir/src/client.cpp.o.provides.build: CMakeFiles/clientexe.dir/src/client.cpp.o


# Object files for target clientexe
clientexe_OBJECTS = \
"CMakeFiles/clientexe.dir/src/client.cpp.o"

# External object files for target clientexe
clientexe_EXTERNAL_OBJECTS =

clientexe: CMakeFiles/clientexe.dir/src/client.cpp.o
clientexe: CMakeFiles/clientexe.dir/build.make
clientexe: CMakeFiles/clientexe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/wupei/source/projectTransferFile_Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable clientexe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clientexe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clientexe.dir/build: clientexe

.PHONY : CMakeFiles/clientexe.dir/build

CMakeFiles/clientexe.dir/requires: CMakeFiles/clientexe.dir/src/client.cpp.o.requires

.PHONY : CMakeFiles/clientexe.dir/requires

CMakeFiles/clientexe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clientexe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clientexe.dir/clean

CMakeFiles/clientexe.dir/depend:
	cd /opt/wupei/source/projectTransferFile_Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/wupei/source/projectTransferFile_Client /opt/wupei/source/projectTransferFile_Client /opt/wupei/source/projectTransferFile_Client/build /opt/wupei/source/projectTransferFile_Client/build /opt/wupei/source/projectTransferFile_Client/build/CMakeFiles/clientexe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clientexe.dir/depend

