#ifndef ClusterCounter_HH
#define ClusterCounter_HH 1

#include "marlin/Processor.h"
#include "lcio.h"
#include "CellDescription.hh"
#include "MappedContainer.hh"
#include "math.h"
#include "algorithm"

#include "TFile.h"
#include "TTree.h"
#include "TROOT.h"

#include <IMPL/LCCollectionVec.h>
#include "EVENT/CalorimeterHit.h"
#include "EVENT/LCRelation.h"
#include "IMPL/LCRelationImpl.h"
#include "EVENT/Cluster.h"
#include "IMPL/ClusterImpl.h"

using namespace lcio ;
using namespace marlin ;
using namespace std;

namespace CALICE
{
  /**
  * @brief Processor finds detached hits in event and gives 2 collections:
  * Detached hits and event w/o detached hits
  *
  * @author vladimir.bocharnikov@desy.de
  * @version 1.0
  * @date December 2018
  */

    class ClusterCounter : public Processor {

  public:
    virtual Processor* newProcessor() { return new ClusterCounter; }

    //Constructor
    ClusterCounter() ;

    //Destructor
    ~ClusterCounter() {};

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

    // function finds neighbours of seed point <I,J> in _hitmap and moves
    // them to seed map, returning number of moved elements;
    int group2DCluster(std::map<std::array<int, 2>, CalorimeterHit*> *_hitmap,
                              std::map<std::array<int, 2>, CalorimeterHit*> *_seedmap);

    // function finds neighbours of seed point <I,J,K> in _hitmap and moves
    // them to _seedmap, returning number of moved elements;
    int group3DCluster(std::map<std::array<int, 3>, CalorimeterHit*> *_hitmap,
                              std::map<std::array<int, 3>, CalorimeterHit*> *_seedmap);

    // function calculates number of neighbours of seed point <I,J,K> in _map
    CalorimeterHitVec getNeighbours3D(std::array<int, 3> _seed,
                                      std::map<std::array<int, 3>, CalorimeterHit*> *_map,
                                      int _volHalfSize);
    // function returns a map of track candidate hits with corresponding approx track vector
    void getTrackCandidates(std::map<std::array<int, 3>, CalorimeterHit*> *_hitmap,
                            std::map<const float*, CalorimeterHit*>* _trackCandidates,
                            std::vector<const float*>* _candpositions);

    // comparison function to sort the track candidates map
    static bool comparison (const float* pos1, const float* pos2)
    {
      if (pos1[2] == pos2[2] && sqrt(pow(pos1[0],2) + pow(pos1[1],2)) != sqrt(pow(pos2[0],2) + pow(pos2[1],2)))
        return sqrt(pow(pos1[0],2) + pow(pos1[1],2)) < sqrt(pow(pos2[0],2) + pow(pos2[1],2));
      else {
        return pos1[2] < pos2[2];
      }
    }

    float getDistBtwPositions(const float* vec1, const float* vec2);

    float getCosBtwVectors(const float* vec1, const float* vec2);

    // function returns minimal cos btw hit to hit and track vectors
    float getTrackingMinCos(const float* _checkvec);

    int getClosestNeighbour(const float* _seed, std::vector<const float*>* _candpositions);

    int groupTrack(const float* seedpos,
                   std::vector<const float*>* _candpositions,
                   std::vector<const float*>* _trackvec,
                   int _maxgap, int startindex);

    std::array<float, 3> get2DClusterCoG (std::map<std::array<int, 2>, CalorimeterHit*> *_map);

    void add2DMapToCluster(IMPL::ClusterImpl* _cluster, std::map<std::array<int, 2>, CalorimeterHit*> *_map);

    void add3DMapToCluster(IMPL::ClusterImpl* _cluster, std::map<std::array<int, 3>, CalorimeterHit*> *_map);

  private:
    float evtcog[3];
    TFile* outputFile;
    TTree* TrackTree;


  protected:
      std::string _evtVarColName;
      std::string _layVarColName; // input hit collection name
      std::string _layer2hitRelationsColName; // - input layer variables to
                                              // hit relations collection name
      std::string _hit2hitVarRelationsColName;// - input hit to hit variables
                                              // relations collection name
      std::string _2DClusterOutColName; // - output 2D cluster collection name
      std::string _3DClusterOutColName; // - output 3D cluster collection name
      std::string _L2COutRelColName;

      bool _writeRootFile;
      std::string _RootOutput;

      int _minHitstIn2DCluster, _minHitstIn3DCluster;
      int _KmaxFor3DCluster;
      int _volumeTsize, _volumeLsize;
      bool _filterHits;

      std::array<float, 3> CoG;
      int n2DClusters;
      int n3DClusters;
      int _nRun ; /**<run number*/
      int _nEvt ; /**<evt number */
      float cosToBeam = -2.; //cos of track to z axis
      std::array<float, 3> trackdr;
      std::array<float, 3> mu;
      float w_x, w_y;
      float denom_w;
      int nTrackHits;
      int trackNr;
      float trEsum;
      std::vector<float> hitEnergies;

    };
  }
  #endif
