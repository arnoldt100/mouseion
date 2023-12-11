//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "compare_DifferentVectorStringCaches.h"

namespace STRING_UTILITIES
{

std::tuple<bool,std::string> compare_DifferentVectorStringCaches (STRING_UTILITIES::VectorStringCache const & obj1,
                                                                  STRING_UTILITIES::VectorStringCache const & obj2)
{
    std::string message;
    bool cache_same = false;
    if (obj1 == obj2)
    {
        cache_same = true;
        message += "Objects are the same but objects should be different.";
    }
    else
    {
        cache_same = false;
        message += "Objects are different.";
    }
    return std::tuple<bool,std::string>(cache_same,message);
}   // -----  end of function compare_DifferentVectorStringCaches  -----


}; // namespace STRING_UTILITIES

