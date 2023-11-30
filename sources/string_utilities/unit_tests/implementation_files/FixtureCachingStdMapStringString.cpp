
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
	// TODO Auto-generated constructor stub
    return;
}

FixtureCachingStdMapStringString::FixtureCachingStdMapStringString( FixtureCachingStdMapStringString const & other)
{
	// TODO Auto-generated constructor stub
    if (this != &other)
    {
        
    }
    return;
}

FixtureCachingStdMapStringString::FixtureCachingStdMapStringString( FixtureCachingStdMapStringString && other)
{
	// TODO Auto-generated constructor stub
    if (this != &other)
    {
    }
    return;
}		// -----  end of method FixtureCachingStdMapStringString::FixtureCachingStdMapStringString  -----


FixtureCachingStdMapStringString::~FixtureCachingStdMapStringString()
{
	// TODO Auto-generated destructor stub
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
