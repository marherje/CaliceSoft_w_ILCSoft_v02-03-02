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
 * this tool calculates the lightyield from CALICE::LinearFitConstants.
 *
 * command line parameters:
 *
 *    \e --temp_corr   -\> switch temperature correction ON\n
 *\n
 *    \e --mip         -\> define MIP input\n
 *    \e --gain        -\> define GAIN input\n
 *    \e --gain_slopes -\> define input for GAIN slopes dG/dT\n
 *    \e --ic          -\> define IC input\n
 *\n
 *    \e --txt    \<inputfile.txt\>                 -\> define .txt file as source (format: module/chip/channel/value/error...)\n
 *    \e --slcio  \<inputfile.slcio\> \<collection\>  -\> define collection from .slcio file as source\n
 *    \e --db     \<DBfolder\> \<time\>               -\> define database folder at time \<time\> as source, using no tag\n
 *    \e --db_tag \<DBfolder\> \<time\> \<tag\>         -\> define database folder at time \<time\> and tag \<tag\> as source\n
 */
class LightyieldCalculator {

public:
  LightyieldCalculator() {

    _doTempCorrection = false;

    _default_mip = 0;
    _default_gain = -400;
    _default_ic = -10;

  }

  ~LightyieldCalculator() {}

  int run(int argc, char** argv);

  double getValue(const char*, unsigned int);
  double getValue(const char*, unsigned int, double);

  double getReferenceTemperature(const char*, unsigned int);

protected:
  int loopAllChannels( const char* = "default_ly.txt" );

private:
  void interpretCommandOptions( int, char** );
  void readCollections();
  void printHelp();

  double _default_mip;
  double _default_gain;
  double _default_ic;

  bool _doTempCorrection;

  AccessLinearFitConstant _accessMip;
  AccessLinearFitConstant _accessGain;
  AccessLinearFitConstant _accessIc;

  AccessLinearFitSlope _accessGainSlopes;

  std::string _source_mip;
  std::string _file_mip;
  std::string _col_mip;
  std::string _dbfolder_mip;
  std::string _dbtime_mip;
  std::string _dbtag_mip;

  std::string _source_gain;
  std::string _file_gain;
  std::string _col_gain;
  std::string _dbfolder_gain;
  std::string _dbtime_gain;
  std::string _dbtag_gain;

  std::string _source_ic;
  std::string _file_ic;
  std::string _col_ic;
  std::string _dbfolder_ic;
  std::string _dbtime_ic;
  std::string _dbtag_ic;

  std::string _source_gain_slopes;
  std::string _file_gain_slopes;
  std::string _col_gain_slopes;
  std::string _dbfolder_gain_slopes;
  std::string _dbtime_gain_slopes;
  std::string _dbtag_gain_slopes;

};
