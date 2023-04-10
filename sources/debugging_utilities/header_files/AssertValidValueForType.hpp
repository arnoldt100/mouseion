#ifndef DEBUGGING_AssertValidValueForType_INC
#define DEBUGGING_AssertValidValueForType_INC
//! @file AssertValidValueForType.hpp
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <limits>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AssertMessage.h"

namespace DEBUGGING
{

// =====================================================================================
//        Class:  AssertValidValueForType
//  Description:  
//  =====================================================================================
class AssertValidValueForType
{
    public:
        // ====================  LIFECYCLE     =======================================

        AssertValidValueForType ()   // constructor
        {
            return;
        }

        AssertValidValueForType (const AssertValidValueForType & other)   // copy constructor
        {
            if ( this != &other)
            {

            }
            return;
        }

        AssertValidValueForType (AssertValidValueForType && other)   // copy-move constructor
        {
            if ( this != &other)
            {

            }
            return;
        }

        virtual ~AssertValidValueForType ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AssertValidValueForType& operator= ( const AssertValidValueForType &other ) // assignment operator
        {
            if ( this != &other)
            {

            }
            return *this;
        }

        AssertValidValueForType& operator= ( AssertValidValueForType && other ) // assignment-move operator
        {
            if ( this != &other)
            {

            }
            return *this;
        }

        // ====================  STATIC        =======================================
        static void isValidValuesForArraySize_t(std::string const & invoker, int const & length, int const * const array)
        {
            // Assert that length is positive.
            std::string message(invoker + ": The array has a non-positive length.");
            assertm(length > 0, message.c_str());

            // Assert that he values for array are positive.
            for (auto ip=0; ip < length; ++ip )
            {
                message = std::string(invoker + ": Array element " + std::to_string(ip) + " has a non-positive value.");
                assertm(array[ip] > 0, message.c_str());
            }
            return;
        }

        template<typename OriginalType,
                 typename FinalType>
        static void isValidValueForCast(OriginalType const & value) ;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AssertValidValueForType  -----


}; // namespace DEBUGGING

#endif // DEBUGGING_AssertValidValueForType_INC
