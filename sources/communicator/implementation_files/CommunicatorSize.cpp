
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommunicatorSize.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommunicatorSize::CommunicatorSize() :
    communicatorSize_(-1)
{
    return;
}

CommunicatorSize::CommunicatorSize( const CommunicatorSize::value_t & my_value) :
    communicatorSize_{my_value}
{
    return;
}

CommunicatorSize::CommunicatorSize( CommunicatorSize const & other) :
    communicatorSize_{other.communicatorSize_}
{
    if (this != &other)
    {
        
    }
    return;
}

CommunicatorSize::CommunicatorSize( CommunicatorSize && other) :
    communicatorSize_{std::move(other.communicatorSize_)}
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method CommunicatorSize::CommunicatorSize  -----


CommunicatorSize::~CommunicatorSize()
{
    return;
}

//============================= ACCESSORS ====================================

CommunicatorSize * CommunicatorSize::clone() const
{
    return new CommunicatorSize(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommunicatorSize& CommunicatorSize::operator= ( const CommunicatorSize &other )
{
    if (this != &other)
    {
        this->communicatorSize_ = other.communicatorSize_;
    }
    return *this;
} // assignment operator

CommunicatorSize& CommunicatorSize::operator= ( CommunicatorSize && other )
{
    if (this != &other)
    {
        this->communicatorSize_ = std::move(other.communicatorSize_);
    }
    return *this;
} // assignment-move operator

CommunicatorSize::value_t CommunicatorSize::operator()() const
{
    return this->communicatorSize_;
}

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
