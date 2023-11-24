# RAW2CALOHITConfig.cmake.in
#
# cmake config file for RAW2CALOHIT
#  RAW2CALOHIT_INCLUDE_DIRS  - the RAW2CALOHIT include directory
#  RAW2CALOHIT_LIBRARIES     - The libraries needed to use RAW2CALOHIT
#  RAW2CALOHIT_DEFINITIONS   - the compile time definitions

SET( RAW2CALOHIT_INCLUDE_DIRS "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/include" )
SET( RAW2CALOHIT_INCLUDE_DIRS "${RAW2CALOHIT_INCLUDE_DIRS}" "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/include/TBTrack" )
SET( RAW2CALOHIT_INCLUDE_DIRS "${RAW2CALOHIT_INCLUDE_DIRS}" "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/include/TBTrackUtil" )
SET( RAW2CALOHIT_INCLUDE_DIRS "${RAW2CALOHIT_INCLUDE_DIRS}" "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/include/gui" )
SET( RAW2CALOHIT_INCLUDE_DIRS "${RAW2CALOHIT_INCLUDE_DIRS}" "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/include/histmgr" )
SET( RAW2CALOHIT_INCLUDE_DIRS "${RAW2CALOHIT_INCLUDE_DIRS}" "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/include/utilities" )

SET( RAW2CALOHIT_LIBRARIES    "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib/libraw2calohit.so" )

SET( RAW2CALOHIT_DEFINITIONS  )

SET( RAW2CALOHIT_ROOT_DIR "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall" )

SET( RAW2CALOHIT_MAJOR_VERSION "6" )
SET( RAW2CALOHIT_MINOR_VERSION "9" )
SET( RAW2CALOHIT_PATH_LEVEL    "0"    )


SET( RAW2CALOHIT_FOUND TRUE )

