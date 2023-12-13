//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "verify_uncache_stdmap.h"
#include "cache_stdmap.h"

namespace STRING_UTILITIES
{

std::tuple<bool,std::string> verify_uncache_stdmap ()
{
    bool status=false;
    std::string message;
    const std::vector<std::string> my_keys = {"key_a",
                                               "key_b",
                                               "key_c",
                                               "key_d",
                                               "key_e",
                                               "key_f",
                                               "key_g"};

    const std::vector<std::string> my_values = {"a",
                                                "b",
                                                "c",
                                                "d",
                                                "e",
                                                "f",
                                                "g"};

    std::tuple<STRING_UTILITIES::VectorStringCache,
               STRING_UTILITIES::VectorStringCache> my_tuple { STRING_UTILITIES::VectorStringCache(my_keys),
                                                               STRING_UTILITIES::VectorStringCache(my_values)};

    std::map<std::string,std::string> my_map = STRING_UTILITIES::uncache_stdmap(my_tuple);

    message += "Stud message for verify_uncache_stdmap";
    return std::tie(status,message);
}   // -----  end of function verify_uncache_stdmap  -----


}; // namespace STRING_UTILITIES

