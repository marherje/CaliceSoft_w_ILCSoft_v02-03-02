#ifndef __TriggerInput_hh__
#define __TriggerInput_hh__

#include <string>
#include <iostream>

/** Documentation missing.
 * @todo Write documentation!
 *
 */

class TriggerInput {
public:
  TriggerInput();
  TriggerInput( const std::string& device,
                const int pin,
                const int delay = 0,
                const int jitter = 1 );
  ~TriggerInput();

  std::ostream& print( std::ostream& out ) const;

protected:

private:
  std::string _device;
  int _pinID;
  int _delay;
  int _jitter;

};  // class TriggerInput

#endif
