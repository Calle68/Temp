# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld/Build

# Include any dependencies generated for this target.
include CMakeFiles/MyProjekt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyProjekt.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyProjekt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyProjekt.dir/flags.make

CMakeFiles/MyProjekt.dir/main.cc.o: CMakeFiles/MyProjekt.dir/flags.make
CMakeFiles/MyProjekt.dir/main.cc.o: ../main.cc
CMakeFiles/MyProjekt.dir/main.cc.o: CMakeFiles/MyProjekt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyProjekt.dir/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProjekt.dir/main.cc.o -MF CMakeFiles/MyProjekt.dir/main.cc.o.d -o CMakeFiles/MyProjekt.dir/main.cc.o -c /home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld/main.cc

CMakeFiles/MyProjekt.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProjekt.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld/main.cc > CMakeFiles/MyProjekt.dir/main.cc.i

CMakeFiles/MyProjekt.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProjekt.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld/main.cc -o CMakeFiles/MyProjekt.dir/main.cc.s

# Object files for target MyProjekt
MyProjekt_OBJECTS = \
"CMakeFiles/MyProjekt.dir/main.cc.o"

# External object files for target MyProjekt
MyProjekt_EXTERNAL_OBJECTS =

MyProjekt: CMakeFiles/MyProjekt.dir/main.cc.o
MyProjekt: CMakeFiles/MyProjekt.dir/build.make
MyProjekt: CMakeFiles/MyProjekt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyProjekt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyProjekt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyProjekt.dir/build: MyProjekt
.PHONY : CMakeFiles/MyProjekt.dir/build

CMakeFiles/MyProjekt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyProjekt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyProjekt.dir/clean

CMakeFiles/MyProjekt.dir/depend:
	cd /home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld /home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld /home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld/Build /home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld/Build /home/calle68/01_Cpp/VSCode/UdemyCppPro/Chapter03/01_HelloWorld/Build/CMakeFiles/MyProjekt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyProjekt.dir/depend

