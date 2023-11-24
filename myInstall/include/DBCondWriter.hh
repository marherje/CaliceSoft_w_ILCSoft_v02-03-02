#ifndef __DBCondWriter_hh__
#define __DBCondWriter_hh__ 1

#include "lcio.h"
#include "LCIOTypes.h"
#include "EVENT/LCCollection.h"

#include "lccd.h"

#include <string>
#include <iostream>

/** Documentation missing.
 * @todo Write documentation!
 *
 */

class DBCondWriter{
public:
  DBCondWriter();
  DBCondWriter( const std::string& dbinit,
                const std::string& folder );
  ~DBCondWriter();

  DBCondWriter& setDBInit( const std::string& dbinit );
  DBCondWriter& setFolder( const std::string& folder );

  DBCondWriter& writeCollection( lcio::LCCollection* col,
                                 const std::string& description = "",
                                 lcio::long64 from = lccd::LCCDMinusInf,
                                 lcio::long64 until = lccd::LCCDPlusInf );

  DBCondWriter& print( std::ostream& os );

private:
  std::string _dbinit;
  std::string _folder;
  std::string _description;
};  // class DBCondWriter

#endif

