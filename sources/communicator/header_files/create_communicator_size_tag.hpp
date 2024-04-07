#ifndef COMMUNICATOR_create_communicator_size_tag_INC
#define COMMUNICATOR_create_communicator_size_tag_INC

//! \file create_communicator_size_tag.hpp

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
#include "CommunicatorSize.h"

namespace COMMUNICATOR
{

//! \brief Stud text for brief description
template< typename T > requires is_communicator_type<T>
CommunicatorSize create_communicator_size_tag ( T const & my_communicator )
{
    const std::size_t my_size = my_communicator->getSizeofCommunicator();
    CommunicatorSize my_communicator_size{static_cast<CommunicatorSize::value_t>(my_size)};
    return my_communicator_size;
}

}; // namespace COMMUNICATOR

#endif // COMMUNICATOR_create_communicator_size_tag_INC
