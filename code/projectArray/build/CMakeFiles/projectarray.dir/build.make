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
CMAKE_SOURCE_DIR = /opt/wupei/git/code/projectArray

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/wupei/git/code/projectArray/build

# Include any dependencies generated for this target.
include CMakeFiles/projectarray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projectarray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projectarray.dir/flags.make

CMakeFiles/projectarray.dir/src/main.cpp.o: CMakeFiles/projectarray.dir/flags.make
CMakeFiles/projectarray.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/wupei/git/code/projectArray/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projectarray.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projectarray.dir/src/main.cpp.o -c /opt/wupei/git/code/projectArray/src/main.cpp

CMakeFiles/projectarray.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projectarray.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/wupei/git/code/projectArray/src/main.cpp > CMakeFiles/projectarray.dir/src/main.cpp.i

CMakeFiles/projectarray.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projectarray.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/wupei/git/code/projectArray/src/main.cpp -o CMakeFiles/projectarray.dir/src/main.cpp.s

CMakeFiles/projectarray.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/projectarray.dir/src/main.cpp.o.requires

CMakeFiles/projectarray.dir/src/main.cpp.o.provides: CMakeFiles/projectarray.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/projectarray.dir/build.make CMakeFiles/projectarray.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/projectarray.dir/src/main.cpp.o.provides

CMakeFiles/projectarray.dir/src/main.cpp.o.provides.build: CMakeFiles/projectarray.dir/src/main.cpp.o


# Object files for target projectarray
projectarray_OBJECTS = \
"CMakeFiles/projectarray.dir/src/main.cpp.o"

# External object files for target projectarray
projectarray_EXTERNAL_OBJECTS =

projectarray: CMakeFiles/projectarray.dir/src/main.cpp.o
projectarray: CMakeFiles/projectarray.dir/build.make
projectarray: CMakeFiles/projectarray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/wupei/git/code/projectArray/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable projectarray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projectarray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projectarray.dir/build: projectarray

.PHONY : CMakeFiles/projectarray.dir/build

CMakeFiles/projectarray.dir/requires: CMakeFiles/projectarray.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/projectarray.dir/requires

CMakeFiles/projectarray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projectarray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projectarray.dir/clean

CMakeFiles/projectarray.dir/depend:
	cd /opt/wupei/git/code/projectArray/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/wupei/git/code/projectArray /opt/wupei/git/code/projectArray /opt/wupei/git/code/projectArray/build /opt/wupei/git/code/projectArray/build /opt/wupei/git/code/projectArray/build/CMakeFiles/projectarray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projectarray.dir/depend

