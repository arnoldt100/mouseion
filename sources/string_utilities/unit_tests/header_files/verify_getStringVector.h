#ifndef STRING_UTILITIES_verify_getStringVector_INC
#define STRING_UTILITIES_verify_getStringVector_INC

//! \file verify_getStringVector.h

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

//! \brief Stud text for brief description
std::tuple<bool,std::string> verify_getStringVector (STRING_UTILITIES::VectorStringCache const & obj1,
                                                     std::vector<std::string> const & vec_str);


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_verify_getStringVector_INC
