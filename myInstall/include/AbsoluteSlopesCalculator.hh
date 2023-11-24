#include "LinearFitConstant.hh"
#include "AccessLinearFitConstant.hh"

#include "lcio.h"
#include "IMPL/LCCollectionVec.h"
#include "IMPL/LCTOOLS.h"
#include "IO/LCReader.h"


/*! @file
 * @ingroup tools
 *
 * This tool calculates absolute slopes from CALICE::LinearFitConstants
 *
 * Command line parameters:
 *\n
 *    \e --rel_slope \<float\>   -\> define relative slope for all channels\n
 *\n
 *    \e --const               -\> define input for constant \n
 *\n
 *    \e --txt    \<inputfile.txt\>                 -\> define .txt file as source (format: module/chip/channel/value/error...) \n
 *    \e --slcio  \<inputfile.slcio\> \<collection\>  -\> define collection from .slcio file as source \n
 *    \e --db     \<DBfolder\> \<time\>               -\> define database folder at time \<time\> as source, using no tag \n
 *    \e --db_tag \<DBfolder\> \<time\> \<tag\>         -\> define database folder at time \<time\> and tag \<tag\> as source \n
 *
 */
class AbsoluteSlopesCalculator {

public:
  AbsoluteSlopesCalculator() {

    _default_const = 0.;
    _default_slope = 0.;
    _default_slope_err = 0.;

    _rel_slope = 0.;

  }

  ~AbsoluteSlopesCalculator() {}

  int run(int argc, char** argv);

  double getValue(const char*, unsigned int);
  double getValue(const char*, unsigned int, double);

  double getReferenceTemperature(const char*, unsigned int);

protected:
  int loopAllChannels( const char* = "default_abs_slopes.txt" );

private:
  void interpretCommandOptions( int, char** );
  void readCollections();
  void printHelp();

  double _default_const;
  double _default_slope;
  double _default_slope_err;

  double _rel_slope;

  AccessLinearFitConstant _accessConst;

  std::string _source_const;
  std::string _file_const;
  std::string _col_const;
  std::string _dbfolder_const;
  std::string _dbtime_const;
  std::string _dbtag_const;

  std::string _outFileName;
};
