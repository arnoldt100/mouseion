//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FixtureCachingStdMapStringString.h"
#include "test_string_utilities.h"
#include "compare_VectorStringCache.h"
#include "compare_DifferentVectorStringCaches.h"
#include "verify_getStringVector.h"

BOOST_AUTO_TEST_SUITE( String_Utilities_Unit_Tests )

BOOST_FIXTURE_TEST_CASE( caching_std_map, FixtureCachingStdMapStringString) 
{
    std::unique_ptr<char[]> my_exp_ca_array;
    std::size_t my_exp_ca_array_length;
    std::tie(my_exp_ca_array,my_exp_ca_array_length) = experimentalVecStringCache.getArrayOfCharacters();

    bool caching_status;
    std::string message;
    std::tie(caching_status,message) = STRING_UTILITIES::compare_VectorStringCache(experimentalVecStringCache,
                                                                         controlVecStringCache);
    BOOST_TEST(caching_status, message);

    bool caching_status1;
    std::string message1;
    std::tie(caching_status1,message1) = STRING_UTILITIES::compare_DifferentVectorStringCaches(incorrectExperimentalVecStringCache1,
                                                                                     controlVecStringCache);
    BOOST_TEST(!caching_status1, message1);

    bool caching_status2;
    std::string message2;
    std::tie(caching_status2,message2) = STRING_UTILITIES::compare_DifferentVectorStringCaches(incorrectExperimentalVecStringCache2,
                                                                                               controlVecStringCache);
    BOOST_TEST(!caching_status2, message2);

}

BOOST_FIXTURE_TEST_CASE( uncaching_std_map, FixtureCachingStdMapStringString)
{
    bool uncaching_status;
    std::string message;

    uncaching_status = false;
    message += "Stud message for uncaching_std_map.";
    BOOST_TEST(uncaching_status, message);
}

BOOST_FIXTURE_TEST_CASE(VectorStringCacheTests,FixtureCachingStdMapStringString)
{
    bool get_string_vec_status;
    std::string message1;
    std::tie(get_string_vec_status,message1) = STRING_UTILITIES::verify_getStringVector(experimentalVecStringCache,
                                                                                        myTestString);
    BOOST_TEST(get_string_vec_status, message1);

}

BOOST_AUTO_TEST_SUITE_END()
