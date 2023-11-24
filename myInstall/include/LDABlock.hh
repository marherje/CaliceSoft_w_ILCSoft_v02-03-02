#ifndef LDABlock_h
#define LDABlock_h 1

// lcio headers
#include "lcio.h"
#include "UTIL/LCFixedObject.h"

#define NINTLDA    4
#define NFLOATLDA  0
#define NDOUBLELDA 0

using namespace lcio;

namespace CALICE {
class LDABlock;

/**
 * Class for the SLCIO EUDAQ BIF Data as acquired by the EUDAQ system.
 * @author E.Brianne @ DESY Hamburg
 * @date May 2016
 * Created for 2016 testbeams EUDAQ data format.
 */
class LDABlock : public LCFixedObject<NINTLDA, NFLOATLDA, NDOUBLELDA> {
public:

    /** Constructor
     */
    LDABlock(){ };

    LDABlock(LCObject * obj) : LCFixedObject<NINTLDA, NFLOATLDA, NDOUBLELDA>(obj){ }


    /** Convenient constructor */
    LDABlock(unsigned long long int StartAcq, unsigned long long int StopAcq,
            unsigned long int TriggerTimeLow, unsigned long int TriggerTimeHigh )
    {
        //std::cout<<"printout of constructor: "<<TriggerTime <<std::endl;
        obj()->setIntVal(0, StartAcq);
        obj()->setIntVal(1, StopAcq);
        obj()->setIntVal(2, TriggerTimeLow);
        obj()->setIntVal(3, TriggerTimeHigh);

        //std::cout<<"printout of constructor: "<<obj()->getIntVal(2) <<std::endl;

    }

    /** Destructor
     */
    virtual ~LDABlock(){ };

    /** Convenient print method
     */
    void print(std::ostream& os, int);

    void setStartAcq(unsigned long long int StartAcq)
    {
        obj()->setIntVal(0, StartAcq);
    }

    void setStopAcq(unsigned long long int StopAcq)
    {
        obj()->setIntVal(1, StopAcq);
    }

    /** Set Time of the LDA Trigger */
    void setTriggerTimeLow(unsigned  long int TriggerTimeLow)
    {
        obj()->setIntVal(2, TriggerTimeLow);
    }
    void setTriggerTimeHigh(unsigned  long int TriggerTimeHigh)
    {
        obj()->setIntVal(3, TriggerTimeHigh);
    }

    // -------- need to implement abstract methods from LCGenericObject

    unsigned long long int getStartAcq() const
    {
        return getIntVal(0);
    }

    unsigned long long int getStopAcq() const
    {
        return getIntVal(1);
    }

    /** Get Time of the LDA Trigger */
    unsigned long int getTriggerTimeLow() const
    {
        return getIntVal(2);
    }

    unsigned long int getTriggerTimeHigh() const
    {
        return getIntVal(3);
    }

    /** Return the type of the class
     */
    const std::string getTypeName() const
    {
        return "LDABlock";
    }

    /** Return a brief description of the data members
     */
    const std::string getDataDescription() const
    {
        return "i:StartAcq; i:StopAcq; i:TriggerTime";
    }
};  // end class
}// end namespace
#endif // ifndef LDABlock_h
