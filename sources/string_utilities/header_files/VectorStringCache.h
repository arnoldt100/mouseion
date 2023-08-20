#ifndef STRINGUTILITIES_VectorStringCache_INC
#define STRINGUTILITIES_VectorStringCache_INC
//! \file VectorStringCache.h
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

namespace STRINGUTILITIES
{

class VectorStringCache
{
    public:
        // ====================  LIFECYCLE     =======================================

        VectorStringCache ();   // constructor

        VectorStringCache (const VectorStringCache & other);   // copy constructor

        VectorStringCache (VectorStringCache && other);   // copy-move constructor

        ~VectorStringCache ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        VectorStringCache& operator= ( const VectorStringCache &other ); // assignment operator

        VectorStringCache& operator= ( VectorStringCache && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class VectorStringCache  -----


}; // namespace STRINGUTILITIES

#endif // STRINGUTILITIES_VectorStringCache_INC
