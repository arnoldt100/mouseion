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

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class FixtureCachingStdMapStringString
{
    public:
        // ====================  LIFECYCLE     =======================================

        FixtureCachingStdMapStringString ();   // constructor

        FixtureCachingStdMapStringString (const FixtureCachingStdMapStringString & other);   // copy constructor

        FixtureCachingStdMapStringString (FixtureCachingStdMapStringString && other);   // copy-move constructor

        virtual ~FixtureCachingStdMapStringString ();  // destructor

        // ====================  ACCESSORS     =======================================
        FixtureCachingStdMapStringString * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        FixtureCachingStdMapStringString& operator= ( const FixtureCachingStdMapStringString &other ); // assignment operator

        FixtureCachingStdMapStringString& operator= ( FixtureCachingStdMapStringString && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class FixtureCachingStdMapStringString  -----


}; // namespace ANANSI

#endif // ANANSI_FixtureCachingStdMapStringString_INC
