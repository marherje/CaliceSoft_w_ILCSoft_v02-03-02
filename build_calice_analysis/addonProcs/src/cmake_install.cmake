# Install script for directory: /nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_analysis/addonProcs/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.36.1-a9696/x86_64-centos7/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/slimLCIOfile" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/slimLCIOfile")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/slimLCIOfile"
         RPATH "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_analysis/bin/slimLCIOfile")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/slimLCIOfile" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/slimLCIOfile")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/slimLCIOfile"
         OLD_RPATH "/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_analysis/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib:"
         NEW_RPATH "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.36.1-a9696/x86_64-centos7/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/slimLCIOfile")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lightgbm_example" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lightgbm_example")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lightgbm_example"
         RPATH "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_analysis/bin/lightgbm_example")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lightgbm_example" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lightgbm_example")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lightgbm_example"
         OLD_RPATH "/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_analysis/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib:"
         NEW_RPATH "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.36.1-a9696/x86_64-centos7/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lightgbm_example")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_analysis/addonProcs/include/" REGEX "/[^/]*\\~$" EXCLUDE REGEX "/[^/]*SVN[^/]*$" EXCLUDE REGEX "/[^/]*CVS[^/]*$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaliceAnalysis.so.1.3.5"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaliceAnalysis.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES
    "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_analysis/lib/libcaliceAnalysis.so.1.3.5"
    "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_analysis/lib/libcaliceAnalysis.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaliceAnalysis.so.1.3.5"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaliceAnalysis.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib:"
           NEW_RPATH "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.36.1-a9696/x86_64-centos7/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaliceAnalysis.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaliceAnalysis.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaliceAnalysis.so"
         RPATH "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_calice_analysis/lib/libcaliceAnalysis.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaliceAnalysis.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaliceAnalysis.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaliceAnalysis.so"
         OLD_RPATH "/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib:"
         NEW_RPATH "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/boost/1.77.0/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lcio/v02-20/lib64:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/Marlin/v01-19/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/gear/v01-09-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/CLHEP/2.4.6.4/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/lccd/v01-05-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CondDBMySQL/CondDBMySQL_ILC-0-9-7/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/MarlinUtil/v01-17-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CED/v01-09-04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/DD4hep/v01-25-01/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-02/root/6.28.04/lib:/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CLHEP/2.4.6.4/lib:/cvmfs/calice.desy.de/lightGBM/v2.3.1/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.36.1-a9696/x86_64-centos7/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcaliceAnalysis.so")
    endif()
  endif()
endif()

