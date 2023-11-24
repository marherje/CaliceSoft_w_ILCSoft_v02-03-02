#ifndef SplitCollectionProcessor_hh
#define SplitCollectionProcessor_hh 1

//#include <marlin/DataSourceProcessor.h>
#include "marlin/Processor.h"

#include "EUDAQBlock2016.hh"
#include "Ahc2HardwareConnection.hh"

#include <sstream>
#include <map>

using namespace marlin ;

namespace CALICE {

  /** Processor used to split the EUDAQ Collection into
  * 3 Collections for the May/June 2018 testbeam
  */

  class SplitCollectionProcessor : public Processor {

  public:

    /** Implementation of new Processor
    * returns pointer to processor
    */
    virtual Processor*  newProcessor() { return new SplitCollectionProcessor;}
    SplitCollectionProcessor() ;
    ~SplitCollectionProcessor() ;

    /** Creates events with LCGenrealObject collections from the EUDAQ input file and
    *  calls all active processors' processEvent() and processRunHeader Method.
    */
    void processEvent( LCEvent* evt ) ;

    /** init method */
    virtual void init() ;

    void FillContainer(LCEvent *evt);
    void FillOutputCollections(int ChipID, EUDAQBlock2016* lBlock, LCCollectionVec*& colPreShower, LCCollectionVec*& colHCAL, LCCollectionVec*& colTC);

    /** end method */
    virtual void end() ;

    /** print parameters */
    void printParameters();

  protected:

    // INPUT collections
    std::string _inputColName;

    // OUTPUT collections
    std::string _outputColNamePreShower;
    std::string _outputColNameHCAL;
    std::string _outputColNameTC;

    //Hardware connection used to separate hit collections
    std::string _Ahc2HardwareConnectionName;
    std::map<int,int> _HardwareConnnectionContainer;/**<map containing relationship between ChipID and Module/ChipNb*/

    std::string _detectorTypeName;

    bool _isFirstEvent;

    /** The run number */
    int _runNumber;

  private:
  };

} // end namespace marlin

#endif /* SplitCollectionProcessor_hh */
