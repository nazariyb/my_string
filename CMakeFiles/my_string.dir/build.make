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
CMAKE_SOURCE_DIR = /home/arattel/CLionProjects/my_string

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arattel/CLionProjects/my_string

# Include any dependencies generated for this target.
include CMakeFiles/my_string.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_string.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_string.dir/flags.make

CMakeFiles/my_string.dir/my_string.c.o: CMakeFiles/my_string.dir/flags.make
CMakeFiles/my_string.dir/my_string.c.o: my_string.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arattel/CLionProjects/my_string/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_string.dir/my_string.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_string.dir/my_string.c.o   -c /home/arattel/CLionProjects/my_string/my_string.c

CMakeFiles/my_string.dir/my_string.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_string.dir/my_string.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arattel/CLionProjects/my_string/my_string.c > CMakeFiles/my_string.dir/my_string.c.i

CMakeFiles/my_string.dir/my_string.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_string.dir/my_string.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arattel/CLionProjects/my_string/my_string.c -o CMakeFiles/my_string.dir/my_string.c.s

CMakeFiles/my_string.dir/my_string.c.o.requires:

.PHONY : CMakeFiles/my_string.dir/my_string.c.o.requires

CMakeFiles/my_string.dir/my_string.c.o.provides: CMakeFiles/my_string.dir/my_string.c.o.requires
	$(MAKE) -f CMakeFiles/my_string.dir/build.make CMakeFiles/my_string.dir/my_string.c.o.provides.build
.PHONY : CMakeFiles/my_string.dir/my_string.c.o.provides

CMakeFiles/my_string.dir/my_string.c.o.provides.build: CMakeFiles/my_string.dir/my_string.c.o


# Object files for target my_string
my_string_OBJECTS = \
"CMakeFiles/my_string.dir/my_string.c.o"

# External object files for target my_string
my_string_EXTERNAL_OBJECTS =

my_string: CMakeFiles/my_string.dir/my_string.c.o
my_string: CMakeFiles/my_string.dir/build.make
my_string: CMakeFiles/my_string.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arattel/CLionProjects/my_string/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable my_string"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_string.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_string.dir/build: my_string

.PHONY : CMakeFiles/my_string.dir/build

CMakeFiles/my_string.dir/requires: CMakeFiles/my_string.dir/my_string.c.o.requires

.PHONY : CMakeFiles/my_string.dir/requires

CMakeFiles/my_string.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_string.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_string.dir/clean

CMakeFiles/my_string.dir/depend:
	cd /home/arattel/CLionProjects/my_string && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arattel/CLionProjects/my_string /home/arattel/CLionProjects/my_string /home/arattel/CLionProjects/my_string /home/arattel/CLionProjects/my_string /home/arattel/CLionProjects/my_string/CMakeFiles/my_string.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_string.dir/depend

