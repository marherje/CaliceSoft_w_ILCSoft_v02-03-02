#ifndef __CaliceDBHelper_hh__
#define __CaliceDBHelper_hh__

#include "lccd.h"
#include "AhcMapper.hh"
#include "AhcTempProvider.hh"


class CaliceDBHelper
{
public:
  CaliceDBHelper();
  ~CaliceDBHelper(){};

  bool setRunTimes(const int runnumber, lccd::LCCDTimeStamp &from, lccd::LCCDTimeStamp &till );
  bool setRunTimes(const int firstRun, const int lastRun, lccd::LCCDTimeStamp &from, lccd::LCCDTimeStamp &till );
  std::string getDBInitString();
  CALICE::AhcMapper *getAhcMapper(const lccd::LCCDTimeStamp runStart, lccd::LCCDTimeStamp runStop);
  std::string getBaseFolderNameConverter(int runnumber);
  bool setSlowControlFolderNames(const int run, std::string &slowControlFolderName, 
				 std::string &slowControlMappingFolderName);
  CALICE::AhcTempProvider* digestTemperatures(const LCCollection* tempCol, LCCollection *calibrationCollection,
					      const CALICE::AhcMapper *ahcMapper, const std::string temperatureProviderModel);

  
private:
  std::string _dbInit;
  std::string _timeFolderName;



};
#endif
