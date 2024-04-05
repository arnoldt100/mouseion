
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
#include "CommunicatorRank.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommunicatorRank::CommunicatorRank() :
    communicatorRank_{-1}
{
    return;
}

CommunicatorRank::CommunicatorRank(rank_t const & rank ) :
    communicatorRank_{rank}
{
    return;
}

CommunicatorRank::CommunicatorRank( CommunicatorRank const & other) :
    communicatorRank_{other.communicatorRank_}
{
    if (this != &other)
    {
    }
    return;
}

CommunicatorRank::CommunicatorRank( CommunicatorRank && other) :
    communicatorRank_{std::move(other.communicatorRank_)}
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method CommunicatorRank::CommunicatorRank  -----


CommunicatorRank::~CommunicatorRank()
{
    return;
}

//============================= ACCESSORS ====================================

CommunicatorRank * CommunicatorRank::clone() const
{
    return new CommunicatorRank(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommunicatorRank& CommunicatorRank::operator= ( const CommunicatorRank &other )
{
    if (this != &other)
    {
        this->communicatorRank_ = other.communicatorRank_;
    }
    return *this;
} // assignment operator

CommunicatorRank& CommunicatorRank::operator= ( CommunicatorRank && other )
{
    if (this != &other)
    {
        this->communicatorRank_ = std::move(other.communicatorRank_);
    }
    return *this;
} // assignment-move operator

CommunicatorRank::rank_t CommunicatorRank::operator()() const 
{
    return this->communicatorRank_;
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
