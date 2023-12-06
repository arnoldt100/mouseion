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

BOOST_FIXTURE_TEST_CASE( caching_std_map, ANANSI::FixtureCachingStdMapStringString) 
{

    bool caching_status;
    std::string message;

    caching_status = false;
    message += "Stud message for caching_std_map.";
    BOOST_TEST(caching_status, message);
}

BOOST_FIXTURE_TEST_CASE( uncaching_std_map, ANANSI::FixtureCachingStdMapStringString)
{
    bool uncaching_status;
    std::string message;

    uncaching_status = false;
    message += "Stud message for uncaching_std_map.";
    BOOST_TEST(uncaching_status, message);

}

BOOST_AUTO_TEST_SUITE_END()
