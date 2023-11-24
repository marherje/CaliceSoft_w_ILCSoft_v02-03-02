##########################################
# create an uninstall target for cmake
# http://www.cmake.org/Wiki/CMake_FAQ
##########################################

IF(NOT EXISTS "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_RootTreeWriter/install_manifest.txt")
  MESSAGE(FATAL_ERROR "Cannot find install manifest: \"/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_RootTreeWriter/install_manifest.txt\"")
ENDIF(NOT EXISTS "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_RootTreeWriter/install_manifest.txt")

FILE(READ "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/build_RootTreeWriter/install_manifest.txt" files)
STRING(REGEX REPLACE "\n" ";" files "${files}")
FOREACH(file ${files})
  MESSAGE(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  IF(EXISTS "$ENV{DESTDIR}${file}")
    EXEC_PROGRAM(
      "/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/CMake/3.23.2/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    IF("${rm_retval}" STREQUAL 0)
    ELSE("${rm_retval}" STREQUAL 0)
      MESSAGE(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    ENDIF("${rm_retval}" STREQUAL 0)
  ELSE(EXISTS "$ENV{DESTDIR}${file}")
    MESSAGE(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
  ENDIF(EXISTS "$ENV{DESTDIR}${file}")
ENDFOREACH(file)
