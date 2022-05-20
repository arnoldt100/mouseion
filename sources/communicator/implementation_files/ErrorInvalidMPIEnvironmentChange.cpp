//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorInvalidMPIEnvironmentChange.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange()
{
    return;
}

ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange( ErrorInvalidMPIEnvironmentChange const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange( ErrorInvalidMPIEnvironmentChange && other)
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange  -----


ErrorInvalidMPIEnvironmentChange::~ErrorInvalidMPIEnvironmentChange()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
const char* ErrorInvalidMPIEnvironmentChange::what() noexcept(true)
{
    return "Invalid change of MPIEnviromentState.";
}


//============================= OPERATORS ====================================

ErrorInvalidMPIEnvironmentChange& ErrorInvalidMPIEnvironmentChange::operator= ( const ErrorInvalidMPIEnvironmentChange &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

ErrorInvalidMPIEnvironmentChange& ErrorInvalidMPIEnvironmentChange::operator= ( ErrorInvalidMPIEnvironmentChange && other )
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

//============================= OPERATORS ====================================


} // namespace COMMUNICATOR
