#include "LinearFitSlope.hh"

#include "lcio.h"
#include "lccd.h"

#include <string>

using namespace lcio;

class AccessLinearFitSlope {

public:
  AccessLinearFitSlope() { _col = 0; }

  ~AccessLinearFitSlope() {}

  void readColFromSlcio( const std::string&, const std::string& );

  void readColFromDB( const std::string&, const std::string&, const std::string& );

  void readFlatFile( const std::string& );

  LCCollection* getCollection();

  CALICE::LinearFitSlope getLfsForHTI( unsigned int );

private:
  lccd::LCCDTimeStamp interpreteTimeString( const std::string&, bool = false );

  LCCollection *_col;


};
