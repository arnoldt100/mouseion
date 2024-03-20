
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommunicatorEmbryo.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommunicatorEmbryo::CommunicatorEmbryo()
{
    return;
}

CommunicatorEmbryo::CommunicatorEmbryo( CommunicatorEmbryo const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

CommunicatorEmbryo::CommunicatorEmbryo( CommunicatorEmbryo && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method CommunicatorEmbryo::CommunicatorEmbryo  -----


CommunicatorEmbryo::~CommunicatorEmbryo()
{
    return;
}

//============================= ACCESSORS ====================================

CommunicatorEmbryo * CommunicatorEmbryo::clone() const
{
    return new CommunicatorEmbryo(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommunicatorEmbryo& CommunicatorEmbryo::operator= ( const CommunicatorEmbryo &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

CommunicatorEmbryo& CommunicatorEmbryo::operator= ( CommunicatorEmbryo && other )
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
