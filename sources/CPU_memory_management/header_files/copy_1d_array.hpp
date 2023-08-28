#ifndef MEMORY_MANAGEMENT_copy_1d_array_INC
#define MEMORY_MANAGEMENT_copy_1d_array_INC

//! \file copy_1d_array.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <tuple>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Array1d.hpp"

namespace MEMORY_MANAGEMENT
{


//! \brief Copies a tuple contianing a 1d array and its length and returns a tuple copy.
//!
//! The purpose of this function os to copy a 1d array.
template< typename T>
std::tuple<T*,std::size_t> copy_1d_array ( std::tuple<T const * const, const std::size_t> & array_in )
{

    std::tuple<T*, std::size_t> ret_tuple{nullptr,0};

    T const * const array_in_ptr = std::get<0>(array_in);
    const std::size_t array_in_length = std::get<1>(array_in);

    const bool array_in_is_not_null = (array_in_ptr != nullptr);
    constexpr bool array_in_has_positive_length = (array_in_length > 0);

    if ( array_in_is_not_null && array_in_has_positive_length ) 
    {
        MEMORY_MANAGEMENT::Array1d<T> array_factory;
        T* out_ptr = array_factory.createArray(array_in.get<1>(array_in));
        for ( auto ip = static_cast<std::size_t>(0); ip < array_in.get<1>(array_in); ++ip)
        {
            out_ptr[ip] = array_in_ptr[ip];
        }
        ret_tuple = std::make_tuple(out_ptr,array_in_length);
    }
    return ret_tuple;
}

}; // namespace MEMORY_MANAGEMENT

#endif // MEMORY_MANAGEMENT_copy_1d_array_INC
