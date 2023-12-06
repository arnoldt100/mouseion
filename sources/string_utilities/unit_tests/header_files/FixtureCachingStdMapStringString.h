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

        FixtureCachingStdMapStringString (const std::vector<std::string> vec_string,
                                          const std::size_t control_ncpv_length,
                                          const std::unique_ptr<std::size_t[]> & control_ncpv,
                                          const std::size_t control_ca_length,
                                          const std::unique_ptr<char[]> & control_ca );   // constructor

        FixtureCachingStdMapStringString (const FixtureCachingStdMapStringString & other);   // copy constructor

        FixtureCachingStdMapStringString (FixtureCachingStdMapStringString && other);   // copy-move constructor

        ~FixtureCachingStdMapStringString ();  // destructor

        // ====================  ACCESSORS     =======================================
        FixtureCachingStdMapStringString * clone () const;

        // ====================  MUTATORS      =======================================
        void setup();

        void teardown();

        // ====================  OPERATORS     =======================================

        FixtureCachingStdMapStringString& operator= ( const FixtureCachingStdMapStringString &other ); // assignment operator

        FixtureCachingStdMapStringString& operator= ( FixtureCachingStdMapStringString && other ); // assignment-move operator

        // ====================  DATA MEMBERS  =======================================
        std::vector<std::string> myTestString;
        std::size_t control_ncpvLength; 
        std::size_t control_caLength;
        std::unique_ptr<char[]> control_characterArray; 
        std::unique_ptr<std::size_t[]> control_numberCharactersPerVectorElement;
        STRING_UTILITIES::VectorStringCache experimentalVecStringCache;
        STRING_UTILITIES::VectorStringCache controlVecStringCache;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        //=====================  MUTATORS      =====================================
        void setupExperimentalVecStringCache_();

        void setupControlVecStringCache_();

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        std::vector<std::string> vecString_;
        
}; // -----  end of class FixtureCachingStdMapStringString  -----


}; // namespace ANANSI

#endif // ANANSI_FixtureCachingStdMapStringString_INC
