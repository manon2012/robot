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
CMAKE_SOURCE_DIR = /opt/wupei/git/code/projectMulinstance

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/wupei/git/code/projectMulinstance/build

# Include any dependencies generated for this target.
include CMakeFiles/mulinstance.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mulinstance.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mulinstance.dir/flags.make

CMakeFiles/mulinstance.dir/src/main.cpp.o: CMakeFiles/mulinstance.dir/flags.make
CMakeFiles/mulinstance.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/wupei/git/code/projectMulinstance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mulinstance.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mulinstance.dir/src/main.cpp.o -c /opt/wupei/git/code/projectMulinstance/src/main.cpp

CMakeFiles/mulinstance.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mulinstance.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/wupei/git/code/projectMulinstance/src/main.cpp > CMakeFiles/mulinstance.dir/src/main.cpp.i

CMakeFiles/mulinstance.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mulinstance.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/wupei/git/code/projectMulinstance/src/main.cpp -o CMakeFiles/mulinstance.dir/src/main.cpp.s

CMakeFiles/mulinstance.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/mulinstance.dir/src/main.cpp.o.requires

CMakeFiles/mulinstance.dir/src/main.cpp.o.provides: CMakeFiles/mulinstance.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/mulinstance.dir/build.make CMakeFiles/mulinstance.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/mulinstance.dir/src/main.cpp.o.provides

CMakeFiles/mulinstance.dir/src/main.cpp.o.provides.build: CMakeFiles/mulinstance.dir/src/main.cpp.o


# Object files for target mulinstance
mulinstance_OBJECTS = \
"CMakeFiles/mulinstance.dir/src/main.cpp.o"

# External object files for target mulinstance
mulinstance_EXTERNAL_OBJECTS =

mulinstance: CMakeFiles/mulinstance.dir/src/main.cpp.o
mulinstance: CMakeFiles/mulinstance.dir/build.make
mulinstance: CMakeFiles/mulinstance.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/wupei/git/code/projectMulinstance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mulinstance"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mulinstance.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mulinstance.dir/build: mulinstance

.PHONY : CMakeFiles/mulinstance.dir/build

CMakeFiles/mulinstance.dir/requires: CMakeFiles/mulinstance.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/mulinstance.dir/requires

CMakeFiles/mulinstance.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mulinstance.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mulinstance.dir/clean

CMakeFiles/mulinstance.dir/depend:
	cd /opt/wupei/git/code/projectMulinstance/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/wupei/git/code/projectMulinstance /opt/wupei/git/code/projectMulinstance /opt/wupei/git/code/projectMulinstance/build /opt/wupei/git/code/projectMulinstance/build /opt/wupei/git/code/projectMulinstance/build/CMakeFiles/mulinstance.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mulinstance.dir/depend

