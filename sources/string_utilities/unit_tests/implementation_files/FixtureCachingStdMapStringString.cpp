//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

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

FixtureCachingStdMapStringString::FixtureCachingStdMapStringString() :
    experimentalVecStringCache{},
    controlVecStringCache{}
{
    return;
}

FixtureCachingStdMapStringString::FixtureCachingStdMapStringString( FixtureCachingStdMapStringString const & other) :
    experimentalVecStringCache(other.experimentalVecStringCache),
    controlVecStringCache(other.controlVecStringCache)
{
    if (this != &other)
    {
    }
    return;
}

FixtureCachingStdMapStringString::FixtureCachingStdMapStringString( FixtureCachingStdMapStringString && other) :
    experimentalVecStringCache(std::move(other.experimentalVecStringCache)),
    controlVecStringCache(std::move(other.controlVecStringCache))

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
        this->experimentalVecStringCache = other.experimentalVecStringCache;
        this->controlVecStringCache = other.controlVecStringCache;
    }
    return *this;
} // assignment operator

FixtureCachingStdMapStringString& FixtureCachingStdMapStringString::operator= ( FixtureCachingStdMapStringString && other )
{
    if (this != &other)
    {
        this->experimentalVecStringCache = std::move(other.experimentalVecStringCache);
        this->controlVecStringCache = std::move(other.controlVecStringCache);
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
