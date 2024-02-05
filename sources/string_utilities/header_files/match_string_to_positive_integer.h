#ifndef STRING_UTILITIES_match_string_to_positive_integer_INC
#define STRING_UTILITIES_match_string_to_positive_integer_INC

//! \file match_string_to_positive_integer.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//


namespace STRING_UTILITIES
{

//! \brief If the string is a positive integer, true is returned, otherwise false is returned.
bool match_string_to_positive_integer ( const std::string a_string );


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_match_string_to_positive_integer_INC
