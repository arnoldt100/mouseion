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
#include "cache_stdmap.h"


namespace STRING_UTILITIES
{

namespace
{
    std::size_t count_total_chars_in_string_vector(const std::vector<std::string> & vec)
    {
        std::size_t total_nm_chars=0;
        for (auto itr : vec)
        {
            total_nm_chars += itr.size();
        }
        return total_nm_chars;
    }

    std::unique_ptr<std::size_t[]> count_chars_in_each_string_vector(const std::vector<std::string> & vec)
    {
        std::unique_ptr<std::size_t[]> nm_chars_ptr = std::make_unique<std::size_t[]>(vec.size());
        std::size_t index = 0;
        for (auto itr : vec)
        {
            nm_chars_ptr[index] = itr.size();
            ++index;
        }
        return nm_chars_ptr; 
    }
}

STRING_UTILITIES::VectorStringCache cache_stdmap (const std::vector<std::string> & vec)
{
    STRING_UTILITIES::VectorStringCache my_cache;
    
    // Compute the total length needed for a char array to
    // store the characters from the the vector string.
    // Variable "total_nm_chars" stores the total number of characters in all
    // elements of string vector "vec".
    std::size_t total_nm_chars=count_total_chars_in_string_vector(vec);

    // Array "nm_chars_ptr" stores the number of characters in each
    // elements of string vector "vec".
    std::unique_ptr<std::size_t[]> nm_chars = count_chars_in_each_string_vector(vec);

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

    delete [] chars_ptr;

    return my_cache;

}   // -----  end of function convert_string_vector_to_char_array  -----


}; // namespace STRING_UTILITIES

