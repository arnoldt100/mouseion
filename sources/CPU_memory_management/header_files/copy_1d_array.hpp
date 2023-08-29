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

namespace
{

template<typename T>
bool is_1d_array_properly_formed(std::tuple<T const * const, const std::size_t> & array_in)
{
    bool ret_value = false;
    auto const * const array_in_ptr = std::get<0>(array_in); // A pointer to 1d array to copied.
    const auto array_in_length = std::get<1>(array_in); // The 1d array's length.

    const bool array_in_is_not_null = (array_in_ptr != nullptr);
    const bool array_in_has_positive_length = (array_in_length > 0);
    if ( array_in_is_not_null && array_in_has_positive_length ) 
    {
        ret_value = true;
    }
    return ret_value;
}

} // End of anonymous namespace;

//! \brief Copies a tuple contianing a 1d array and its length and returns a tuple copy.
//!
//! The purpose of this function of to copy a 1d array. This function argument is a tuple
//! of a pointer to a 1d array to be copied and its length. Returned is a copy of the
//! tuple argument. If the tuple to be copied is illformed, then a tuple containing a nullptr is
//! is ruturned. 
//!
//! \param[in] array_in A tuple containing the pointer to be copied
//! \return A tuple, std::tuple<T*,std::size_t>, that is a copy of array_in.
template< typename T>
std::tuple<T*,std::size_t> copy_1d_array ( std::tuple<T const * const, const std::size_t> & array_in )
{
    // Initialize the return tuple to contain a 1d array pointing to a nullptr.
    std::tuple<T*, std::size_t> ret_tuple{nullptr,0};

    if ( is_1d_array_properly_formed(array_in) ) 
    {
        MEMORY_MANAGEMENT::Array1d<T> array_factory;
        T const * const array_in_ptr = std::get<0>(array_in); // A pointer to 1d array to copied.
        const std::size_t array_in_length = std::get<1>(array_in); // The length of the 1d array to be copied.

        T* out_ptr = array_factory.createArray(array_in_length);
        for ( auto ip = static_cast<std::size_t>(0); ip < array_in_length; ++ip)
        {
            out_ptr[ip] = array_in_ptr[ip];
        }
        ret_tuple = std::make_tuple(out_ptr,array_in_length);
    }
    return ret_tuple;
}

}; // namespace MEMORY_MANAGEMENT

#endif // MEMORY_MANAGEMENT_copy_1d_array_INC
