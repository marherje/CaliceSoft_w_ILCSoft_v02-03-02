#ifndef __CALICE_DB_EXCEPTION__
#define __CALICE_DB_EXCEPTION__

#include <exception>
#include <string>

namespace CALICE {

  /**
   * @brief exception to be thrown if the given runNumber is not supported
   *
   */

  class NonSupportedRunNumberException : public std::exception {

  public:

    NonSupportedRunNumberException(std::string text) throw() {
      _message = std::string("CALICE::NonSupportedRunNumberException: ") + text;
    }
    const char* what() const throw() {
      return _message.c_str();
    }
    ~NonSupportedRunNumberException() throw() {;}

    
  protected:

    NonSupportedRunNumberException() {;}
    std::string _message;


  };

}


#endif
