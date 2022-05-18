
#ifndef  MPIEnvironment_INC
#define  MPIEnvironment_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//


//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "NullMPIEnvironment.h"
#include "ClassInstanceLimiter.hpp"

namespace COMMUNICATOR
{

constexpr auto MAX_MPIENVIRONMENT_INSTANCES = 1;

class MPIEnvironment final : private COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        MPIEnvironment(); /* constructor */

        MPIEnvironment(const MPIEnvironment &other)=delete; /* copy constructor */

        MPIEnvironment (MPIEnvironment && other)= delete;

        ~MPIEnvironment(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */
        void enable(int const & argc, char const * const * const & argv) const;

        void enable() const;

        void enableEnvironment(int const & argc, char const * const * const & argv) const;

        void enableEnvironment() const;

        void disable() const;


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
        std::shared_ptr<COMMUNICATOR::NullMPIEnvironment> nullmpistate_;
        std::shared_ptr<COMMUNICATOR::MPIEnvironmentState> mpistate_;

}; /* -----  end of class MPIEnvironment  ----- */


}; /* namespace COMMUNICATOR */

#endif   /* ----- #ifndef MPIEnvironment_INC  ----- */
