# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/dc/dev/NN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dc/dev/NN/build

# Include any dependencies generated for this target.
include CMakeFiles/NN.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NN.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NN.out.dir/flags.make

CMakeFiles/NN.out.dir/src/Main.cpp.o: CMakeFiles/NN.out.dir/flags.make
CMakeFiles/NN.out.dir/src/Main.cpp.o: ../src/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dc/dev/NN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NN.out.dir/src/Main.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NN.out.dir/src/Main.cpp.o -c /home/dc/dev/NN/src/Main.cpp

CMakeFiles/NN.out.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NN.out.dir/src/Main.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dc/dev/NN/src/Main.cpp > CMakeFiles/NN.out.dir/src/Main.cpp.i

CMakeFiles/NN.out.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NN.out.dir/src/Main.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dc/dev/NN/src/Main.cpp -o CMakeFiles/NN.out.dir/src/Main.cpp.s

CMakeFiles/NN.out.dir/src/Main.cpp.o.requires:

.PHONY : CMakeFiles/NN.out.dir/src/Main.cpp.o.requires

CMakeFiles/NN.out.dir/src/Main.cpp.o.provides: CMakeFiles/NN.out.dir/src/Main.cpp.o.requires
	$(MAKE) -f CMakeFiles/NN.out.dir/build.make CMakeFiles/NN.out.dir/src/Main.cpp.o.provides.build
.PHONY : CMakeFiles/NN.out.dir/src/Main.cpp.o.provides

CMakeFiles/NN.out.dir/src/Main.cpp.o.provides.build: CMakeFiles/NN.out.dir/src/Main.cpp.o


CMakeFiles/NN.out.dir/src/NN.cpp.o: CMakeFiles/NN.out.dir/flags.make
CMakeFiles/NN.out.dir/src/NN.cpp.o: ../src/NN.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dc/dev/NN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NN.out.dir/src/NN.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NN.out.dir/src/NN.cpp.o -c /home/dc/dev/NN/src/NN.cpp

CMakeFiles/NN.out.dir/src/NN.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NN.out.dir/src/NN.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dc/dev/NN/src/NN.cpp > CMakeFiles/NN.out.dir/src/NN.cpp.i

CMakeFiles/NN.out.dir/src/NN.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NN.out.dir/src/NN.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dc/dev/NN/src/NN.cpp -o CMakeFiles/NN.out.dir/src/NN.cpp.s

CMakeFiles/NN.out.dir/src/NN.cpp.o.requires:

.PHONY : CMakeFiles/NN.out.dir/src/NN.cpp.o.requires

CMakeFiles/NN.out.dir/src/NN.cpp.o.provides: CMakeFiles/NN.out.dir/src/NN.cpp.o.requires
	$(MAKE) -f CMakeFiles/NN.out.dir/build.make CMakeFiles/NN.out.dir/src/NN.cpp.o.provides.build
.PHONY : CMakeFiles/NN.out.dir/src/NN.cpp.o.provides

CMakeFiles/NN.out.dir/src/NN.cpp.o.provides.build: CMakeFiles/NN.out.dir/src/NN.cpp.o


CMakeFiles/NN.out.dir/src/Layer.cpp.o: CMakeFiles/NN.out.dir/flags.make
CMakeFiles/NN.out.dir/src/Layer.cpp.o: ../src/Layer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dc/dev/NN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/NN.out.dir/src/Layer.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NN.out.dir/src/Layer.cpp.o -c /home/dc/dev/NN/src/Layer.cpp

CMakeFiles/NN.out.dir/src/Layer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NN.out.dir/src/Layer.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dc/dev/NN/src/Layer.cpp > CMakeFiles/NN.out.dir/src/Layer.cpp.i

CMakeFiles/NN.out.dir/src/Layer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NN.out.dir/src/Layer.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dc/dev/NN/src/Layer.cpp -o CMakeFiles/NN.out.dir/src/Layer.cpp.s

CMakeFiles/NN.out.dir/src/Layer.cpp.o.requires:

.PHONY : CMakeFiles/NN.out.dir/src/Layer.cpp.o.requires

CMakeFiles/NN.out.dir/src/Layer.cpp.o.provides: CMakeFiles/NN.out.dir/src/Layer.cpp.o.requires
	$(MAKE) -f CMakeFiles/NN.out.dir/build.make CMakeFiles/NN.out.dir/src/Layer.cpp.o.provides.build
.PHONY : CMakeFiles/NN.out.dir/src/Layer.cpp.o.provides

CMakeFiles/NN.out.dir/src/Layer.cpp.o.provides.build: CMakeFiles/NN.out.dir/src/Layer.cpp.o


CMakeFiles/NN.out.dir/src/Node.cpp.o: CMakeFiles/NN.out.dir/flags.make
CMakeFiles/NN.out.dir/src/Node.cpp.o: ../src/Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dc/dev/NN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/NN.out.dir/src/Node.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NN.out.dir/src/Node.cpp.o -c /home/dc/dev/NN/src/Node.cpp

CMakeFiles/NN.out.dir/src/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NN.out.dir/src/Node.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dc/dev/NN/src/Node.cpp > CMakeFiles/NN.out.dir/src/Node.cpp.i

CMakeFiles/NN.out.dir/src/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NN.out.dir/src/Node.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dc/dev/NN/src/Node.cpp -o CMakeFiles/NN.out.dir/src/Node.cpp.s

CMakeFiles/NN.out.dir/src/Node.cpp.o.requires:

.PHONY : CMakeFiles/NN.out.dir/src/Node.cpp.o.requires

CMakeFiles/NN.out.dir/src/Node.cpp.o.provides: CMakeFiles/NN.out.dir/src/Node.cpp.o.requires
	$(MAKE) -f CMakeFiles/NN.out.dir/build.make CMakeFiles/NN.out.dir/src/Node.cpp.o.provides.build
.PHONY : CMakeFiles/NN.out.dir/src/Node.cpp.o.provides

CMakeFiles/NN.out.dir/src/Node.cpp.o.provides.build: CMakeFiles/NN.out.dir/src/Node.cpp.o


# Object files for target NN.out
NN_out_OBJECTS = \
"CMakeFiles/NN.out.dir/src/Main.cpp.o" \
"CMakeFiles/NN.out.dir/src/NN.cpp.o" \
"CMakeFiles/NN.out.dir/src/Layer.cpp.o" \
"CMakeFiles/NN.out.dir/src/Node.cpp.o"

# External object files for target NN.out
NN_out_EXTERNAL_OBJECTS =

NN.out: CMakeFiles/NN.out.dir/src/Main.cpp.o
NN.out: CMakeFiles/NN.out.dir/src/NN.cpp.o
NN.out: CMakeFiles/NN.out.dir/src/Layer.cpp.o
NN.out: CMakeFiles/NN.out.dir/src/Node.cpp.o
NN.out: CMakeFiles/NN.out.dir/build.make
NN.out: CMakeFiles/NN.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dc/dev/NN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable NN.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NN.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NN.out.dir/build: NN.out

.PHONY : CMakeFiles/NN.out.dir/build

CMakeFiles/NN.out.dir/requires: CMakeFiles/NN.out.dir/src/Main.cpp.o.requires
CMakeFiles/NN.out.dir/requires: CMakeFiles/NN.out.dir/src/NN.cpp.o.requires
CMakeFiles/NN.out.dir/requires: CMakeFiles/NN.out.dir/src/Layer.cpp.o.requires
CMakeFiles/NN.out.dir/requires: CMakeFiles/NN.out.dir/src/Node.cpp.o.requires

.PHONY : CMakeFiles/NN.out.dir/requires

CMakeFiles/NN.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NN.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NN.out.dir/clean

CMakeFiles/NN.out.dir/depend:
	cd /home/dc/dev/NN/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dc/dev/NN /home/dc/dev/NN /home/dc/dev/NN/build /home/dc/dev/NN/build /home/dc/dev/NN/build/CMakeFiles/NN.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NN.out.dir/depend

