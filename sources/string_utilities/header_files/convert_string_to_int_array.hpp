#ifndef STRING_UTILITIES_convert_string_to_int_array_INC
#define STRING_UTILITIES_convert_string_to_int_array_INC

//! \file convert_string_to_int_array.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <array>
#include <iterator>
#include <regex>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "match_string_to_positive_integer.h"


namespace STRING_UTILITIES
{

template<int N>
std::array<int,N> convert_string_to_int_array (const std::string a_string)
{
    std::array<int,N> my_array;

    const std::string whitespace_pattern_txt = "[^[:SPACE:]]+";

    auto pattern = std::regex(whitespace_pattern_txt,std::regex::extended);
    auto first_word = std::sregex_iterator(a_string.begin(), a_string.end(), pattern);
    auto last_word = std::sregex_iterator();

    std::size_t index = 0;
    for (std::sregex_iterator word = first_word; word != last_word; ++word)
    {
         std::smatch match = *word;
         std::string match_str = match.str();
         std::size_t pos{};
         my_array[index]  = std::stoi(match_str, &pos);
         ++index;
    }
    return my_array;
    // Each word must a positive integer.
}


}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_convert_string_to_int_array_INC
