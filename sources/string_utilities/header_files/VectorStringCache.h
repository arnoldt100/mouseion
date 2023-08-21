#ifndef STRINGUTILITIES_VectorStringCache_INC
#define STRINGUTILITIES_VectorStringCache_INC
//! \file VectorStringCache.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cstddef>

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
        std::size_t ncpvLength_;
        std::size_t * numberCharactersPerVector_;

        std::size_t caLength_; 
        char* charactersArray_;

}; // -----  end of class VectorStringCache  -----


}; // namespace STRINGUTILITIES

#endif // STRINGUTILITIES_VectorStringCache_INC
