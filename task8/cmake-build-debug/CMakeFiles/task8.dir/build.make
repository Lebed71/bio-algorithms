# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/lebed71/Downloads/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/lebed71/Downloads/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lebed71/CLionProjects/task8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lebed71/CLionProjects/task8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task8.dir/flags.make

CMakeFiles/task8.dir/main.cpp.o: CMakeFiles/task8.dir/flags.make
CMakeFiles/task8.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lebed71/CLionProjects/task8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task8.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task8.dir/main.cpp.o -c /home/lebed71/CLionProjects/task8/main.cpp

CMakeFiles/task8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task8.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lebed71/CLionProjects/task8/main.cpp > CMakeFiles/task8.dir/main.cpp.i

CMakeFiles/task8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task8.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lebed71/CLionProjects/task8/main.cpp -o CMakeFiles/task8.dir/main.cpp.s

CMakeFiles/task8.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/task8.dir/main.cpp.o.requires

CMakeFiles/task8.dir/main.cpp.o.provides: CMakeFiles/task8.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/task8.dir/build.make CMakeFiles/task8.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/task8.dir/main.cpp.o.provides

CMakeFiles/task8.dir/main.cpp.o.provides.build: CMakeFiles/task8.dir/main.cpp.o


# Object files for target task8
task8_OBJECTS = \
"CMakeFiles/task8.dir/main.cpp.o"

# External object files for target task8
task8_EXTERNAL_OBJECTS =

task8: CMakeFiles/task8.dir/main.cpp.o
task8: CMakeFiles/task8.dir/build.make
task8: CMakeFiles/task8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lebed71/CLionProjects/task8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task8.dir/build: task8

.PHONY : CMakeFiles/task8.dir/build

CMakeFiles/task8.dir/requires: CMakeFiles/task8.dir/main.cpp.o.requires

.PHONY : CMakeFiles/task8.dir/requires

CMakeFiles/task8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task8.dir/clean

CMakeFiles/task8.dir/depend:
	cd /home/lebed71/CLionProjects/task8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lebed71/CLionProjects/task8 /home/lebed71/CLionProjects/task8 /home/lebed71/CLionProjects/task8/cmake-build-debug /home/lebed71/CLionProjects/task8/cmake-build-debug /home/lebed71/CLionProjects/task8/cmake-build-debug/CMakeFiles/task8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task8.dir/depend
