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
CMAKE_SOURCE_DIR = /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_cddata

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata

# Include any dependencies generated for this target.
include dbfill/CMakeFiles/hcalcassvscrctodb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dbfill/CMakeFiles/hcalcassvscrctodb.dir/compiler_depend.make

# Include the progress variables for this target.
include dbfill/CMakeFiles/hcalcassvscrctodb.dir/progress.make

# Include the compile flags for this target's objects.
include dbfill/CMakeFiles/hcalcassvscrctodb.dir/flags.make

dbfill/CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.o: dbfill/CMakeFiles/hcalcassvscrctodb.dir/flags.make
dbfill/CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.o: /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_cddata/dbfill/hcalcassvscrctodb.cc
dbfill/CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.o: dbfill/CMakeFiles/hcalcassvscrctodb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dbfill/CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.o"
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata/dbfill && /cvmfs/sft.cern.ch/lcg/releases/gcc/10.3.0-f5826/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dbfill/CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.o -MF CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.o.d -o CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.o -c /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_cddata/dbfill/hcalcassvscrctodb.cc

dbfill/CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.i"
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata/dbfill && /cvmfs/sft.cern.ch/lcg/releases/gcc/10.3.0-f5826/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_cddata/dbfill/hcalcassvscrctodb.cc > CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.i

dbfill/CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.s"
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata/dbfill && /cvmfs/sft.cern.ch/lcg/releases/gcc/10.3.0-f5826/x86_64-centos7/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_cddata/dbfill/hcalcassvscrctodb.cc -o CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.s

# Object files for target hcalcassvscrctodb
hcalcassvscrctodb_OBJECTS = \
"CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.o"

# External object files for target hcalcassvscrctodb
hcalcassvscrctodb_EXTERNAL_OBJECTS =

bin/hcalcassvscrctodb: dbfill/CMakeFiles/hcalcassvscrctodb.dir/hcalcassvscrctodb.cc.o
bin/hcalcassvscrctodb: dbfill/CMakeFiles/hcalcassvscrctodb.dir/build.make
bin/hcalcassvscrctodb: lib/libhelper_lib.so
bin/hcalcassvscrctodb: lib/libcondDataCreators_lib.so
bin/hcalcassvscrctodb: /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib/libraw2calohit.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64/liblcio.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib/liblccd.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib/libMarlin.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib/libMarlinXML.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64/liblcio.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib/liblccd.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib/libMarlin.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib/libMarlinXML.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib/libgearsurf.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib/libgear.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib/libgearxml.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib/libCLHEP-2.4.6.4.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib/libstreamlog.so
bin/hcalcassvscrctodb: /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib/libuserlib.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib/libconddb.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libCore.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libImt.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libRIO.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libNet.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libHist.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libGraf.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libGraf3d.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libGpad.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libROOTDataFrame.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libTree.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libTreePlayer.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libRint.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libPostscript.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libMatrix.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libPhysics.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libMathCore.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libThread.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libMultiProc.so
bin/hcalcassvscrctodb: /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib/libROOTVecOps.so
bin/hcalcassvscrctodb: dbfill/CMakeFiles/hcalcassvscrctodb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/hcalcassvscrctodb"
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata/dbfill && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hcalcassvscrctodb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dbfill/CMakeFiles/hcalcassvscrctodb.dir/build: bin/hcalcassvscrctodb
.PHONY : dbfill/CMakeFiles/hcalcassvscrctodb.dir/build

dbfill/CMakeFiles/hcalcassvscrctodb.dir/clean:
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata/dbfill && $(CMAKE_COMMAND) -P CMakeFiles/hcalcassvscrctodb.dir/cmake_clean.cmake
.PHONY : dbfill/CMakeFiles/hcalcassvscrctodb.dir/clean

dbfill/CMakeFiles/hcalcassvscrctodb.dir/depend:
	cd /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_cddata /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_cddata/dbfill /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata/dbfill /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_cddata/dbfill/CMakeFiles/hcalcassvscrctodb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dbfill/CMakeFiles/hcalcassvscrctodb.dir/depend

