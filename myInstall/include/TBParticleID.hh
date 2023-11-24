#ifndef TB_PARTICLE_ID_H
#define TB_PARTICLE_ID_H 1

#include "TFile.h"
#include "TTree.h"
#include "TROOT.h"
//#include "FindStartAndPrimaryTrack.h"

#include "LightGBM/c_api.h"

/** @brief  Marlin processor for particle ID in AHCAL

@version 1.0
@author V. bocharnikov
@date October 2018
*/

//=============================================================================
// Particle ID for AHCAL test beams in 2018
// CALICE setup:
//      AHCAL @ CERN May 2018     38 Layers
//
//             version 1.0
//             October 2018
//
//      based on the Particle ID for the physics prototype
//      developed by M. Chadeeva
//
//      @author V. Bocharnikov
//=============================================================================

#include "marlin/Processor.h"
#include "lcio.h"

using namespace std;
using namespace lcio ;
using namespace marlin ;

namespace CALICE
{
	class IDVariables {
	public:
		/** Constructor with member initialization*/
		IDVariables() {
			zcog = frac22 = fracCentral = fracCore = radius = eSum = meanEhitAferStart = 0.;
			nHits = st = nShowerHits = nTrackHits = nLastLayers = 0;
		}

		/** Default destructor*/
		~IDVariables() {}

		int nHits;
		float zcog; // Event CoG in z
		float frac22; // fraction of energy in first 25 layers
		float fracCentral; // fraction of energy in central region of shower
		float fracCore; // fraction of energy in the shower core
		float fracTrack; // fraction of energy in the tracks
		float fracDetached; // fraction of energy in the detached hits
		float radius; // event radius
		float eSum; // energy sum
		int st; // shower start layer
		float meanEhitAferStart; // mean hit energy after shower start
		int nTrackHits; // number of hits assigned to tracks
		int nShowerHits; // number of hits after shower start
		int nLastLayers; // number of layers with hits from NLastLayersForMuons
	};

	class IDCuts {
	public:
		/** Constructor with member initialization*/
		IDCuts() {
			zcog_min = zcog_max = frac25_min = radius_min = radius_max = eSum_min = eSum_max = 0.;
			fracCore_min = fracTrack_min = fracTrack_max = fracDet_max = 0.;
			nHits_min = nHits_max = st_min = st_max = 0;
		}
		/** Default destructor*/
		~IDCuts() {}

		int nHits_min;
		int nHits_max;
		int st_min; // min shower start layer
		int st_max; // max shower start layer
		float zcog_min; // min Event CoG in z
		float zcog_max; // max Event CoG in z
		float frac25_min; // min fraction of energy in first 25 layers
		float radius_min; // min event radius
		float radius_max; // max event radius
		float eSum_min; // min energy sum
		float eSum_max; // min energy sum
		float fracCore_min; // min energy frac in shower core
		float fracTrack_min; // min energy fraction in track hits
		float fracTrack_max; //max energy frac in track hits
		float fracDet_max; // max energy frac in detached hits
	};

  class  TBParticleID : public Processor {

  public:
    virtual Processor* newProcessor() { return new  TBParticleID; }

    //Constructor
     TBParticleID() ;

    //Destructor
    ~ TBParticleID() {};

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

		int   ievt;
		int nLayers;
		//int nHits;
		float xcog, ycog;
		IDCuts mu_cuts, ele_cuts;
		bool isMuon = false;
		bool isElectron = false;
		bool isHadron = false;
		bool isEmpty = false;
		bool isMultiParticle = false;
	    	char cutType;
		TFile* outputFile;
		TTree *IDtree, *had_IDtree, *mu_IDtree, *ele_IDtree, *rej_IDtree;

  protected:

		IDVariables IDset;
		int _firstAHCALlayerK;
		bool _applyEventFiltering;
		int _IDMode;
		int _minNhits;
		float _radiusOfCentralRegion; // Radius to calculate central energy fraction
		int _nLastLayersForMuons; // Number of last layers for muon-like event selection
		float _maxZofClusterStart;
		int _nFirstLayers; // number of first layers to calculate clusters spread
		float _maxClusterSpread; //Maximum average cluster spread in first NfirstLayers layers
		bool _writeIDRoot;
		bool _writeCutBasedIDtoEvent;
		bool _manualCuts;
		int _nPrimaryTrackLayers;
		int	_minHitsInPrimaryTrack;

		int _mu_nHits_min;
		int _mu_nHits_max;
		int _mu_st_min; // min shower start layer
		int _mu_st_max; // max shower start layer
		float _mu_zcog_min; // min Event CoG in z
		float _mu_zcog_max; // max Event CoG in z
		float _mu_frac25_min; // min fraction of energy in first 25 layers
		float _mu_radius_min; // min event radius
		float _mu_radius_max; // max event radius
		float _mu_eSum_min; // min energy sum
		float _mu_eSum_max; // min energy sum
		float _mu_fracTrack_min; // min energy fraction in track hits

		int _ele_nHits_min;
		int _ele_nHits_max;
		int _ele_st_min; // min shower start layer
		int _ele_st_max; // max shower start layer
		float _ele_zcog_min; // min Event CoG in z
		float _ele_zcog_max; // max Event CoG in z
		float _ele_frac25_min; // min fraction of energy in first 25 layers
		float _ele_radius_min; // min event radius
		float _ele_radius_max; // max event radius
		float _ele_eSum_min; // min energy sum
	 	float _ele_eSum_max; // min energy sum
		float _ele_fracCore_min; // min energy fraction in shower core
		float _ele_fracDet_max; // max energy fraction in detached hits
		float _ele_fracTrack_max; // max energy fraction in track hits

		//BDT_ID
		BoosterHandle handle;
		double classifier[3];
		bool _applyBDTModel;
		std::string _pathToLightGBMModel;
		int num_iteration;

		// clustering
		int nClusters; //number of elements outside the cone
		//float zclOverlay; // maximum cluster overlay in z projection
		//--------------------------------------------------------------------------

		std::string _hitInColName; //<input collection name
		std::string _evtVarColName; //event variables collection name
		std::string _layVarColName; //layer variables collection name
		std::string _hitVarColName; //hit variables collection name
		std::string _clusterColName;
		std::string _RootIDoutput;

		int _nRun ; /**<run number*/
		int _nEvt ; /**<evt number*/

		bool checkCuts(IDVariables var, IDCuts cuts);

  };
}
#endif
