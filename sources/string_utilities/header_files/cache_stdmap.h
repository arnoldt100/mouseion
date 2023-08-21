#ifndef STRING_UTILITIES_cache_stdmap_INC
#define STRING_UTILITIES_cache_stdmap_INC

//! \file cache_stdmap.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "VectorStringCache.h"

namespace STRING_UTILITIES
{

//! \brief Converts a vector of strings to char array.
STRING_UTILITIES::VectorStringCache cache_stdmap (
    const std::vector<std::string> & vec);


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_cache_stdmap_INC
