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
 * This tool evaluates LinearFitConstants at a certain temperature T_ref.
 *
 * Command line parameters:
 *
 *     \e --tref \<T_ref\> -\> define one fixed reference temperature for all channels \n
 *\n
 *     \e --values -\> define LinearFitConstant input\n
 *     \e --slopes -\> define input for LinearFitSlopes\n
 *     \e --fref   -\> define input for channelwise reference temperature \n
 *\n
 *     \e --txt    \<inputfile.txt\>                 -\> define .txt file as source (format: module/chip/channel/value/error...)\n
 *     \e --slcio  \<inputfile.slcio\> \<collection\>  -\> define collection from .slcio file as source\n
 *     \e --db     \<DBfolder\> \<time\>               -\> define database folder at time \<time\> as source, using no tag\n
 *     \e --db_tag \<DBfolder\> \<time\> \<tag\>         -\> define database folder at time \<time\> and tag \<tag\> as source\n
 *
 */

class ShiftLinearFitConstants {

public:
  ShiftLinearFitConstants() {

    _useSingleTref = 0;

  }

  ~ShiftLinearFitConstants() {}

  int run(int argc, char** argv);

  double getValue(unsigned int, double);
  double getRefTemp(unsigned int);

protected:
  int loopAllChannels( const char* = "default_lfc_shifted.txt" );

private:
  void interpretCommandOptions( int, char** );
  void readCollections();
  void printHelp();

  AccessLinearFitConstant _accessLfc;
  AccessLinearFitSlope _accessLfs;
  AccessSimpleValue _accessSv_Tref;

  bool _useSingleTref;

  double _ref_temp;
  double _ref_temp_error;

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

  std::string _source_t_ref;
  std::string _file_t_ref;
  std::string _col_t_ref;
  std::string _dbfolder_t_ref;
  std::string _dbtime_t_ref;
  std::string _dbtag_t_ref;

};
