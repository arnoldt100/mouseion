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
#include "test_communicator.h"

BOOST_AUTO_TEST_SUITE( Test_Suite_Communicator )

BOOST_AUTO_TEST_CASE( communicator_test )
{
    std::string message("Stud test for target 'communicator' which intentionally fails as the default behavior.");
    bool status=false;
    BOOST_TEST(status, message.c_str());
}


BOOST_AUTO_TEST_SUITE_END()
