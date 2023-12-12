//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "verify_getStringVector.h"

namespace STRING_UTILITIES
{

std::tuple<bool,std::string> verify_getStringVector (STRING_UTILITIES::VectorStringCache const & obj1,
                                                     std::vector<std::string> const & vec_str)
{
    bool status=false;
    std::string message;

    std::vector<std::string> exp_vec_string1 = obj1.getStringVector();

    if (exp_vec_string1 == vec_str)
    {
        message += "Vector string are the same.";
        status = true;
    }
    else
    {
        message += "Vector string are differnent but should be the same.";
        status = false;
    }
    return std::tie(status,message);
}   // -----  end of function verify_getStringVector  -----


}; // namespace STRING_UTILITIES

