#ifndef COMMUNICATOR_create_communicator_embryo_INC
#define COMMUNICATOR_create_communicator_embryo_INC

//! \file create_communicator_embryo.hpp

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

namespace COMMUNICATOR
{

//! \brief The primary template function for creating a "CommunicatorEmbryo".
template< typename T>
CommunicatorEmbryo create_communicator_embryo ( const T & arg  );

}; // namespace COMMUNICATOR

#endif // COMMUNICATOR_create_communicator_embryo_INC
