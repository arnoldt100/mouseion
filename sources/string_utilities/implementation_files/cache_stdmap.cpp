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

    std::unique_ptr<std::size_t[]> count_chars_in_each_string_vector_element(const std::vector<std::string> & vec)
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
    return std::make_tuple(key_cache,value_cache);

}   // -----  end of function convert_string_vector_to_char_array  -----

std::map<std::string,std::string> 
uncache_stdmap(std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache> & a_tuple)
{
    std::map<std::string,std::string> a_map;
    return a_map;
}


}; // namespace STRING_UTILITIES

