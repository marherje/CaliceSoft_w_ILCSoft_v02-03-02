#ifndef AHC2GANGINGPROCESSOR_H
#define AHC2GANGINGPROCESSOR_H 1

#include "marlin/Processor.h"
#include "lcio.h"

#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <iomanip>


#include <TString.h>

#include "EVENT/SimCalorimeterHit.h"
#include "EVENT/CalorimeterHit.h"

using namespace lcio ;
using namespace marlin ;
using std::vector;

namespace CALICE
{
    /** Helper class to store I, J, K.
    */
    struct geometricalIndices {
        int I;
        int J;
        int K;
    };

    /** Needed to fill the geometricalIndices struct in a map.
    */
    bool operator<( const geometricalIndices& lhs, const geometricalIndices& rhs) {
        // let the stl decide what is smaller
        return std::make_pair(lhs.I, std::make_pair(lhs.J,lhs.K) ) <
        std::make_pair(rhs.I, std::make_pair(rhs.J,rhs.K) );
    }

    std::ostream& operator<<(std::ostream& out, const geometricalIndices& ijk) {
        out << "I: " << ijk.I << " J: " << ijk.J << " K: " << ijk.K ;
        return out;
    }


    class Ganger;

    /** A ContributionMap maps a ganged index to all its contributing
    * SimCalorimeterHits.
    */
    //typedef std::map<geometricalIndices,std::vector<SimCalorimeterHit*> > ContributionMap;
    typedef std::map<geometricalIndices, std::pair<float, float> > ContributionMap;

    /** The processor performing the ganging.
    *
    */
    class Ahc2GangingProcessor : public Processor {

    public:

        // default c'tor
        Ahc2GangingProcessor();
        ~Ahc2GangingProcessor(){};

        virtual Processor* newProcessor() { return new Ahc2GangingProcessor; }

        /** Initiliases the ganging chain of responsibilty for fine and
        *  coarse modules. Defines location of module types.
        */
        virtual void init();

        /** Called every event.
        */
        virtual void processEvent(lcio::LCEvent* evt);

        /** Helper function to add up all SimCalorimeterHit energies.
        */
        float energySum(std::vector<SimCalorimeterHit*> vecSimHits);

        /** Creates the ganged collection.
        */
      //Trying the void thing  
      virtual void createOutputCollections(lcio::LCEvent* evt);
      
      /** Resets everything which is event specific.
        */
        virtual void tidyUp();


        virtual void  printParameters();

        /**
        */
        void end();

    protected:

        vector<std::string> _calorimInpCollections;//input collection name.
        vector<std::string> _calorimOutCollections;//output collection name

        float _tileBorderAttenuationFactor;
        int _TokyoLayer;// tokyo layer number

        /** Instance which holds the gather SimCalorimeterHits. The outcome
        *  of the ganging is here.
        */
        ContributionMap _contributionMap;

        /** All gangers needed for a tokyo module. Filled in init().
        */
        std::vector<Ganger*> _gangersForTokyoModule;
    };

    /** The work horse. A ganger holds all information for a region
    * to perform the ganging.
    */
    class Ganger
    {

    public:

        /** The Ganger is constructed with all information needed for a
        *  region to perform the ganging.
        */
        Ganger(int cs, int off_I, int off_J, ContributionMap* cm, float factor)
        : _cellSize(cs), _offset_I(off_I), _offset_J(off_J), _contributionMap(cm), _tileBorderAttenuationFactor(factor)
        {} // end of constructor

        virtual ~Ganger() {};

        /** Implementations have to implement where in I/J they are responsible.
        */
        virtual bool responsible(geometricalIndices indices) = 0;

        /** Function which return true if the ganger is responsible for this
        * region and adds the hit to the ContributionMap.
        */
        bool addHit(geometricalIndices indices, CalorimeterHit* hit)
        {
            if(responsible(indices) == true)
            {
                //      _GP->_gangMap[coarsen(indices)] += energy;
                float energy = hit->getEnergy();
                float time = hit->getTime();

                const float factor = this->_tileBorderAttenuationFactor;
                geometricalIndices gangedIJ;

                gangedIJ = coarsen(indices); // affecting the new ganged (I,J) index to the  gangedIJ

                if( indices.I == gangedIJ.I || indices.I == (gangedIJ.I + (_cellSize-1)) )
                    energy *= factor;

                if( indices.J == gangedIJ.J || indices.J == (gangedIJ.J + (_cellSize-1)) )
                    energy *= factor;

                (*_contributionMap)[gangedIJ].first += energy;
                (*_contributionMap)[gangedIJ].second = 99999.;

                //Get the smallest time in the ganged tile
                if(time < (*_contributionMap)[gangedIJ].second)
                (*_contributionMap)[gangedIJ].second = time;

                // streamlog_out(ERROR) << " Hit  " << hit->getEnergy() << " "
                // 	     << hit->getPosition() << " "
                // 	     <<  hit->getPosition(1) << " "
                // 	     << indices.I << " "
                // 	     << indices.J << " "
                // 	     << indices.K << " " << std::endl;
                // 	  	 << energy/hit->getEnergy() << " "
                // 	     << 1000*hit->getEnergy() << std::endl;

                return true;
            }
            else
            return false;
        }

        /** Function which returns the ganged index according to the
        *  constants defined at construction.
        */
        geometricalIndices coarsen(geometricalIndices ijk)
        {
            geometricalIndices coarsenedIndices =
            {
                coarsenSingleIndex(ijk.I, _offset_I), // calculating the new ganged index for I
                coarsenSingleIndex(ijk.J, _offset_J), // calculating the new ganged index for J
                // nothing to do for K
                ijk.K
            };

            return coarsenedIndices;
        };

        /** Performs mapping from Mokka indices to ganged indices. The main
        "algorithm".
        */
        int coarsenSingleIndex(int index, int offset)
        {
            int coarsened_index = static_cast<int>( floor(static_cast<float>(index - offset) / static_cast<float>(_cellSize)) ) + offset;
            return coarsened_index;
        }

    private:

        /** Quadratic side length of the cells in the region the Ganger is responsible.
        */
        int _cellSize;

        /** Offset with respect to starting counting at 1 for I.
        */
        int _offset_I;

        /** Offset with respect to starting counting at 1 for J.
        */
        int _offset_J;

        /** Pointer to map which stores all ganged indices and SimCalorimeterHits
        */
        ContributionMap* _contributionMap;

        float _tileBorderAttenuationFactor;
    };

}


#endif
