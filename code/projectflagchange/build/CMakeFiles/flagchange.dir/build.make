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
CMAKE_SOURCE_DIR = /opt/wupei/git/code/projectflagchange

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/wupei/git/code/projectflagchange/build

# Include any dependencies generated for this target.
include CMakeFiles/flagchange.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/flagchange.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/flagchange.dir/flags.make

CMakeFiles/flagchange.dir/src/main.cpp.o: CMakeFiles/flagchange.dir/flags.make
CMakeFiles/flagchange.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/wupei/git/code/projectflagchange/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/flagchange.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flagchange.dir/src/main.cpp.o -c /opt/wupei/git/code/projectflagchange/src/main.cpp

CMakeFiles/flagchange.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flagchange.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/wupei/git/code/projectflagchange/src/main.cpp > CMakeFiles/flagchange.dir/src/main.cpp.i

CMakeFiles/flagchange.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flagchange.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/wupei/git/code/projectflagchange/src/main.cpp -o CMakeFiles/flagchange.dir/src/main.cpp.s

CMakeFiles/flagchange.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/flagchange.dir/src/main.cpp.o.requires

CMakeFiles/flagchange.dir/src/main.cpp.o.provides: CMakeFiles/flagchange.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/flagchange.dir/build.make CMakeFiles/flagchange.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/flagchange.dir/src/main.cpp.o.provides

CMakeFiles/flagchange.dir/src/main.cpp.o.provides.build: CMakeFiles/flagchange.dir/src/main.cpp.o


# Object files for target flagchange
flagchange_OBJECTS = \
"CMakeFiles/flagchange.dir/src/main.cpp.o"

# External object files for target flagchange
flagchange_EXTERNAL_OBJECTS =

flagchange: CMakeFiles/flagchange.dir/src/main.cpp.o
flagchange: CMakeFiles/flagchange.dir/build.make
flagchange: CMakeFiles/flagchange.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/wupei/git/code/projectflagchange/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable flagchange"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flagchange.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/flagchange.dir/build: flagchange

.PHONY : CMakeFiles/flagchange.dir/build

CMakeFiles/flagchange.dir/requires: CMakeFiles/flagchange.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/flagchange.dir/requires

CMakeFiles/flagchange.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flagchange.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flagchange.dir/clean

CMakeFiles/flagchange.dir/depend:
	cd /opt/wupei/git/code/projectflagchange/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/wupei/git/code/projectflagchange /opt/wupei/git/code/projectflagchange /opt/wupei/git/code/projectflagchange/build /opt/wupei/git/code/projectflagchange/build /opt/wupei/git/code/projectflagchange/build/CMakeFiles/flagchange.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flagchange.dir/depend

