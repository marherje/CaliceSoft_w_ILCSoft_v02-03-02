/** @todo: move this tool to calice_cddata */

#ifndef __SimpleFileWriter_hh__
#define __SimpleFileWriter_hh__ 1

#include "EVENT/LCCollection.h"

#include <string>
#include <iostream>

/** Documentation missing.
 * @todo Write documentation!
 *
 */

class SimpleFileWriter{
public:
  SimpleFileWriter();
  SimpleFileWriter( const std::string& file) ;
  ~SimpleFileWriter();

  SimpleFileWriter& setFile( const std::string& file );

  SimpleFileWriter& writeCollection( EVENT::LCCollection* col,
                                     const std::string name );

  SimpleFileWriter& print( std::ostream& os );

private:
  std::string _file;
};  // class SimpleFileWriter

#endif

