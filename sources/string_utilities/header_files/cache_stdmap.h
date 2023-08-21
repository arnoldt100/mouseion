#ifndef STRING_UTILITIES_cache_stdmap_INC
#define STRING_UTILITIES_cache_stdmap_INC

//! \file cache_stdmap.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>
#include <map>
#include <tuple>

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
std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache>
cache_stdmap( const std::map<std::string,std::string> & a_map);

std::map<std::string,std::string> 
reform_stdmap(std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache> & a_tuple);

}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_cache_stdmap_INC
