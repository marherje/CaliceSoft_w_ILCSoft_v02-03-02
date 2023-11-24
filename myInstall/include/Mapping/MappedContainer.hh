#ifndef MappedContainer_hh
#define MappedContainer_hh 1

/* c++ includes*/
#include <vector>

/* CALICE includes*/
#include "Mapper.hh"
#include "DecoderSet.hh"

namespace CALICE {

  /**
   * @brief Container for fast access by index
   *
   * This class stores arbitrary data types and offers transparent access by
   * different coordinate systems.
   *
   * @author Benjamin.Lutz@desy.de
   * @version 1.3
   * @date November 2009
   */
  template <class T>
  class MappedContainer {

  public:

    /**
     * Constructor
     *
     * @param[in] mapper Mapper object that is used to translate coordinate systems
     * @param[in] deleteElements Determines if the object behind the stored reference should be deleted, 
     * when it is removed from the container.
     */
    MappedContainer(const Mapper* mapper, const bool deleteElements = true) : 
      _mapper(mapper), _deleteElements(deleteElements) 
    {
      _version=0;
      _mapperVersion = _mapper->getVersion();

      initOrderedData(_mapper->getMaxIndex());

    }

    ~MappedContainer() {
      //cleanup
      initOrderedData(0);
    }

    /**
     * return a pointer to the DecoderSet handling the decoding of IDs with encoding strings
     *
     * This function returns a pointer to the DecoderSet used by the Mapper.
     * This allows to change the used encoding string.
     * Be aware that the DecoderSet might be the same for many Objects using the same Mapper.
     * Therefore, you should always enfore your encoding before using the MappedContainer.
     *
     */
    DecoderSet* getDecoder() { return _mapper->getDecoder(); }

    /**
     * fill content for (Mokka) cellID
     *
     * If unique is set, an already set value cannot be overwritten and an exception is thrown.
     * Otherwise, the old value gets overwritten.
     *
     * @param[in] cellID coordinate for content as (Mokka) cellID see Mapper
     * @param[in] object data to be stored
     * @param[in] unique enables protection from overwriting
     *
     * @throws BadDataException
     */
    void fillByCellID(const int cellID, T* object, bool unique = true);

    /**
     * fill content for (Module) channel ID
     *
     * If unique is set, an already set value cannot be overwritten and an exception is thrown.
     * Otherwise, the old value gets overwritten.
     *
     * @param[in] channelID coordinate for content as Module channel ID see Mapper
     * @param[in] object data to be stored
     * @param[in] unique enables protection from overwriting
     *
     * @throws BadDataException
     */
    void fillByModuleID(const int channelID, T* object, bool unique = true);

    /**
     * fill content for DAQ channel ID
     *
     * If unique is set, an already set value cannot be overwritten and an exception is thrown.
     * Otherwise, the old value gets overwritten.
     *
     * @param[in] DAQID coordinate for content as DAQ channel ID see Mapper
     * @param[in] object data to be stored
     * @param[in] unique enables protection from overwriting
     *
     * @throws BadDataException
     */
    void fillByDAQID(const int DAQID, T* object, bool unique = true);

    /**
     * get content for (Mokka) cellID
     *
     * @param[in] cellID coordinate for content as (Mokka) cellID see Mapper
     * @returns data for cellID or 0 if no data is available (or channel does not exist)
     */
    T* getByCellID(const int cellID) {
      checkMapping();
      return getByIndex(_mapper->getIndexByCellID(cellID));
    }

    /**
     * get content for (Module) channel ID
     *
     * @param[in] channelID coordinate for content as (Module) channel ID see Mapper
     * @returns data for channel ID or 0 if no data is available (or channel does not exist)
     */
    T* getByModuleID(const int channelID) {
      checkMapping();
      return getByIndex(_mapper->getIndexByModuleID(channelID));
    }


    /**
     * get content for DAQ channel ID
     *
     * @param[in] DAQID coordinate for content as (Module) channel ID see Mapper
     * @returns data for channel ID or 0 if no data is available (or channel does not exist)
     */
    T* getByDAQID(const int DAQID) {
      checkMapping();
      return getByIndex(_mapper->getIndexByDAQID(DAQID));
    }

    /**
     * get content for (Mokka) cellID and remove it from the container
     *
     * @param[in] cellID coordinate for content as (Module) channel ID see Mapper
     * @returns data for cellID or 0 if no data is available (or channel does not exist)
     */
    T* removeByCellID(const int cellID) {
      checkMapping();
      return removeByIndex(_mapper->getIndexByCellID(cellID));
    }

    /**
     * get content for (Module) channel ID and remove it from the container
     *
     * @param[in] channelID coordinate for content as (Module) channel ID see Mapper
     * @returns data for channel ID or 0 if no data is available (or channel does not exist)
     */
    T* removeByModuleID(const int channelID) {
      checkMapping();
      return removeByIndex(_mapper->getIndexByModuleID(channelID));
    }

    /**
     * get content for DAQ channel ID and remove it from the container
     *
     * @param[in] DAQID coordinate for content as (Module) channel ID see Mapper
     * @returns data for channel ID or 0 if no data is available (or channel does not exist)
     */
    T* removeByDAQID(const int DAQID) {
      checkMapping();
      return removeByIndex(_mapper->getIndexByDAQID(DAQID));
    }


    /**
     * delete entry for (Mokka) cellID
     *
     * If deleteElements is set, the stored object will be deleted, too.
     *
     * @param[in] cellID coordinate for content as (Module) channel ID see Mapper
     */
    void deleteByCellID(const int cellID) {
      checkMapping();
      deleteByIndex(_mapper->getIndexByCellID(cellID));
    }

    /**
     * delete entry for (Module) channel ID
     *
     * If deleteElements is set, the stored object will be deleted, too.
     *
     * @param[in] channelID coordinate for content as (Module) channel ID see Mapper
     */
    void deleteByModuleID(const int channelID) {
      checkMapping();
      deleteByIndex(_mapper->getIndexByModuleID(channelID));
    }

    /**
     * delete entry for DAQ channel ID
     *
     * If deleteElements is set, the stored object will be deleted, too.
     *
     * @param[in] DAQID coordinate for content as (Module) channel ID see Mapper
     */
    void deleteByDAQID(const int DAQID) {
      checkMapping();
      deleteByIndex(_mapper->getIndexByDAQID(DAQID));
    }


    /**
     * clear container
     */
    void clear() {
      initOrderedData(_mapper->getMaxIndex());
    }

    /** get a vector with all elements
     */
    std::vector<T*> getAllElements() const;

    /** get version number to check for updates
     */
    unsigned int getVersion() const { return _version;}
  private:

    T* getByIndex(const unsigned int index) const {
      if (index > _maxIndex) return 0;

      DataWithAddress *dataWithAddr = _orderedData[index];
      if (dataWithAddr) return dataWithAddr->getData();
      else return 0;
    }

    void fillByIndex(const unsigned int index, T* object, bool unique = true);
    T* removeByIndex(const unsigned int index);
    void deleteByIndex(const unsigned int index);
    void initOrderedData(const unsigned int size, const bool clearAddresses = true);
    void refillOrderedData(const unsigned int size);

    void checkMapping() {
      if ( _mapperVersion != _mapper->getVersion() ) refillOrderedData(_mapper->getMaxIndex());
    }

    void contentModified() {
      ++_version;
    };

    const Mapper* _mapper;
    bool _deleteElements;

    class DataWithAddress {
    public:
      DataWithAddress(const int address, T* data) : _address(address), _data(data) {;}
      int getAddress() const { return _address; }
      T* getData() const {return _data; }
    private:
      int _address;
      T* _data;
    };

    std::vector<DataWithAddress*> _orderedData;

    unsigned int _mapperVersion;
    unsigned int _version;

    unsigned int _maxIndex;

  };


}

#include <sstream>
#include "CaliceException.hh"

namespace CALICE {

  template <class T>
  void MappedContainer<T>::fillByIndex(const unsigned int index, T* object, bool unique) {

    if (index > _maxIndex) throw BadDataException("Index out of range, are you filling an not existing channel?\n");

    if (_orderedData.at(index) && unique) {
      std::ostringstream error;
      error << "index " << index << std::dec << " already filled and has to be unique" << std::endl;
      throw BadDataException(error.str());
    }

    DataWithAddress *objectWithAddress = new DataWithAddress(_mapper->getCellIDOfIndex(index),object);
    _orderedData.at(index) = objectWithAddress;

    contentModified();
  }

  template <class T>
  T* MappedContainer<T>::removeByIndex(const unsigned int index) {

    if (index > _maxIndex) return 0;

    DataWithAddress *dataWithAddr = _orderedData[index];
    if (! dataWithAddr) return 0;

    T* object = dataWithAddr->getData();
    delete _orderedData[index];
    _orderedData[index] = 0;

    contentModified();

    return object;
  }

  template <class T>
  void MappedContainer<T>::deleteByIndex(const unsigned int index) {

    if (index > _maxIndex) return;

    DataWithAddress *dataWithAddr = _orderedData[index];
    if (! dataWithAddr) return;

    if (_deleteElements) delete dataWithAddr->getData();
    delete dataWithAddr;
    _orderedData[index] = 0;

    contentModified();
  }

  template <class T>
  void MappedContainer<T>::fillByCellID(const int cellID, T* object, bool unique) {
    checkMapping();

    fillByIndex(_mapper->getIndexByCellID(cellID),object,unique);
  }

  template <class T>
  void MappedContainer<T>::fillByModuleID(const int channelID, T* object, bool unique) {
    checkMapping();

    fillByIndex(_mapper->getIndexByModuleID(channelID),object,unique);
  }

  template <class T>
  void MappedContainer<T>::fillByDAQID(const int DAQID, T* object, bool unique) {
    checkMapping();

    fillByIndex(_mapper->getIndexByDAQID(DAQID),object,unique);
  }

  template <class T>
  void MappedContainer<T>::refillOrderedData(const unsigned int size) {

    _mapperVersion = _mapper->getVersion();

    std::vector<DataWithAddress*> temporayCopy;
    for (unsigned int i =0; i< _orderedData.size();++i)
      if (_orderedData[i]) temporayCopy.push_back(_orderedData[i]);

    initOrderedData(size, false);

    for ( typename std::vector<DataWithAddress*>::iterator iter = temporayCopy.begin(); iter != temporayCopy.end(); ++iter) {
      fillByIndex(_mapper->getIndexByCellID((*iter)->getAddress()),(*iter)->getData(),false);
      delete (*iter);
    }
  }

  template <class T>
  void MappedContainer<T>::initOrderedData(const unsigned int size, const bool clearAddresses) {
    if (clearAddresses)
      for ( typename std::vector<DataWithAddress*>::iterator iter = _orderedData.begin(); iter != _orderedData.end(); ++iter) {
        if ( *iter ) {

          if ( _deleteElements ) delete (*iter)->getData();

          delete (*iter);
        }
      }
    _orderedData.clear();
    _orderedData.resize(size,0);
    _maxIndex = size;

    contentModified();
  }

  template <class T>
  std::vector<T*> MappedContainer<T>::getAllElements() const {
    std::vector<T*> result;
    for (unsigned int i =0; i< _orderedData.size();++i)
      if (_orderedData[i]) result.push_back(_orderedData[i]->getData());
    return result;
  }

}

#endif
