#ifndef FIND_START_AND_PRIMARY_TRACK_H
#define FIND_START_AND_PRIMARY_TRACK_H 1

// STD
#include <iostream>
#include <cmath>
#include <vector>

/** @brief  First interaction layer and primary track finder
for CALICE calorimeter configurations:
   CERN 2007 (Fe-AHCAL), 2011 (W-AHCAL)
   FNAL 2009 (Fe-AHCAL)
ECAL(optional,30 layers) + HCAL(38 layers) + TCMT(16 layers)

@author M.V. Chadeeva
@ date December 2016
*/
// version 2.4

using namespace std;

/** Detector parameters */
const int ELAY1 = 0; /** Number of layers in 1st ECAL segment*/
const int ELAY2 = 0; /** Number of layers in 1st+2nd ECAL segments*/
const int ELAY  = 0; /** Number of layers in ECAL*/
const int HLAY  = 38; /** Number of layers in HCAL*/
const int EHLAY = 38; /** Number of layers in ECAL+HCAL*/
const int HTAIL = 0; /** Number of first layer in HCAL with lower granularity*/
const int TCAL1 = 12;  /** Number of layers in 1st TCMT segment*/
const int NLAYER = 52;

/** Constant parameters for Track Finder*/
const float s1ECAL = 10.0; /** Cell size in ECAL*/
const float s3HCAL = 30.0; /** Cell size in central part of HCAL*/
const float s6HCAL = 60.0; /** Cell size outside the central part of HCAL*/
const float s12HCAL = 120.0; /** Cell size on the HCAL edges*/
const float b3 = 360; /** The boundary of central part of HCAL*/
const float b6 = 360; /** The boundary of 6x6 part of HCAL*/
const float SQ2  = 1.5*0.5; // >sqrt(2)*0.5 = half of square diagonal;
const float SQ1  = SQ2*s1ECAL; /**Half diagonal of ECAL cells*/
const float SQ3  = SQ2*s3HCAL; /**Half diagonal of HCAL 3x3 cells*/
const float SQ6  = SQ2*s6HCAL; /**Half diagonal of HCAL 6x6cells*/
const float SQ12 = SQ2*s12HCAL;/**Half diagonal of HCAL 12x12 cells*/
//const float minDistForParallelInHcal = 35.;/** Criteria for parallel tracks*/
const float minDistForParallel = 35.;
//const float minDistForLongParallelInHcal = 25;
const float maxTrackHitDispersion = 25.;
const float longTrackLength = 8;
const float MEANMIP = 1.4; // mean mip per layer (cell)

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
  std::vector<CHit*> vl;
  int nh;     // number of hits
  int max1;  // max number of neighbors from the same layer per hit for two hits
  int max2;  // max number of neighbors from the same and previous layers per hit for two hits
  int max3;  // max number of neighbors in the surrounding volume per hit for two hits
  float emip; // mips in layer
};

class Point2D {
 public:
  Point2D(float ini) { x = ini; y = ini; }
  float x;
  float y;
};

class FindStartAndPrimaryTrack {
 public:
  /** Constructor*/
  FindStartAndPrimaryTrack(float, int, float);
  /** Destructor*/
  ~FindStartAndPrimaryTrack() { };
  //-------------------------------------------------------------
  /** Calculates and returns distance between two hits in XY-plane*/
  float distXY( float, float, float, float );
  //-------------------------------------------------------------
  /** Finds and returns the number of layer where shower started
      using the following criteria:
      1. Moving average sum of MIPs inside the  window = 10 layers
      for two successive layers is greater than miplim value.
      2. Number of hits in two successive layers is greater than
      hitlim value.
      They are energy dependent and similar for ECAL and HCAL.*/
  int getStartLayerMip( std::vector<CLayer>, int, int, float, int );
  //-------------------------------------------------------------
  /** Finds and returns the number of layer where shower started
      using criterion based on max # of (3D) neighbors per hit
      for two hits in layer. */
  int getStartLayerNei( std::vector<CLayer>, int );
  //-------------------------------------------------------------
  /** Finds hits belonging to primary track taking in account
      the earlier found shower starting layer. The "nearest neighbour"
      criteria is used. Maximum distance parameters are defined taking
      in account the cell size.
      First parameter is the number of shower starting layer.
      Second parameter is an array with of objects CLayer
      that contain layer parameters.
      0- no track found; 1- single primary track found; >1- parallel tracks */
  int FindTrack( int, float, float, bool, int, int, int, int, CLayer*, bool );
  //-------------------------------------------------------------
  /** True for isolated hits.
      Calculates number of neighbors per hit:
      1) in the same layer;
      2) in the previous and same layers;
      3) in the previous, same and next layers. */
  bool getNumberOfNeighbors( CHit, std::vector<CLayer>, int* );
  //-------------------------------------------------------------
  /** Calculates sums for two hits in the given layer of the following values:
      1) maximum number of neighbors per hit in volume;
      2) maximum number of neighbors in the same layer;
      3) maximum number of neighbors in the same and previous layers. */
  void getMaxNeighbors( CLayer, int* );
  //-------------------------------------------------------------
  Point2D* getTrackXY();
  //-------------------------------------------------------------
  std::vector<CHit*> getFinalTrack() { return intrack; };
  //-------------------------------------------------------------
  void clearTrack(){ intrack.clear(); };
  //-------------------------------------------------------------

  private:
    int absTrackLength;
    float relTrackLength;
    std::vector<CHit*> intrack;  /** Vector with pointers to primary track hits*/
    float addNeiLimit1;
    float addNeiLimit2;

};
#endif
