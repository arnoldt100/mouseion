#ifndef STRING_UTILITIES_words_in_string_are_positive_integers_INC
#define STRING_UTILITIES_words_in_string_are_positive_integers_INC

//! \file words_in_string_are_positive_integers.h

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

//! \brief Verifies all words in string are positive integers.
//!
//! \details The string words are separated by whitespace, If every
//!          is a positive integer, then true is returned. Otherwise
//!          false is returned.
bool words_in_string_are_positive_integers (const std::string a_string);


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_words_in_string_are_positive_integers_INC
