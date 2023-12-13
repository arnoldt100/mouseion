//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <algorithm>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "copy_1d_array.hpp"
#include "Array1d.hpp"
#include "Array1dChar.hpp"
#include "VectorStringCache.h"
#include "under_line_string.h"

namespace STRING_UTILITIES {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

VectorStringCache::VectorStringCache() :
    ncpvLength_{0},
    numberCharactersPerVectorElement_{nullptr},
    caLength_{0},
    charactersArray_{nullptr}
{
    return;
}

VectorStringCache::VectorStringCache(const std::vector<std::string> & str_vec) :
    ncpvLength_{0},
    numberCharactersPerVectorElement_{nullptr},
    caLength_{0},
    charactersArray_{nullptr}
{
    // ---------------------------------------------------
    // Compute the total number of characters in all elements of the
    // string vector.
    // ---------------------------------------------------
    for (auto a_string : str_vec)
    {
        this->caLength_ += a_string.size();
    }
    this->caLength_ += 1; //  We need to  account for the '/0' termination character.

    // ---------------------------------------------------
    // Compute the number of elements in vector "str_vec".
    // ---------------------------------------------------
    this->ncpvLength_ = str_vec.size();

    // ---------------------------------------------------
    // Allocate array numberCharactersPerVectorElement_ and fill in.
    // ---------------------------------------------------
    this->numberCharactersPerVectorElement_ = std::make_unique<std::size_t[]>(this->ncpvLength_);
    std::size_t ip = 0;
    for (auto a_string : str_vec)
    {
        this->numberCharactersPerVectorElement_[ip] = a_string.size();
        ++ip;
    }

    // ---------------------------------------------------
    // Allocate array charactersArray_ and fill in and we add the termination
    // character '/0' at the end.
    // ---------------------------------------------------
    this->charactersArray_ = std::make_unique<char[]>(this->caLength_);
    std::size_t jp = 0;
    for (auto a_string : str_vec)
    {
        for ( auto a_char : a_string)
        {
            this->charactersArray_[jp] = a_char;
            ++jp;
        }
    }
    this->charactersArray_[jp] = '\0';
    return;
}


VectorStringCache::VectorStringCache(const std::size_t ncpv_length,
                                     std::unique_ptr<std::size_t[]> ncpv_array,
                                     const std::size_t ca_length,
                                     std::unique_ptr<char[]> ca_array) :
    ncpvLength_{ncpv_length},
    numberCharactersPerVectorElement_{std::move(ncpv_array)},
    caLength_{ca_length},
    charactersArray_{std::move(ca_array)}
{
  return;
}



VectorStringCache::~VectorStringCache()
{
    return;
}

VectorStringCache::VectorStringCache(VectorStringCache const & other) :
    ncpvLength_{0},
    numberCharactersPerVectorElement_{nullptr},
    caLength_{0},
    charactersArray_{nullptr}
{
    if (this != &other)
    {
        // Fill in the array "this->numberCharactersPerVectorElement_".
        std::tie(this->numberCharactersPerVectorElement_,this->ncpvLength_) =
            MEMORY_MANAGEMENT::copy_1d_array(other.numberCharactersPerVectorElement_,
                                           other.ncpvLength_);

        // Fill in the array "this->charactersArray_".
        std::tie(this->charactersArray_,this->caLength_) = 
            MEMORY_MANAGEMENT::copy_1d_array(other.charactersArray_,other.caLength_);
    }
    return;
}

VectorStringCache::VectorStringCache( VectorStringCache && other) :
    ncpvLength_(std::move(other.ncpvLength_)),
    numberCharactersPerVectorElement_{nullptr},
    caLength_(std::move(other.caLength_)),
    charactersArray_{nullptr}
{
    if (this != &other)
    {
        this->numberCharactersPerVectorElement_ = std::move(other.numberCharactersPerVectorElement_);
        other.numberCharactersPerVectorElement_ = nullptr;
        other.ncpvLength_ = 0;
        this->charactersArray_ = std::move(other.charactersArray_);
        other.charactersArray_ = nullptr;
        other.caLength_ = 0;
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

std::unique_ptr<std::size_t[]> VectorStringCache::getArrayOfNumberCharactersPerVector() const
{
    std::unique_ptr<std::size_t[]> out_ptr = std::make_unique<std::size_t[]>(this->ncpvLength_);
    for (auto ip=static_cast<std::size_t>(0); ip < this->ncpvLength_; ++ip )
    {
        out_ptr[ip] = this->numberCharactersPerVectorElement_[ip];
    }
    return out_ptr;
}

std::tuple<std::unique_ptr<char[]>, std::size_t> VectorStringCache::getArrayOfCharacters() const
{
    std::unique_ptr<char[]> out_ptr = std::make_unique<char[]>(this->caLength_);
    std::size_t tmp_ca_length = this->caLength_;
    for (auto ip=static_cast<std::size_t>(0); ip <this->caLength_; ++ip )
    {
        out_ptr[ip] = this->charactersArray_[ip];
    }
    return std::tuple<std::unique_ptr<char[]>, std::size_t> (std::move(out_ptr),tmp_ca_length);
}

std::vector<std::string> VectorStringCache::getStringVector() const
{
    std::vector<std::string> ret_value;
    char const * src = this->charactersArray_.get();
    std::cout << "src = " << src << std::endl;

    for (auto ip = static_cast<std::size_t>(0); ip < this->ncpvLength_; ++ip)
    {
        // Get the number of characters in the next word.
        const std::size_t nm_chars = this->numberCharactersPerVectorElement_[ip];

        // Increment the pointer src to the next starting position
        // for the next set of characters and create a string with these
        // characters.
        if (ip > 0)
        {
            src += nm_chars-1;
        }
        std::cout << "src = " << src << std::endl;
        const std::string tmp_string(src,nm_chars);
        std::cout << "src = " << tmp_string.c_str() << std::endl;

        // Add the newly created string to  
        ret_value.push_back(tmp_string);
    }
    return ret_value;
}

void VectorStringCache::printToStdOut() const
{
    const std::string header("VectorStringCache");
    const std::size_t len1 = header.size();
    const std::string line = underline_string(len1); 
    std::cout << line.c_str() << std::endl;
    std::cout << "VectorStringCache" << std::endl;
    std::cout << line.c_str() << std::endl;
    std::cout << "this->ncpvLength_ = " << this->ncpvLength_ << std::endl;
    for (auto ip = static_cast<std::size_t>(0); ip < this->ncpvLength_; ++ip)
    {
        std::cout << "this->numberCharactersPerVectorElement_[" << ip << "] = "; 
        std::cout << this->numberCharactersPerVectorElement_[ip] << std::endl;
    }
    std::cout << std::endl; 

    std::size_t counter = 0;
    for (auto ip = static_cast<std::size_t>(0); ip < this->ncpvLength_; ++ip)
    {
        std::cout << "Entry: " << ip << std::endl;
        std::cout << "Character range: " << counter << " - " << counter + this->numberCharactersPerVectorElement_[ip] - 1 << std::endl;
        for (auto jp=0; jp < this->numberCharactersPerVectorElement_[ip]; ++jp )
        {
            std::cout << this->charactersArray_[counter];
            ++counter;
        }
        std::cout << std::endl; 
        std::cout << std::endl; 
    }

    std::cout << std::endl; 
    std::cout << line.c_str() << std::endl << std::endl;
    return;
}
//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

VectorStringCache& VectorStringCache::operator= ( const VectorStringCache &other )
{
    if (this != &other)
    {
        std::tie(this->numberCharactersPerVectorElement_,this->ncpvLength_) = 
            MEMORY_MANAGEMENT::copy_1d_array(other.numberCharactersPerVectorElement_,
                                             other.ncpvLength_);

        // Fill in the array "this->charactersArray_".
        std::tie(this->charactersArray_,this->caLength_) = 
            MEMORY_MANAGEMENT::copy_1d_array(other.charactersArray_,other.caLength_);

    }
    return *this;
} // assignment operator

VectorStringCache& VectorStringCache::operator= ( VectorStringCache && other )
{
    if (this != &other)
    {
        // Move values to  class members elements "this->ncpvLength_" and
        // "this->numberCharactersPerVectorElement_".
        this->ncpvLength_ = other.ncpvLength_;
        this->numberCharactersPerVectorElement_ =  std::move(other.numberCharactersPerVectorElement_);
        other.ncpvLength_ = 0;
        other.numberCharactersPerVectorElement_ = nullptr;

        // Move values to class members elements "this->caLength_" and
        // "this->charactersArray_".
        this->caLength_ = other.caLength_;
        this->charactersArray_ = std::move(other.charactersArray_);
        other.caLength_ = 0;
        other.charactersArray_ = nullptr;
    }
    return *this;
} // assignment-move operator

bool VectorStringCache::operator==( VectorStringCache const & other ) const
{
    bool status_ncpv = (this->ncpvLength_ == other.ncpvLength_) ? true : false;
    bool ncpv_elements_are_same = true; 
    if (status_ncpv)
    {
        for (std::size_t ip=0; ip < this->ncpvLength_; ++ip)
        {
            if (this->numberCharactersPerVectorElement_[ip] != other.numberCharactersPerVectorElement_[ip]) 
            {
                ncpv_elements_are_same = false;
                status_ncpv = false;
            }
        }
    } 
    else
    {
        ncpv_elements_are_same = false;
    }

    bool status_ca = (this->caLength_ == other.caLength_) ? true : false;
    bool ca_elements_are_same = true; 
    if (status_ca)
    {
        for (std::size_t ip=0; ip < this->caLength_; ++ip)
        {
            if (this->charactersArray_[ip] != other.charactersArray_[ip]) 
            {
                ca_elements_are_same = false;
                status_ca = false;
            }
        }
    }
    else
    {
        ca_elements_are_same = false;
    }

    const bool objects_are_equal = ( ncpv_elements_are_same  &&  ca_elements_are_same ) ? true : false ;
    return objects_are_equal;
}
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
