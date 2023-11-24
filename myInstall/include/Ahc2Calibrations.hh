#ifndef Ahc2Calibrations_hh
#define Ahc2Calibrations_hh

#include "SimpleValue.hh"
#include "SimpleValueVector.hh"
#include "LinearFitCompound.hh"
#include "CellDescription.hh"
#include "SaturationParameters.hh"

namespace CALICE {

/**
 * storing all informations necessary to calibrate a HBU SiPM read channel
 *
 * This class is meant as central holder of all necessary informations to calibrate a HBU SiPM.
 * Currently, following informations are stored:
 * \li \c MIP calibration in form of a \b LinearFitResult
 * \li \c gain calibration in form of a \b LinearFitResult
 * \li \c pedestal calibration in form of a \b SimpleValue
 * \li \c temperature calibration in form of a \b SimpleValue
 * \li \c inter \c calibration in form of a \b SimpleValue
 * \li \c inter \c calibration Physics Calib in form of a \b SimpleValue
 * \li \c saturation \c parameters \c in form of a \b SaturationParameters
 * \li \c time slopes \c parameters \c in form of a \b SimpleValueVector
 * \li \c time pedestal \c parameters \c in form of a \b SimpleValueVector
 * \li \c status in form of an \b integer
 *
 * @author Shaojun.lu@desy.de
 * @version 0.1
 * @date Feburary 2013
 */

class Ahc2Calibrations {

public:
Ahc2Calibrations();

Ahc2Calibrations(LinearFitCompound* MIP,
                 LinearFitCompound* gain,
                 SimpleValue* pedestal,
                 SimpleValueVector* pedestalMemoryCellOffset,
                 SimpleValue* lowGainPedestal,
                 SimpleValueVector* lowGainPedestalMemoryCellOffset,
                 SimpleValue* interCalibration,
                 SimpleValue* interCalibrationPhysicsCalib,
                 SimpleValue* temperature,
                 SaturationParameters *saturation,
                 SimpleValueVector *timeSlopesCalibration,
                 SimpleValueVector *timeOffsetCalibration,
                 SimpleValueVector *timeOffsetMemCellEvenCalibration,
                 SimpleValueVector *timeOffsetMemCellOddCalibration,

                 SimpleValueVector *timeOffsetMemCellEvenBufferEvenEventEvenCalibration,
                 SimpleValueVector *timeOffsetMemCellOddBufferEvenEventOddCalibration,
                 SimpleValueVector *timeOffsetMemCellEvenBufferOddEventEvenCalibration,
                 SimpleValueVector *timeOffsetMemCellOddBufferOddEventOddCalibration,

                 SimpleValueVector *OccupancyBxidEvenHighGainCalibration,
                 SimpleValueVector *OccupancyBxidEvenLowGainCalibration,
                 SimpleValueVector *OccupancyBxidOddHighGainCalibration,
                 SimpleValueVector *OccupancyBxidOddLowGainCalibration,

                 const int status,
                 const int cellID,
                 const std::string& cellIDEncoding);

~Ahc2Calibrations();

LinearFitCompound*   getMIP()                  const {
	return _MIP;
}
LinearFitCompound*   getGain()                 const {
	return _gain;
}

SimpleValue*       getPedestal()             const {
	return _pedestal;
}
SimpleValueVector*       getPedestalMemoryCellOffset()             const {
	return _pedestalMemoryCellOffset;
}
SimpleValue*       getLowGainPedestal()             const {
	return _lowGainPedestal;
}
SimpleValueVector*       getLowGainPedestalMemoryCellOffset()             const {
	return _lowGainPedestalMemoryCellOffset;
}
SimpleValue*       getInterCalibration()     const {
	return _interCalibration;
}
SimpleValue*       getPhysicsCalibIC()     const {
	return _interCalibrationPhysicsCalib;
}

SimpleValue*       getTemperature()          const {
	return _temperature;
}

SaturationParameters* getSaturation()        const {
	return _saturation;
}

SimpleValueVector* getTimeSlopes() const {
	return _timeSlopesCalibration;
}
SimpleValueVector* getTimeOffset() const {
	return _timeOffsetCalibration;
}
SimpleValueVector* getTimeOffsetMemCellEven() const {
	return _timeOffsetMemCellEvenCalibration;
}
SimpleValueVector* getTimeOffsetMemCellOdd() const {
	return _timeOffsetMemCellOddCalibration;
}




SimpleValueVector* getTimeOffsetMemCellEvenBufferEvenEventEven() const {
	return _timeOffsetMemCellEvenBufferEvenEventEvenCalibration;
}
SimpleValueVector* getTimeOffsetMemCellOddBufferEvenEventOdd() const {
	return _timeOffsetMemCellOddBufferEvenEventOddCalibration;
}
SimpleValueVector* getTimeOffsetMemCellEvenBufferOddEventEven() const {
	return _timeOffsetMemCellEvenBufferOddEventEvenCalibration;
}
SimpleValueVector* getTimeOffsetMemCellOddBufferOddEventOdd() const {
	return _timeOffsetMemCellOddBufferOddEventOddCalibration;
}


SimpleValueVector* getOccupancyBxidEvenHighGain() const {
	return _OccupancyBxidEvenHighGainCalibration;
}
SimpleValueVector* getOccupancyBxidEvenLowGain() const {
	return _OccupancyBxidEvenLowGainCalibration;
}
SimpleValueVector* getOccupancyBxidOddHighGain() const {
	return _OccupancyBxidOddHighGainCalibration;
}
SimpleValueVector* getOccupancyBxidOddLowGain() const {
	return _OccupancyBxidOddLowGainCalibration;
}


int                getStatus()               const {
	return _status;
}

int                getCellID()               const {
	return _cellID;
}

const std::string& getCellIDEncoding()       const {
	return _cellIDEncoding;
}

void setMIP                 (LinearFitCompound* MIP );
void setGain                (LinearFitCompound* gain);

void setPedestal            (SimpleValue*     pedestal);
void setPedestalMemoryCellOffset            (SimpleValueVector*     pedestalMemoryCellOffset);
void setLowGainPedestal            (SimpleValue*    lowGainPedestal);
void setLowGainPedestalMemoryCellOffset            (SimpleValueVector*     lowGainPedestalMemoryCellOffset);
void setInterCalibration    (SimpleValue*     interCalibration);
void setPhysicsCalibIC      (SimpleValue*     interCalibrationPhysicsCalib);

void setTemperature         (SimpleValue*     temperature);

void setSaturation          (SaturationParameters* param);
void setTimeSlopes          (SimpleValueVector* timeSlopes);
void setTimeOffset        (SimpleValueVector* timeOffset);
void setTimeOffsetMemCellEven        (SimpleValueVector* timeOffsetMemCellEven);
void setTimeOffsetMemCellOdd        (SimpleValueVector* timeOffsetMemCellOdd);

void setTimeOffsetMemCellEvenBufferEvenEventEven        (SimpleValueVector* timeOffsetMemCellEvenBufferEvenEventEven);
void setTimeOffsetMemCellOddBufferEvenEventOdd        (SimpleValueVector* timeOffsetMemCellOddBufferEvenEventOdd);
void setTimeOffsetMemCellEvenBufferOddEventEven        (SimpleValueVector* timeOffsetMemCellEvenBufferOddEventEven);
void setTimeOffsetMemCellOddBufferOddEventOdd        (SimpleValueVector* timeOffsetMemCellOddBufferOddEventOdd);

void setOccupancyBxidEvenHighGain(SimpleValueVector* OccupancyBxidEvenHighGain);
void setOccupancyBxidEvenLowGain(SimpleValueVector* OccupancyBxidEvenLowGain);
void setOccupancyBxidOddHighGain(SimpleValueVector* OccupancyBxidOddHighGain);
void setOccupancyBxidOddLowGain(SimpleValueVector* OccupancyBxidOddLowGain);



void setStatus              (const int status);

void setCellID              (const int cellID);
void setCellIDEncoding      (const std::string& encoding);

private:
LinearFitCompound *_gain;
LinearFitCompound *_MIP;

SimpleValue     *_pedestal;
SimpleValueVector     *_pedestalMemoryCellOffset;
SimpleValue     *_lowGainPedestal;
SimpleValueVector     *_lowGainPedestalMemoryCellOffset;
SimpleValue     *_interCalibration;
SimpleValue     *_interCalibrationPhysicsCalib;

SimpleValue     *_temperature;

SaturationParameters *_saturation;
SimpleValueVector* _timeSlopesCalibration;
SimpleValueVector* _timeOffsetCalibration;
SimpleValueVector* _timeOffsetMemCellEvenCalibration;
SimpleValueVector* _timeOffsetMemCellOddCalibration;


SimpleValueVector* _timeOffsetMemCellEvenBufferEvenEventEvenCalibration;
SimpleValueVector* _timeOffsetMemCellOddBufferEvenEventOddCalibration;
SimpleValueVector* _timeOffsetMemCellEvenBufferOddEventEvenCalibration;
SimpleValueVector* _timeOffsetMemCellOddBufferOddEventOddCalibration;

SimpleValueVector* _OccupancyBxidEvenHighGainCalibration;
SimpleValueVector* _OccupancyBxidEvenLowGainCalibration;
SimpleValueVector* _OccupancyBxidOddHighGainCalibration;
SimpleValueVector* _OccupancyBxidOddLowGainCalibration;


int _status;

int _cellID;
std::string _cellIDEncoding;
};

} // end namespace CALICE

#endif
