#ifndef COMMUNICATOR_create_communicator_rank_tag_INC
#define COMMUNICATOR_create_communicator_rank_tag_INC

//! \file create_communicator_rank_tag.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "is_communicator_type.hpp"
#include "CommunicatorRank.h"

namespace COMMUNICATOR
{

template< typename T > requires is_communicator_type<T>
CommunicatorRank create_communicator_rank_tag ( T const & my_communicator )
{
    const std::size_t my_rank = my_communicator->getCommunicatorRank();
    CommunicatorRank my_communicator_rank{my_rank};
    return my_communicator_rank;
}


}; // namespace COMMUNICATOR

#endif // COMMUNICATOR_create_communicator_rank_tag_INC
