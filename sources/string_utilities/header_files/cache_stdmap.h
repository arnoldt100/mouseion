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
//! \param[in] a_map The std::map to be flattened.
//! \returns std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache>
std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache>
cache_stdmap(const std::map<std::string,std::string> & a_map);

//! \brief Converts an object of type
//! std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache>
//! to
//!        std::map<std::string,std::string>.
//!
//! This function is used to convert a tuple of type
//! std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache>
//! back to std::map<std::string,std::string>. The 0'th and 1'st elements of the
//! tuple contain respectively the keys and value of the std::map.
//!
//! \param[in] a_tuple The tuple to be converted back to std::map.
std::map<std::string,std::string> 
uncache_stdmap(std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache> & a_tuple);

}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_cache_stdmap_INC
