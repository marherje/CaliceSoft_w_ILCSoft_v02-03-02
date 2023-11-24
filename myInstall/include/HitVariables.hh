#ifndef HitVariables_h
#define HitVariables_h 1

#include "lcio.h"
#include "UTIL/LCFixedObject.h"

#define NHINT 6
#define NHFLOAT 2
#define NHDOUBLE 0

using namespace lcio ;
using namespace std;

namespace CALICE {

  /* Class for the standard hit variables, used later for
   * common and user analysis
   * @author V. Bocharnikov DESY Hamburg
   * @date Aug 2018
   */

  class HitVariables : public UTIL::LCFixedObject<NHINT,NHFLOAT,NHDOUBLE> {

  public:

    HitVariables(){};
    HitVariables(int hitI, int hitJ, int hitK, int cellSize, float radius, float energyDensity)
    {
      obj()->setIntVal(0, hitI);
      obj()->setIntVal(1, hitJ);
      obj()->setIntVal(2, hitK);
      obj()->setIntVal(3, cellSize);
      obj()->setIntVal(4, 0); // variable is used  for hit classification
      obj()->setIntVal(5, 0);

      obj()->setFloatVal(0, radius);
      obj()->setFloatVal(1, energyDensity);
    }

    /** 'Copy constructor' needed to interpret LCCollection read from file/database.
     */
    HitVariables(LCObject* obj) : UTIL::LCFixedObject<NHINT,NHFLOAT,NHDOUBLE>(obj) { }

    /** Important for memory handling*/
    virtual ~HitVariables() { /* no op*/  }

    int getHitI() const{
      return getIntVal(0);
    }

    int getHitJ() const{
      return getIntVal(1);
    }

    int getLayerNumber() const{
      return getIntVal(2);
    }

    int getCellsize() const{
      return getIntVal(3);
    }

    float getHitRadius() const{
      return getFloatVal(0);
    }

    float getHitEnergyDensity() const{
      return getFloatVal(1);
    }

    void setDetachedFlag() {
      obj()->setIntVal(4, 1);
    }

    void setClusterFlag() {
      obj()->setIntVal(4, 2);
    }

    void setTrackCandidateFlag() {
      obj()->setIntVal(4, 3);
    }

    bool isClassified() {
      if (getIntVal(4) == 0) return false;
      else return true;
    }

    bool isDetached() {
      if (getIntVal(4) == 0) {
        streamlog_out(ERROR)
          << "Hit was not classified. Check your steering." << endl;
        return false;
      }
      if (getIntVal(4) == 1) return true;
      else return false;
    }

    bool isInCluster() {
      if (getIntVal(4) == 0) {
        streamlog_out(ERROR)
          << "Hit was not classified. Check your steering." << endl;
      }
      if (getIntVal(4) == 2) return true;
      else return false;
    }

    bool isTrackHitCandidate() {
      if (getIntVal(4) == 0) {
        streamlog_out(ERROR)
          << "Hit was not classified. Check your steering." << endl;
      }
      if (getIntVal(4) == 3) return true;
      else return false;
    }

    int getRelatedTrackNumber() const{
      return getIntVal(5);
    }
    void setTrackNumber(int _n) {
      obj()->setIntVal(5, _n);
    }

    /** Convenient print method
         */
    void print(  std::ostream& os, int ) ;


    // -------- need to implement abstract methods from LCGenericObject

    /** Return the type of the class
     */
    virtual const std::string getTypeName() const {
      return "HitVariables" ;
    }

    /** Return a brief description of the data members
     */
    virtual const std::string getDataDescription() const {
      return "i:hitI; i:hitJ; i:hitK; i:cellSize; i:hitClass; f:hitRadius; f:hitEnergy" ;
    }

  }; // class
}

#endif
