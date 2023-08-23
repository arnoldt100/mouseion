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

//! \brief Converts an object of type std::map<std::string,std::string> to
//!        a tuple of type
//!        std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache>
//!
//! This function is used to help convert a_map to a form that facilitates communicating them between
//! MPI ranks - we need "a_map" expressed as contiguous data types.
//! An object of type std::map<std::string,std::string> is transformed to a
//! tuple of type
//! std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache>
//! where the 0'th and 1'st element of the tuple are respectively the key and
//! values of the std::map<std::string,std::string>. This tuple is returned to the invoking
//! function.
//!
//! \param[in] a_map The to be flattened.
//! \returns std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache>
std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache>
cache_stdmap(const std::map<std::string,std::string> & a_map);

std::map<std::string,std::string> 
reform_stdmap(std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache> & a_tuple);

}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_cache_stdmap_INC
