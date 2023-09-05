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

//! \brief Takes an object of type std::map<std::string,std::string> and caches
//! it to a VectorStringCache.
//!
//! This function "cache_stdmap" is used to unpack
//! std::map<std::string,std::string> to to a convenient intermediate form to
//! facilitate communication. An object of type
//! std::map<std::string,std::string> is cached to an object of type
//! std::tuple<VectorStringCache, VectorStringCache> and returned to the
//! invoking function. The 0'th and 1'st tuple elements are respectively caches
//! of the std::map key and values.
std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache>
cache_stdmap (const std::map<std::string,std::string> & a_map)
{

    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // Form string vectors of the keys and values of the
    // map "a_map".
    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    // ---------------------------------------------------
    // Cache the std:map keys to a VectorStringCache.
    // ---------------------------------------------------
    std::vector<std::string> map_keys;
    for (auto it = a_map.begin(); it != a_map.end(); ++it)
    {
        // Reform the map object form the broadcasted keys and values.
        auto key = it->first;
        map_keys.push_back(key);
    }
    STRING_UTILITIES::VectorStringCache key_cache(map_keys);

    // ---------------------------------------------------
    // Cache the std:map values to a VectorStringCache.
    // ---------------------------------------------------
    std::vector<std::string> map_values;
    // Form a vector of the keys and values of the map "a_map".
    for (auto it = a_map.begin(); it != a_map.end(); ++it)
    {
        auto value = it->second;
        map_values.push_back(value);
    }
    STRING_UTILITIES::VectorStringCache value_cache(map_values);

    // ---------------------------------------------------
    // Return the tuple of key_cache and value_cache.
    // ---------------------------------------------------
    return std::move(std::make_tuple(key_cache,value_cache));

}   // -----  end of function cache_stdmap  -----

//! \brief Takes an object of type tuple::map<VectorStringCache,VectorStringCache> and uncaches
//! it to a std::map<std::string,std::string>
//!
//! This function "uncache_stdmap" is used to unpack tuple::map<VectorStringCache,VectorStringCache>
//! back to std::map<std::string,std::string>. The first tuple element is the VectorStringCache of the
//! the keys which corresponds the the first element of std::map<std::string,std::string>. 
//! The second tuple element is the VectorStringCache of the
//! the values which corresponds the the second element of std::map<std::string,std::string>. 
std::map<std::string,std::string> 
uncache_stdmap(const std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache> & a_tuple)
{
    std::map<std::string,std::string> a_map;
    std::vector<std::string> key_str_vector = std::get<0>(a_tuple).getStringVector();
    std::vector<std::string> value_str_vector = std::get<1>(a_tuple).getStringVector();
    for (auto ip = static_cast<std::size_t>(0); ip < key_str_vector.size(); ++ip)
    {
        a_map[key_str_vector[ip]] = value_str_vector[ip]; 

    }
    return a_map;
}   // -----  end of function uncache_stdmap  -----


}; // namespace STRING_UTILITIES

