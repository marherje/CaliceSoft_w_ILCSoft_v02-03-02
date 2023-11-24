#ifndef __CALICEDBINITHELPER_HH__
#define __CALICEDBINITHELPER_HH__

#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "lccd.h"

/**
 * CALICE namespace
 */
namespace calice {

#ifdef CALICE_DB_INIT_DEFAULT
  /**
   *
   * This is a helper header that provides a function to read the DBInitString from the system variable
   * CALICE_DB_INIT.
   *
   * If there is no CALICE_DB_INIT set in the environment, a calice default init string defined via -DCALICE_DB_INIT_DEFAULT
   * at compilation time will be used.
   *
   */
#else
  /**
   *
   * This is a helper header that provides a function to read the DBInitString from the system variable
   * CALICE_DB_INIT.
   *
   * If there is no CALICE_DB_INIT set in the environment, the output of lccd::getDBInitString() will be used as default.
   *
   */
#endif

  std::string getDBInitString(){

    const char* initstring = getenv("CALICE_DB_INIT");

    if (initstring)
      return initstring;

    else {

#ifdef CALICE_DB_INIT_DEFAULT

      return CALICE_DB_INIT_DEFAULT ;

#else

      std::string lccd_initstring = lccd::getDBInitString();

      if ( lccd_initstring == "localhost:lccd_test:calvin:hobbes" ) {

        std::cerr << "WARNING: using default default DBInitString \"localhost:lccd_test:calvin:hobbes\" " << std::endl;

      }

      return lccd_initstring;


#endif

    }
  }

}

#endif
