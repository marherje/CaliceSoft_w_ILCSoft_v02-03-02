#include "SimpleValue.hh"

#include "lcio.h"
#include "lccd.h"

#include <string>

using namespace lcio;

class AccessSimpleValue {

public:
  AccessSimpleValue() { _col = 0; }

  ~AccessSimpleValue() {}

  void readColFromSlcio( const std::string&, const std::string& );

  void readColFromDB( const std::string&, const std::string&, const std::string& );

  void readFlatFile( const std::string& );

  LCCollection* getCollection();

  CALICE::SimpleValue getSvForHTI( unsigned int );

private:
  lccd::LCCDTimeStamp interpreteTimeString( const std::string&, bool = false );

  LCCollection *_col;


};
