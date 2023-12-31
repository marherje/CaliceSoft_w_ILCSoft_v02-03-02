#ifndef DigisimConditionsProcessor_hh
#define DigisimConditionsProcessor_hh 1

#ifdef USE_LCCD

#include "lccd/IConditionsChangeListener.hh"

#include "IMPL/LCCollectionVec.h"

#include "marlin/Processor.h"
#include "lcio.h"
#include <string>



using namespace lcio ;


/** Processor that provides access to conditions data in a Marlin application.
 *  Uses LCCD ConditionsHandler. For every ConditionsHandler you have to specify a 
 *  line in the steering file. Use MyMarlin -l to get examples for the steering
 *  parameters.<br>
 *  The conditions data are added to the event as LCCollections with their name.
 *  Optionally IConditionsChangeListener subclasses, e.g. ConditionsMaps can be  
 *  registered for conditions data 'name', these are updated whenever the 
 *  data changes.
 * 
 *  <h4>Input - Prerequisites</h4>
 *  none
 *
 *  <h4>Output</h4> 
 *  Collections of conditions data are added to the event.
 * 
 * 
 * @param DBCondHandler	    Initialization of a conditions database handler
 * @param DBFileHandler     Initialization of a conditions db file handler
 * @param DBInit            Initialization string for conditions database
 * @param DataFileHandler   Initialization of a data file handler
 * @param SimpleFileHandler Initialization of a simple conditions file handler
 *
 *  @author F. Gaede, DESY
 *  @version $Id: DigisimConditionsProcessor.hpp,v 1.1 2007-03-28 18:25:02 magnan Exp $ 
 */
 
class DigisimConditionsProcessor : public marlin::Processor
{//class
public:
  marlin::Processor* newProcessor() { return new DigisimConditionsProcessor ;}
  
  DigisimConditionsProcessor() ;


  /** Registers an IConditionsChangeListener, e.g. a ConditionsMap with the conditions handler 'name'.
   *  Returns true if successfull.
   */
  static bool registerChangeListener( lccd::IConditionsChangeListener* cl, const std::string&  name) ;

  /** Initializes conditions handlers as defined in the steering file
   */
  virtual void init() ;


//   /** Called for every run.
//    */
  void processRunHeader( LCRunHeader* run ) ;
  
  /** Updates all registered conditions handlers and adds the data to the event.
   */
  void processEvent( LCEvent * evt ) ;
 
//   virtual void check( LCEvent * evt ) ; 
//   /** Called after data processing for clean up.
//    */
  virtual void end() ;

  
 protected:
  /** Default database init string */
  std::string _dbInit ;

  /** initialization of SimpleFileHandlers */
  StringVec _simpleHandlerInit ;

  /** initialization of DBCondHandlers */
  StringVec _dbcondHandlerInit ;

  /** initialization of DBFileHandlers */
  StringVec _dbfileHandlerInit ;

  /** initialization of DataFileHandlers */
  StringVec _datafileHandlerInit ;

  /** the names of all handlers */
  StringVec _condHandlerNames ;

  int _nRun ;
  int _nEvt ;
  const LCParameters *_params;
  LCCollection* cole;

};//end class


#endif // #ifdef USE_LCCD
#endif


