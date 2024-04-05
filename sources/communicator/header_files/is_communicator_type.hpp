#ifndef COMMUNICATOR_is_communicator_type_INC
#define COMMUNICATOR_is_communicator_type_INC

//! \file is_communicator_type.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <type_traits>
#include <memory>
#include <concepts>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"

namespace COMMUNICATOR
{


template<typename T>
struct is_smart_ptr
{
    static bool value(std::false_type);
};

template<typename T>
struct is_smart_ptr<std::shared_ptr<T>> 
{
    static bool value(std::true_type);
};

template<typename T>
struct is_smart_ptr<std::unique_ptr<T>> 
{
    static bool value(std::true_type);
};

//! \brief Stud text for brief description
template< typename sp_t > 
concept is_communicator_type = requires (sp_t x) 
{
     requires(std::move_constructible<sp_t>); 
     requires(std::is_convertible<sp_t,std::shared_ptr<Communicator>>::value); 
};


}; // namespace COMMUNICATeOR

#endif // COMMUNICATOR_is_communicator_type_INC
