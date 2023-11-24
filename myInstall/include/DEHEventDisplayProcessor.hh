#ifndef DEHEVENTDISPLAYPROCESSOR_hh
#define DEHEVENTDISPLAYPROCESSOR_hh 1

#include <cmath>

// LCIO includes
#include "lcio.h"
#include "EVENT/CalorimeterHit.h"
#include "lccd/IConditionsChangeListener.hh"

// Marlin includes
#include "marlin/Processor.h"

// CALICE includes
#include "Ahc2CalibrationsProcessor.hh"
#include "Mapper.hh"
#include "Ahc2Mapper.hh"
#include "Ahc2Calibrations.hh"
#include "MappedContainer.hh"
#include "CellNeighbours.hh"
#include "CellDescription.hh"
#include "ConditionsChangeDelegator.hh"

#include "EventVariables.hh"


using namespace lcio ;
using namespace marlin ;

namespace CALICE {

  /**  @brief This is a Marlin processor for displaying events with CED.
  *
  * If you want to display events with CED, you need to start the display (<CODE>glced</CODE>) before running Marlin.
  *
  * Mouse commands that can be used within CED:
  *
  *    - <CODE> left + move </CODE> -> rotate view
  *    - <CODE> right + move down/up </CODE> -> zoom view in/out
  *    - <CODE> center + move </CODE> -> shift view
  *    - <CODE> wheel </CODE> -> shift view along z-axis
  *
  *
  * Keyboard commands that can be used within CED:
  *
  *    - <CODE> b </CODE> -> toggle background color
  *    - <CODE> r </CODE> -> got to default angular view
  *    - <CODE> s </CODE> -> got to default side view
  *    - <CODE> f </CODE> -> got to default front view
  *    - <CODE> v </CODE> -> switch on/off fisheye view
  *    - <CODE> 0 ... 9 </CODE> -> switch on/off CED display layer 0 ... 9
  *    - <CODE> shift + 0 ... 9 </CODE> -> switch on/off display layer 10 ... 19
  *    - <CODE> t </CODE> -> switch on/off CED display layer 20
  *    - <CODE> y </CODE> -> switch on/off CED display layer 21
  *    - <CODE> u </CODE> -> switch on/off CED display layer 22
  *    - <CODE> i </CODE> -> switch on/off CED display layer 23
  *
  *
  * Assignment of CED display layers:
  *
  *    -  0:
  *    -  1: HBU / EBU hits ( hit energy < 0.5 mip )
  *    -  2: HBU / EBU hits ( 0.5 mip <= hit energy < 1.65 mip )
  *    -  3: HBU / EBU hits ( 1.65 mip <= hit energy < 2.9 mip )
  *    -  4: HBU / EBU hits ( 2.9 mip <= hit energy < 5.4 mip )
  *    -  5: HBU / EBU hits ( hit energy >= 5.4 mip )
  *    -  6:
  *    -  7:
  *    -  8:
  *    -  9:
  *    - 10:
  *    - 11:
  *    - 12:
  *    - 13:
  *    - 14:
  *    - 15:
  *    - 16:
  *    - 17:
  *    - 18:
  *    - 19:
  *    - 20: cell frames: EBU strips
  *    - 21: cell frames: HBU tiles 3x3 cm^2
  *    - 22:
  *    - 23:
  *
  * CED color coding for hit energies:
  *
  * @image html EventDisplayProcessor_colorCode.png
  * @image latex EventDisplayProcessor_colorCode.eps "CED color coding" width=10cm
  *
  *
  * @author S. Lu, DESY
  * @version 1.0
  * @date November 2014
  *
  * Modification : E. Brianne, DESY
  * Date : December 2015
  */
  class DEHEventDisplayProcessor : public Processor, public lccd::IConditionsChangeListener  {

  public:

    virtual Processor*  newProcessor() { return new DEHEventDisplayProcessor ; }


    DEHEventDisplayProcessor() ;

    /** Called at the begin of the job before anything is read.
    * Use to initialize the processor, e.g. book histograms.
    */
    virtual void init() ;

    /** Called for every run.
    */
    virtual void processRunHeader( LCRunHeader* run ) ;

    /** Called for every event - the working horse.
    */
    virtual void processEvent( LCEvent * evt ) ;

    virtual void check( LCEvent * evt ) ;

    /** Called after data processing for clean up.
    */
    virtual void end() ;

    /*
     * callback functions for LCCD
     */
    virtual void conditionsChanged( LCCollection *col ) ;



  protected:

    std::string _colNameEcal;
    std::string _colNameHcal;
    std::string _colNameTC;
    std::string _colNamePS;

    std::string _evtVarColName; //event variables collection name

    std::string _mappingProcessorName;
    std::string _cellNeighboursProcessorName;
    std::string _cellDescriptionProcessorName;
    std::string _calibProcessorName;/**<Calibration Processor Name*/

    std::string _colNameModuleLocation;
    bool _moduleLocationChanged;
    LCCollection* _colModuleLocation;

    int _waitForKeyPressed;
    int _draw;
    bool _drawst;
    int _appendToExistingCED;
    int _portCED;
    bool _doT0selection;
    bool _saveLogFile;
    int _nT0s;
    int _minNHits;
    bool _use_time;
    int _nHits;
    int  st; //Calculated shower start layer
    int MC_st; // Determined true MC shower start layer
    int nLayers;
    std::vector<std::string> _inputCollectionNames;
    std::string _inputCollectionNameDWC;

    int _trackDraw;
    float _moduleMaxZ;
    std::vector<float> _trackOffsets;

    StringVec _T0Vector; /**<Vector containing T0s*/
    std::map<int, std::vector< std::pair<int, int> > > _mapT0s; /**<map for T0s*/

    int _nRun ;
    int _nEvt ;

    const CALICE::Ahc2Mapper *_mapper;

    unsigned int _mapperVersion;

    CALICE::MappedContainer<CALICE::CellDescription>* _cellDescriptions;
    CALICE::MappedContainer<CALICE::CellNeighbours>* _cellNeighbours;
    CALICE::MappedContainer<CALICE::Ahc2Calibrations> *_calibContainer;      /**<mapped container of SiPM calibrations*/

    void chooseColorAndLayer(const float var, unsigned int& color, unsigned int& layer, const bool isTime) const;

    void drawCell(const CALICE::CellDescription* description, const unsigned int color, const unsigned int layer, const bool solid = true) const ;
    void drawCell2(const CALICE::CellDescription* description, const unsigned int color, const unsigned int layer, const bool solid = true) const ;
    void drawHit(const CalorimeterHit* hit, const unsigned int color, const unsigned int layer) const ;
    void drawStartLayer(int st, int MC_st, int nLayers) ; // Function to draw shower start layer blue and MC true shower start layer red

    bool isT0event(LCEvent *evt);
    void drawModule(int module_type, double module_center_pos[3]);
    void drawDetectorDEH();
    // void drawEcalEvent(LCEvent *evt);
    // void drawHcalEvent(LCEvent *evt);
    // void drawPSEvent(LCEvent *evt);
    // void drawTCEvent(LCEvent *evt);
    void drawEvent(LCCollection *col);
    void drawTrack(LCCollection *colDWC);

  } ;

}

#endif
