#ifndef DWCBlock_h
#define DWCBlock_h 1

//lcio headers
#include "lcio.h"
#include "UTIL/LCFixedObject.h"

#define DWCNINT 0
#define DWCNFLOAT 4
#define DWCNDOUBLE 0

using namespace lcio ;

namespace CALICE {

  class DWCBlock ;

  /**
   * Class for the DWC track information.
   * @author L.Linghui @ University of Tokyo
   * @date Aug. 2018
   * Created for 2018 testbeams DWC
   */
  class DWCBlock : public LCFixedObject<DWCNINT,DWCNFLOAT,DWCNDOUBLE> {

  public:

    /** Constructor
     */
    DWCBlock() {};

    DWCBlock(LCObject *obj) : LCFixedObject(obj) {}

    /** Convenient constructor */
    DWCBlock(float segmentX, float segmentY, float slopeX, float slopeY) {

      obj()->setFloatVal( 0 ,  segmentX );
      obj()->setFloatVal( 1 ,  segmentY );
      obj()->setFloatVal( 2 ,  slopeX );
      obj()->setFloatVal( 3 ,  slopeY );

    }

    /** Destructor
     */
    virtual ~DWCBlock() {};

    /** Convenient print method
     */
    void print(  std::ostream& os, int ) ;

    /** Set Segments */
    void setSegmentX(int segmentX) {
      obj()->setFloatVal( 0 ,  segmentX );
    }
    void setSegmentY(int segmentY) {
      obj()->setFloatVal( 1 ,  segmentY );
    }

    /** Set Slopes */
    void setSlopeX(int slopeX) {
      obj()->setFloatVal( 2 ,  slopeX );
    }
    void setSlopeY(int slopeY) {
      obj()->setFloatVal( 3 ,  slopeY );
    }

    // -------- need to implement abstract methods from LCGenericObject

    /** Get Segments of the Track */
    const float getSegmentX() const {
      return getFloatVal(0);
    }
    const float getSegmentY() const {
      return getFloatVal(1);
    }

    /** Get Slopes of the Track */
    const float getSlopeX() const {
      return getFloatVal(2);
    }
    const float getSlopeY() const {
      return getFloatVal(3);
    }

    /** Return the type of the class
     */
    const std::string getTypeName() const {
      return "DWCBlock";
    }

    /** Return a brief description of the data members
     */
    const std::string getDataDescription() const {
      return "f:segmentX; f:segmentY; f:slopeX; f:slopeY";
    }

  };//end class

}//end namespace
#endif
