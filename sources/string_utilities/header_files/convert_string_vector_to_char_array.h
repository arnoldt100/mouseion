#ifndef STRING_UTILITIES_convert_string_vector_to_char_array_INC
#define STRING_UTILITIES_convert_string_vector_to_char_array_INC

//! \file convert_string_vector_to_char_array.h

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

//! \brief Converts a vector of strings to char array.
void convert_string_vector_to_char_array (
    const std::vector<std::string> & vec);


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_convert_string_vector_to_char_array_INC
