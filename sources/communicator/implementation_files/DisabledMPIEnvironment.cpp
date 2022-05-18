//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "NullMPIEnvironment.h"
#include "EnabledMPIEnvironment.h"
#include "DisabledMPIEnvironment.h"
#include "MPIEnvironment.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

DisabledMPIEnvironment::DisabledMPIEnvironment()
{
    return;
}

DisabledMPIEnvironment::DisabledMPIEnvironment( DisabledMPIEnvironment const & other) :
    MPIEnvironmentState(other)
{
    if (this != &other)
    {

    }
    return;
}

DisabledMPIEnvironment::DisabledMPIEnvironment( DisabledMPIEnvironment && other) :
    MPIEnvironmentState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method DisabledMPIEnvironment::DisabledMPIEnvironment  -----


DisabledMPIEnvironment::~DisabledMPIEnvironment()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

DisabledMPIEnvironment& DisabledMPIEnvironment::operator= ( const DisabledMPIEnvironment &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

DisabledMPIEnvironment& DisabledMPIEnvironment::operator= ( DisabledMPIEnvironment && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

void DisabledMPIEnvironment::enable_(MPIEnvironment* const mpi_environment)
{
 /* :TODO:05/18/2022 05:34:55 PM:: Throw an error here. */
    return;
}

void DisabledMPIEnvironment::enable_(MPIEnvironment* const mpi_environment, int const & argc, char const * const * const & argv)
{
 /* :TODO:05/18/2022 05:35:26 PM:: Throw an error here. */
    return;
}

//============================= OPERATORS ====================================


} // namespace COMMUNICATOR
