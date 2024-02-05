//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <regex>
#include <iterator>

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
    const std::regex rgx("[\\s+]");
    auto first_word = std::sregex_iterator(a_string.begin(), a_string.end(), rgx);
    auto last_word = std::sregex_iterator();
    auto nm_words = std::distance(first_word, last_word); 
    return static_cast<int>(nm_words);
}   // -----  end of function count_words_in_string  -----


}
; // namespace STRING_UTILITIES

