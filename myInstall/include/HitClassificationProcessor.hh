#ifndef HitClassificationProcessor_HH
#define HitClassificationProcessor_HH 1

#include "marlin/Processor.h"
#include "lcio.h"
#include "CellDescription.hh"
#include "MappedContainer.hh"

#include <IMPL/LCCollectionVec.h>

using namespace lcio ;
using namespace marlin ;

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

    class HitClassificationProcessor : public Processor {

  public:
    virtual Processor* newProcessor() { return new HitClassificationProcessor; }

    //Constructor
    HitClassificationProcessor() ;

    //Destructor
    ~HitClassificationProcessor() {};

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

  protected:
      std::string _hitInColName; // input hit collection name
      std::string _hitRelationsColName; // input hit relations collection name
      std::string _noDetHitOutColName;
      std::string _detHitOutColName;
      std::string _clusterHitOutColName;
      std::string _trackCandHitOutColName;
      CALICE::MappedContainer<CALICE::CellDescription>* _cellDescriptions;

      int _nRun ; /**<run number*/
      int _nEvt ; /**<evt number */
    };
  }
  #endif
