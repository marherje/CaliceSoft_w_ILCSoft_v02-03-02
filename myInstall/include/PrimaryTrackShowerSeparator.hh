#ifndef PRIMARY_TRACK_FINDER_HH
#define PRIMARY_TRACK_FINDER_HH 1

//ROOT
#include "TROOT.h"
#include "TPad.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TTree.h"
// STD
#include <cmath>
#include <vector>
//CALICE
#include <marlin/Processor.h>
#include <EVENT/LCEvent.h>
#include <UTIL/LCTOOLS.h>
#include <EVENT/LCCollection.h>
#include <EVENT/LCIntVec.h>
#include <IMPL/LCCollectionVec.h>
#include <EVENT/CalorimeterHit.h>
#include <IMPL/CalorimeterHitImpl.h>
#include <EVENT/LCParameters.h>
#include <collection_names.hh>
#include <TriggerBits.hh>
#include <CellIndex.hh>
#include <HcalCellIndex.hh>
#include <IMPL/LCGenericObjectImpl.h>
#include <IMPL/LCFlagImpl.h>
#include "lcio.h"
#include "CellDescription.hh"
#include "MappedContainer.hh"

#include <IMPL/LCCollectionVec.h>

//********************************
#include "layers.h"

//********************************
//=======================================================================

using namespace std;

namespace CALICE
{

//=======================================================================
/*
Primary Track and Shower Separator
version 1.00
November 2019
Uses CalorimeterHit collections data and EventVariables Shower Start Layer
to separate primary track and shower cluster hits in individual collections of class CalorimeterHit.
Detector configuration for CERN 2018 runs

@author D. Heuchel
*/

class PrimaryTrackShowerSeparator : public marlin::Processor {
public:
  /** Default constructor*/
    PrimaryTrackShowerSeparator();
  /** Default destructor*/
   ~PrimaryTrackShowerSeparator() {};

    PrimaryTrackShowerSeparator* newProcessor(){ return new PrimaryTrackShowerSeparator(); }

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

  int   st;              /**< Shower Start Layer */
  float cogx, cogy; //Event Center of Gravity in X and Y


//------------------------------------
protected:

  // Collections IN
  std::string _hitInColName; //input collection name
  std::string _evtVarColName; //event variables collection name

  float _cogradius; //Radius around cogx and cogy of event to remove primary track hits
  float _upperenergy; //Upper energy for hit for primary track collection
  bool _stminus1; // Flag for sorting hits at st or st-1 and layers behind into shower collection

  // Collections OUT
  std::string _prtrackColName; //Output Track Collection of Type Hits
  std::string _startColName; //Output Shower Cluster Collection of Type Hits

  CALICE::MappedContainer<CALICE::CellDescription>* _cellDescriptions;


  int _nRun ; /**<run number*/
  int _nEvt ; /**<evt number*/

};

}
#endif
