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
CMAKE_SOURCE_DIR = /opt/wupei/git/code/project0612

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/wupei/git/code/project0612/build

# Include any dependencies generated for this target.
include CMakeFiles/p0612.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p0612.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p0612.dir/flags.make

CMakeFiles/p0612.dir/src/main.cpp.o: CMakeFiles/p0612.dir/flags.make
CMakeFiles/p0612.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/wupei/git/code/project0612/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p0612.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p0612.dir/src/main.cpp.o -c /opt/wupei/git/code/project0612/src/main.cpp

CMakeFiles/p0612.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p0612.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/wupei/git/code/project0612/src/main.cpp > CMakeFiles/p0612.dir/src/main.cpp.i

CMakeFiles/p0612.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p0612.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/wupei/git/code/project0612/src/main.cpp -o CMakeFiles/p0612.dir/src/main.cpp.s

CMakeFiles/p0612.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/p0612.dir/src/main.cpp.o.requires

CMakeFiles/p0612.dir/src/main.cpp.o.provides: CMakeFiles/p0612.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/p0612.dir/build.make CMakeFiles/p0612.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/p0612.dir/src/main.cpp.o.provides

CMakeFiles/p0612.dir/src/main.cpp.o.provides.build: CMakeFiles/p0612.dir/src/main.cpp.o


# Object files for target p0612
p0612_OBJECTS = \
"CMakeFiles/p0612.dir/src/main.cpp.o"

# External object files for target p0612
p0612_EXTERNAL_OBJECTS =

p0612: CMakeFiles/p0612.dir/src/main.cpp.o
p0612: CMakeFiles/p0612.dir/build.make
p0612: CMakeFiles/p0612.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/wupei/git/code/project0612/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable p0612"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p0612.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p0612.dir/build: p0612

.PHONY : CMakeFiles/p0612.dir/build

CMakeFiles/p0612.dir/requires: CMakeFiles/p0612.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/p0612.dir/requires

CMakeFiles/p0612.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p0612.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p0612.dir/clean

CMakeFiles/p0612.dir/depend:
	cd /opt/wupei/git/code/project0612/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/wupei/git/code/project0612 /opt/wupei/git/code/project0612 /opt/wupei/git/code/project0612/build /opt/wupei/git/code/project0612/build /opt/wupei/git/code/project0612/build/CMakeFiles/p0612.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p0612.dir/depend

