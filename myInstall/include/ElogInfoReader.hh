#ifndef ElogInfoReader_hh
#define ElogInfoReader_hh 1

#include <string>
#include <map>
#include <utility>

  /**
   * Implementation of the e-log information
   *
   * @author Benjamin.Lutz@desy.de
   * @date April 2010
   */

class ElogInfo 
{
  
public:
  
  /** Constructor from the run number
   */
  ElogInfo(const unsigned int runNumber);

  unsigned int getRunNumber() const {return _runnumber;}

  bool isBad() const {return _bad;}

  int getParticleID() const {return _particleID;}
  int getTriggerType() const {return _triggerType;}
  int getTriggerSetting() const {return _triggerSetting;}
  int getQualityFlag() const {return _qualityFlag;}

  float getEnergy() const {return _energy;}
  float getCherenkovPressure() const {return _cherenkovPressure;}
  float getCherenkov2Pressure() const {return _cherenkov2Pressure;}
  float getPositionX() const {return _position.first;}
  float getPositionY() const {return _position.second;}
  float getRotationAngle() const {return _rotationAngle;}

  const std::string &getRunType() const {return _runType;}
  const std::string &getTarget() const {return _target;}
  const std::string &getAbsorber() const {return _absorber;}
  const std::string &getComment() const {return _comment;}

  void setBad(const bool value = true);

  void setParticleID(const int PDG);
  void setTriggerType(const int triggerType);
  void setTriggerSetting(const int triggerSetting);
  void setQualityFlag(const int qualityFlag);

  void setEnergy(const float energy);
  void setCherenkovPressure(const float cherenkovPressure);
  void setCherenkov2Pressure(const float cherenkov2Pressure);
  void setPosition(const std::pair<float, float> &position);
  void setRotationAngle(const float rotationAngle);

  void setRunType(const std::string &type);
  void setTarget(const std::string &target);
  void setAbsorber(const std::string &absorber);
  void setComment(const std::string &comment);

private:
  const unsigned int _runnumber;/**<run number*/

  bool _bad;
  int _particleID; /**<particle ID (PDG)*/
  int _triggerType;/**<trigger type: 10 for the '10x10' trigger, 
		      20 for the '20x20' trigger,
		      100 for the '100x100' trigger*/
  int _triggerSetting;/**<trigger setting for FNAL*/
  int _qualityFlag; /**<quality flag: 0 (good), 1 (junk, garbage), >1 for FNAL*/
  
  float _energy;/**<beam energy for the given run*/
  float _cherenkovPressure;/**<Cherenkov pressure in counter A for the given run*/
  float _cherenkov2Pressure;/**<Cherenkov pressure in counter B for the given run*/  
  std::pair<float,float> _position;/**<beam position (x, y) for the given run*/
  float _rotationAngle;

  std::string _target;/**<target (Pb, air)*/
  std::string _absorber;/**<absorber*/
  std::string _runType;/**<run type (beamdata, ahcBeam, beamHoldScane...)*/
  std::string _comment;/**<additional comment*/

};


  /**
   * Implementation of the reading of the e-log information
   *
   * @author Benjamin.Lutz@desy.de
   * @date April 2010
   */
class ElogInfoReader 
{

public:
  ElogInfoReader() {
    _debug = false;
  }
  void readFile(const std::string &fileName);
  void setDebug(const bool value);

  const ElogInfo* getInfo(const unsigned int runnumber) const;

  std::map<unsigned int,ElogInfo*> &getInfoMap() {return _data;}

private:
  typedef std::map<unsigned int,ElogInfo*> DataMap_t;
  DataMap_t _data;

  bool _debug;

  template <class T>
  bool convert(const std::string &input, T &result) const;
  std::string lowerCase(const std::string &input) const;
  std::string identifyRunType(const std::string &input) const;

  bool getTriggerType(const std::string &input, int &triggerType) const;
  bool getTriggerSetting(const std::string &input, int &triggerSetting) const;
  bool getQualityFlag(const std::string &input, int &qualityFlag) const;
  bool getEnergy(const std::string &input, float &energy) const;
  bool getParticle(const std::string &input, int &particle) const;
  bool getBeamFile(const std::string &input, int &file) const;
  bool getTarget(const std::string &input, std::string &target) const;
  bool getAbsorber(const std::string &input, std::string &absorber) const;
  bool getCherenkovPressure(const std::string &input, float &cherenkovPressure) const;
  bool getCherenkov2Pressure(const std::string &input, float &cherenkov2Pressure) const;
  bool getPosition(const std::string &input, std::pair<float,float> &position) const;

};


#endif
