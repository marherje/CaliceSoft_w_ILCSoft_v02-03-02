#include "LinearFitConstant.hh"

#include "AccessLinearFitConstant.hh"

#include "lcio.h"
#include "IMPL/LCCollectionVec.h"
#include "IMPL/LCTOOLS.h"
#include "IO/LCReader.h"


/*! @file
 * @ingroup tools
 *
 * This tool compares two sets of CALICE::LinearFitConstants.
 *
 * Command line parameters:
 *
 *     \e --label1  -\> define label for VAL1) \n
 *     \e --label2  -\> define label for VAL2 \n
 *
 *     \e --val1     -\> define VAL1 input \n
 *     \e --val2     -\> define VAL2 input \n
 *
 *     \e --txt \<inputfile.txt\>                      -> define .txt file as source (format: module/chip/channel/value/error...) \n
 *     \e --slcio \<inputfile.slcio\> \<collection\>   -> define collection from .slcio file as source \n
 *     \e --db \<DBfolder\> \<time\>                   -> define database folder at time \<time\> as source, using no tag \n
 *     \e --db_tag \<DBfolder\> \<time\> \<tag\>       -> define database folder at time \<time\> and tag \<tag\> as source \n
 *
 */

class CompareLinearFitConstants {

public:
  CompareLinearFitConstants() {}

  ~CompareLinearFitConstants() {}

  int run(int argc, char** argv);

  double getValue(unsigned int, unsigned int );

protected:
  int loopAllChannels( const char* = "default_output.txt" );

private:
  void interpretCommandOptions( int, char** );
  void readCollections();
  void printHelp();

  double _default_val1;
  double _default_val2;

  AccessLinearFitConstant _accessVal1;
  AccessLinearFitConstant _accessVal2;

  std::string _label_val1;
  std::string _source_val1;
  std::string _file_val1;
  std::string _col_val1;
  std::string _dbfolder_val1;
  std::string _dbtime_val1;
  std::string _dbtag_val1;

  std::string _label_val2;
  std::string _source_val2;
  std::string _file_val2;
  std::string _col_val2;
  std::string _dbfolder_val2;
  std::string _dbtime_val2;
  std::string _dbtag_val2;

};
