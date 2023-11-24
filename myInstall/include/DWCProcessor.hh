#ifndef DWCProcessor_hh
#define DWCProcessor_hh 1

#define DWC_RESOLUTION 0.2
#define DWC_TDC_NS 25e-3    //one bin in the TDC corresponds to 25ps
#define DWC_NS_MM 0.2       //one ns of delay corresponds to 200microns
#define BIF_US 0.025

//#include <marlin/DataSourceProcessor.h>
#include "marlin/Processor.h"

#include <sstream>
#include <fstream>
#include <map>

#include "TFile.h"
#include "TTree.h"
#include "LineFitter.hh"

using namespace marlin ;

namespace CALICE{

  class DWCProcessor : public Processor {

  public:

    /** Implementation of new Processor
     * returns pointer to processor
     */
    virtual Processor*  newProcessor() { return new DWCProcessor;}
    DWCProcessor() ;
    ~DWCProcessor() ;

    /** Creates events with LCGenrealObject collections from the EUDAQ input file and
     *  calls all active processors' processEvent() and processRunHeader Method.
     */
    void processEvent( LCEvent* evt ) ;

    /** init method */
    virtual void init() ;

    /** end method */
    virtual void end() ;

    virtual void printParameters() ;


  protected:

    // INPUT collections
    std::string _inputColNameBIF;

    // INPUT files
    std::string _inputFileNameBIF;
    std::string _inputFileNameAHCAL;
    std::string _inputFileNameDWC;

    FILE *_bifFile;
    FILE *_ahcalFile;
    TFile *_dwcFile;
    TTree *_dwcTree;

    // OUTPUT collections
    std::string _outputColNameDWC;

    unsigned long long int _BIFTDC;
    unsigned long long int _AHCALTDC;

    std::vector <unsigned long long int> _BIFTime;
    std::vector <unsigned long long int> _DWCTime;
    std::vector <unsigned int> _DWCTrig;

    unsigned int _index;
    std::vector<int> *_dwcCh[16] = {0};

    const int BUNCH_THR = 5000;
    const int DWC_THR = 4;

    LineFitter _trackX;
    LineFitter _trackY;

    const struct {
      float A_X = -1.29;
      float A_Y = -2.54;
      float D_X = -0.56;
      float D_Y = -7.36;
      float E_X = -2.20;
      float E_Y = -7.49;
    } DWC_Offset;

    std::vector<float> _DWCOffsets;

    const float DWC_Z_E = -1090;
    const float DWC_Z_D = -2350;
    const float DWC_Z_A = -15090;
    const float DWC_Z_EXT = -17690;

    enum DWC_MAP {
      DWC_A,
      DWC_D,
      DWC_E,
      DWC_EXT
    };

    enum DWC_to_TDC_MAP {
      DWCE_L = 0,     //DWC E
      DWCE_R = 1,
      DWCE_D = 2,
      DWCE_U = 3,
      DWCD_L = 4,     //DWC D
      DWCD_R = 5,
      DWCD_D = 6,
      DWCD_U = 7,
      DWCA_L = 9,     //DWC A
      DWCA_R = 8,
      DWCA_D = 10,
      DWCA_U = 11,
      DWCEXT_L = 13,  //DWC Ext
      DWCEXT_R = 12,
      DWCEXT_D = 14,
      DWCEXT_U = 15
    };

  int load_ahcal_tdc();
  int load_bif_tdc();
  void event_match();

  private:

  };

} // end namespace marlin

#endif
