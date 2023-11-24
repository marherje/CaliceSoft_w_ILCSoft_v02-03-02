# CALICE_USERLIBConfig.cmake.in
#
# cmake config file for CALICE_USERLIB
#  CALICE_USERLIB_INCLUDE_DIRS  - the CALICE_USERLIB include directory
#  CALICE_USERLIB_LIBRARIES     - The libraries needed to use CALICE_USERLIB
#  CALICE_USERLIB_DEFINITIONS   - the compile time definitions


#fixme: not true if INCLUDE_INSTALL_DIR is absolute path
SET( CALICE_USERLIB_INCLUDE_DIRS "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/include" )
SET( CALICE_USERLIB_INCLUDE_DIRS "${CALICE_USERLIB_INCLUDE_DIRS}"
                                  "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/include/Mapping"
                                  "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/include/CellDescription" 
                                  "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/include/Neighbours")

SET( CALICE_USERLIB_LIBRARIES "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib/libuserlib.so" )

SET( CALICE_USERLIB_DEFINITIONS -DTRIGGER_HANDLER_IS_SINGLETON )

SET( CALICE_USERLIB_ROOT_DIR "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall" )

SET( CALICE_USERLIB_MAJOR_VERSION "6" )
SET( CALICE_USERLIB_MINOR_VERSION "7" )
SET( CALICE_USERLIB_PATH_LEVEL    "0"    )


SET( CALICE_USERLIB_FOUND TRUE )

