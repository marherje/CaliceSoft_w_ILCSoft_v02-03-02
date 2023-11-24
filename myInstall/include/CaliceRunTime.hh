#ifndef __CaliceRunTime_hh__
#define __CaliceRunTime_hh__  1

#include "lcio.h"
#include "LCIOTypes.h"
#include "UTIL/LCTime.h"
#include "EVENT/LCCollection.h"

#include "RunTimeInfo.hh"

/** Documentation missing.
 * @todo Write documentation!
 *
 */

class CaliceRunTime {
public:
  CaliceRunTime();
  CaliceRunTime( unsigned int runnum );
  CaliceRunTime( lcio::LCCollection* col );
  CaliceRunTime( const CALICE::RunTimeInfo& info );
  ~CaliceRunTime();

  CaliceRunTime& newRunNumber( unsigned int runnum );
  CaliceRunTime& newCollection( lcio::LCCollection* col );
  CaliceRunTime& newRunTimeInfo( const CALICE::RunTimeInfo& info );

  lcio::long64 getStartTimeStamp();
  lcio::long64 getStopTimeStamp();
  lcio::LCTime getStartTime();
  lcio::LCTime getStopTime();

protected:

private:
  CALICE::RunTimeInfo* _runTimeInfo;

};  // class CaliceRunTime

#endif
