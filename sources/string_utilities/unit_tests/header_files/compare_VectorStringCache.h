#ifndef STRING_UTILITIES_compare_VectorStringCache_INC
#define STRING_UTILITIES_compare_VectorStringCache_INC

//! \file compare_VectorStringCache.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <tuple>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "VectorStringCache.h"


namespace STRING_UTILITIES
{

//! \brief Compares 2 VectorStringCache.
//! 
//! \details Compares 2 VectorStringCache and
//! returns a tuple of std::tuple<bool,std::string>.
//! where the first element of the tuple indicates if 
//! the objects are equal, and the second tuple element
//! is a info messsage of difference of the 2 objects.
std::tuple<bool,std::string> compare_VectorStringCache (STRING_UTILITIES::VectorStringCache const & obj1,
                                                        STRING_UTILITIES::VectorStringCache const & obj2);


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_compare_VectorStringCache_INC
