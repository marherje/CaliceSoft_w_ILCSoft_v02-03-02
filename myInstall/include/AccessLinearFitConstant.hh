#include "LinearFitConstant.hh"

#include "lcio.h"
#include "lccd.h"

#include <string>

using namespace lcio;

class AccessLinearFitConstant {

public:
  AccessLinearFitConstant() { _col = 0; }

  ~AccessLinearFitConstant() {}

  void readColFromSlcio( const std::string&, const std::string& );

  void readColFromDB( const std::string&, const std::string&, const std::string& );

  void readFlatFile( const std::string& );

  LCCollection* getCollection();

  CALICE::LinearFitConstant getLfcForHTI( unsigned int );

private:
  lccd::LCCDTimeStamp interpreteTimeString( const std::string&, bool = false );

  LCCollection *_col;


};
