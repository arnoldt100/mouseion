#ifndef STRING_UTILITIES_check_string_for_banned_chars_INC
#define STRING_UTILITIES_check_string_for_banned_chars_INC

//! \file check_string_for_banned_chars.h

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

//! \brief Checks if input string contains any banned characteres.
//!
//! \details If the input string contains any banned characters, then true is returned.
//!          Otherwise false is returned.
//!
//! \param[in] input_string The string to be checked for banned characters.
//! \param[in] banned_chars The characters to check for in input_string.
//! 
//! retuns A bool value.
bool check_string_for_banned_chars (const std::string input_string,
                                    const std::string banned_chars);


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_check_string_for_banned_chars_INC
