//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIEnvironmentState.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPIEnvironmentState::MPIEnvironmentState()
{
    return;
}

MPIEnvironmentState::MPIEnvironmentState( MPIEnvironmentState const & other)
{
    return;
}

MPIEnvironmentState::MPIEnvironmentState( MPIEnvironmentState && other)
{
    return;
}		// -----  end of method MPIEnvironmentState::MPIEnvironmentState  -----


MPIEnvironmentState::~MPIEnvironmentState()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void MPIEnvironmentState::enable()
{
    this->enable_();
    return;
}

void MPIEnvironmentState::disable()
{
    this->disable_();
    return;
}


//============================= OPERATORS ====================================

MPIEnvironmentState& MPIEnvironmentState::operator= ( const MPIEnvironmentState &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

MPIEnvironmentState& MPIEnvironmentState::operator= ( MPIEnvironmentState && other )
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

void MPIEnvironmentState::enable_()
{
    return;
}

void MPIEnvironmentState::disable_()
{
    return;
}


//============================= OPERATORS ====================================


} // namespace COMMUNICATOR