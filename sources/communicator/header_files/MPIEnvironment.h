
#ifndef  MPIEnvironment_INC
#define  MPIEnvironment_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//


//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ClassInstanceLimiter.hpp"

namespace COMMUNICATOR
{

constexpr auto MAX_MPIENVIRONMENT_INSTANCES = 1;

class MPIEnvironment final : private COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        MPIEnvironment(); /* constructor */

        MPIEnvironment(int const & argc, char const * const * const & argv); /* constructor */

        MPIEnvironment(const MPIEnvironment &other)=delete; /* copy constructor */

        MPIEnvironment (MPIEnvironment && other)= delete;

        ~MPIEnvironment(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        MPIEnvironment& 
        operator=(const MPIEnvironment &other)=delete; /* assignment operator */

        MPIEnvironment&
		operator=(MPIEnvironment &&other)=delete;

        /* ====================  STATIC        ======================================= */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class MPIEnvironment  ----- */


}; /* namespace COMMUNICATOR */

#endif   /* ----- #ifndef MPIEnvironment_INC  ----- */
