# ${PROJECT_NAME}Config.cmake.in
#
# cmake config file for ${PROJECT_NAME}
#  ${PROJECT_NAME}_INCLUDE_DIRS  - the ${PROJECT_NAME} include directory
#  ${PROJECT_NAME}_LIBRARIES     - The libraries needed to use ${PROJECT_NAME}
#  ${PROJECT_NAME}_DEFINITIONS   - the compile time definitions


#fixme: not true if INCLUDE_INSTALL_DIR is absolute path
SET( ${PROJECT_NAME}_INCLUDE_DIRS "" )
SET( ${PROJECT_NAME}_LIBRARIES    "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall/lib/libCALIBMULTI.so" )

SET( ${PROJECT_NAME}_DEFINITIONS @${PROJECT_NAME}_EXPORT_DEFINITIONS@ )

SET( ${PROJECT_NAME}_ROOT_DIR "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/myInstall" )

SET( ${PROJECT_NAME}_MAJOR_VERSION "@${PROJECT_NAME}_MAJOR_VERSION@" )
SET( ${PROJECT_NAME}_MINOR_VERSION "@${PROJECT_NAME}_MINOR_VERSION@" )
SET( ${PROJECT_NAME}_PATH_LEVEL    "@${PROJECT_NAME}_PATCH_LEVEL@"    )


SET( ${PROJECT_NAME}_FOUND TRUE )

