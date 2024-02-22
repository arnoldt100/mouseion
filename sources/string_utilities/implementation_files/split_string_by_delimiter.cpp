//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "split_string_by_delimiter.h"

namespace STRING_UTILITIES
{

std::vector<std::string> split_string_by_delimiter(  const std::string input, 
                                                     const std::string delimiter)
{
    std::vector<std::string> my_strings;
    boost::algorithm::split(my_strings,
                            input,
                            boost::is_any_of(delimiter.c_str()),
                            boost::token_compress_on);
    return my_strings;
}   // -----  end of function split_string_by_delimiter  -----


}; // namespace STRING_UTILITIES

