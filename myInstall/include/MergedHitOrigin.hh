#ifndef MergedHitOrigin_h
#define MergedHitOrigin_h 1

//lcio headers
#include "lcio.h"
#include "UTIL/LCFixedObject.h"

#define HITORIGINNINT 3
#define HITORIGINNFLOAT 1
#define HITORIGINNDOUBLE 0

using namespace lcio ;

namespace CALICE {

  /**
   * Class for indicating origin of hits in merged event.
   * @author L.Linghui @ University of Tokyo
   * @date Feb. 2021
   * Created for 2018 testbeams
   */
  class MergedHitOrigin : public LCFixedObject<HITORIGINNINT,HITORIGINNFLOAT,HITORIGINNDOUBLE> {

  public:

    /** Constructor
     */
    MergedHitOrigin() {};

    MergedHitOrigin(LCObject *obj) : LCFixedObject(obj) {}

    /** Convenient constructor */
    MergedHitOrigin(int cellID0, int cellID1, int hitOrigin, float energyFraction) {

      obj()->setIntVal( 0 ,  cellID0 );
      obj()->setIntVal( 1 ,  cellID1 );
      obj()->setIntVal( 2 ,  hitOrigin );
      obj()->setFloatVal( 0 ,  energyFraction );

    }

    /** Destructor
     */
    virtual ~MergedHitOrigin() {};

    /** Convenient print method
     */
    void print(  std::ostream& os, int ) ;

    /** Set CellIDs */
    void setCellID0(int cellID0) {
      obj()->setIntVal( 0 ,  cellID0 );
    }
    void setCellID1(int cellID1) {
      obj()->setIntVal( 1 ,  cellID1 );
    }
    void setCellID(long long cellID) {
      obj()->setIntVal( 0 , (int) (cellID>>32) );
      obj()->setIntVal( 1 , (int) (cellID & 0xFFFFFFFF) );
    }

    /** Set Hit Origin */
    void setHitOrigin(int hitOrigin) {
      obj()->setIntVal( 2 ,  hitOrigin );
    }

    /** Set Energy Fraction */
    void setEnergyFraction(float energyFraction) {
      obj()->setFloatVal( 0 ,  energyFraction );
    }

    // -------- need to implement abstract methods from LCGenericObject

    /** Get CellIDs */
    const int getCellID0() const {
      return getIntVal(0);
    }
    const int getCellID1() const {
      return getIntVal(1);
    }
    const long long getCellID() {
      long long cellID = ((long long)getIntVal(0) << 32) | getIntVal(1) ;
      return cellID;
    }

    /** Get Hit Origin */
    const int getHitOrigin() const {
      return getIntVal(2);
    }

    /** Get Energy Fraction */
    const float getEnergyFraction() const {
      return getFloatVal(0);
    }

    /** Return the type of the class
     */
    const std::string getTypeName() const {
      return "MergedHitOrigin";
    }

    /** Return a brief description of the data members
     */
    const std::string getDataDescription() const {
      return "i:cellID0; i:cellID1; i:hitOrigin; f:energyFraction";
    }

  };//end class

}//end namespace
#endif
