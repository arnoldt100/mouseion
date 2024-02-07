#ifndef STRING_UTILITIES_verify_N_integers_in_string_INC
#define STRING_UTILITIES_verify_N_integers_in_string_INC

//! \file verify_N_integers_in_string.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "count_words_in_string.h"
#include "words_in_string_are_positive_integers.h"


namespace STRING_UTILITIES
{

//! \brief Stud text for brief description
template<int N>
bool verify_N_positive_integers_in_string(const std::string a_string)
{
    bool valid_string = true;

    // There must be only N words or return false.
    auto count = STRING_UTILITIES::count_words_in_string(a_string);
    if (count != N)
    {
        valid_string = false;
        return valid_string;
    }
   
    // Each word must a positive integer.
    const bool all_words_positive_integers = STRING_UTILITIES::words_in_string_are_positive_integers(a_string);
    if (! all_words_positive_integers )
    {
        valid_string = false;
        return valid_string;
    }

    return valid_string;
};

}; // namespace STRING_UTILITIES

#endif // STRING_UTILITIES_verify_N_integers_in_string_INC
