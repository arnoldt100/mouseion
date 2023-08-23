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

std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache>
cache_stdmap (const std::map<std::string,std::string> & a_map)
{
    STRING_UTILITIES::VectorStringCache key_cache;
    STRING_UTILITIES::VectorStringCache value_cache;

    // Form a vector of the keys and values of the map "a_map".
    std::vector<std::string> map_keys;
    for (auto it = a_map.begin(); it != a_map.end(); ++it)
    {
        // Reform the map object form the broadcasted keys and values.
        auto key = it->first;
        map_keys.push_back(key);
    }
    std::size_t total_nm_chars1=count_total_chars_in_string_vector(map_keys);
    std::unique_ptr<std::size_t[]> nm_chars1 = count_chars_in_each_string_vector(map_keys);
    key_cache = STRING_UTILITIES::VectorStringCache(map_keys);

    std::vector<std::string> map_values;
    // Form a vector of the keys and values of the map "a_map".
    for (auto it = a_map.begin(); it != a_map.end(); ++it)
    {
        auto value = it->second;
        map_values.push_back(value);
    }
    std::size_t total_nm_chars2=count_total_chars_in_string_vector(map_values);
    std::unique_ptr<std::size_t[]> nm_chars2 = count_chars_in_each_string_vector(map_values);
    value_cache = STRING_UTILITIES::VectorStringCache(map_values);

    return std::make_tuple(key_cache,value_cache);

}   // -----  end of function convert_string_vector_to_char_array  -----

std::map<std::string,std::string> 
reform_stdmap(std::tuple<STRING_UTILITIES::VectorStringCache,STRING_UTILITIES::VectorStringCache> & a_tuple)
{
    std::map<std::string,std::string> a_map;
    return a_map;
}


}; // namespace STRING_UTILITIES

