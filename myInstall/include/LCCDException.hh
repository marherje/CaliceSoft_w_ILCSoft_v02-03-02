#ifndef LCCD_EXCEPTION_H
#define LCCD_EXCEPTION_H 1

#include <stdexcept>


namespace lccd {

/** Defines an exception similar to the one defined by the CondDBMySQL
  * package.
  * @author: R. Pöschl DESY (based on a class created by the CondDBMySQL team)
  * @date Aug 17 2005
  */

// WARN: ErrorCode values to be defined, will set 0 in the
//       intermediate time

  class LCCDException : public std::runtime_error {

  public:
    
    LCCDException(const std::string& theMessage,
                  unsigned long theErrorCode) : 
      runtime_error("LCCDException: " + theMessage), errorCode(theErrorCode) { }
    LCCDException() : 
      runtime_error("LCCDException: No message given" ), errorCode(0) { }

    
  /// Returns the error message.
    virtual const char*     getMessage() const { return what(); }
    
  /// Returns the error code.
    virtual unsigned long   getErrorCode() const { return errorCode; }
    
  private:
    
    unsigned long errorCode;
  };
}

#endif
