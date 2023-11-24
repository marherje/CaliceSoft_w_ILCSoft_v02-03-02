#ifndef DecoderSet_hh
#define DecoderSet_hh 1

#include "FastDecoder.hh"

#include <iostream>
#include <map>

namespace CALICE {

  /**
   * @defgroup CellIDgroup Functions for (Mokka) cell ID
   */

  /**
   * @defgroup DAQgroup Functions for DAQ channel ID
   */

  /**
   * @defgroup ModuleIDgroup Functions for Module channel ID
   */

  /**
   * @defgroup VirtualCellID Functions to work with virtual Cell IDs
   */


  /**
   * class containing decoders for the three CALICE coordinate systems
   *
   * @author Benjamin.Lutz@desy.de
   * @version 0.1
   * @date November 2009
   *
   */
  class DecoderSet {
  public:

    /**
     * standard constructor
     *
     * encoding strings will be initialised to defaults
     */
    DecoderSet();

    /**
     * constructor with encoding strings
     *
     * @param[in] cellIDencoding encoding string for (Mokka) cell IDs
     * @param[in] moduleEncoding encoding string for module channel ID
     * @param[in] DAQencoding encoding string for DAQ channel ID
     */
    DecoderSet(const std::string& cellIDencoding, const std::string& moduleEncoding, const std::string& DAQencoding );

    /**
     * set a new cell ID encoding string
     * if an empty string is given the function will use the default encoding string
     * @param[in] encoding encoding string
     * @ingroup CellIDgroup
     */
    void setCellIDEncoding(const std::string &encoding);

    /**
     * set a new Module tile encoding string
     * if an empty string is given the function will use the default encoding string
     * @param[in] encoding encoding string
     * @ingroup ModuleIDgroup
     */
    void setModuleEncoding(const std::string &encoding);

    /**
     * set a new DAQ channel ID encoding string
     * if an empty string is given the function will use the default encoding string
     * @param[in] encoding encoding string
     * @ingroup DAQgroup
     */
    void setDAQEncoding(const std::string &encoding);

    /**
     * get the current cell ID encoding string
     * @returns cell ID encoding string
     * @ingroup CellIDgroup
     */
    const std::string& getCellIDEncoding() const {return _cellIDencodingString;}

    /**
     * get the current Module tile encoding string
     * @returns module channel ID encoding string
     * @ingroup ModuleIDgroup
     */
    const std::string& getModuleEncoding() const {return _moduleIDEncodingString;}

    /**
     * get the current DAQ channel ID encoding string
     * @returns DAQ channel ID encoding string
     * @ingroup DAQgroup
     */
    const std::string& getDAQEncoding() const {return _daqIDencodingString;}


    /**
     * get I from (Mokka) CellID
     * The right encoding string has to be set before.
     * @see setCellIDencoding
     * @param[in] cellID cell ID to decode
     * @returns I
     * @ingroup CellIDgroup
     */
    unsigned int getIFromCellID(const int cellID) const { return _IFromCellID->decodeU(cellID);}

    /**
     * get J from (Mokka) CellID
     * The right encoding string has to be set before.
     * @see setCellIDencoding
     * @param[in] cellID cell ID to decode
     * @returns J
     * @ingroup CellIDgroup
     */
    unsigned int getJFromCellID(const int cellID) const { return _JFromCellID->decodeU(cellID);}

    /**
     * get K from (Mokka) CellID
     * The right encoding string has to be set before.
     * @see setCellIDencoding
     * @param[in] cellID cell ID to decode
     * @returns K
     * @ingroup CellIDgroup
     */
    unsigned int getKFromCellID(const int cellID) const { return _KFromCellID->decodeU(cellID);}

    /**
     * get module from (Module) channel ID
     * The right encoding string has to be set before.
     * @see setModuleEncoding
     * @param[in] moduleID cell ID to decode
     * @returns module
     * @ingroup ModuleIDgroup
     */
    unsigned int getModuleFromModuleID(const int moduleID) const { return _moduleFromModuleID->decodeU(moduleID);}

    /**
     * get chip from (Module) channel ID
     * The right encoding string has to be set before.
     * @see setModuleEncoding
     * @param[in] moduleID cell ID to decode
     * @returns module
     * @ingroup ModuleIDgroup
     */
    unsigned int getChipFromModuleID(const int moduleID) const { return _chipFromModuleID->decodeU(moduleID);}

    /**
     * get channel from (Module) channel ID
     * The right encoding string has to be set before.
     * @see setModuleEncoding
     * @param[in] moduleID cell ID to decode
     * @returns channel
     * @ingroup ModuleIDgroup
     */
    unsigned int getChannelFromModuleID(const int moduleID) const { return _channelFromModuleID->decodeU(moduleID);}

    /**
     * get channel from DAQ channel ID
     * The right encoding string has to be set before.
     * @see setDAQEncoding
     * @param[in] DAQconnection DAQ connection ID to decode
     * @returns channel
     * @ingroup DAQgroup
     */
    unsigned int getChannelFromDAQID(const int DAQconnection) const { return _channelFromDAQID->decodeU(DAQconnection);}

    /**
     * get chip from DAQ channel ID
     * The right encoding string has to be set before.
     * @see setDAQEncoding
     * @param[in] DAQconnection DAQ connection ID to decode
     * @returns chip
     * @ingroup DAQgroup
     */
    unsigned int getChipFromDAQID(const int DAQconnection) const { return _chipFromDAQID->decodeU(DAQconnection);}

    /**
     * get fe from DAQ channel ID
     * The right encoding string has to be set before.
     * @see setDAQEncoding
     * @param[in] DAQconnection DAQ connection ID to decode
     * @returns fe
     * @ingroup DAQgroup
     */
    unsigned int getFeFromDAQID(const int DAQconnection) const { return _feFromDAQID->decodeU(DAQconnection);}

    /**
     * get slot from DAQ channel ID
     * The right encoding string has to be set before.
     * @see setDAQEncoding
     * @param[in] DAQconnection DAQ connection ID to decode
     * @returns slot
     * @ingroup DAQgroup
     */
    unsigned int getSlotFromDAQID(const int DAQconnection) const { return _slotFromDAQID->decodeU(DAQconnection);}

    /**
     * get crate from DAQ channel ID
     * The right encoding string has to be set before.
     * @see setDAQEncoding
     * @param[in] DAQconnection DAQ connection ID to decode
     * @returns crate
     * @ingroup DAQgroup
     */
    unsigned int getCrateFromDAQID(const int DAQconnection) const { return _crateFromDAQID->decodeU(DAQconnection);}

    /**
     * get CellID from triple I,J,K
     *
     * The right encoding string has to be set before.
     *
     * @warning This cell ID will only contain information about I, J and K.
     *          If the encoding string contains additional fields this will have value 0.
     *
     * @see setCellIDencoding
     * @param[in] I I of cell
     * @param[in] J J of cell
     * @param[in] K K of cell
     * @returns (Mokka) cell ID
     * @ingroup CellIDgroup
     */
    int getCellID(const unsigned int I, const unsigned int J, const unsigned int K) const {
      return (_IFromCellID->encodeU(I) | _JFromCellID->encodeU(J) | _KFromCellID->encodeU(K));
    }

    /**
     * get (Module) channel ID from triple module, chip, channel
     *
     * The right encoding string has to be set before.
     *
     * @warning This (Module) channel ID will only contain information about module, chip and channel.
     *          If the encoding string contains additional fields this will have value 0.
     *
     * @see setModuleEncoding
     * @param[in] module module of this channel
     * @param[in] chip chip of this channel
     * @param[in] channel hardware channel of this channel
     * @returns (Module) channel ID
     * @ingroup ModuleIDgroup
     */
    int getModuleID(const unsigned int module, const unsigned int chip, const unsigned int channel) const 
    {
      return (_moduleFromModuleID->encodeU(module) | _chipFromModuleID->encodeU(chip) 
	      | _channelFromModuleID->encodeU(channel));
      
    }

    /**
     * get DAQ channel ID from crate, slot, fe, chip, channel
     *
     * The right encoding string has to be set before.
     *
     * @warning This DAQ channel ID will only contain information about crate, slot, fe, chip and channel.
     *          If the encoding string contains additional fields this will have value 0.
     *
     * @see setDAQEncoding
     * @param[in] crate crate of this channel
     * @param[in] slot slot of this channel
     * @param[in] fe frontend of this channel
     * @param[in] chip chip of this channel
     * @param[in] channel hardware channel of this channel
     * @returns DAQ channel ID
     * @ingroup DAQgroup
     */
    int getDAQID(const unsigned int crate, const unsigned int slot, const unsigned int fe, 
		 const unsigned int chip, const unsigned int channel) const {
      return (_crateFromDAQID->encodeU(crate) | _slotFromDAQID->encodeU(slot) 
	      | _feFromDAQID->encodeU(fe) | _chipFromDAQID->encodeU(chip) 
	      | _channelFromDAQID->encodeU(channel));
    }


  private:
    std::string _cellIDencodingString;
    std::string _moduleIDEncodingString;
    std::string _daqIDencodingString;

    static const std::string _defaultCellIDEncoding;
    static const std::string _defaultModuleEncoding;
    static const std::string _defaultDAQEncoding;

    FastDecoder *_IFromCellID;
    FastDecoder *_JFromCellID;
    FastDecoder *_KFromCellID;
    FastDecoder *_moduleFromModuleID;
    FastDecoder *_chipFromModuleID;
    FastDecoder *_channelFromModuleID;
    FastDecoder *_channelFromDAQID;
    FastDecoder *_chipFromDAQID;
    FastDecoder *_feFromDAQID;
    FastDecoder *_slotFromDAQID;
    FastDecoder *_crateFromDAQID;

    struct MokkaID_t{
      FastDecoder *forI;
      FastDecoder *forJ;
      FastDecoder *forK;
    };

    typedef std::map<std::string, MokkaID_t> mokkaDecoderMap_t;
    mokkaDecoderMap_t _mokkaDecoderMap;
    


  };

} // end namespace CALICE

#endif
