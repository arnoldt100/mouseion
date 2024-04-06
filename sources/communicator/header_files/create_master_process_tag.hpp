#ifndef COMMUNICATOR_create_master_process_tag_INC
#define COMMUNICATOR_create_master_process_tag_INC

//! \file create_master_process_tag.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MasterProcess.h"
#include "is_communicator_type.hpp"

namespace COMMUNICATOR
{

//! \brief Stud text for brief description
template< typename T > requires is_communicator_type<T>
MasterProcess create_master_process_tag ( T const & my_communicator)
{
    const bool value = my_communicator->iAmMasterProcess();
    MasterProcess my_master_process{value};
    return my_master_process;
}

}; // namespace COMMUNICATOR

#endif // COMMUNICATOR_create_master_process_tag_INC
