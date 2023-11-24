#ifndef EventFilter_h
#define EventFilter_h 1

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <lcio.h>
#include "marlin/Processor.h"

using namespace lcio;

namespace CALICE {


  class EventFilter : public marlin::Processor {

  public:
    EventFilter();
    virtual Processor* newProcessor() {return new EventFilter();}
    virtual void init();
    void processEvent(LCEvent *evt);
    void end();

  protected:
    std::string _dwcColName; //DWC collection name
    std::string _layVarColName; //layer variables collection name
    std::string _evtVarColName; //event variables collection name
    std::string _hitInColName; //HCAL calorimeter hits collection name
    bool _requireTrack; //Flag for requiring at least one track in DWC collection
    bool _requireSingleTrack; //Flag for requiring one track in DWC collection

    bool _requireTrackHitMatchLayer1; //Flag for requiring a track - hit match in layer 1 within r
    bool _requireTrackHitMatchLayer1or2or3; //Flag for requiring a track - hit match in layer 1, 2 or 3 within r
    float _maxr; //Maximum radius for track hit match from tile center (x,y) to projected track position (x,y)
    int _kfirstAHCALlayer; //First AHCAL layer for track-hit match check

    bool _hitinLayer1; //Flag for requiring at least one it in layer 1
    bool _hitinLayer2; //Flag for requiring at least one it in layer 2
    bool _hitinLayer3; //Flag for requiring at least one it in layer 3

    bool _hitinLayer1or2or3; //Flag for requiring at least one it in layer 1 or 2 or 3

    bool _filternoshowering; //Flag for filtering events with shower start not within calorimeter
    bool _apply_showerstartupperlimit; //Flag for filtering events with shower start before specific layer
    int _showerstart_upper_limit; //Shower start upper limit for filtering

    bool _apply_maxE; //Flag for filtering events with maximum energy
    float _maxE; //Maximum energy value for event to be filtered

    bool _apply_gap_rej; // Flag for applying gap rejection for events with track within slab gap
    float _gap_width; // Gap width for gap event rejection. Rejection of events with abs(track x) within track offset (gap center) +- _gap_width

    float _xoffset; // Track offset X (calirated for data, for MC = 0)
    float _yoffset; // Track offset Y (calirated for data, for MC = 0)

  private:
    void checkEvent();
    unsigned _nEvent; //Event survining the Conditions
    unsigned _nEvent_all; //All input Events

  };

}

#endif
