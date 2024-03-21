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
#include "CommunicatorEmbryo.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommunicatorEmbryo::CommunicatorEmbryo() :
    communicatorType_{communicator_types::rectangular},
    communicatorSpatialDecomposition_{{1,1,1}}
{
    return;
}

CommunicatorEmbryo::CommunicatorEmbryo(const communicator_types comm_type,
                                       const std::array<std::size_t,3> communicator_spatial_decomposition) :
    communicatorType_{comm_type},
    communicatorSpatialDecomposition_{communicator_spatial_decomposition}
{
    return;
}

CommunicatorEmbryo::CommunicatorEmbryo( CommunicatorEmbryo const & other) :
    communicatorType_{other.communicatorType_},
    communicatorSpatialDecomposition_{other.communicatorSpatialDecomposition_}
{
    if (this != &other)
    {
        
    }
    return;
}

CommunicatorEmbryo::CommunicatorEmbryo( CommunicatorEmbryo && other) :
        communicatorType_{std::move(other.communicatorType_)},
        communicatorSpatialDecomposition_{std::move(other.communicatorSpatialDecomposition_)}
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

CommunicatorEmbryo::communicator_types CommunicatorEmbryo::typeOfCommunicator() const
{
    return this->communicatorType_;
}

std::array<std::size_t,3> CommunicatorEmbryo::communicatorDimensions() const
{
    return this->communicatorSpatialDecomposition_;
}


//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommunicatorEmbryo& CommunicatorEmbryo::operator= ( const CommunicatorEmbryo &other )
{
    if (this != &other)
    {
        this->communicatorType_ = other.communicatorType_;
        this->communicatorSpatialDecomposition_ = other.communicatorSpatialDecomposition_;

    }
    return *this;
} // assignment operator

CommunicatorEmbryo& CommunicatorEmbryo::operator= ( CommunicatorEmbryo && other )
{
    if (this != &other)
    {
        this->communicatorType_ = std::move(other.communicatorType_);
        communicatorSpatialDecomposition_ = std::move(other.communicatorSpatialDecomposition_);
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
