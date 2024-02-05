#ifndef STRING_UTILITIES_count_words_in_string_INC
#define STRING_UTILITIES_count_words_in_string_INC

//! \file count_words_in_string.h

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

//! \brief Counts the number of words in a std::string.
//!
//! \details Counts the number of words in a std::string with the words
//!          being separated by whitespace. We limit this function to 
//!          strings of length less than PTRDIFF_MAX to avoid 
//!          potential problems where the number of words can't be
//!          represented by PTRDIFF_MAX.
    
int count_words_in_string ( const std::string & a_string );


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_count_words_in_string_INC
