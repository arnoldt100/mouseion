//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iterator>
#include <regex>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "words_in_string_are_positive_integers.h"
#include "match_string_to_positive_integer.h"
namespace STRING_UTILITIES
{

bool words_in_string_are_positive_integers (const std::string a_string)
{
    bool all_words_are_positive_integers = true;

    const std::string whitespace_pattern_txt = "[^[:SPACE:]]+";
    auto pattern = std::regex(whitespace_pattern_txt,std::regex::extended);
    auto first_word = std::sregex_iterator(a_string.begin(), a_string.end(), pattern);
    auto last_word = std::sregex_iterator();
    for (std::sregex_iterator word = first_word; word != last_word; ++word)
    {
         std::smatch match = *word;
         std::string match_str = match.str();
         if ( ! STRING_UTILITIES::match_string_to_positive_integer(match_str) )
         {
             all_words_are_positive_integers = false;
             break;
         }
    }
    return all_words_are_positive_integers;
}   // -----  end of function words_in_string_are_positive_integers  -----


}; // namespace STRING_UTILITIES

