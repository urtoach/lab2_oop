# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /nix/store/rxb9zl1mdx9f2n3z0nyv9zhngj3f2pw0-cmake-3.24.3/bin/cmake

# The command to remove a file.
RM = /nix/store/rxb9zl1mdx9f2n3z0nyv9zhngj3f2pw0-cmake-3.24.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/runner/lab2oop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/runner/lab2oop/build

# Include any dependencies generated for this target.
include CMakeFiles/BinarySignal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BinarySignal.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BinarySignal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BinarySignal.dir/flags.make

CMakeFiles/BinarySignal.dir/BinarySignal.cpp.o: CMakeFiles/BinarySignal.dir/flags.make
CMakeFiles/BinarySignal.dir/BinarySignal.cpp.o: /home/runner/lab2oop/BinarySignal.cpp
CMakeFiles/BinarySignal.dir/BinarySignal.cpp.o: CMakeFiles/BinarySignal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/lab2oop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BinarySignal.dir/BinarySignal.cpp.o"
	/nix/store/dq0xwmsk1g0i2ayg6pb7y87na2knzylh-gcc-wrapper-11.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BinarySignal.dir/BinarySignal.cpp.o -MF CMakeFiles/BinarySignal.dir/BinarySignal.cpp.o.d -o CMakeFiles/BinarySignal.dir/BinarySignal.cpp.o -c /home/runner/lab2oop/BinarySignal.cpp

CMakeFiles/BinarySignal.dir/BinarySignal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BinarySignal.dir/BinarySignal.cpp.i"
	/nix/store/dq0xwmsk1g0i2ayg6pb7y87na2knzylh-gcc-wrapper-11.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/lab2oop/BinarySignal.cpp > CMakeFiles/BinarySignal.dir/BinarySignal.cpp.i

CMakeFiles/BinarySignal.dir/BinarySignal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BinarySignal.dir/BinarySignal.cpp.s"
	/nix/store/dq0xwmsk1g0i2ayg6pb7y87na2knzylh-gcc-wrapper-11.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/lab2oop/BinarySignal.cpp -o CMakeFiles/BinarySignal.dir/BinarySignal.cpp.s

# Object files for target BinarySignal
BinarySignal_OBJECTS = \
"CMakeFiles/BinarySignal.dir/BinarySignal.cpp.o"

# External object files for target BinarySignal
BinarySignal_EXTERNAL_OBJECTS =

libBinarySignal.a: CMakeFiles/BinarySignal.dir/BinarySignal.cpp.o
libBinarySignal.a: CMakeFiles/BinarySignal.dir/build.make
libBinarySignal.a: CMakeFiles/BinarySignal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/lab2oop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libBinarySignal.a"
	$(CMAKE_COMMAND) -P CMakeFiles/BinarySignal.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BinarySignal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BinarySignal.dir/build: libBinarySignal.a
.PHONY : CMakeFiles/BinarySignal.dir/build

CMakeFiles/BinarySignal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BinarySignal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BinarySignal.dir/clean

CMakeFiles/BinarySignal.dir/depend:
	cd /home/runner/lab2oop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/lab2oop /home/runner/lab2oop /home/runner/lab2oop/build /home/runner/lab2oop/build /home/runner/lab2oop/build/CMakeFiles/BinarySignal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BinarySignal.dir/depend

