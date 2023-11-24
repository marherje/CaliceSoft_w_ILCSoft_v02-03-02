#ifndef TRACKVALIDATION_HH
#define TRACKVALIDATION_HH 1

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
using namespace lcio;
using namespace marlin;

namespace CALICE
{

  class TrackVariables {
	public:
		/** Constructor with member initialization*/
		TrackVariables() {
			cogx_event = cogy_event = cogz_event = cogx_layer1 = cogy_layer1 = trackx = tracky = beamgunpositionx = beamgunpositiony = endpointpositionx = endpointpositiony = endpointpositionz = x_hit1_layer1 = x_hit2_layer1 = x_hit3_layer1 = x_hit4_layer1 = x_hit5_layer1  = y_hit1_layer1 = y_hit2_layer1 = y_hit3_layer1 = y_hit4_layer1 = y_hit5_layer1 = -10000.;
      x_hit6_layer1 = x_hit7_layer1 = x_hit8_layer1 = x_hit9_layer1 = x_hit10_layer1  = y_hit6_layer1 = y_hit7_layer1 = y_hit8_layer1 = y_hit9_layer1 = y_hit10_layer1 = -10000.;
      x_hit11_layer1 = x_hit12_layer1 = x_hit13_layer1 = x_hit14_layer1 = x_hit15_layer1  = y_hit11_layer1 = y_hit12_layer1 = y_hit13_layer1 = y_hit14_layer1 = y_hit15_layer1 = -10000.;
			nHits_event = nHits_layer1 = -10000;
      energy_primary_z = energy_leading_daughter_z = -10000.;

		}

		/** Default destructor*/
		~TrackVariables() {}

		  int nHits_event; //Number of hits in event
	    float cogx_event; // center of gravity x event
	    float cogy_event; // center of gravity y event
	    float cogz_event; // center of gravity z event

      int nHits_layer1; //Number of hits in layer1
	    float cogx_layer1; // center of gravity x layer1
	    float cogy_layer1; // center of gravity y layer1

      float x_hit1_layer1; // X Position of hit 1 in layer 1
      float x_hit2_layer1; // X Position of hit 2 in layer 1
      float x_hit3_layer1; // X Position of hit 3 in layer 1
      float x_hit4_layer1; // X Position of hit 4 in layer 1
      float x_hit5_layer1; // X Position of hit 5 in layer 1
      float x_hit6_layer1; // X Position of hit 6 in layer 1
      float x_hit7_layer1; // X Position of hit 7 in layer 1
      float x_hit8_layer1; // X Position of hit 8 in layer 1
      float x_hit9_layer1; // X Position of hit 9 in layer 1
      float x_hit10_layer1; // X Position of hit 10 in layer 1
      float x_hit11_layer1; // X Position of hit 11 in layer 1
      float x_hit12_layer1; // X Position of hit 12 in layer 1
      float x_hit13_layer1; // X Position of hit 13 in layer 1
      float x_hit14_layer1; // X Position of hit 14 in layer 1
      float x_hit15_layer1; // X Position of hit 15 in layer 1

      float y_hit1_layer1; // Y Position of hit 1 in layer 1
      float y_hit2_layer1; // Y Position of hit 2 in layer 1
      float y_hit3_layer1; // Y Position of hit 3 in layer 1
      float y_hit4_layer1; // Y Position of hit 4 in layer 1
      float y_hit5_layer1; // Y Position of hit 5 in layer 1
      float y_hit6_layer1; // Y Position of hit 6 in layer 1
      float y_hit7_layer1; // Y Position of hit 7 in layer 1
      float y_hit8_layer1; // Y Position of hit 8 in layer 1
      float y_hit9_layer1; // Y Position of hit 9 in layer 1
      float y_hit10_layer1; // Y Position of hit 10 in layer 1
      float y_hit11_layer1; // Y Position of hit 11 in layer 1
      float y_hit12_layer1; // Y Position of hit 12 in layer 1
      float y_hit13_layer1; // Y Position of hit 13 in layer 1
      float y_hit14_layer1; // Y Position of hit 14 in layer 1
      float y_hit15_layer1; // Y Position of hit 15 in layer 1

      float trackx; //x position of track at calorimeter frontface z = 0
      float tracky; //y position of track at calorimeter frontface z = 0

      float beamgunpositionx; // x position of MC beam gun
      float beamgunpositiony; // y position of MC beam gun

	    float endpointpositionx; // x position of primary MC particle endpoint
      float endpointpositiony; // y position of primary MC particle endpoint
      float endpointpositionz; // z position of primary MC particle endpoint

      float energy_primary_z; //Energy of Primary MC Particle at Endpoint
      float energy_leading_daughter_z; // Energy of leading daughter particle
	};


  class  TrackValidationProcessor : public Processor {

  public:
    virtual Processor* newProcessor() { return new TrackValidationProcessor; }

    //Constructor
    TrackValidationProcessor() ;

    //Destructor
    ~TrackValidationProcessor() {};

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

  int nHits; //number of hits in event
  float cogx, cogy, cogz; //center of gravity in event
  int nhitslayer1; //number of hits in layer 1
  float cogxlayer1, cogylayer1; //center of gravity in layer 1
  float hitx1_layer1, hitx2_layer1, hitx3_layer1, hitx4_layer1, hitx5_layer1, hitx6_layer1, hitx7_layer1, hitx8_layer1, hitx9_layer1, hitx10_layer1, hitx11_layer1, hitx12_layer1, hitx13_layer1, hitx14_layer1, hitx15_layer1; //X Position of hits in layer 1
  float hity1_layer1, hity2_layer1, hity3_layer1, hity4_layer1, hity5_layer1, hity6_layer1, hity7_layer1, hity8_layer1, hity9_layer1, hity10_layer1, hity11_layer1, hity12_layer1, hity13_layer1, hity14_layer1, hity15_layer1; //Y Position of hits in layer 1

  vector<float> hitx_vector; //Vector for X positions of hits in layer 1
  vector<float> hity_vector; //Vector for Y positions of hits in layer 1

  int ntracks; //Number of tracks in DWC collection
  float segX; // x position of track at calorimeter front face
  float segY; // y position of track at calorimeter front face
  float slpX; // x slope of track
  float slpY; // y slope of track

  double beamgunx; //x position of MC beam gun
  double beamguny; //y position of MC beam gun

  float endpointx; //x position of primary mc particle endpoint
  float endpointy; //y position of primary mc particle endpoint
  float endpointz; //z position of primary mc particle endpoint

  float energy_primary_z; //Energy of Primary MC Particle at Endpoint
  float energy_daughter_z; //Energy of highest energy daughter MC Particle
  float mass_daughter; // Daughter MC Particle Mass
  float energy_leading_z; // Energy of leading daughter particle

  TrackVariables TrackVar; // Track variables for RootTree
  TFile* outputFile; //Output Rootfile with hardness parameters
  TTree *tracktree; //Root Tree for track parameters

  protected:

  std::string _evtVarColName; //event variables collection name
  std::string _layVarColName; //layer variables collection name
  std::string _hitInColName; //HCAL calorimeter hits collection name
  std::string _MCParticleColName; //MC particle collection name
  std::string _DWCColName; //DWC collection name

  float _xoffset; // Track offset X (calirated for data, for MC = 0)
  float _yoffset; // Track offset Y (calirated for data, for MC = 0)

  int _nRun ; /**<run number*/
  int _nEvt ; /**<evt number*/

  std::string _rootoutput; //Path Root output file
  bool _isMC; //Flag if Input SLCIO file contains MCParticle collection

  };


}


#endif
