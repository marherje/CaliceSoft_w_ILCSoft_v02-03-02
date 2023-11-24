SET( ILC_HOME "/cvmfs/ilc.desy.de/sw/x86_64_gcc82_centos7/v02-03-02" CACHE PATH "Path to ILC Software" FORCE)
MARK_AS_ADVANCED( ILC_HOME )

SET( CMAKE_PREFIX_PATH
     ${ILC_HOME}/lccd/v01-05-01;
     ${ILC_HOME}/Marlin/v01-19;
     ${ILC_HOME}/MarlinUtil/v01-16-71;
     ${ILC_HOME}/MarlinReco/v01-34;
     ${ILC_HOME}/PandoraPFANew/v03-25-03;
     ${ILC_HOME}/LCFIVertex/v00-08;
     ${ILC_HOME}/MarlinKinfit/v00-06-01;
     ${ILC_HOME}/MarlinTrk/v02-09-01;
     ${ILC_HOME}/KiTrack/v01-10;
     ${ILC_HOME}/KiTrackMarlin/v01-13-02;
     ${ILC_HOME}/Clupatra/v01-03;
     ${ILC_HOME}/FCalClusterer/v01-00-03;
     ${ILC_HOME}/RAIDA/v01-11;
     ${ILC_HOME}/KalTest/v02-05-01;
     ${ILC_HOME}/KalDet/v01-14-01;
     ${ILC_HOME}/GBL/V02-02-01;
     ${ILC_HOME}/xercesc/v3.2.2/lib64/cmake/XercesC;
     ${ILC_HOME}/DD4hep/v01-25-01/cmake;
     ${ILC_HOME}/aidaTT/v00-10;
     ${ILC_HOME}/DDKalTest/v01-07;
     ${ILC_HOME}/CED/v01-09-04;
     ${ILC_HOME}/lcio/v02-20;
     ${ILC_HOME}/gear/v01-09-01;
     ${ILC_HOME}/sio/v00-01;
     ${ILC_HOME}/root/6.28.04/cmake;
     ${ILC_HOME}/CLHEP/2.4.6.4/lib/CLHEP-2.4.6.4;
     ${ILC_HOME}/Qt5/v5.13.1/lib/cmake/Qt5;
     ${ILC_HOME}/geant4/11.1.1/lib64/Geant4-11.1.1;
     ${ILC_HOME}/CondDBMySQL/CondDBMySQL_ILC-0-9-7;
     ${ILC_HOME}/ilcutil/v01-07-01;
     ${ILC_HOME}/boost/1.77.0/lib/cmake/Boost-1.77.0;
     ${ILC_HOME}/eigen/3.4.0/share/eigen3/cmake/;
     /cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/ilcutil/v01-07-01/
CACHE PATH "CMAKE_PREFIX_PATH" FORCE )

option(USE_CXX11 "Use cxx11" False)
option(Boost_NO_BOOST_CMAKE "dont use cmake find module for boost" ON)

# To handle cmake LOCATION errors for cmake v>3.0 
cmake_policy(SET CMP0026 OLD)

# calice code installation directory

SET( CALICE_HOME
     "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02"
     CACHE PATH "Path to CALICE Software" FORCE )
MARK_AS_ADVANCED( CALICE_HOME )

# calice cmake module directory

SET( CMAKE_MODULE_PATH
     "${CALICE_HOME}/calice_cmake"
     CACHE PATH "Path to CMake Modules" FORCE )

#################################################
## Set the installation prefix,
## i.e. the directory where you want your libraries
## and binaries to be installed.
#################################################
SET( CMAKE_INSTALL_PREFIX "${CALICE_HOME}/myInstall"
     CACHE PATH "Install prefix" FORCE)

#################################################
##
## CALICE packages
##
#################################################
SET( CALICE_USERLIB_HOME "${CALICE_HOME}/calice_userlib/cmake"
     CACHE PATH "Path to calice_userlib" FORCE )

SET( CALICE_RECO_HOME "${CALICE_HOME}/calice_reco/cmake"
     CACHE PATH "Path to calice_reco" FORCE )

SET( RAW2CALOHIT_HOME "${CALICE_HOME}/calice_reco/raw2calohit/cmake"
     CACHE PATH "Path to calice_reco/raw2calohit" FORCE )

SET( CLUSTERING_HOME "${CALICE_HOME}/calice_reco/clustering/cmake"
     CACHE PATH "Path to calice_reco/clustering" FORCE )

SET( LABVIEW2LCIO_DIR "${CALICE_HOME}/labview_converter/raw2lcio/cmake"
     CACHE PATH "Path to labview_converter" FORCE )

SET( CELLGEOMETRY_DIR "${CALICE_HOME}/calice_reco/cellGeometry/cmake"
     CACHE PATH "Path to calice_reco/cellGeometry" FORCE )

SET( RECOSIPM_DIR "${CALICE_HOME}/calice_reco/recoSiPM/cmake"
     CACHE PATH "Path to calice_reco/recoSiPM" FORCE )