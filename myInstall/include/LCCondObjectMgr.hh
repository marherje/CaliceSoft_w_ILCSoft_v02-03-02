#ifndef LCCondObjectMgr_h
#define LCCondObjectMgr_h

#include "lccd.h"
#include "LCCondObject.hh"

#include <map>

namespace lccd {

  typedef  std::map< std::string, LCCondObject* > LCCondObjectMap ;

  class LCCondObjectMgr {

  public:

    LCCondObjectMgr();

    ~LCCondObjectMgr() {};

    static LCCondObjectMgr* instance();

    void registerLCCondObject(LCCondObject* obj);

    void registerLCCondObject(LCCondObject* obj, const std::string& name);

    void removeLCCondObject(const std::string& name );

    LCCondObject* getLCCondObject (const std::string& name);

    void clear();

  private:
    LCCondObjectMap _map ;

    static LCCondObjectMgr* _me ;

  };

}

#endif
