/* Processor which generate the event tree*/

#ifndef ROOTTREEGENERATOREUDAQ2016_h
#define ROOTTREEGENERATOREUDAQ2016_h 1
#include "marlin/Processor.h"
#include "TFile.h"
#include "TTree.h"
#include <map>
#include <vector>

using namespace marlin ;

namespace CALICE {

  /** Class to process Labview raw
  * @author: Shaojun Lu DESY
  * @date Nov 15 2012
  *
  */


  class RootTreeGeneratorEUDAQ2016 : public Processor{

  public:
    virtual Processor* newProcessor() { return new RootTreeGeneratorEUDAQ2016;}
    RootTreeGeneratorEUDAQ2016();
    ~RootTreeGeneratorEUDAQ2016();
    void init();
    void processEvent( LCEvent * evt ) ;
    void end();
    void registerBranches( TTree* hostTree );
    void FillVariable(LCCollection *col);

  protected:
    std::string _inputColName;
    std::string _prefix;

    TFile *_rootFile;
    std::string _rootFileName;

    TTree *_treeEUDAQBlock2016;

    int iEvt;
    int nHits;
    int VCalib;
    std::vector<int> *BunchXID;
    std::vector<int> *CycleNr;
    std::vector<int> *ChipID;
    std::vector<int> *EvtNr;
    std::vector<int> *Channel;
    std::vector<int> *TDC;
    std::vector<int> *ADC;
    std::vector<int> *HitBit;
    std::vector<int> *GainBit;

  private:

    static std::map<TTree*,RootTreeGeneratorEUDAQ2016*> _treeFillerMap;
    static std::map<TTree*,RootTreeGeneratorEUDAQ2016*> _treeOwnerMap;
    static std::map<TFile*,RootTreeGeneratorEUDAQ2016*> _fileOwnerMap;

    static const double INVALID;

    int _nHits;
    int ievt;
    int runNumber;
    int eventNumber;
    int Timestamp;
  };
}
#endif
