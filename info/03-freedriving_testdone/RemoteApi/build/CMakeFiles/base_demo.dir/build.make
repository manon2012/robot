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
CMAKE_SOURCE_DIR = /home/wupei/Desktop/03-freedriving/RemoteApi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wupei/Desktop/03-freedriving/RemoteApi/build

# Include any dependencies generated for this target.
include CMakeFiles/base_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/base_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/base_demo.dir/flags.make

CMakeFiles/base_demo.dir/base_demo.o: CMakeFiles/base_demo.dir/flags.make
CMakeFiles/base_demo.dir/base_demo.o: ../base_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wupei/Desktop/03-freedriving/RemoteApi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/base_demo.dir/base_demo.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base_demo.dir/base_demo.o -c /home/wupei/Desktop/03-freedriving/RemoteApi/base_demo.cpp

CMakeFiles/base_demo.dir/base_demo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base_demo.dir/base_demo.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wupei/Desktop/03-freedriving/RemoteApi/base_demo.cpp > CMakeFiles/base_demo.dir/base_demo.i

CMakeFiles/base_demo.dir/base_demo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base_demo.dir/base_demo.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wupei/Desktop/03-freedriving/RemoteApi/base_demo.cpp -o CMakeFiles/base_demo.dir/base_demo.s

CMakeFiles/base_demo.dir/base_demo.o.requires:

.PHONY : CMakeFiles/base_demo.dir/base_demo.o.requires

CMakeFiles/base_demo.dir/base_demo.o.provides: CMakeFiles/base_demo.dir/base_demo.o.requires
	$(MAKE) -f CMakeFiles/base_demo.dir/build.make CMakeFiles/base_demo.dir/base_demo.o.provides.build
.PHONY : CMakeFiles/base_demo.dir/base_demo.o.provides

CMakeFiles/base_demo.dir/base_demo.o.provides.build: CMakeFiles/base_demo.dir/base_demo.o


# Object files for target base_demo
base_demo_OBJECTS = \
"CMakeFiles/base_demo.dir/base_demo.o"

# External object files for target base_demo
base_demo_EXTERNAL_OBJECTS =

base_demo: CMakeFiles/base_demo.dir/base_demo.o
base_demo: CMakeFiles/base_demo.dir/build.make
base_demo: CMakeFiles/base_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wupei/Desktop/03-freedriving/RemoteApi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable base_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/base_demo.dir/build: base_demo

.PHONY : CMakeFiles/base_demo.dir/build

CMakeFiles/base_demo.dir/requires: CMakeFiles/base_demo.dir/base_demo.o.requires

.PHONY : CMakeFiles/base_demo.dir/requires

CMakeFiles/base_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/base_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/base_demo.dir/clean

CMakeFiles/base_demo.dir/depend:
	cd /home/wupei/Desktop/03-freedriving/RemoteApi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wupei/Desktop/03-freedriving/RemoteApi /home/wupei/Desktop/03-freedriving/RemoteApi /home/wupei/Desktop/03-freedriving/RemoteApi/build /home/wupei/Desktop/03-freedriving/RemoteApi/build /home/wupei/Desktop/03-freedriving/RemoteApi/build/CMakeFiles/base_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/base_demo.dir/depend
