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

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

NullMPIEnvironment::NullMPIEnvironment()
{
    return;
}

NullMPIEnvironment::NullMPIEnvironment( NullMPIEnvironment const & other)
{
    return;
}

NullMPIEnvironment::NullMPIEnvironment( NullMPIEnvironment && other)
{
    return;
}		// -----  end of method NullMPIEnvironment::NullMPIEnvironment  -----


NullMPIEnvironment::~NullMPIEnvironment()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

NullMPIEnvironment& NullMPIEnvironment::operator= ( const NullMPIEnvironment &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

NullMPIEnvironment& NullMPIEnvironment::operator= ( NullMPIEnvironment && other )
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

void NullMPIEnvironment::enable_()
{
    return;
}

void NullMPIEnvironment::disable_()
{
    return;
}


//============================= OPERATORS ====================================


} // namespace __NAMESPACE__
