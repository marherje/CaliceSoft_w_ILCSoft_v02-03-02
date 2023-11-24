#ifndef __TimeString_hh__
#define __TimeString_hh__ 1

#include "lcio.h"
#include "UTIL/LCTime.h"
#include <string>

/** Documentation missing.
 * @todo Write documentation!
 *
 */

class TimeString {
public:
  TimeString( const std::string str );
  ~TimeString();

  const lcio::long64 getTimeStamp() const;
  const lcio::LCTime getLCTime() const;

private:
  lcio::LCTime _time;

};  // class TimeString

#endif
