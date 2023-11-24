# CALICEANALYSISConfig.cmake.in
#
# cmake config file for CALICEANALYSIS
#  CALICEANALYSIS_INCLUDE_DIRS  - the CALICEANALYSIS include directory
#  CALICEANALYSIS_LIBRARIES     - The libraries needed to use CALICEANALYSIS
#  CALICEANALYSIS_DEFINITIONS   - the compile time definitions


#fixme: not true if INCLUDE_INSTALL_DIR is absolute path
SET( CALICEANALYSIS_INCLUDE_DIRS "" )
SET( CALICEANALYSIS_LIBRARIES    "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib/libcaliceAnalysis.so" )

SET( CALICEANALYSIS_DEFINITIONS  )

SET( CALICEANALYSIS_ROOT_DIR "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall" )

SET( CALICEANALYSIS_MAJOR_VERSION "1" )
SET( CALICEANALYSIS_MINOR_VERSION "3" )
SET( CALICEANALYSIS_PATH_LEVEL    "5"    )


SET( CALICEANALYSIS_FOUND TRUE )

