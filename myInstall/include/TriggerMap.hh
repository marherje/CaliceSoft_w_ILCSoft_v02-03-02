#ifndef __TriggerMap_hh__
#define __TriggerMap_hh__

#include <map>
#include <iostream>
#include "EVENT/LCCollection.h"
#include "TriggerInput.hh"

/** Documentation missing.
 * @todo Write documentation!
 *
 */

class TriggerMap {
public:
  TriggerMap( EVENT::LCCollection* col );
  ~TriggerMap();

  std::ostream& print( std::ostream& out ) const;

protected:

private:
  typedef std::map< unsigned, TriggerInput > Data_t;
  Data_t _data;
};


#endif   // __TriggerMap_hh__
