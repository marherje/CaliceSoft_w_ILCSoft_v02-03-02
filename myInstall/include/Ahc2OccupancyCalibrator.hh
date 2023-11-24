#ifndef Ahc2OccupancyCalibrator_hh
#define Ahc2OccupancyCalibrator_hh 1

#include <map>
#include <unordered_map>
#include <tuple>

#include "lcio.h"
#include "marlin/Processor.h"
#include "IMPL/CalorimeterHitImpl.h"
// #include "UTIL/LCRelationNavigator.h"

#include "EVENT/LCIntVec.h"

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


class Ahc2OccupancyCalibrator : public marlin::Processor {
public:


struct CalibValue {
	float curvevalue = 0;
	float curveerror = 0;
	int curvestatus = 0;

	float slopevalue = 0;
	float slopeerror = 0;
	int slopestatus = 0;

	float offsetvalue = 0;
	float offseterror = 0;
	int offsetstatus = 0;
};

/*Return a new instance of this processor
 */
Ahc2OccupancyCalibrator *newProcessor()
{
	return new Ahc2OccupancyCalibrator;
}

/*Default constructor
 */
Ahc2OccupancyCalibrator();

/*Destructor
 */
~Ahc2OccupancyCalibrator(){
};

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


void ProcessHit(CalorimeterHit* hit, int evtBxID);

void FitOccupancy();
void WriteConstants();


protected:

std::map<int, std::map<int,int> > _occupancyPerChip;

std::map<int, std::map<int,std::map<int, std::map<int, std::map<int,std::map<int, std::vector<float> > > > > > >  _sortedHitContainer;

std::map<int, std::map<int, std::map<int, std::map<int, std::map<int,  CalibValue  > > > > >_m_calibration_constants;


int _nChannels;

double _tdcError;     //TDC
double _timeReferenceError;     //ns

std::string _hitInColName;                    /**<name of the input collection*/
std::string _occupancyInColName;
std::string _ahcHitOutputColName;             /**<name of the output AHC hit collection*/
std::string _mappingProcessorName;            /**<name of the processor which provides the mapping*/
std::string _Ahc2HardwareConnectionName;
std::string _temperatureProcessorName;        /**<name of the processor which provides the SiPM temperature*/
std::string _bifColName;        /**<name of the processor which provides the SiPM temperature*/
int _BIFTriggerInputSource;        /*Input source of the trigger that is used as a time reference in the BIF*/

std::string _prefix;

bool _skipFirstMemoryCell;

int _maxOccupancy;

int _minHitsFit;
int _maxHitsFit;

std::string _cellDescriptionProcessorName;     /**<name of the processor which provides the cells description*/
MappedContainer<CellDescription>*   _cellDescriptions;     /**<mapped container of cells description*/

const Ahc2Mapper* _mapper;     /**<the mapper*/

MappedContainer<SimpleValue>*       _temperatureContainer;    /**<mapped container of cells temperature*/

bool _newdataformat;                   /**<flag for the new data format in EUDAQ*/
bool _isFirstEvent;     /**<flag to switch to DATA/MC at the first event, the following events should be the same. */

MappedContainer<CalorimeterHitImpl> *_HitContainer;         /**<mapped container of AHCAL cells*/
std::map<int, std::pair<int, int> > _HardwareConnnectionContainer;    /**<map containing relationship between ChipID and Module/ChipNb*/

int _iEvt = 0;

};//end of class Ahc2OccupancyCalibrator

}//end of namespace CALICE
#endif
