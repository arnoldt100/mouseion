
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
#include "Array1d.hpp"
#include "VectorStringCache.h"

namespace STRING_UTILITIES {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

VectorStringCache::VectorStringCache() :
    ncpvLength_(0),
    numberCharactersPerVector_(nullptr),
    caLength_(0),
    charactersArray_(nullptr)
{
    return;
}

VectorStringCache::~VectorStringCache()
{
    MEMORY_MANAGEMENT::Array1d<std::size_t> int_factory;
    int_factory.destroyArray(this->numberCharactersPerVector_);

    MEMORY_MANAGEMENT::Array1d<char> char_factory;
    char_factory.destroyArray(this->charactersArray_);

    return;
}

VectorStringCache::VectorStringCache( VectorStringCache const & other) :
    ncpvLength_(other.ncpvLength_),
    numberCharactersPerVector_(nullptr),
    caLength_(other.caLength_),
    charactersArray_(nullptr)
{
    if (this != &other)
    {
        for (auto ip = static_cast<std::size_t>(0); ip < this->ncpvLength_; ++ip)
        {
            this->numberCharactersPerVector_[ip] = other.numberCharactersPerVector_[ip];
        }

        for (auto jp=static_cast<std::size_t>(0); jp < this->caLength_; ++jp)
        {
            this->charactersArray_[jp] = other.charactersArray_[jp];
        }
    }
    return;
}

VectorStringCache::VectorStringCache( VectorStringCache && other) :
    ncpvLength_(other.ncpvLength_),
    caLength_(other.caLength_)
{
    if (this != &other)
    {
        this->numberCharactersPerVector_ = std::move(other.numberCharactersPerVector_);
        this->charactersArray_ = std::move(other.charactersArray_);
    }
    return;
}		// -----  end of method VectorStringCache::VectorStringCache  -----

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

VectorStringCache& VectorStringCache::operator= ( const VectorStringCache &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

VectorStringCache& VectorStringCache::operator= ( VectorStringCache && other )
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


} // namespace STRING_UTILITIES
