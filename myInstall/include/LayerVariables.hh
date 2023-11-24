#ifndef LayerVariables_h
#define LayerVariables_h 1

#include "lcio.h"
#include "UTIL/LCFixedObject.h"

#define NLINT 3
#define NLFLOAT 10
#define NLDOUBLE 0

using namespace lcio ;

namespace CALICE {

  /* Class for the standard layer variables, used later for
   * common and user analysis
   * @author V. Bocharnikov DESY Hamburg
   * @date Aug 2018
   */

  class LayerVariables : public UTIL::LCFixedObject<NLINT,NLFLOAT,NLDOUBLE> {

  public:

    LayerVariables() {};
    LayerVariables(int LayerNr, int lnHits, float lenergySum, float lenergyDensity,
        float lradius, float lradiusEw, float lcogX, float lcogY, float lcogI, float lcogJ,
        float lCogIgeom, float lCogJgeom)
    {
      obj()->setIntVal(0, LayerNr);
      obj()->setIntVal(1, lnHits);
      obj()->setIntVal(2, 0);// number of clusters in layer

      obj()->setFloatVal(0, lenergySum);
      obj()->setFloatVal(1, lenergyDensity);
      obj()->setFloatVal(2, lradius);
      obj()->setFloatVal(3, lradiusEw);
      obj()->setFloatVal(4, lcogX);
      obj()->setFloatVal(5, lcogY);
      obj()->setFloatVal(6, lcogI);
      obj()->setFloatVal(7, lcogJ);
      obj()->setFloatVal(8, lCogIgeom);
      obj()->setFloatVal(9, lCogJgeom);
    }

    /** 'Copy constructor' needed to interpret LCCollection read from file/database.
     */
    LayerVariables(LCObject* obj) : UTIL::LCFixedObject<NLINT,NLFLOAT,NLDOUBLE>(obj) { }

    /** Important for memory handling*/
    virtual ~LayerVariables() { /* no op*/  }

     /** get the CycleNr.
     */
    int getLayerNumber() const {
      return getIntVal(0);
    }

    int getLayerNHits() const {
      return getIntVal(1);
    }

    int getNumberOfClusters() const {
      return getIntVal(2);
    }

    void setNumberOfClusters(int nClusters) {
      obj()->setIntVal(2, nClusters);
    }

    float getLayerEnergySum() const{
      return getFloatVal(0);
    }

    float getLayerEnergyDensity() const{
      return getFloatVal(1);
    }

    float getLayerRadius() const{
      return getFloatVal(2);
    }

    float getLayerRadiusEw() const{
      return getFloatVal(3);
    }

    float getLayerCoGx() const{
      return getFloatVal(4);
    }

    float getLayerCoGy() const{
      return getFloatVal(5);
    }

    float getLayerCoGI() const{
      return getFloatVal(6);
    }

    float getLayerCoGJ() const{
      return getFloatVal(7);
    }

    float getLayerCoGIGeom() const{
      return getFloatVal(8);
    }

    float getLayerCoGJGeom() const{
      return getFloatVal(9);
    }

    /** Convenient print method
         */
    void print(  std::ostream& os, int ) ;


    // -------- need to implement abstract methods from LCGenericObject

    /** Return the type of the class
     */
    const std::string getTypeName() const {
      return"LayerVariables" ;
    }

    /** Return a brief description of the data members
     */
    const std::string getDataDescription() const {
      return "i:CycleNr:i:nHits; i:nLayers; f:energySum; f:energyDensity; f:EvtRadius, f:EvtRadiusEw, f:CoGx, f:CoGy, f:CoGz" ;
    }

  }; // class
}

#endif
