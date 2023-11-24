#ifndef __RunOffsetValue_hh__
#define __RunOffsetValue_hh__ 1

#include "UTIL/LCFixedObject.h"
#include "EVENT/LCObject.h"
#include <string>

namespace CALICE{

  /**  @brief  Class to store float value, its error, and status flag plus
   *           integer index in LCIO
   *
   *    Adapted from SimpleValue.hh
   *
   *   This class provides an interface to store four numbers inside an LCIO
   *   object:
   *   - an integer identifier, e.g. the run number 
   *   - a int value, e.g. an offset
   *   - an integer status flag, e.g. to tell default from measured constants
   *
   *   @author cgraf@mpp.mpg.de
   *   @date   January 2019
   */
  class RunOffsetValue : public UTIL::LCFixedObject<3, 0, 0> {
  public:
    /**  Empty constructor
     */
    RunOffsetValue(){}

    /**  Constructor with initial values
     */
    RunOffsetValue( const int run, const int val, const int stat ){
      obj()->setIntVal( 0, run );
      obj()->setIntVal( 1, val );
      obj()->setIntVal( 2, stat );
    }

    /**  Constructor from LCObject
     */
    RunOffsetValue( EVENT::LCObject* obj ) : UTIL::LCFixedObject<3,0,0>( obj ){
    }


    /**  Destructor
     */
    ~RunOffsetValue(){
    }

    /**  Return run number
     */
    int getRunNumber() const {
      return getIntVal( 0 );
    }

    /**  Return the value
     */
    float getValue() const {
      return getIntVal( 1 );
    }

    /**  Return the status
     */
    int getStatus() const {
      return getIntVal( 2 );
    }

    /**  set index identifier
     */
    void setRunNumber(const int run) {
      obj()->setIntVal( 0, run );
    }

    /** set the value
     */
    void setValue(const int value) {
      obj()->setIntVal( 1, value );
    }

    /**  set the status
     */
    void setStatus(const int status) {
      obj()->setIntVal( 2, status );
    }

    /**  Implementation of LCGenericObject::getTypeName
     */
    virtual const std::string getTypeName() const {
      return "RunOffsetValue";
    }

    /**  Implementation of LCGenericObject::getDataDescription
     */
    virtual const std::string getDataDescription() const {
      return "i:run,i:value,i:status";
    }

  };  // class RunOffsetValue

}  // namespace CALICE

#endif
