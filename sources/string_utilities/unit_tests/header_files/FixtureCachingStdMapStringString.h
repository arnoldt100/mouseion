#ifndef ANANSI_FixtureCachingStdMapStringString_INC
#define ANANSI_FixtureCachingStdMapStringString_INC
//! \file FixtureCachingStdMapStringString.h
//!
//! \brief Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "VectorStringCache.h"

namespace ANANSI
{

class FixtureCachingStdMapStringString
{
    public:
        // ====================  LIFECYCLE     =======================================

        FixtureCachingStdMapStringString ();   // constructor

        FixtureCachingStdMapStringString (const FixtureCachingStdMapStringString & other);   // copy constructor

        FixtureCachingStdMapStringString (FixtureCachingStdMapStringString && other);   // copy-move constructor

        ~FixtureCachingStdMapStringString ();  // destructor

        // ====================  ACCESSORS     =======================================
        FixtureCachingStdMapStringString * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        FixtureCachingStdMapStringString& operator= ( const FixtureCachingStdMapStringString &other ); // assignment operator

        FixtureCachingStdMapStringString& operator= ( FixtureCachingStdMapStringString && other ); // assignment-move operator

        // ====================  DATA MEMBERS  =======================================
        STRING_UTILITIES::VectorStringCache experimentalVecStringCache;
        STRING_UTILITIES::VectorStringCache controlVecStringCache;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        std::vector<std::string> vecString_;

}; // -----  end of class FixtureCachingStdMapStringString  -----


}; // namespace ANANSI

#endif // ANANSI_FixtureCachingStdMapStringString_INC
