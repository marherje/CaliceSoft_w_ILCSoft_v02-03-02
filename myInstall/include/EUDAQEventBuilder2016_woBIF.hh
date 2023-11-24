#ifndef EUDAQEventBuilder2016_woBIF_h
#define EUDAQEventBuilder2016_woBIF_h 1

//#include <marlin/DataSourceProcessor.h>
#include "marlin/Processor.h"

#include <sstream>
#include <map>

using namespace marlin ;

namespace CALICE{
  
  /** Processor for reading the AHCAL EUDAQ SLCIO files.   
   *  It processes the input data to create events with LCIO collections
   *  of the AHCAL EUDAQ SLCIO output (sorted by readout cycles).
   *  Based on F. Gaede's StdHepReader to be found in the marlin package. 
   *  @author: A. Irles (DESY), based on the S. Lu's (DESY Hamburg) LabviewConverter2
   *  @date May 20 2015
   */
  
  class EUDAQEventBuilder2016_woBIF : public Processor {
    
  public:

    /** Implementation of new Processor 
     * returns pointer to processor  
     */
    virtual Processor*  newProcessor() { return new EUDAQEventBuilder2016_woBIF;}
    EUDAQEventBuilder2016_woBIF() ;
    ~EUDAQEventBuilder2016_woBIF() ;

    /** Creates events with LCGenrealObject collections from the EUDAQ input file and
     *  calls all active processors' processEvent() and processRunHeader Method.
     */
    void processEvent( LCEvent* evt ) ;

    /** work on slow control data, ASIC */
    void writeSlowControl() ;

    /** work on slow control data,  Temperature*/
    //void writeTemperature() ;
    
    /** init method */
    virtual void init() ;

    /** end method */
    virtual void end() ;

    /** print parameters */                                                                                                                                                                                         
    void printParameters();
   
  protected:

    // INPUT collections
    std::string _inputColName;
    std::string _inputColNameHodo1;
    std::string _inputColNameHodo2;
    std::string _inputColNameTemp;

    // OUTPUT collections
    std::string _outputColNameECAL;
    std::string _outputColNameHCAL;
    std::string _outputColNameHodo1;
    std::string _outputColNameHodo2;
    std::string _outputColNameTemp;

    std::string _detectorTypeName;

      /** The run number */
    int _runNumber;

    /** The slcio data format. 
     */
    struct rawData {
      int iCyNr;
      int iBxID;
      int iCpID;
      int iEvNr;
      int iChan;
      int iTDC ;
      int iADC ;
      int iHBit;
      int iGBit;
      int iHBit2;
      int iGBit2;
    };

   /** The slcio data format. 
     */
    struct rawData2016 {
      int iCycleNr;
      int iBxID;
      int iEvNr;
      int iCpID;
      int iNChan;
      std::vector<int> iTDC ;
      std::vector<int> iADC ;
    };

    /** The slcio data format for the temperature sensor
     */
    struct rawTemp {
      int iLDANumber;
      int iPortNumber;
      int iT1;
      int iT2;
      int iT3;
      int iT4;
      int iT5;
      int iT6;
      int iTDIF;
      int iTPWR;
    };

   
  private:

   // new event number after reco
    int LcioEventNr;
    // number of discarded events for bad data quality 
    // wrong size packets may introduce errors in the data
    // one of the hints of this is the difference between hit bit and gain bit in 
    // the adc or tdc packet
    int discarded_events;
    int all_events;

  
  // true if the readoutcycle contains temperature information
    bool temperaturecollection_write ;  

  };

  // new event number after reco
  //  int LcioEventNr=0;
  
  // true if the readoutcycle contains temperature information
  //  bool temperaturecollection_write = false;

} // end namespace marlin 

#endif
