#include "LinearFitConstant.hh"
#include "AccessLinearFitConstant.hh"
#include "AccessLinearFitSlope.hh"
#include "AccessSimpleValue.hh"

#include "lcio.h"
#include "IMPL/LCCollectionVec.h"
#include "IMPL/LCTOOLS.h"
#include "IO/LCReader.h"

/*! @file
 * @ingroup tools
 *
 * This tool transports CALICE:LienarFitConstants from one set of conditon parameters (e.g. high voltage) to another.
 *
 * Command line parameters:
 *
 *     \e --values   -\> define LinearFitConstant input
 *     \e --slopes   -\> define input for LinearFitSlopes
 *     \e --cond_in  -\> define initial conditions (e.g. reference high voltage)
 *     \e --cond_out -\> define conditions the constants are shifted to (e.g. different high voltage settings)
 *
 *     \e --txt    \<inputfile.txt\>                 -\> define .txt file as source (format: module/chip/channel/value/error...)
 *     \e --slcio  \<inputfile.slcio\> \<collection\>  -\> define collection from .slcio file as source
 *     \e --db     \<DBfolder\> \<time\>               -\> define database folder at time \<time\> as source, using no tag
 *     \e --db_tag \<DBfolder\> \<time\> \<tag\>         -\> define database folder at time \<time\> and tag \<tag\> as source
 *
 */

class TransportLinearFitConstants {

public:
  TransportLinearFitConstants() {

  }

  ~TransportLinearFitConstants() {}

  int run(int argc, char** argv);

  void getValue( const unsigned int, float&, float&, float&, float& );

protected:
  int loopAllChannels( const char* = "default_lfc_transported.txt" );

private:
  void interpretCommandOptions( int, char** );
  void readCollections();
  void printHelp();

  AccessLinearFitConstant _accessLfc;
  AccessLinearFitSlope _accessLfs;
  AccessSimpleValue _accessSv_cond_in;
  AccessSimpleValue _accessSv_cond_out;

  std::string _source_lfc;
  std::string _file_lfc;
  std::string _col_lfc;
  std::string _dbfolder_lfc;
  std::string _dbtime_lfc;
  std::string _dbtag_lfc;

  std::string _source_lfs;
  std::string _file_lfs;
  std::string _col_lfs;
  std::string _dbfolder_lfs;
  std::string _dbtime_lfs;
  std::string _dbtag_lfs;

  std::string _source_cond_in;
  std::string _file_cond_in;
  std::string _col_cond_in;
  std::string _dbfolder_cond_in;
  std::string _dbtime_cond_in;
  std::string _dbtag_cond_in;

  std::string _source_cond_out;
  std::string _file_cond_out;
  std::string _col_cond_out;
  std::string _dbfolder_cond_out;
  std::string _dbtime_cond_out;
  std::string _dbtag_cond_out;

};
