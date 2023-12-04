
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FixtureCachingStdMapStringString.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

FixtureCachingStdMapStringString::FixtureCachingStdMapStringString()
{
    return;
}

FixtureCachingStdMapStringString::FixtureCachingStdMapStringString( FixtureCachingStdMapStringString const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

FixtureCachingStdMapStringString::FixtureCachingStdMapStringString( FixtureCachingStdMapStringString && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method FixtureCachingStdMapStringString::FixtureCachingStdMapStringString  -----


FixtureCachingStdMapStringString::~FixtureCachingStdMapStringString()
{
    return;
}

//============================= ACCESSORS ====================================

FixtureCachingStdMapStringString * FixtureCachingStdMapStringString::clone() const
{
    return new FixtureCachingStdMapStringString(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

FixtureCachingStdMapStringString& FixtureCachingStdMapStringString::operator= ( const FixtureCachingStdMapStringString &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

FixtureCachingStdMapStringString& FixtureCachingStdMapStringString::operator= ( FixtureCachingStdMapStringString && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
