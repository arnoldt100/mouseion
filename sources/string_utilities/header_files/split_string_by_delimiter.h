#ifndef STRING_UTILITIES_split_string_by_delimiter_INC
#define STRING_UTILITIES_split_string_by_delimiter_INC

//! \file split_string_by_delimiter.h

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


namespace STRING_UTILITIES
{

//! \brief Splits a string with respect to 'delimiter'.
//!
//! \details Multiple delimiters are compressed or merged together.
//! 
//! \param [in] input The string to searched.
//! \param [in] delimiter The string of characters to split the string.
std::vector<std::string> split_string_by_delimiter ( const std::string input, 
                                                     const std::string delimiter);


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_split_string_by_delimiter_INC
