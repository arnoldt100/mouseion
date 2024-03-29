//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <regex>
#include <iterator>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "count_words_in_string.h"

namespace STRING_UTILITIES
{

int count_words_in_string ( const std::string & a_string )
{
    // The pattern is anything that is not a space and
    // multiple nonspace chars.
    const std::string whitespace_pattern_txt = "[^[:SPACE:]]+";
    auto pattern = std::regex(whitespace_pattern_txt,std::regex::extended);
    auto first_word = std::sregex_iterator(a_string.begin(), a_string.end(), pattern);
    auto last_word = std::sregex_iterator();
    auto nm_words = std::distance(first_word, last_word); 
    return static_cast<int>(nm_words);
}   // -----  end of function count_words_in_string  -----


}
; // namespace STRING_UTILITIES

