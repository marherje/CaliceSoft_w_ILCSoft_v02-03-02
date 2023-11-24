#ifndef LCCONDOBJECT_H
#define LCCONDOBJECT_H 1

#include "lcio.h"
#include "IMPL/LCGenericObjectImpl.h"

#include <iostream>

using namespace lcio ;

namespace lccd {

class LCCondObject : public LCGenericObjectImpl {

public:
  LCCondObject(): LCGenericObjectImpl() {};

  LCCondObject(int nInt, int nFloat, int nDouble): LCGenericObjectImpl(nInt, nFloat, nDouble) { };

  virtual ~LCCondObject() {};

  virtual LCCondObject* convert(LCObject* obj) { return NULL; }

  virtual void print(std::ostream& os) {};
  virtual void printHdr(std::ostream& os) {};
  virtual void printTbl(std::ostream& os) {};
  virtual void getCreateQuery(std::ostream& os) {};
  virtual void getInsertQuery(std::ostream& os) {};
  virtual void getDropQuery(std::ostream& os) {};

};

}
#endif
