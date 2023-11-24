#ifndef DBINTERFACEMGR_HH
#define DBINTERFACEMGR_HH 1

#include <string>
#include <map>
#include <utility>

#include "lccd/DBInterface.hh"

namespace lccd {
  /**
   * @brief singelton that manages lccd::DBInterface classes on the basis of DBInit string and database folder
   *
   * The class holds a map of DBInterfaces. When a DBInterface is requested it is checked if a suitable DBInterface
   * is already available. If not the DBInterface is generated.
   */
  class DBInterfaceMgr {
  public:
    /**
     * @brief Get a suitable DBInterface
     * @param[in] DBInit database init string
     * @param[in] folder database folder
     * @return a pointer to a suitable DBInterface
     */
    static DBInterface* getDBInterface(const std::string DBInit, const std::string folder) ;

    /**
     * clean up the database connections and memory
     */
    static void clear();

    ~DBInterfaceMgr();

  private:

    static DBInterfaceMgr* _instance;

    DBInterfaceMgr() {}

    std::map< std::pair<std::string,std::string>, DBInterface* > _interfaceMap;
  };

}

#endif
