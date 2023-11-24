#ifndef EventVariables_h
#define EventVariables_h 1

#include "lcio.h"
#include "UTIL/LCFixedObject.h"

#define NEINT 5
#define NEFLOAT 20
#define NEDOUBLE 0

using namespace lcio ;

namespace CALICE {

  /* Class for the standard event variables, used later for
   * common and user analysis
   * @author V. Bocharnikov DESY Hamburg
   * @date Aug 2018
   */

  class EventVariables : public UTIL::LCFixedObject<NEINT,NEFLOAT,NEDOUBLE> {

  public:

    EventVariables() {};
    EventVariables(int nHits, int nLayers, float energySum, float energyDensity,
        float radius, float radiusEw, float cogX, float cogY, float cogZ,
        float nhits5l, float esum5l, float cogX5l, float cogY5l, float cogZ5l,
        float cogI, float cogJ, float cogIgeom, float cogJgeom, float fr25)
    {
      obj()->setIntVal(0, nHits);
      obj()->setIntVal(1, nLayers);
      obj()->setIntVal(2, -100); // variable used later for shower start layer
      obj()->setIntVal(3, -100); // variable used later for MC true shower start layer
      obj()->setIntVal(4, -100); // variable used later for MIP (0) or GeV flag (1)

      obj()->setFloatVal(0, energySum);
      obj()->setFloatVal(1, energyDensity);
      obj()->setFloatVal(2, radius);
      obj()->setFloatVal(3, radiusEw);
      obj()->setFloatVal(4, cogX);
      obj()->setFloatVal(5, cogY);
      obj()->setFloatVal(6, cogZ);
      obj()->setFloatVal(7, nhits5l);
      obj()->setFloatVal(8, esum5l);
      obj()->setFloatVal(9, cogX5l);
      obj()->setFloatVal(10, cogY5l);
      obj()->setFloatVal(11, cogZ5l);
      obj()->setFloatVal(12, cogI);
      obj()->setFloatVal(13, cogJ);
      obj()->setFloatVal(14, cogIgeom);
      obj()->setFloatVal(15, cogJgeom);
      obj()->setFloatVal(16, fr25);
      obj()->setFloatVal(17, -100); // variable used later for shower start position in z
      obj()->setFloatVal(18, -100); // variable used later for MC true shower start position in z
      obj()->setFloatVal(19, -100); // variable used later for input MIP to GeV factor
    }

    /** 'Copy constructor' needed to interpret LCCollection read from file/database.
     */
    EventVariables(LCObject* obj) : UTIL::LCFixedObject<NEINT,NEFLOAT,NEDOUBLE>(obj) { }

    /** Important for memory handling*/
    virtual ~EventVariables() { /* no op*/  }

     /** get the CycleNr.
     */
    int getNHits() const {
      return getIntVal(0);
    }

    int getNLayers() const {
      return getIntVal(1);
    }

    float getEnergySum() const{
      return getFloatVal(0);
    }

    float getEventEnergyDensity() const{
      return getFloatVal(1);
    }

    float getEventRadius() const{
      return getFloatVal(2);
    }

    float getEventRadiusEw() const{
      return getFloatVal(3);
    }

    float getEventCoGx() const{
      return getFloatVal(4);
    }

    float getEventCoGy() const{
      return getFloatVal(5);
    }

    float getEventCoGz() const{
      return getFloatVal(6);
    }

    float get5layerNHits() const{
      return getFloatVal(7);
    }

    float get5layerEnergySum() const{
      return getFloatVal(8);
    }

    float get5layerCoGx() const{
      return getFloatVal(9);
    }

    float get5layerCoGy() const{
      return getFloatVal(10);
    }

    float get5layerCoGz() const{
      return getFloatVal(11);
    }

    float getEventCoGI() const{
      return getFloatVal(12);
    }

    float getEventCoGJ() const{
      return getFloatVal(13);
    }

    float getEventCoGIGeom() const{
      return getFloatVal(14);
    }

    float getEventCoGJGeom() const{
      return getFloatVal(15);
    }

    float getFraction25layers() const{
      return getFloatVal(16);
    }

    void setShowerStart(int _st) {
      obj()->setIntVal(2, _st);
    }

    int getShowerStart() const{
      return getIntVal(2);
    }
    void setShowerStart_z(float _st_z) {
      obj()->setFloatVal(17, _st_z);
    }
    float getShowerStart_z() const{
      return getFloatVal(17);
    }
    void setMCTrueShowerStart(int _MCst) {
      obj()->setIntVal(3, _MCst);
    }
    int getMCTrueShowerStart() const{
      return getIntVal(3);
    }
    void setMCTrueShowerStart_z(float _MCst_z) {
      obj()->setFloatVal(18, _MCst_z);
    }
    float getMCTrueShowerStart_z() const{
      return getFloatVal(18);
    }
    void setMIP2GeVFlag(int _MIP2GeVFlag) {
      obj()->setIntVal(4, _MIP2GeVFlag);
    }
    int getMIP2GeVFlag() const{
      return getIntVal(4);
    }
    void setMIP2GeVFactor(float _MIP2GeVFactor) {
      obj()->setFloatVal(19, _MIP2GeVFactor);
    }
    float getMIP2GeVFactor() const{
      return getFloatVal(19);
    }

    /** Convenient print method
         */
    void print(  std::ostream& os, int ) ;


    // -------- need to implement abstract methods from LCGenericObject

    /** Return the type of the class
     */
    const std::string getTypeName() const {
      return"EventVariables" ;
    }

    /** Return a brief description of the data members
     */
    const std::string getDataDescription() const {
      return "i:CycleNr; i:nHits; i:nLayers; f:energySum; f:energyDensity; f:EventRadius; f:EventRadiusEw; f:CoGx; f:CoGy; f:CoGz; f:nHits5layer; f:eSum5layer; f:cogX5layer; f:cogY5layer; f:cogZ5layer; f:CoGI; f:CoGJ; f:CoGIgeom; f:CoGJgeom;" ;
    }

  }; // class
}

#endif
