#ifndef E4DMapper_hh
#define E4DMapper_hh

#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

// CALICE includes
#include "DecoderSet.hh"

using namespace std;
using namespace CALICE;

namespace CALICE {

  /**
   * AHCAL EPT implementation of Mapper class 
   * Functions to get dimensions of detector geometry
   *
   * @author shaojun.lu@desy.de
   * @version 1.0
   * @date 21 August 2012
   */
  class E4DMapper { //: public Mapper {

  public:

    E4DMapper() {

      clear();

      const std::string CellIDEncoding("M:3,S-1:3,I:9,J:9,K-1:6");
      const std::string ModuleEncoding("module:6,chip:4,chan:6,SiPM:16");
      //const std::string ModuleEncoding("module:2,chip:7,chan:7,SiPM:16");//For Coralie-v1
      //const std::string ModuleEncoding("module:6,chip:7,chan:7,SiPM:12");//For Coralie-v2

      _decoderSet.setCellIDEncoding( CellIDEncoding );
      _decoderSet.setModuleEncoding( ModuleEncoding );

    }


    /*
     * generate CellID1 from module(only 1 currently), chip(4 on one HBU), channel(36 in one chip)
     * and CellID0 from I, J, K
     *
     * encoding string.
     * CellID1: ModuleEncoding("module:6,chip:4,chan:6,SiPM:16")
     * CellID0: CellIDEncoding("M:3,S-1:3,I:9,J:9,K-1:6")
     *
     * @param[in] module module number
     * @param[in] chip chip number
     * @param[in] channel channel number
     *
     * @param[in] I I index
     * @param[in] J J index
     * @param[in] K K index
     *
     */
  
    //getCellID0
    int getCellID0FromIJK( const unsigned int I, const unsigned int J, const unsigned int K) const {
       return getDecoder().getCellID(I, J, K);
    }

    int getCellID0FromModuleChipChannel( const unsigned int module, const unsigned int chip, const unsigned int channel) const {
      int CellID1 = getDecoder().getModuleID(module,chip,channel);
       for ( map<int,int>::const_iterator it=_mapCell_ID1_ID0.begin() ; it != _mapCell_ID1_ID0.end(); it++ ){
	if (it->first == CellID1 ) 
	  return it->second;
      }
      return 0;
      //int CellID0 = _mapCell_ID1_ID0.at(CellID1);
      //return CellID0;
    }
    
    int getCellID0FromCellID1( const int CellID1) const {
      for ( map<int,int>::const_iterator it=_mapCell_ID1_ID0.begin() ; it != _mapCell_ID1_ID0.end(); it++ ){
	if (it->first == CellID1 ) 
	  return it->second;
      }
      return 0;
      //return _mapCell_ID1_ID0.at(CellID1);
    }
    
    //getCellID1
    int getCellID1FromModuleChipChannel( const unsigned int module, const unsigned int chip, const unsigned int channel) const {
      return getDecoder().getModuleID(module,chip,channel);
    }
    
    int getCellID1FromIJK( const unsigned int I, const unsigned int J, const unsigned int K) const {
      for ( map<int,int>::const_iterator it=_mapCell_ID1_ID0.begin() ; it != _mapCell_ID1_ID0.end(); it++ ){
	if (it->second == getDecoder().getCellID(I, J, K) ) 
	  return it->first;
      }
      return 0;
    }

    int getCellID1FromCellID0( const int CellID0) const {

      std::cout << "In getCellID1FromCellID0: CellID0 = " << CellID0 << std::endl;

      for ( map<int,int>::const_iterator it = _mapCell_ID1_ID0.begin() ; it != _mapCell_ID1_ID0.end(); it++ ){
      	if (it->second == CellID0 ) {
      	  return it->first;
	  std::cout << "So CellID1 = " << it->first << std::endl;
	}
      }
      return 0;
    }

    //getChip
    
    unsigned int getChipFromCellID0(const int cellID0) const {
      return getDecoder().getChipFromModuleID( getCellID1FromCellID0( cellID0 ) );
    }
    
    unsigned int getChipFromCellID1(const int cellID1) const {
      return getDecoder().getChipFromModuleID( cellID1 );
    }

    //unsigned int getChipFromIJ(const unsigned int I, const unsigned int J) const {
      // TODO
    //}
    unsigned int getChipFromIJK(const unsigned int I, const unsigned int J, const unsigned int K) const {
      return getDecoder().getChipFromModuleID( getCellID1FromIJK(I, J, K) );
    }
    
    //getChannel
    unsigned int getChannelFromCellID0(const int cellID0) const {
      return getDecoder().getChannelFromModuleID(  getCellID1FromCellID0( cellID0 ) );
    }

    unsigned int getChannelFromCellID1(const int cellID1) const {
      return getDecoder().getChannelFromModuleID( cellID1 );
    }
    //unsigned int getChannelFromIJ(const unsigned int I, const unsigned int J) const {
      //TODO
    //}
    unsigned int getChannelFromIJK(const unsigned int I, const unsigned int J, const unsigned int K) const {
       return getDecoder().getChannelFromModuleID( getCellID1FromIJK(I, J, K) );
    }
    //getModule
    unsigned int getModuleFromCellID0(const int cellID0) const {
      return getDecoder().getModuleFromModuleID( getCellID1FromCellID0(cellID0) );
    }

    unsigned int getModuleFromCellID1(const int cellID1) const {
      return getDecoder().getModuleFromModuleID( cellID1 );
    }

    unsigned int getModuleFromK(const unsigned int K) const {
      for (  map<int,int>::const_iterator it=_mapCell_ID1_ID0.begin() ; it != _mapCell_ID1_ID0.end(); it++ ){
	if ( getDecoder().getKFromCellID( it->second ) == K ) 
	  return getDecoder().getModuleFromModuleID( it->first );
      }
      return 0;
    }


    //GetI
    unsigned int getIFromCellID0(const int cellID0) const {
      return getDecoder().getIFromCellID( cellID0 ); 
    }
    unsigned int getIFromCellID1(const int cellID1) const {
      return getDecoder().getIFromCellID(  getCellID0FromCellID1( cellID1 ) );
    }
    //unsigned int getIFromChipChannel(const unsigned int chip, const unsigned int channel) const {
      //TODO
    //}
    unsigned int getIFromModuleChipChannel(const unsigned int module, const unsigned int chip, const unsigned int channel) const {
      return getDecoder().getIFromCellID(getCellID0FromModuleChipChannel(module, chip, channel ) );
    }

    //getJ
    unsigned int getJFromCellID0(const int cellID0) const {
      return getDecoder().getJFromCellID( cellID0 );
    }
    unsigned int getJFromCellID1(const int cellID1) const {
      return getDecoder().getJFromCellID(  getCellID0FromCellID1( cellID1 ) );
    }
    //unsigned int getJFromChipChannel(const unsigned int chip, const unsigned int channel) const {
      //TODO
    //}
    unsigned int getJFromModuleChipChannel(const unsigned int module, const unsigned int chip, const unsigned int channel) const {
       return getDecoder().getJFromCellID( getCellID0FromModuleChipChannel( module, chip, channel ) );
    }
    //getK
    unsigned int getKFromCellID0(const int cellID0) const {
      return getDecoder().getKFromCellID( cellID0 );
    }
    unsigned int getKFromCellID1(const int cellID1) const {
      return getDecoder().getKFromCellID(  getCellID0FromCellID1( cellID1 ) );
    }
    unsigned int getKFromModule(const unsigned int module) const {
      for ( map<int,int>::const_iterator it=_mapCell_ID1_ID0.begin() ; it != _mapCell_ID1_ID0.end(); it++ ){
	if (getDecoder().getModuleFromModuleID( it->first ) == module ) 
	  return getDecoder().getKFromCellID( it->second );
      }
      return 0;
    }
    void createMapbyCellID(const int cellID1, const int cellID0)
    {
      _mapCell_ID1_ID0[cellID1]=cellID0;
    }

    void createMapbyMCCIJK(const unsigned int module, const unsigned int chip, const unsigned int channel, const unsigned int I, const unsigned int J, const unsigned int K)
    {
      _nCellID1 = getCellID1FromModuleChipChannel( module, chip, channel);
      _nCellID0 = getCellID0FromIJK( I, J, K );
      createMapbyCellID(_nCellID1, _nCellID0);

      std::cout << "in createMapbyMCCIJK function: " 
		<< " module " << module << " chip " << chip << " chan " << channel 
		<< " _nCellID1 " << _nCellID1 << std::endl;
      std::cout << "_nCellID1 in decimal " << std::setw(10) << _nCellID1 << std::endl;
      std::cout << "_nCellID0 in decimal " << std::setw(10) << _nCellID0 << std::endl;
    }

    void clear(void){ _mapCell_ID1_ID0.clear(); }
    void printMap(void);
    void printModuleDescription(void);

    /**
     * get class which handles the bit en/decoding of the different IDs
     *
     * The encoding strings can be set there.
     */
    DecoderSet getDecoder() const {
      return _decoderSet;
    }


    //private variables

  private:

    std::map<int,int> _mapCell_ID1_ID0 ;
    //std::map<int,int>::const_iterator it;
    //std::map<int,int>::iterator it;


    //Hardware Module information
    unsigned int _nChip;   
    unsigned int _nChannel;
    unsigned int _nModule; 
    int _nCellID1;

    //Hardware Local Module information
    unsigned int _nI;
    unsigned int _nJ;
    unsigned int _nK;
    int _nCellID0;

    //rotation
    int xRot;
    int yRot;
    int zRot;

    //
    DecoderSet _decoderSet;
  };
}





#endif //E4DMapper_hh
