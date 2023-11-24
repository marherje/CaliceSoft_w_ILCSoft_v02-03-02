#ifndef STDVARIABLESPROCESSOR_HH
#define STDVARIABLESPROCESSOR_HH 1

#include "marlin/Processor.h"
#include "lcio.h"
#include "ConditionsChangeDelegator.hh"
#include "MappedContainer.hh"
#include "CellDescription.hh"

#include "EVENT/LCRelation.h"
#include "IMPL/LCRelationImpl.h"
#include <IMPL/LCGenericObjectImpl.h>
#include <IMPL/LCCollectionVec.h>
#include "lccd/IConditionsChangeListener.hh"



using namespace lcio ;
using namespace marlin ;

namespace CALICE
{
/**
  * @brief Processor calculating standard hit and event variables for further
  * analyses
  * calculations moved from HitWriteEngine (CaliceSoft pre-v04-11)@
  *
  * @author vladimir.bocharnikov@desy.de
  * @version 1.0
  * @date August 2018
  */

  class HitVariablesHelper {
  public:
    /** Constructor with member initialization*/
    HitVariablesHelper() {
      x = y = z = e = ed = r = cs = 0.0;
      i = j = k = cID = 0;
    }
    /** Default destructor*/
    ~HitVariablesHelper() { }

    float x;  /** x coordinate of hit*/
    float y;  /** y coordinate of hit*/
    float z;  /** z coordinate of hit*/

    int i;  //I coordinate of hit
    int j;  //J coordinate of hit
    int k;  //K coordinate of hit

    int cID; //hit cell ID

    float e;  /** Hit energy in MIP*/
    float ed; //hit energy density
    float r;  //distance of hit from XYCoG
    float cs;  /** Cell size in mm for track error estimate*/

  };

  /** Auxiliary class to keep layer data*/
  class LayerVariablesHelper {
  public:
    /** Constructor with member initialization*/
    LayerVariablesHelper() {
      nh = 0; emip = xcog = ycog = icog = jcog = edlay = rl = rlEw = icogGeom = jcogGeom = 0.0;
      vl.reserve(50);
    }
    /** Destructor with vector cleaning*/
    ~LayerVariablesHelper() {vl.clear(); }
    std::vector<HitVariablesHelper*> vl;
    int nh;     // number of hits
    float emip; // mips in layer
    float xcog;
    float ycog;
    float icog;
    float jcog;
    float icogGeom;
    float jcogGeom;
    float edlay;
    float rl; //shower radius in layer
    float rlEw;
  };

  class StdVariablesProcessor : public Processor, public lccd::IConditionsChangeListener {

  public:
    virtual Processor* newProcessor() { return new StdVariablesProcessor; }

    //Constructor
    StdVariablesProcessor() ;

    //Destructor
    ~StdVariablesProcessor() {};

    //Initialise
    virtual void init() ;

    //Process header
    virtual void processRunHeader( LCRunHeader* run ) ;

    //Process event (the working horse)
    virtual void processEvent( LCEvent * evt ) ;

    //Check
    virtual void check( LCEvent * evt ) ;

    //End of processing
    virtual void end() ;

    //Print Parameters
    virtual void printParameters();

    //Nlayers from DB
    virtual void conditionsChanged( LCCollection *col ) ;

  private:
    //const void StdVariablesProcessor::getNlayers(LCCollection *mdcol);

    int   ievt;
    unsigned int nHits;
    int _nHits;
    float eSum;
    float cogX;
    float cogY;
    float cogZ;
    float lradius;
    float radius;
    float radiusEw;

    unsigned int nLayers;
    int _nLayers;

    float energySum;
    float energyDensity;
    float energyPerLayer;

    int nHitsPerLayer;
    float cogXPerLayer;
    float cogYPerLayer;
    float radiusPerLayer;
    float radiusEwPerLayer;

    int hitCellID;
    int hitI;
    int hitJ;
    int hitK;
    float hitX;
    float hitY;
    float hitZ;
    float hitEnergy;
    float hitRadius;
    float hitEnergyDensity;

    int   cellSize;

    float ampl;
    float time;
    int   type;
    float ampl_GeV;
    float esum_5Layer;
    int   nhits_5Layer;
    float cogIJeSum;
    float cogI;
    float cogJ;
    int   nIJHits;
    float cogIGeom;
    float cogJGeom;

    float esum_all5Layer;
    float cogx5;
    float cogy5;
    float cogz5;

    float frac22;

  protected:
    std::string _hitInColName; //<input collection name
    std::string _hitOutColName; //<output hit collection name
    std::string _evtvarColName; //<output evnt collection name
    std::string _layvarColName;
    std::string _hitvarColName;
    std::string _layerVar2CalHitColName;
    std::string _calHit2HitVarColName;

    std::string _colNameModuleLocation;
    std::string _cellDescriptionProcessorName;
    CALICE::MappedContainer<CALICE::CellDescription>* _cellDescriptions;
    bool _moduleLocationChanged;
    LCCollection* _colModuleLocation;

    //const CALICE::Ahc2Mapper *_mapper;

    //CALICE::MappedContainer<CALICE::CellDescription>* _cellDescriptions;

    int _MIP2GeVFlag; //< Input Flag if MIP to GeV Conversion (0 - No, 1 - Yes) from Event Parameters
    float _MIP2GeVFactor; //< Input Sampling Factor MIP 2 GeV Conversion from Event Parameters

    int _firstLayerK;

    int _nRun ; /**<run number*/
    int _nEvt ; /**<evt number*/
  };
}
#endif
