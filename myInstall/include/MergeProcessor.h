#ifndef MergeProcessor_h
#define MergeProcessor_h 1

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <fstream>
#include <numeric>


#include <marlin/Processor.h>
#include "lcio.h"
#include <IO/LCReader.h>
#include <EVENT/LCCollection.h>
#include <EVENT/CalorimeterHit.h>
#include "MergedHitOrigin.hh"
#include <IMPL/LCCollectionVec.h>
#include "MappedContainer.hh"
#include "CellDescription.hh"

using namespace marlin;
using namespace lcio;
using namespace std;

namespace CALICE {
  class MergeProcessor : public Processor {
  public:
    virtual Processor* newProcessor() { return new MergeProcessor; }

    MergeProcessor();
    ~MergeProcessor() {};

    virtual void init();
    virtual void processRunHeader( LCRunHeader * run );
    virtual void processEvent( LCEvent * evt );
    virtual void check( LCEvent * evt );
    virtual void end();
    virtual void printParameters();

    void merge(LCCollection * src1, LCCollection * src2, LCCollectionVec * dest);
    EVENT::LCEvent* readNextEvent( int event_index );

  private:
    std::string _cellDescriptionProcessorName{};
    MappedContainer<CellDescription>* _cellDescriptions;

    LCReader * _MergefileReader{};
    unsigned int _nAvailableEvents{0};
    unsigned int _nAvailableRuns{0};

    std::string _hitOriginColName{};
    LCCollectionVec * _hitOriginSrc;
    LCCollectionVec * _hitOriginDest;
    std::map<long long, int> _hitOriginSrcMap;
    std::map<long long, MergedHitOrigin*> _hitOriginDestMap;

    std::string _mergeFileName{};
    std::string _evtVarColName{}; //Name of Event Variable Collection both Input files
    LCCollection* inEvtVarCol{}; //Event Variable Collection of First File
    LCCollection* inEvtVarCol2{}; //Event Variable Collection of Second File
    std::string _copyevtVarColName{}; //Name of Event Variable Collection from file 2 to be saved as copy in file 1
    std::vector<int> _eventMap{};
    std::vector<int> _runMap{};
    int eventmap_length{}; //Length of eventMap vector
    int runmap_length{}; //Length of runMap vecto
    std::vector<std::string> _mergeCollections{};
    std::vector< std::pair< std::string, std::pair<std::string, std::string> > > _mergeCollectionMap{};

    bool _allowOverhang{false};
    bool _zeroSuppression{true};
    bool _twoParticleMode{true};
    bool _allacceptanceMode{true};
    bool _subsequentMode{true};
    bool _cheatHitTypeMode{false};
    float _mipCut{0};

    float _radialDistanceInput; //Input Radial Shower Distance (mm)
    float _radialDistanceRange; //Input Radial Shower Distance Range +-_radialDistanceRange (mm)
    int _maxAttemps; //Number of maximum attempts of combining event pair, to reject far off r events

    std::vector<int> _shiftSrc1, _shiftSrc2;

    float cogx_file1, cogy_file1; //Event center of gravity of current event in file 1
    float cogx_file2, cogy_file2; //Event center of gravity of current event in file 2
    float radial_distance; //Current radial distance of event pair

    bool overlay_match; //Bool indicating if overlay distance criterium is fullfilled

    int counter_overlaid_hits; //Counting overlaid hits of an event pair
    vector<int> vector_overlaid_hits; //Vector holding #overlaid hits of events
    float mean_overlaid_hits; //Mean overlaid hits of all event pairs

    int counter_below_mip_hits; //Counting number of initial hits below 0.5 MIP threshold of an event pair
    vector<int> vector_below_mip_hits; //Vector holding #below MIP hits of events
    float mean_below_mip_hits; //Mean of initial hits below 0.5 MIP threshold of all event pairs

    int counter_new_hits; //Counting overlaid hits (both initially below 0.5 MIP) reaching 0.5 MIP threshold of an event pair
    vector<int> vector_new_hits; //Vector holding #new 0.5 MIP hits of events
    float mean_new_hits; // Mean of counter_new_hits over event pairs

    int counter_cut_hits; //Counting overlaid hits not reaching 0.5 MIP threshold of an event pair
    vector<int> vector_cut_hits; //Vector holding #hits not reaching 0.5 MIP of event pairs
    float mean_cut_hits; // Mean of counter_cut_hits over event pairs

    float temp_neutral_energy_fraction; //Temporary fraction of neutral hadron energy for overlaid hit
    vector<float> temp_vector_neutral_energy_fraction; //Vector holding temporary fractions of neutral hadron energy for overlaid hits of event
    float event_overlaid_hit_neutral_fraction; //Temporary mean fraction of neutral hadron energy for overlaid hits of an event
    vector<float> vector_overlaid_hit_neutral_fraction; //Vector holding fractions of neutral hadron energy for overlaid hits of events
    float mean_overlaid_hit_neutral_fraction; // Mean fraction of neutral hadron energy for overlaid hits over all events

    float temp_charged_energy_fraction; //Temporary fraction of charged hadron energy for overlaid hit
    vector<float> temp_vector_charged_energy_fraction; //Vector holding temporary fractions of charged hadron energy for overlaid hits of event
    float event_overlaid_hit_charged_fraction; //Temporary mean fraction of charged hadron energy for overlaid hits of an event
    vector<float> vector_overlaid_hit_charged_fraction; //Vector holding fractions of charged hadron energy for overlaid hits of events
    float mean_overlaid_hit_charged_fraction; // Mean fraction of charged hadron energy for overlaid hits over all events

    int counter_events_overlay; //Counter for events where at least 1 hit is overlaid
    int counter_events_overlay_criterium; //Counter for events with fullfilled overlay radial distance criterium
    int counter_skipped_file1_events; // Counter for Events not matched to events of file 2 after attempt limit
    int counter_skipped_file2_events; // Counter for file 2 events not matched to events of file 1 during attempt check
    int _nRun{0};
    int _nEvt{0};
    unsigned int _nEvt_mergefile{0};
  };

}

#endif
