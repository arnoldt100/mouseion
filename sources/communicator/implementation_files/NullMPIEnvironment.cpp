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

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

NullMPIEnvironment::NullMPIEnvironment() :
    MPIEnvironmentState()
{
    return;
}

NullMPIEnvironment::NullMPIEnvironment( NullMPIEnvironment const & other) :
    MPIEnvironmentState(other)
{
    if (this != &other)
    {

    }
    return;
}

NullMPIEnvironment::NullMPIEnvironment( NullMPIEnvironment && other) :
    MPIEnvironmentState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method NullMPIEnvironment::NullMPIEnvironment  -----


NullMPIEnvironment::~NullMPIEnvironment()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

NullMPIEnvironment& NullMPIEnvironment::operator=( const NullMPIEnvironment &other )
{
    if (this != &other)
    {
        MPIEnvironmentState::operator=(other);
    }
    return *this;
} // assignment operator

NullMPIEnvironment& NullMPIEnvironment::operator=( NullMPIEnvironment && other )
{
    if (this != &other)
    {
        MPIEnvironmentState::operator=(std::move(other));
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

void NullMPIEnvironment::enable_()
{
    return;
}

void NullMPIEnvironment::disable_()
{
    return;
}


//============================= OPERATORS ====================================


} // namespace COMMUNICATOR
