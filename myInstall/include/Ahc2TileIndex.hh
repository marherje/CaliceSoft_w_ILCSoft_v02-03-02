#ifndef HCAL_TILE_INDEX_HH
#define HCAL_TILE_INDEX_HH 1

#include <string>
#include <sstream>

#include <iostream>

#include "lcio.h"
#include "UTIL/BitField64.h"

namespace CALICE {
/**
   @brief Encodes/decodes hardware channel information for the Large CALICE AHCAL prototype

   This class encodes and decodes module, chip and channel as well as the
   SiPM number into/from a single integer. This integer is intended to be
   stored in the CellID1 field of LCIO CalorimeterHit objects for easy reference
   to and unique identification of the hardware information of reconstructed hits.

   This class is adapted from the HcalTileIndex.hh class in order to make it flexible
   for different CellID encodings

   @author Christian Graf
   @date 2018, Jan
   @version 1.0

*/
class Ahc2TileIndex{
 public:
  /** Empty constructor. All parameters default to zero.
   */
  Ahc2TileIndex(){
    setModuleEncodingString("");
    _bf_cellID = new UTIL::BitField64(_moduleEncodingString);
    _bf_cellID->reset();
    if(_bf_cellID->size() < 3 || _bf_cellID->size() > 4) {
        std::stringstream msg;
        msg << "Error: Wrong format for cell encoding.\n";
        msg << "Given: " << _moduleEncodingString << "\n";
        msg << "Required: Module:x,Chip:y,Chan:z" << "\n";
        throw std::runtime_error( msg.str() );
    }

    setModule(0).setChip(0).setChannel(0).setSipm(0);
  }

  Ahc2TileIndex(std::string moduleEncodingString){
      setModuleEncodingString(moduleEncodingString);
      _bf_cellID = new UTIL::BitField64(_moduleEncodingString);
      _bf_cellID->reset();
      if(_bf_cellID->size() < 3 || _bf_cellID->size() > 4) {
          std::stringstream msg;
          msg << "Error: Wrong format for cell encoding.\n";
          msg << "Given: " << _moduleEncodingString << "\n";
          msg << "Required: Module:x,Chip:y,Chan:z" << "\n";
          throw std::runtime_error( msg.str() );
      }

      Ahc2TileIndex();
  }

  /** Constructor from an integer for decoding
   */
  Ahc2TileIndex(int index, std::string moduleEncodingString="") {
      setModuleEncodingString(moduleEncodingString);
      _bf_cellID = new UTIL::BitField64(_moduleEncodingString);
      _bf_cellID->reset();
      if(_bf_cellID->size() < 3 || _bf_cellID->size() > 4) {
          std::stringstream msg;
          msg << "Error: Wrong format for cell encoding.\n";
          msg << "Given: " << _moduleEncodingString << "\n";
          msg << "Required: Module:x,Chip:y,Chan:z" << "\n";
          throw std::runtime_error( msg.str() );
      }

      setIndex(index);

  }

  /** Constructor from the minimum set of parameters required for unique identification.
      The SiPM number defaults to zero.

      @param mod Module identifier
      @param chip ASIC chip identifier
      @param chan Multiplex channel identifier
      @param moduleEncodingString encoding string
   */

  Ahc2TileIndex(short mod, short chip, short chan, std::string moduleEncodingString = "") : _index(0) {
    setModuleEncodingString(moduleEncodingString);
    _bf_cellID = new UTIL::BitField64(_moduleEncodingString);
    _bf_cellID->reset();
    if(_bf_cellID->size() < 3 || _bf_cellID->size() > 4) {
        std::stringstream msg;
        msg << "Error: Wrong format for cell encoding.\n";
        msg << "Given: " << _moduleEncodingString << "\n";
        msg << "Required: Module:x,Chip:y,Chan:z" << "\n";
        throw std::runtime_error( msg.str() );
    }

    setModule(mod).setChip(chip).setChannel(chan).setSipm(0);
  }

  /** Constructor from the full set of parameters

      @param mod Module identifier
      @param chip ASIC chip identifier
      @param chan Multiplex channel identifier
      @param sipm SiPM identifier
      @param moduleEncodingString encoding string
   */
  Ahc2TileIndex(short mod, short chip, short chan, short sipm, std::string moduleEncodingString = ""){
    setModuleEncodingString(moduleEncodingString);
    _bf_cellID = new UTIL::BitField64(_moduleEncodingString);
    _bf_cellID->reset();
    if(_bf_cellID->size() < 3 || _bf_cellID->size() > 4) {
        std::stringstream msg;
        msg << "Error: Wrong format for cell encoding.\n";
        msg << "Given: " << _moduleEncodingString << "\n";
        msg << "Required: Module:x,Chip:y,Chan:z" << "\n";
        throw std::runtime_error( msg.str() );
    }

    setModule(mod).setChip(chip).setChannel(chan).setSipm(sipm);
  }

  /** Destructor - does nothing
   */
  ~Ahc2TileIndex(){};

  /** Decode module identifier
   */
  unsigned int getModule() const {
      return (*_bf_cellID)[0];
    // return (_index & HTI_MOD_MASK) >> HTI_MOD_SHIFT;
  }



  /**  Derive module type from module and chip identifier
   */
  unsigned short getModuleType() const {

    // module numbering starts at 1, always return type 0 for invalid
    // modules
    if(getModule() == 0) return 0;

    short type = 0;
    if ( getChip() > 5 ) ++type;        //  lower part
    if ( getModule() > 30 ) type += 2;  //  coarse modules
    return type;
  }

  /** Decode ASIC identifier
   */
  unsigned short getChip() const {
      return (*_bf_cellID)[1];
    // return (_index & HTI_CHIP_MASK) >> HTI_CHIP_SHIFT;
  }

  /** Decode multiplex channel
   */
  unsigned short getChannel() const {
      return (*_bf_cellID)[2];
    //return (_index & HTI_CHAN_MASK) >> HTI_CHAN_SHIFT;
  }

  /** Decode SiPM number
   */
  unsigned short getSipm() const {
      return 0;
    // return (_index & HTI_SIPM_MASK) >> HTI_SIPM_SHIFT;
  }

  /** Return THE index
   */
  unsigned int getIndex() const {
    return _index;
  }

  /**  set module encoding stirng
   */
  Ahc2TileIndex& setModuleEncodingString(std::string moduleEncodingString){
    if(moduleEncodingString == "") _moduleEncodingString = "module:0:6,chip:6:4,channel:10:6";
    else _moduleEncodingString = moduleEncodingString;

    return (*this);
  }

  Ahc2TileIndex& setIndex(unsigned int index){
      _index = index;
      _bf_cellID->setValue(_index);
      return (*this);
  }

  /**  Encode module identifier
   */
  Ahc2TileIndex& setModule(short mod){
    // _index = (_index & ~HTI_MOD_MASK) | ((mod << HTI_MOD_SHIFT) & HTI_MOD_MASK);
    (*_bf_cellID)[0] = mod;
    _index = _bf_cellID->getValue();
    return (*this);
  }

  /** Encode ASIC identifier
   */
  Ahc2TileIndex& setChip(short chip){
    // _index = (_index & ~HTI_CHIP_MASK) | ((chip << HTI_CHIP_SHIFT) & HTI_CHIP_MASK);
    (*_bf_cellID)[1] = chip;
    _index = _bf_cellID->getValue();
    return (*this);
  }

  /** Encode multiplex channel
   */
  Ahc2TileIndex& setChannel(short chan){
    // _index = (_index & ~HTI_CHAN_MASK) | ((chan << HTI_CHAN_SHIFT) & HTI_CHAN_MASK);
    (*_bf_cellID)[2] = chan;
    _index = _bf_cellID->getValue();
    return (*this);
  }

  /** Encode SiPM number
   */
  Ahc2TileIndex& setSipm(short sipm){
    // _index = (_index & ~HTI_SIPM_MASK) | ((sipm << HTI_SIPM_SHIFT) & HTI_SIPM_MASK);
    return (*this);
  }

  /** Return the cellid encoding string according to an lcio BitField64
   */
  std::string getEncodingString(const unsigned int startbit) {

    // std::ostringstream EncodingString;
    //
    // EncodingString << EncodingStringHelper::GetFieldDesc("module",  HTI_MOD_MASK,  HTI_MOD_SHIFT, startbit)
    //                << ","
    //                << EncodingStringHelper::GetFieldDesc("chip",    HTI_CHIP_MASK, HTI_CHIP_SHIFT, startbit)
    //                << ","
    //                << EncodingStringHelper::GetFieldDesc("channel", HTI_CHAN_MASK, HTI_CHAN_SHIFT, startbit)
    //                << ","
    //                << EncodingStringHelper::GetFieldDesc("SiPM",    HTI_SIPM_MASK, HTI_SIPM_SHIFT, startbit);
    //
    // return EncodingString.str();

    return _moduleEncodingString;

  }



 protected:
    unsigned int _index;
    std::string _moduleEncodingString;
    UTIL::BitField64* _bf_cellID;

 private:

};

inline std::ostream& operator<<(std::ostream& out,
                         const CALICE::Ahc2TileIndex& hti) {

  out << "module: " << hti.getModule()
      << " chip: " << hti.getChip()
      << " channel: " << hti.getChannel()
    //        << " SiPM: " << hti.getSipm()
    ;

  return out;

}

}

#endif
