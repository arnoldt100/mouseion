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
#include "check_string_for_banned_chars.h"

namespace STRING_UTILITIES
{

bool check_string_for_banned_chars (const std::string input_string,
                                    const std::string banned_chars)
{
    std::vector<std::string> SplitVec;
    boost::split( SplitVec, input_string, boost::is_any_of(banned_chars), boost::token_compress_on );
    bool found_banned_chars = ( SplitVec.size() == 1 ) ? false : true;
    return found_banned_chars; 
};   // -----  end of function check_string_for_banned_chars  -----
}; // namespace STRING_UTILITIES

