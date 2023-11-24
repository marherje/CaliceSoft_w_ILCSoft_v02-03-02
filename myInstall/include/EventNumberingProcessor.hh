#ifndef __EventNumberingProcessor__
#define __EventNumberingProcessor__ 1

#include <string>

// Marlin and LCIO headers
#include "marlin/Processor.h"
#include "marlin/EventModifier.h"



using namespace marlin;

namespace CALICE{
  class EventNumberingProcessor : public Processor, public EventModifier {

  public:

    EventNumberingProcessor();
    virtual ~EventNumberingProcessor() {};

    virtual Processor* newProcessor() { return new EventNumberingProcessor; }

    // Needed for modifyEvent
    virtual const std::string & name() const { return Processor::name(); }

    virtual void modifyEvent( LCEvent* evt );

    virtual void init();
    virtual void processRunHeader( LCRunHeader* run );
    virtual void check( LCEvent* evt );
    virtual void end();

  private:

    // The desired run number offset start for subsequent event numbering
    int _eventNumberOffset;
    int iterator;

  };

#endif
}
