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

BOOST_AUTO_TEST_CASE( caching_std_map)
{
    // The control data to form the experimental fixture.
    std::vector<std::string> myTestString =
    {std::string("ABCDEFG"),
     std::string("12345678"),
     std::string("abcdefghi")
    };

    std::size_t control_ncpvLength = myTestString.size();

    std::unique_ptr<std::size_t[]> control_numberCharactersPerVectorElement(new std::size_t[3]);
    control_numberCharactersPerVectorElement[0] = 7;
    control_numberCharactersPerVectorElement[1] = 8;
    control_numberCharactersPerVectorElement[2] = 9;

    std::size_t control_caLength = 3;

    std::unique_ptr<char[]> control_characterArray(new char[24]);
    control_characterArray[0] = 'A';
    control_characterArray[1] = 'B';
    control_characterArray[2] = 'C';
    control_characterArray[3] = 'D';
    control_characterArray[4] = 'E';
    control_characterArray[5] = 'F';
    control_characterArray[6] = 'G';
    control_characterArray[7] = '1';
    control_characterArray[8] = '2';
    control_characterArray[9] = '3';
    control_characterArray[10] = '4';
    control_characterArray[11] = '5';
    control_characterArray[12] = '6';
    control_characterArray[13] = '7';
    control_characterArray[14] = '8';
    control_characterArray[15] = 'a';
    control_characterArray[16] = 'b';
    control_characterArray[17] = 'c';
    control_characterArray[18] = 'd';
    control_characterArray[19] = 'e';
    control_characterArray[20] = 'f';
    control_characterArray[21] = 'g';
    control_characterArray[22] = 'h';
    control_characterArray[23] = 'i';
     
    ANANSI::FixtureCachingStdMapStringString myFixture;


    bool caching_status;
    std::string message;

    caching_status = false;
    message += "Stud message for caching_std_map.";
    BOOST_TEST(caching_status, message);
}

BOOST_AUTO_TEST_CASE( uncaching_std_map)
{
    ANANSI::FixtureCachingStdMapStringString myFixture;
    bool uncaching_status;
    std::string message;

    uncaching_status = false;
    message += "Stud message for uncaching_std_map.";
    BOOST_TEST(uncaching_status, message);

}

BOOST_AUTO_TEST_SUITE_END()
