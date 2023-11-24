# RECOSIPMConfig.cmake.in
#
# cmake config file for RECOSIPM
#  RECOSIPM_INCLUDE_DIRS  - the RECOSIPM include directory
#  RECOSIPM_LIBRARIES     - The libraries needed to use RECOSIPM
#  RECOSIPM_DEFINITIONS   - the compile time definitions


#fixme: not true if INCLUDE_INSTALL_DIR is absolute path
SET( RECOSIPM_INCLUDE_DIRS "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/include" )
SET( RECOSIPM_LIBRARIES    "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib/librecoSiPM.so" )

SET( RECOSIPM_DEFINITIONS  )

SET( RECOSIPM_ROOT_DIR "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall" )

SET( RECOSIPM_MAJOR_VERSION "6" )
SET( RECOSIPM_MINOR_VERSION "9" )
SET( RECOSIPM_PATH_LEVEL    "0"    )


SET( RECOSIPM_FOUND TRUE )

