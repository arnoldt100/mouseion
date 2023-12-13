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
    const std::map<std::string,std::string> my_control_map { 
                                    {"key_a","a"},
                                    {"key_b","b"},
                                    {"key_c","c"},
                                    {"key_d","d"},
                                    {"key_e","e"},
                                    {"key_f","f"},
                                    {"key_g","g"}
                                  };

    const std::vector<std::string> my_keys = {"key_b",
                                              "key_a",
                                              "key_c",
                                              "key_d",
                                              "key_e",
                                              "key_f",
                                              "key_g"};

    const std::vector<std::string> my_values = {"b",
                                                "a",
                                                "c",
                                                "d",
                                                "e",
                                                "f",
                                                "g"};


    std::tuple<STRING_UTILITIES::VectorStringCache,
               STRING_UTILITIES::VectorStringCache> my_tuple { STRING_UTILITIES::VectorStringCache(my_keys),
                                                               STRING_UTILITIES::VectorStringCache(my_values)};

    std::map<std::string,std::string> my_map = STRING_UTILITIES::uncache_stdmap(my_tuple);

    if ( my_map == my_control_map)
    {
        status = true;
        message += "Maps are equal.";
    } 
    else
    {
        status = false;
        message += "Maps are unequal but they should be the same!";
    }

    return std::tie(status,message);
}   // -----  end of function verify_uncache_stdmap  -----


}; // namespace STRING_UTILITIES

