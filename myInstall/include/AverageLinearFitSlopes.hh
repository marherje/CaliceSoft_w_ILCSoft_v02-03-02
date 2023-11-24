#include "LinearFitSlope.hh"

#include "AccessLinearFitSlope.hh"

#include "lcio.h"
#include "IMPL/LCCollectionVec.h"
#include "IMPL/LCTOOLS.h"
#include "IO/LCReader.h"


/*! @file
 * @ingroup tools
 *
 * This tool calculates the average of n sets of CALICE::LinearFitSlopes.
 *
 * Command line parameters:\n
 *\n
 *   /e  --val  -\> add new value for average\n
 *\n
 *   /e  --txt    \<inputfile.txt\>                 -\> define .txt file as source (format: module/chip/channel/value/error...)\n
 *   /e  --slcio  \<inputfile.slcio\> \<collection\>  -\> define collection from .slcio file as source\n
 *   /e  --db     \<DBfolder\> \<time\>               -\> define database folder at time \<time\> as source, using no tag\n
 *   /e  --db_tag \<DBfolder\> \<time\> \<tag\>         -\> define database folder at time \<time\> and tag \<tag\> as source\n
 */

class AverageLinearFitSlopes {

public:
  AverageLinearFitSlopes() {}

  ~AverageLinearFitSlopes() {}

  int run(int argc, char** argv);

protected:
  int loopAllChannels( const char* = "defualt_output.txt" );

private:
  void interpretCommandOptions( int, char** );
  void readCollections();
  void printHelp();

  std::vector< AccessLinearFitSlope > _vec_access;

  std::vector< std::string > _vec_source;
  std::vector< std::string > _vec_file;
  std::vector< std::string > _vec_col;
  std::vector< std::string > _vec_dbfolder;
  std::vector< std::string > _vec_dbtime;
  std::vector< std::string > _vec_dbtag;

};
