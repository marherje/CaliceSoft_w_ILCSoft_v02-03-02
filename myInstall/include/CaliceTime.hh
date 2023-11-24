#ifndef __CaliceTime_hh__
#define __CaliceTime_hh__ 1

#include <iostream>
#include <string>
#include "lcio.h"
#include "LCIOTypes.h"
#include "UTIL/LCTime.h"

/** Documentation missing.
 * @todo Write documentation!
 *
 */

class CaliceTime {
public:
  CaliceTime( const char* arg, const bool runstart = true );
  ~CaliceTime();

  CaliceTime& set( const char* arg, const bool runstart );

  const lcio::long64 timeStamp() const;
  //  static const lcio::long64 timeStamp( const char* arg, bool runstart = true );

  void print( std::ostream& out ) const;

  static const char* EARLIEST;
  static const char* LATEST;

private:
  UTIL::LCTime _time;
  //  std::string _str;
};

#endif
