#ifndef AHC2MCTRUTHHARDSHOWERSTART_HH_
#define AHC2MCTRUTHHARDSHOWERSTART_HH_

/** @brief Processor to get MCTruth Shower Start only for "Hard" interactions.
Other events get rejected.
Hardness criterium defined by energy of secondary particles.
Output of Root file with hardness criteria of events
MC GEANT4 Plugin used:  to flag first hadronic interactions and get daughters etc.

Based on idea by O. Hartbricht

Created by Daniel Heuchel, DESY
Date April 2019
*/

//Marlin includes
#include "marlin/Processor.h"
#include "lcio.h"
#include <EVENT/LCEvent.h>
#include <UTIL/LCTOOLS.h>
#include <EVENT/LCCollection.h>
#include "UTIL/CellIDDecoder.h"
#include <EVENT/CalorimeterHit.h>

//CALICE includes
#include "EventVariables.hh"


//Root includes
#include "TFile.h"
#include "TTree.h"
#include "TROOT.h"


using namespace std;
using namespace lcio;
using namespace marlin;

#define NLAYER 100

namespace CALICE
{

  class HardVariables {
	public:
		/** Constructor with member initialization*/
		HardVariables() {
			esum_secondaries = elead = hardness = 0.;
			nsecondaries = mctruthlayer = 0;
		}

		/** Default destructor*/
		~HardVariables() {}

		  int nsecondaries; //Numver of secondary particles after hard interaction
	    float esum_secondaries; // esum of secondaries without lead hadron
	    float elead; // energy of leading hadron
	    float hardness; // hardness = esum_secondaries - elead
	    unsigned int mctruthlayer; // MC truth shower start layer
	};




class Ahc2MCTruthHardShowerStart : public Processor
{
public:

  virtual Processor*  newProcessor() { return new Ahc2MCTruthHardShowerStart; }

  /** Default constructor.
  */
  Ahc2MCTruthHardShowerStart();

  /** Default destructor.
  */
  ~Ahc2MCTruthHardShowerStart(){};

  /** Marlin init() function.
  */
  virtual void init();

  /** Marlin processRunHeader() function.
  */
  virtual void processRunHeader(LCEvent *evt);

  /** Marlin processEvent() function.
  */
  virtual void processEvent(LCEvent *evt);

  /** Marlin check() function.
  */
  virtual void check( LCEvent * evt );

  /** Marlin end() function.
  */
  virtual void end();

  void printParameters();


private:

  HardVariables Hardset; // Variables for RootTree
  TFile* outputFile; //Output Rootfile with hardness parameters
  TTree *Hardtree; //Root Tree for Hard Parameters

  double mom_primary_z; //Momentum of primary particle in Z direction

protected:

  int _nEvt;
  int _nRun;
  unsigned int NLayer; //Number of layers for testbeam
  float posLayer[NLAYER] = {0.};

  std::string _evtVarColName; //event variables collection name
  std::string _hitInColName; //Input collection name
  std::string _MCParticleColName; //MC collection
  bool _isTBMay2018; //Switch for TB May 2018 geometry
  bool _isTBJune2018; //Switch for TB June 2018 geometry
  float _hardnesscut; //Interaction energy hardness defined by sum(Edaughters) - Eleadinghadron

  //MCParticle variables
  int _numberOfMCparticles;
  int _MCpid;
  float _MCdecayPos[3]; //Coordinates of flagged first hadronnic interaction
  float _hardness; //Interaction energy hardness defined by sum(Edaughters) - Eleadinghadron
  int _nsecondary; // number of secondary particles
  unsigned int _MClayer; //MC Truth Shower Start Layer
  float st_z; //MC Truth Shower Start Z Coordinate
  float _esum_secondaries; // sum(Edaughters)
  float _elead; //Eleadinghadron
  double mass_primary; // Mass primary particle
  double mom_daughter_z; // Kinetic energy Z of daughter particle
  double mass_daughter; // Mass daughter particle

  bool hasKminus1; //Check for Z Position Finder
  unsigned int layer; // Layer Iterator to find Z Position

  std::string _RootHardoutput; //Path Root output file
};


}
#endif /* AHC2MCTRUTHSHOWERSTART_HH_ */
