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
    std::smatch my_match;

    // There should be 0 spaces in the string. We use the extended regular
    // expression to form the patterns.
    const std::string whitespace_pattern_txt = "[:SPACE:]";
    auto pattern = std::regex(whitespace_pattern_txt,std::regex::extended);
    const bool found_whitespaces = std::regex_search(a_string,my_match,pattern );
    if ( found_whitespaces )
    {
        positive_integer = false;
        return positive_integer;
    }

    // The first character should not be a "-".
    // const std::string first_char_minus_sign_pattern_text = "^-";
    // pattern = std::regex(first_char_minus_sign_pattern_text,std::regex::extended);
    // const bool found_minus_sign = std::regex_match(a_string,my_match,pattern );
    // if ( found_minus_sign ) 
    // {
    //     positive_integer = false;
    //     return positive_integer;
    // }

    return positive_integer ;

}   // -----  end of function match_string_to_positive_integer  -----


}; // namespace STRING_UTILITIES

