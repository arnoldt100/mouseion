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

BOOST_AUTO_TEST_SUITE( String_Utilities_Unit_Tests )

BOOST_FIXTURE_TEST_CASE( caching_std_map, FixtureCachingStdMapStringString) 
{

    bool caching_status;
    std::string message;

    experimentalVecStringCache.printToStdOut();
    controlVecStringCache.printToStdOut();

    std::unique_ptr<char[]> my_exp_ca_array;
    std::size_t my_exp_ca_array_length;
    std::tie(my_exp_ca_array,my_exp_ca_array_length) = experimentalVecStringCache.getArrayOfCharacters();

    std::unique_ptr<char[]> my_control_ca_array;
    std::size_t my_control_ca_array_length;
    std::tie(my_control_ca_array,my_control_ca_array_length) = controlVecStringCache.getArrayOfCharacters();

    caching_status = false;
    message += "Stud message for caching_std_map.";
    BOOST_TEST(caching_status, message);
}

BOOST_FIXTURE_TEST_CASE( uncaching_std_map, FixtureCachingStdMapStringString)
{
    bool uncaching_status;
    std::string message;

    uncaching_status = false;
    message += "Stud message for uncaching_std_map.";
    BOOST_TEST(uncaching_status, message);
}

BOOST_AUTO_TEST_SUITE_END()
