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
CMAKE_SOURCE_DIR = /opt/wupei/source/projectSellTicket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/wupei/source/projectSellTicket/build

# Include any dependencies generated for this target.
include CMakeFiles/sellticket.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sellticket.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sellticket.dir/flags.make

CMakeFiles/sellticket.dir/src/main.cpp.o: CMakeFiles/sellticket.dir/flags.make
CMakeFiles/sellticket.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/wupei/source/projectSellTicket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sellticket.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sellticket.dir/src/main.cpp.o -c /opt/wupei/source/projectSellTicket/src/main.cpp

CMakeFiles/sellticket.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sellticket.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/wupei/source/projectSellTicket/src/main.cpp > CMakeFiles/sellticket.dir/src/main.cpp.i

CMakeFiles/sellticket.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sellticket.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/wupei/source/projectSellTicket/src/main.cpp -o CMakeFiles/sellticket.dir/src/main.cpp.s

CMakeFiles/sellticket.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/sellticket.dir/src/main.cpp.o.requires

CMakeFiles/sellticket.dir/src/main.cpp.o.provides: CMakeFiles/sellticket.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sellticket.dir/build.make CMakeFiles/sellticket.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/sellticket.dir/src/main.cpp.o.provides

CMakeFiles/sellticket.dir/src/main.cpp.o.provides.build: CMakeFiles/sellticket.dir/src/main.cpp.o


# Object files for target sellticket
sellticket_OBJECTS = \
"CMakeFiles/sellticket.dir/src/main.cpp.o"

# External object files for target sellticket
sellticket_EXTERNAL_OBJECTS =

sellticket: CMakeFiles/sellticket.dir/src/main.cpp.o
sellticket: CMakeFiles/sellticket.dir/build.make
sellticket: CMakeFiles/sellticket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/wupei/source/projectSellTicket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sellticket"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sellticket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sellticket.dir/build: sellticket

.PHONY : CMakeFiles/sellticket.dir/build

CMakeFiles/sellticket.dir/requires: CMakeFiles/sellticket.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/sellticket.dir/requires

CMakeFiles/sellticket.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sellticket.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sellticket.dir/clean

CMakeFiles/sellticket.dir/depend:
	cd /opt/wupei/source/projectSellTicket/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/wupei/source/projectSellTicket /opt/wupei/source/projectSellTicket /opt/wupei/source/projectSellTicket/build /opt/wupei/source/projectSellTicket/build /opt/wupei/source/projectSellTicket/build/CMakeFiles/sellticket.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sellticket.dir/depend

