#ifndef Ahc2TimeCalibrator_hh
#define Ahc2TimeCalibrator_hh 1

#include <map>
#include <tuple>

#include "lcio.h"
#include "marlin/Processor.h"
#include "IMPL/CalorimeterHitImpl.h"
// #include "UTIL/LCRelationNavigator.h"



/* CALICE Header */
#include "EUDAQBlock2016.hh"
#include "LabviewBlock2.hh"
#include "Mapper.hh"
#include "MappedContainer.hh"
#include "Ahc2Mapper.hh"
//#include "AhcAmplitude.hh"
#include "Ahc2CalibrationsProcessor.hh"
//#include "AhcTempProvider.hh"


namespace CALICE {
  /**
  * Processor that does the SiPM calibration. The calibration is done according to the formula:
  * \f$E_{calibrated}=f_{saturation}((E_{raw}-pedestal) \cdot IC/gain) \cdot gain/IC/MIP\f$
  *
  * Please note:
  *  - this processor does the calibration for both data and Monte Carlo, based on the type of the input collection
  *    ("LCGenericObject" for data, and "CalorimeterHit" for Monte Carlo);
  *  - for noise creation, the saturation correction is disabled (doSaturationCorrection=false),
  *    as well as the ZeroSuppression (ZeroSuppression = false)
  *  - for Monte Carlo, the pedestal subtraction is disabled (PedestalSubtraction=false)
  *
  * @par processor parameters
  * <table>
  * <tr><td> steering file parameter name </td><td> description </td></tr>
  * <tr><td><b><em> InputCollectionName  </em></b></td><td> name of the input collection, with energy in ADC counts</td></tr>
  * <tr><td><b><em> OutputCollectionName </em></b></td><td> name of the output collection, with energy in MIPs</td></tr>
  * <tr><td><b><em> MappingProcessorName </em></b></td><td> name of the mapping processor that provides the necessary Mapper class</td></tr>
  * <tr><td><b><em> Ahc2CalibrationsProcessorName </em></b></td><td> name of the processor which provides the SiPM calibrations</td></tr>
  * <tr><td><b><em> SiPMTemperatureProcessorName </em></b></td><td> name of the processor which provides the SiPM temperature</td></tr>
  * <tr><td><b><em> PedestalSubtraction </em></b></td><td> Flag to enable/disable pedestal subtraction</td></tr>
  * <tr><td><b><em> ZeroSuppression </em></b></td><td> Flag to enable/disable zero suppression (intention to apply the MIP cut)</td></tr>
  * <tr><td><b><em> MipCut </em></b></td><td> Value of the MIP cut (default: 0.4 MIPs)</td></tr>
  * <tr><td><b><em> doMipConversion </em></b></td><td> Flag to enable/disable MIP Calibration</td></tr>
  * <tr><td><b><em> doMipTemperatureCorrection </em></b></td><td> Flag to enable/disable temperature correction of the MIP</td></tr>
  * <tr><td><b><em> doGainTemperatureCorrection </em></b></td><td> Flag to enable/disable temperature correction of the gain</td></tr>
  * <tr><td><b><em> doSaturationCorrection </em></b></td><td> Flag to enable/disable the saturation correction</td></tr>
  * <tr><td><b><em> doTimeConversion </em></b></td><td> Flag to enable/disable the TDC Calibration</td></tr>
  * <tr><td><b><em> doErrorCalculation </em></b></td><td> Flag to enable/disable error calculation</td></tr>
  * <tr><td><b><em> filterDeadCells </em></b></td><td> Flag to enable/disable the filtering of dead cells</td></tr>
  * <tr><td><b><em> filterDefaultCells </em></b></td><td> Flag to enable/disable the filtering of default dead cells</td></tr>
  * </table>
  *
  * @author cgraf@mpp.mpg.de
  * @version 0.1
  * @date January 2018
  */

  class Ahc2TimeCalibrator: public marlin::Processor {
  public:
      struct Hit {
          int BXID = 0;
          int MemoryCell = 0;
          int CycleNr = 0;
          int HitBit = 0;
          int GainBit = 0;
          int ModuleNr = 0;   // Which module (1-40 for big prototype)
          int ChipNr = 0;     // Which chip on the module (1-16 for 4-HBU layers)
          int ChipID = 0;     // Chip identifier
          int ModuleID = 0;   // encoded Module identifier
          int Channel = 0;    // Which channel of the chip (1-36)
          short ADC = 0;
          short TDC = 0;

          float timeReference = 0;
      };

      struct CalibValue {
          float value = 0;
          float error = 0;
          int status = 0;
      };

    /*Return a new instance of this processor
    */
    Ahc2TimeCalibrator *newProcessor()
    {
      return new Ahc2TimeCalibrator;
    }

    /*Default constructor
    */
    Ahc2TimeCalibrator();

    /*Destructor
    */
    ~Ahc2TimeCalibrator(){};

    /*Initialise variables, if needed
    */
    virtual void init();

    /*Process event (the working horse)
    @param evt event to be processed
    */
    virtual void processEvent(LCEvent *evt);

    /*Function called after all events have been processed, for cleanup
    */
    virtual void end();

  protected:


    void FillContainer(LCEvent *evt);

    Hit ReadLabviewBlock(const LabviewBlock2& block);
    Hit ReadEUDAQBlock(const EUDAQBlock2016& block, int channel);

    void ProcessHit(Hit* hit);

    void FitCalibration();
    std::pair<float,float> calculateSlope(int moduleNr, int chipNr, int refMemCell);
    void WriteSlopes(std::string fname);
    void WriteOffsets(std::string fname);
    void WriteNonLinearity(std::string fname);
    void WriteTimeWalk(std::string fname);

  protected:

    // ModuleNr, ChipNr, channel(0..36), memCell(0..15), bxID(0,1,2), v_referenceTimes, v_Hits
    // while channel 36 is the sum of all channels, memCell 0 is the sum of all memCells
    // and bxID 2 is the sum of both bxIDs
    // std::map<int, std::map<int, std::map<int, std::map<int, std::map<int, std::vector<std::pair<double, Hit&> > > > > > > _sortedHitContainer;
    std::map<int, std::map<int, std::map<int, std::map<int, std::map<int, std::vector<std::pair<float, short> > > > > > > _sortedHitContainer;

    std::map<int, std::map<int, std::map<int, std::map<int, std::map<int, CalibValue > > > > >_m_calibration_slopes;
    std::map<int, std::map<int, std::map<int, std::map<int, std::map<int, CalibValue > > > > >_m_calibration_offsets;
    std::map<int, std::map<int, std::map<int, std::map<int, std::map<int, CalibValue > > > > >_m_calibration_nonLin_A;
    std::map<int, std::map<int, std::map<int, std::map<int, std::map<int, CalibValue > > > > >_m_calibration_nonLin_B;
    std::map<int, std::map<int, std::map<int, std::map<int, std::map<int, CalibValue > > > > >_m_calibration_nonLin_C;
    std::map<int, std::map<int, std::map<int, std::map<int, std::map<int, CalibValue > > > > >_m_calibration_timeWalk_A;
    std::map<int, std::map<int, std::map<int, std::map<int, std::map<int, CalibValue > > > > >_m_calibration_timeWalk_B;
    std::map<int, std::map<int, std::map<int, std::map<int, std::map<int, CalibValue > > > > >_m_calibration_timeWalk_C;

    int _nChannels;

    double _tdcError; //TDC
    double _timeReferenceError; //ns

    std::string _inputColName;                /**<name of the input collection*/
    std::string _ahcHitOutputColName;         /**<name of the output AHC hit collection*/
    std::string _mappingProcessorName;        /**<name of the processor which provides the mapping*/
    std::string _Ahc2HardwareConnectionName;
    std::string _temperatureProcessorName;    /**<name of the processor which provides the SiPM temperature*/
    std::string _BIFCollectionName;    /**<name of the processor which provides the SiPM temperature*/
    int _BIFTriggerInputSource;    /*Input source of the trigger that is used as a time reference in the BIF*/
    std::string _referenceTimeType;

    std::string _outputFileName_timeSlopes;
    std::string _outputFileName_timeOffsets;
    std::string _outputFileName_timeNonLinearity;
    std::string _outputFileName_timeWalk;

    bool _skipFirstMemoryCell;

    int _minHitsFit;
    int _maxHitsFit;

    std::string _cellDescriptionProcessorName; /**<name of the processor which provides the cells description*/
    MappedContainer<CellDescription>*   _cellDescriptions; /**<mapped container of cells description*/

    const Mapper* _mapper; /**<the mapper*/

    MappedContainer<SimpleValue>*       _temperatureContainer;/**<mapped container of cells temperature*/

    bool _newdataformat;               /**<flag for the new data format in EUDAQ*/
    bool _isFirstEvent; /**<flag to switch to DATA/MC at the first event, the following events should be the same. */

    MappedContainer<CalorimeterHitImpl> *_HitContainer;     /**<mapped container of AHCAL cells*/
    std::map<int, std::pair<int, int> > _HardwareConnnectionContainer;/**<map containing relationship between ChipID and Module/ChipNb*/

    int _iEvt = 0;

};//end of class Ahc2TimeCalibrator

}//end of namespace CALICE
#endif
