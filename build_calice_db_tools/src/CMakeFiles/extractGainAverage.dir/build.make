# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CMake/3.23.2/bin/cmake

# The command to remove a file.
RM = /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CMake/3.23.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_db_tools

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools

# Include any dependencies generated for this target.
include src/CMakeFiles/extractGainAverage.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/extractGainAverage.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/extractGainAverage.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/extractGainAverage.dir/flags.make

src/CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.o: src/CMakeFiles/extractGainAverage.dir/flags.make
src/CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.o: /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_db_tools/src/extractGainAverage.cc
src/CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.o: src/CMakeFiles/extractGainAverage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.o"
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools/src && /cvmfs/sft.cern.ch/lcg/releases/gcc/10.3.0-f5826/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.o -MF CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.o.d -o CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.o -c /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_db_tools/src/extractGainAverage.cc

src/CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.i"
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools/src && /cvmfs/sft.cern.ch/lcg/releases/gcc/10.3.0-f5826/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_db_tools/src/extractGainAverage.cc > CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.i

src/CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.s"
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools/src && /cvmfs/sft.cern.ch/lcg/releases/gcc/10.3.0-f5826/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_db_tools/src/extractGainAverage.cc -o CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.s

# Object files for target extractGainAverage
extractGainAverage_OBJECTS = \
"CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.o"

# External object files for target extractGainAverage
extractGainAverage_EXTERNAL_OBJECTS =

bin/extractGainAverage: src/CMakeFiles/extractGainAverage.dir/extractGainAverage.cc.o
bin/extractGainAverage: src/CMakeFiles/extractGainAverage.dir/build.make
bin/extractGainAverage: lib/libcalice_db_tools.so.1.2.1
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64/liblcio.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib/liblccd.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib/libMarlin.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib/libMarlinXML.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64/liblcio.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib/liblccd.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib/libMarlin.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib/libMarlinXML.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib/libgearsurf.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib/libgear.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib/libgearxml.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib/libCLHEP-2.4.6.4.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib/libstreamlog.so
bin/extractGainAverage: /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib/libuserlib.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib/libconddb.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libCore.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libImt.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libRIO.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libNet.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libHist.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libGraf.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libGraf3d.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libGpad.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libROOTDataFrame.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libTree.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libTreePlayer.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libRint.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libPostscript.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libMatrix.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libPhysics.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libMathCore.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libThread.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libMultiProc.so
bin/extractGainAverage: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libROOTVecOps.so
bin/extractGainAverage: src/CMakeFiles/extractGainAverage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/extractGainAverage"
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/extractGainAverage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/extractGainAverage.dir/build: bin/extractGainAverage
.PHONY : src/CMakeFiles/extractGainAverage.dir/build

src/CMakeFiles/extractGainAverage.dir/clean:
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools/src && $(CMAKE_COMMAND) -P CMakeFiles/extractGainAverage.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/extractGainAverage.dir/clean

src/CMakeFiles/extractGainAverage.dir/depend:
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_db_tools /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_db_tools/src /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools/src /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_db_tools/src/CMakeFiles/extractGainAverage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/extractGainAverage.dir/depend

