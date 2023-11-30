//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "test_string_utilities.h"

BOOST_AUTO_TEST_SUITE( String_Utilities_Unit_Tests )

BOOST_AUTO_TEST_CASE( caching_std_map)
{
    bool caching_status;
    std::string message;

    caching_status = false;
    message += "Stud message for caching_std_map.";
    BOOST_TEST(caching_status, message);
}

BOOST_AUTO_TEST_CASE( uncaching_std_map)
{
    bool uncaching_status;
    std::string message;

    uncaching_status = false;
    message += "Stud message for uncaching_std_map.";
    BOOST_TEST(uncaching_status, message);

}

BOOST_AUTO_TEST_SUITE_END()
