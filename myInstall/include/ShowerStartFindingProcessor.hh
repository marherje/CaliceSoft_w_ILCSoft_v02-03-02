#ifndef SHOWERSTARTFINDINGPROCESSOR_HH
#define SHOWERSTARTFINDINGPROCESSOR_HH 1

//Standard includes
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <fstream>

/* LCIO includes*/
#include <marlin/Processor.h>
#include "lcio.h"
#include <EVENT/LCEvent.h>
#include <UTIL/LCTOOLS.h>
#include <EVENT/LCCollection.h>
#include <EVENT/CalorimeterHit.h>
#include <marlin/Exceptions.h>
#include "UTIL/LCRelationNavigator.h"
#include "EVENT/Cluster.h"

//CALICE includes
#include "CellIndex.hh"
#include "EventVariables.hh"
#include "LayerVariables.hh"
#include "HitVariables.hh"

//Root includes
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"

using namespace std;
using namespace lcio ;
using namespace marlin ;

/*
------------------------------------------------------------------------------
 * @Processor calculating Shower Start Layer and Position (ToDo) for the latest AHCAL 2018+ Prototypes with Layers >= 38
 * Based on M. Chadeevas developed shower start finding with Window MIP Criteria for physics prototype
 *
 *
 * @author daniel.heuchel@desy.de
 * @version 1.0
 * @date March 2019
 ------------------------------------------------------------------------------
 */


namespace CALICE
{

  /** Auxiliary class to keep hit data*/
  class CHit {
  public:
    /** Constructor with member initialization*/
    CHit() { x = y = z = e = r = c = 0.0; l = 0; n1 = n2 = n3 = 0; nc = -1; }
    /** Default destructor*/
    ~CHit() { }
    int l; /** Layer number*/
    float x;  /** x coordinate of hit*/
    float y;  /** y coordinate of hit*/
    float z;  /** z coordinate of hit*/
    float e;  /** Hit energy in MIP*/
    float r;  /** Criteria for distance between neighbour hits*/
    float c;  /** Cell size in mm for track error estimate*/
    int n1; /** Number of neighbors in the same layer*/
    int n2; /** Number of neighbors in the same and previous layers*/
    int n3; /** Number of neighbors around the hit*/
    int nc; /** Cluster number*/
  };

  /** Auxiliary class to keep layer data*/
  class CLayer {
  public:
    /** Constructor with member initialization*/
    CLayer() { nh = 0; max1 = max2 = max3 = 0; emip = 0.0; vl.reserve(50);  }
    /** Destructor with vector cleaning*/
    ~CLayer() {vl.clear(); }
    std::vector<CHit> vl;
    int nh;     // number of hits
    int max1;  // max number of neighbors from the same layer per hit for two hits
    int max2;  // max number of neighbors from the same and previous layers per hit for two hits
    int max3;  // max number of neighbors in the surrounding volume per hit for two hits
    float emip; // mips in layer
  };



  class  ShowerStartFindingProcessor : public Processor {

  public:
    virtual Processor* newProcessor() { return new ShowerStartFindingProcessor; }

    //Constructor
    ShowerStartFindingProcessor() ;

    //Destructor
    ~ShowerStartFindingProcessor() {};

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


  private:


  float mipLimitBeam; //Energy MIP limit for shower start, calculated from beam energy and _correctionMIPcrit
  int hitLimitBeam; //Hit limit for shower start

  int nLayers; //number of layers
  int nHits; //number of hits in event
  float xcog, ycog, zcog;
  float frac25; // fraction of energy in first 25 layers
  float radius; // event radius
  float eSum; // energy sum

  int st; // shower start layer
  int start; // Start of layer iteration, since layer variables always start from first element. Shift for specific test beam later
  int last_layer; //Last layer in k of testbeam
  float st_z; // Shower Start Z Coordinate
  bool shower; //Shower condition
  float mi0, mi1; //start parameters mip window
  int hi0, hi1; //start parameters hit window
  int w1; //start window for mip and hit check
  int counts; // Counts for the density in Muon Criterium
  int k; // Iterator for Muon Criterium


  protected:

  std::string _hitInColName; //input collection name
  std::string _evtVarColName; //event variables collection name
  std::string _layVarColName; //layer variables collection name
  std::string _hitVarColName; //hit variables collection name

  float _beamEnergy; //energy of particles
  float _correctionMIPcrit; // Tuning Parameter for mip criterium in moving average window
  int _win_mov_av; // Layers of moving average (Default = 10)
  bool _muonCritFlag; //Flag to turn on/off muon criterium
  bool _isTBMay18; //Flag for Testbeam AHCAL SPS Cern 2018 May
  bool _isTBJune18; //Flag for Testbeam AHCAL SPS Cern 2018 June
  bool _Legacy_SSF_Thresholds; //Flag for using Old or New Energy and Hit Tresholds
  float _muonCritThreshold; //Value for Muon Criterium Threshold
  int _MIP2GeVFlag; // MIP2GeV Conversion Flag from EventVariables
  float _MIP2GeVFactor; // MIP2GeV Conversion Factor from EventVariables

  int _nRun ; /**<run number*/
  int _nEvt ; /**<evt number*/

  };
}
#endif
