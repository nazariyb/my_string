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
CMAKE_SOURCE_DIR = /home/nazariy/Documents/poc/labs/lab2/my_string/prog2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nazariy/Documents/poc/labs/lab2/my_string/prog2/build

# Include any dependencies generated for this target.
include CMakeFiles/prog2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prog2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prog2.dir/flags.make

CMakeFiles/prog2.dir/prog2.c.o: CMakeFiles/prog2.dir/flags.make
CMakeFiles/prog2.dir/prog2.c.o: ../prog2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nazariy/Documents/poc/labs/lab2/my_string/prog2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/prog2.dir/prog2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/prog2.dir/prog2.c.o   -c /home/nazariy/Documents/poc/labs/lab2/my_string/prog2/prog2.c

CMakeFiles/prog2.dir/prog2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/prog2.dir/prog2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nazariy/Documents/poc/labs/lab2/my_string/prog2/prog2.c > CMakeFiles/prog2.dir/prog2.c.i

CMakeFiles/prog2.dir/prog2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/prog2.dir/prog2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nazariy/Documents/poc/labs/lab2/my_string/prog2/prog2.c -o CMakeFiles/prog2.dir/prog2.c.s

CMakeFiles/prog2.dir/prog2.c.o.requires:

.PHONY : CMakeFiles/prog2.dir/prog2.c.o.requires

CMakeFiles/prog2.dir/prog2.c.o.provides: CMakeFiles/prog2.dir/prog2.c.o.requires
	$(MAKE) -f CMakeFiles/prog2.dir/build.make CMakeFiles/prog2.dir/prog2.c.o.provides.build
.PHONY : CMakeFiles/prog2.dir/prog2.c.o.provides

CMakeFiles/prog2.dir/prog2.c.o.provides.build: CMakeFiles/prog2.dir/prog2.c.o


# Object files for target prog2
prog2_OBJECTS = \
"CMakeFiles/prog2.dir/prog2.c.o"

# External object files for target prog2
prog2_EXTERNAL_OBJECTS =

prog2: CMakeFiles/prog2.dir/prog2.c.o
prog2: CMakeFiles/prog2.dir/build.make
prog2: CMakeFiles/prog2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nazariy/Documents/poc/labs/lab2/my_string/prog2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable prog2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prog2.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E copy prog2 ../bin/

# Rule to build all files generated by this target.
CMakeFiles/prog2.dir/build: prog2

.PHONY : CMakeFiles/prog2.dir/build

CMakeFiles/prog2.dir/requires: CMakeFiles/prog2.dir/prog2.c.o.requires

.PHONY : CMakeFiles/prog2.dir/requires

CMakeFiles/prog2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prog2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prog2.dir/clean

CMakeFiles/prog2.dir/depend:
	cd /home/nazariy/Documents/poc/labs/lab2/my_string/prog2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nazariy/Documents/poc/labs/lab2/my_string/prog2 /home/nazariy/Documents/poc/labs/lab2/my_string/prog2 /home/nazariy/Documents/poc/labs/lab2/my_string/prog2/build /home/nazariy/Documents/poc/labs/lab2/my_string/prog2/build /home/nazariy/Documents/poc/labs/lab2/my_string/prog2/build/CMakeFiles/prog2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prog2.dir/depend
