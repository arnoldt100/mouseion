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

STRINGUTILITIES::VectorStringCache convert_string_vector_to_char_array (const std::vector<std::string> & vec)
{
    STRINGUTILITIES::VectorStringCache my_cache;
    
    // Compute the total length needed for a char array to
    // store the characters from the the vector string.

    // Variable "total_nm_chars" stores the total number of characters in all
    // elements of string vector "vec".
    std::size_t total_nm_chars=0;
    for (auto itr : vec)
    {
        total_nm_chars += itr.size();
    }

    // Array "nm_chars_ptr" stores the number of characters in each
    // elements of string vector "vec".
    std::size_t* nm_chars_ptr = new std::size_t [total_nm_chars];
    std::size_t index = 0;
    for (auto itr : vec)
    {
        nm_chars_ptr[index] = itr.size();
        ++index;
    }

    // Array "chars_ptr" stores the all of characters in each
    // element of string vector "vec", and chars_ptr array length is
    // total_nm_chars + 1 to account for the null terminating char.
    char* chars_ptr = new char [total_nm_chars + 1];
    std::ptrdiff_t start_index=0;
    std::ptrdiff_t end_index=0;
    for (auto itr : vec)
    {
        std::size_t nm_chars = itr.size();
        end_index = static_cast<std::ptrdiff_t>(start_index + nm_chars - 1);

        for (std::ptrdiff_t ip = start_index; ip <= end_index; ++ip)
        {

        }
        start_index = end_index + 1;
    }

    delete [] nm_chars_ptr;
    delete [] chars_ptr;

    return my_cache;

}   // -----  end of function convert_string_vector_to_char_array  -----


}; // namespace STRING_UTILITIES

