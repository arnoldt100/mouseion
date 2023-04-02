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
        static void isArrayValidValuesForSize_t(int const & length, int const * const array)
        {
            // Assert that length is positive.
            return;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AssertValidValueForType  -----


}; // namespace DEBUGGING

#endif // DEBUGGING_AssertValidValueForType_INC
