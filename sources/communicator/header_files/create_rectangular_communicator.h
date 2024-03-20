#ifndef COMMUNICATOR_create_rectangular_communicator_INC
#define COMMUNICATOR_create_rectangular_communicator_INC

//! \file create_rectangular_communicator.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"

namespace COMMUNICATOR
{

//! \brief Creates rectangular communicator.
std::unique_ptr<COMMUNICATOR::Communicator> create_rectangular_communicator (std::unique_ptr<COMMUNICATOR::Communicator> a_communicator);


}; // namespace COMMUNICATOR

#endif // COMMUNICATOR_create_rectangular_communicator_INC
