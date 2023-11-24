
#ifndef __DB_FOLDER_FINDER__
#define __DB_FOLDER_FINDER__


#include <string>
#include <sstream>

#include "DBException.hh"

class DBFolderFinder {


public:

  DBFolderFinder(const unsigned int runNumber);
  ~DBFolderFinder() {};

  std::string GetGenericBaseFolder()      const {return m_baseFolderNameGeneric;}
  std::string GetConverterBaseFolder()    const {return m_baseFolderNameConverter;}
  std::string GetSiteBaseFolder()         const {return m_baseFolderNameSite;}
  std::string GetDataQualityBaseFolder()  const {return m_baseFolderNameDataQuality;}

  std::string GetTimeFolder()             const {return m_timeFolderName;}
  std::string GetRunInfoFolder()          const {return m_runInfoFolder;}
  std::string GetRunSummaryFolder()       const {return m_runSummaryFolder;}
  std::string GetBeamSettingsFolder()     const {return m_beamSettingsFolder;}
  std::string GetStagePosFolder()         const {return m_stagePosFolder;}
  std::string GetVetoThresholdFolder()    const {return m_vetoThresholdFolder;}
  std::string GetVetoFractionFolder()     const {return m_vetoFractionFolder;}
  std::string GetTempSensorCalibFolder()  const {return m_tempSensorCalibrationFolder;}
  std::string GetSroModFolder()           const {return m_ahcSroModFolder;}
  std::string GetSroMappingFolder()       const {return m_ahcSroMappingFolder;}
  std::string GetModConnectionFolder()    const {return m_modConnectionFolder;}
  std::string GetModDescriptionFolder()   const {return m_modDescriptionFolder;}
  std::string GetEmcTransformationFolder()   const {return m_emcDetTransformationFolder;}
  std::string GetAhcTransformationFolder()   const {return m_ahcDetTransformationFolder;}

  std::string GetSite()                   const {return m_Site;}

private:

  DBFolderFinder(const DBFolderFinder&) {};

  std::string m_timeFolderName;
  std::string m_baseFolderNameGeneric;
  std::string m_baseFolderNameConverter;
  std::string m_baseFolderNameSite;
  std::string m_baseFolderNameDataQuality;
  std::string m_Site;

  std::string m_runInfoFolder;
  std::string m_runSummaryFolder;
  std::string m_beamSettingsFolder;
  std::string m_stagePosFolder;
  std::string m_vetoThresholdFolder;
  std::string m_vetoFractionFolder;
  std::string m_tempSensorCalibrationFolder;
  std::string m_ahcSroModFolder;
  std::string m_ahcSroMappingFolder;
  std::string m_modDescriptionFolder;
  std::string m_modConnectionFolder;
  std::string m_emcDetTransformationFolder;
  std::string m_ahcDetTransformationFolder;

};


#endif
