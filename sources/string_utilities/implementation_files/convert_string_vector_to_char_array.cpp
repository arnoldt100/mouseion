//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "convert_string_vector_to_char_array.h"

namespace STRING_UTILITIES
{

void convert_string_vector_to_char_array (const std::vector<std::string> & vec)
{
    // Compute the total length needed for a char array to
    // store the characters from the the vector string.

    // Variable "total_nm_chars" stores the total number of characters in all
    // elements of string vector "vec".
    std::size_t total_nm_chars=0;
    for (auto itr : vec)
    {
        total_nm_chars += itr.size();
    }

    // Variable "nm_chars_ptr" stores the number of characters in each
    // elements of string vector "vec".
    std::size_t* nm_chars_ptr = new std::size_t [total_nm_chars];
    
    // Variable "chars_ptr" stores the all of characters in each
    // elements of string vector "vec".
    char* chars_ptr = new char [total_nm_chars];
    std::size_t index = 0;
    for (auto itr : vec)
    {
        nm_chars_ptr[index] = itr.size();
        ++index;
    }



    delete [] nm_chars_ptr;
    delete [] chars_ptr;

    return ;
}   // -----  end of function convert_string_vector_to_char_array  -----


}; // namespace STRING_UTILITIES

