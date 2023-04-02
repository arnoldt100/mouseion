//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <algorithm>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "convert_sequence_of_chars_to_vector_string.h"
#include "AssertValidValueForType.hpp"


namespace STRING_UTILITIES 
{
    std::vector<std::string> 
    convert_sequence_of_chars_to_vector_string( 
       int const & length,
       int const * const start_offsets_ptr,
       int const * const end_offsets_ptr,
       const char * sequence_of_characters)
    {
        #ifdef MOUSEION_DBG
        const std::string invoker("STRING_UTILITIES::convert_sequence_of_chars_to_vector_string");
        #endif

        #ifdef MOUSEION_DBG_VALID_VALUES
        DEBUGGING::AssertValidValueForType::isValidValuesForArraySize_t(invoker,length,start_offsets_ptr);
        DEBUGGING::AssertValidValueForType::isValidValuesForArraySize_t(invoker,length,end_offsets_ptr);
        #endif

        std::vector<std::string> aVectorString;

        for (int ip=0; ip < length; ++ip)
        {
            const auto starting_index = static_cast<std::size_t>(start_offsets_ptr[ip]);
            const auto ending_index = static_cast<std::size_t>(end_offsets_ptr[ip]);
            auto terminating_null_char_location = ending_index;
            auto terminating_null_char_found = false;
            for (std::size_t jp=starting_index; jp <= ending_index; ++jp )
            {
                if ( (sequence_of_characters[jp] == '\0') && ( ! terminating_null_char_found ) )
                {
                       terminating_null_char_location = jp;
                       terminating_null_char_found = true; 
                } 
            }
            const auto num_chars = terminating_null_char_location - starting_index; 
            std::string aHostname(std::string(&(sequence_of_characters[starting_index]),num_chars));   
            aVectorString.push_back(aHostname);
        }
        std::sort(aVectorString.begin(),aVectorString.end());

        return aVectorString;
    }

}; /* namespace STRING_UTILITIES */

