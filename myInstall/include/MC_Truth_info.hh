#ifndef MC_TRUTH_INFO_HH_
#define MC_TRUTH_INFO_HH_

/**
 * @brief Processor MCTruth <<==>> Reco link
 * In this processor, it relates Recohit to the corresponding Simhit and looks for the MC particles contributed to the Simhit.
 *
 * @author olin.pinto@desy.de
 * @version 1.0
 * @date October 2020
 */


//Marlin includes
#include "marlin/Processor.h"
#include "lcio.h"
#include "EVENT/LCEvent.h"
#include "UTIL/LCTOOLS.h"
#include "EVENT/LCCollection.h"
#include "UTIL/CellIDDecoder.h"
#include "EVENT/CalorimeterHit.h"
//CALICE includes
#include "EventVariables.hh"
//Root includes
#include "TFile.h"
#include "TTree.h"
#include "TROOT.h"
#include "TH2.h"
#include "TGraph.h"

using namespace std;
using namespace lcio;
using namespace marlin;

namespace CALICE
{
  class MC_Truth_Variables {
  public:
    /** Constructor with member initialization*/
    MC_Truth_Variables() {
      nEvt.clear();
      MC_Cont_Energy.clear();
    }
    /** Default destructor*/
    ~MC_Truth_Variables() {}

    void Clear()
    {      
      nEvt.clear();
      MC_Cont_Energy.clear();
    }
    vector<int> nEvt;  
    vector<double> MC_Cont_Energy;
  };

  class MC_Truth_info : public Processor
  {

  public:

    virtual Processor*  newProcessor() { return new MC_Truth_info; }

    /** Default constructor.
    */
    MC_Truth_info();

    /** Default destructor.
    */
    ~MC_Truth_info(){};

    /** Marlin init() function.
    */
    virtual void init();

    /** Marlin processRunHeader() function.
    */
    virtual void processRunHeader(LCEvent *evt);

    /** Marlin processEvent() function.
    */
    virtual void processEvent(LCEvent *evt);

    /** Marlin check() function.
    */
    virtual void check( LCEvent * evt );

    /** Marlin end() function.
    */
    virtual void end();

    // print the processor parameters
    void printParameters();

  private:
    MC_Truth_Variables MC_particle_info; // Variables for RootTree
    TFile* outputFile; //Output Rootfile 
    TTree *MC_particle_info_tree; //Root Tree for MC Parameters
    
  protected:
    int _nEvt;
    int _nRun;
    string _evtVarColName; //Event variables collection name
    string _hitInColName; //Input collection name
    string _inHitVarColName;//Hit variables collection name
    
    string _MCParticleColName; //MC collection
    string _SimhitInColName; //MCIMPL collection
    string _calohitMCTruthLink; //lcrelation collection
    string _hitvarColName;//Output hit variable collection
    
    //MCParticle variables
    int PDG_contribution;// the PDG code of the shower particle that caused this contribution
    int NMC_contribution;//  the number of MC contributions to the hit
    string _RootMC; //Path Root output file
  };
}
#endif /* MC_TRUTH_INFO_HH_ */
