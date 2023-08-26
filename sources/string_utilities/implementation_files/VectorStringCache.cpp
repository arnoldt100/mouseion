
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <algorithm>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Array1d.hpp"
#include "Array1dChar.hpp"
#include "VectorStringCache.h"

namespace STRING_UTILITIES {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

VectorStringCache::VectorStringCache() :
    ncpvLength_(0),
    numberCharactersPerVectorElement_(nullptr),
    caLength_(0),
    charactersArray_(nullptr)
{
    return;
}

VectorStringCache::VectorStringCache(const std::vector<std::string> & str_vec) :
    ncpvLength_(0),
    numberCharactersPerVectorElement_(nullptr),
    caLength_(0),
    charactersArray_(nullptr)
{
    // ---------------------------------------------------
    // Compute the total number of characters in all elements of the
    // string vector.
    // ---------------------------------------------------
    for (auto a_string : str_vec)
    {
        this->caLength_ += a_string.size();
    }

    // ---------------------------------------------------
    // Compute the number of elements in vector "str_vec".
    // ---------------------------------------------------
    this->ncpvLength_ = str_vec.size();

    // ---------------------------------------------------
    // Allocate array numberCharactersPerVectorElement_ and fill in.
    // ---------------------------------------------------
    MEMORY_MANAGEMENT::Array1d<std::size_t> int_array_factory;
    this->numberCharactersPerVectorElement_ = int_array_factory.createArray(this->ncpvLength_);
    std::size_t ip = 0;
    for (auto a_string : str_vec)
    {
        this->numberCharactersPerVectorElement_[ip] = a_string.size();
        ++ip;
    }

    // ---------------------------------------------------
    // Allocate array charactersArray_ and fill in.
    // ---------------------------------------------------
    MEMORY_MANAGEMENT::Array1d<char> char_array_factory;
    this->charactersArray_ = char_array_factory.createArray(this->caLength_);
    std::size_t jp = 0;
    for (auto a_string : str_vec)
    {
        for ( auto a_char : a_string)
        {
            this->charactersArray_[jp] = a_char;
            ++jp;
        }
    }
    return;
}

VectorStringCache::~VectorStringCache()
{
    MEMORY_MANAGEMENT::Array1d<std::size_t> int_array_factory;
    int_array_factory.destroyArray(this->numberCharactersPerVectorElement_);

    MEMORY_MANAGEMENT::Array1d<char> char_array_factory;
    char_array_factory.destroyArray(this->charactersArray_);

    return;
}

VectorStringCache::VectorStringCache( VectorStringCache const & other) :
    ncpvLength_(other.ncpvLength_),
    numberCharactersPerVectorElement_(nullptr),
    caLength_(other.caLength_),
    charactersArray_(nullptr)
{
    MEMORY_MANAGEMENT::Array1d<std::size_t> int_array_factory;
    MEMORY_MANAGEMENT::Array1d<char> char_array_factory;
    if (this != &other)
    {
        this->numberCharactersPerVectorElement_ = int_array_factory.createArray(this->ncpvLength_);
        for (auto ip = static_cast<std::size_t>(0); ip < this->ncpvLength_; ++ip)
        {
            this->numberCharactersPerVectorElement_[ip] = other.numberCharactersPerVectorElement_[ip];
        }

        this->charactersArray_ = char_array_factory.createArray(this->caLength_);
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
        this->numberCharactersPerVectorElement_ = std::move(other.numberCharactersPerVectorElement_);
        this->charactersArray_ = std::move(other.charactersArray_);
    }
    return;
}		// -----  end of method VectorStringCache::VectorStringCache  -----

//============================= ACCESSORS ====================================
std::size_t VectorStringCache::getNumberCharactersPerVectorArrayLength() const
{
    return this->ncpvLength_;
}

std::size_t VectorStringCache::getCharacterArrayLength() const
{
    return this->caLength_;
}

std::size_t* VectorStringCache::getArrayOfNumberCharactersPerVector() const
{
    MEMORY_MANAGEMENT::Array1d<std::size_t> int_array_factory;
    std::size_t* out_ptr = int_array_factory.createArray(this->ncpvLength_);
    for (auto ip=static_cast<std::size_t>(0); ip <this->ncpvLength_; ++ip )
    {
        out_ptr[ip] = this->numberCharactersPerVectorElement_[ip];
    }
    return out_ptr;
}

char* VectorStringCache::getArrayOfCharacters() const
{
    MEMORY_MANAGEMENT::Array1d<char> char_array_factory;
    char* out_ptr = char_array_factory.createArray(this->caLength_);
    for (auto ip=static_cast<std::size_t>(0); ip <this->caLength_; ++ip )
    {
        out_ptr[ip] = this->charactersArray_[ip];
    }
    return out_ptr;
}

std::vector<std::string> VectorStringCache::getStringVector() const
{
    std::vector<std::string> a_vec;
    return a_vec;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

VectorStringCache& VectorStringCache::operator= ( const VectorStringCache &other )
{
    MEMORY_MANAGEMENT::Array1d<std::size_t> int_array_factory;
    MEMORY_MANAGEMENT::Array1d<char> char_array_factory;
    if (this != &other)
    {
        // Assign values to  class members elements "this->ncpvLength_" and
        // "this->numberCharactersPerVectorElement_".
        int_array_factory.destroyArray(numberCharactersPerVectorElement_);
        this->ncpvLength_ = other.ncpvLength_;
        this->numberCharactersPerVectorElement_ = int_array_factory.createArray(this->ncpvLength_);
        for ( std::size_t ip = 0; ip < this->ncpvLength_; ++ip)
        {
            this->numberCharactersPerVectorElement_[ip] = other.numberCharactersPerVectorElement_[ip];
        }

        // Assign values to class members elements "this->caLength_" and
        // "this->charactersArray_".
        char_array_factory.destroyArray(charactersArray_);
        this->caLength_ = other.caLength_;
        this->charactersArray_ = char_array_factory.createArray(this->caLength_);
        for ( std::size_t jp = 0; jp < this->caLength_; ++jp)
        {
            this->charactersArray_[jp] = other.charactersArray_[jp];
        }
    }
    return *this;
} // assignment operator

VectorStringCache& VectorStringCache::operator= ( VectorStringCache && other )
{
    MEMORY_MANAGEMENT::Array1d<std::size_t> int_array_factory;
    MEMORY_MANAGEMENT::Array1d<char> char_array_factory;
    if (this != &other)
    {
        // Move values to  class members elements "this->ncpvLength_" and
        // "this->numberCharactersPerVectorElement_".
        this->ncpvLength_ = other.ncpvLength_;
        this->numberCharactersPerVectorElement_ =  std::move(other.numberCharactersPerVectorElement_);
        int_array_factory.destroyArray(other.numberCharactersPerVectorElement_);
        other.ncpvLength_ = 0;

        // Move values to class members elements "this->caLength_" and
        // "this->charactersArray_".
        this->caLength_ = other.caLength_;
        this->charactersArray_ = std::move(other.charactersArray_);
        char_array_factory.destroyArray(other.charactersArray_);
        other.caLength_ = 0;
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
