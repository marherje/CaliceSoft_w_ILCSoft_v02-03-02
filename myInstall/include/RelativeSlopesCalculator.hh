#include "LinearFitConstant.hh"
#include "AccessLinearFitConstant.hh"
#include "AccessLinearFitSlope.hh"

#include "lcio.h"
#include "IMPL/LCCollectionVec.h"
#include "IMPL/LCTOOLS.h"
#include "IO/LCReader.h"


/*! @file
 * @ingroup tools
 *
 * This tool calculates relative slopes from CALICE::LinearFitConstants and CALICE::LinearFitSlopes.
 *
 * Command line parameters:
 *
 *     \e --temp_corr   \<reference temperature\> -\> correct constants to reference temperature\n
 *\n
 *     \e --const                               -\> define input for constants\n
 *     \e --slopes                              -\> define input for slopes\n
 *\n
 *     \e --txt    \<inputfile.txt\>                 -\> define .txt file as source (format: module/chip/channel/value/error...)\n
 *     \e --slcio  \<inputfile.slcio\> \<collection\>  -\> define collection from .slcio file as source\n
 *     \e --db     \<DBfolder\> \<time\>               -\> define database folder at time \<time\> as source, using no tag\n
 *     \e --db_tag \<DBfolder\> \<time\> \<tag\>         -\> define database folder at time \<time\> and tag \<tag\> as source\n
 */
class RelativeSlopesCalculator {

public:
  RelativeSlopesCalculator() {

    _doTempCorrection = false;

    _def_ref_temp = 0.;

    _default_const = 0.;
    _default_slope = 0.;
    _default_rel_slope = 0.;

  }

  ~RelativeSlopesCalculator() {}

  int run(int argc, char** argv);

  double getValue(const char*, unsigned int);
  double getValue(const char*, unsigned int, double);

  double getReferenceTemperature(const char*, unsigned int);

protected:
  int loopAllChannels( const char* = "default_rel_slopes.txt" );

private:
  void interpretCommandOptions( int, char** );
  void readCollections();
  void printHelp();

  double _default_const;
  double _default_slope;
  double _default_rel_slope;

  float _def_ref_temp;
  bool _doTempCorrection;

  AccessLinearFitConstant _accessConsts;
  AccessLinearFitSlope _accessSlopes;

  std::string _source_const;
  std::string _file_const;
  std::string _col_const;
  std::string _dbfolder_const;
  std::string _dbtime_const;
  std::string _dbtag_const;

  std::string _source_slopes;
  std::string _file_slopes;
  std::string _col_slopes;
  std::string _dbfolder_slopes;
  std::string _dbtime_slopes;
  std::string _dbtag_slopes;

};
