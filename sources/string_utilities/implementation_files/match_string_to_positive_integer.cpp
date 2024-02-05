//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
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

bool  match_string_to_positive_integer ( const std::string a_string )
{
    bool positive_integer = true;
    std::smatch my_space_match;

    // There should be 0 spaces in the string.
    const std::string whitespace_pattern_txt = "[[:SPACE:]]";
    auto pattern = std::regex(whitespace_pattern_txt,std::regex::extended);
    const bool found_whitespaces = std::regex_search(a_string, my_space_match, pattern );
    if ( found_whitespaces )
    {
        positive_integer = false;
        return positive_integer;
    }

    // The first character should not be a "-".
    const std::string first_char_minus_sign_pattern_text = "^-";
    pattern = std::regex(first_char_minus_sign_pattern_text,std::regex::extended);
    std::smatch my_minus_sign_match;
    const bool found_minus_sign = std::regex_search(a_string,my_minus_sign_match,pattern );
    if ( found_minus_sign ) 
    {
        positive_integer = false;
        return positive_integer;
    }

    // The first character should be a digit but not zero.
    const std::string first_char_0_text = "^0";
    pattern = std::regex(first_char_0_text,std::regex::extended);
    std::smatch my_0_first_match;
    const bool found_0_as_first_char = std::regex_search(a_string,my_0_first_match,pattern );
    if ( found_0_as_first_char ) 
    {
        positive_integer = false;
        return positive_integer;
    }

    const std::string all_digits_text = "^[[:digit:]]+$";
    pattern = std::regex(all_digits_text,std::regex::extended);
    std::smatch my_digits_match;
    const bool found_all_digits = std::regex_match(a_string,my_digits_match,pattern );
    if (! found_all_digits )
    {
        positive_integer = false;
        return positive_integer;
    }

    return positive_integer ;

}   // -----  end of function match_string_to_positive_integer  -----


}; // namespace STRING_UTILITIES

