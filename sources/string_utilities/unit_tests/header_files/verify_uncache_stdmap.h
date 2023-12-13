#ifndef STRING_UTILITIES_verify_uncache_stdmap_INC
#define STRING_UTILITIES_verify_uncache_stdmap_INC

//! \file verify_uncache_stdmap.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <tuple>
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

std::tuple<bool,std::string> verify_uncache_stdmap ();


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_verify_uncache_stdmap_INC
