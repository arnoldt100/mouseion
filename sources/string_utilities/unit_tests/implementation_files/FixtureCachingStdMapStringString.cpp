//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FixtureCachingStdMapStringString.h"
#include "copy_1d_array.hpp"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

FixtureCachingStdMapStringString::FixtureCachingStdMapStringString() :
    myTestString{},
    control_ncpvLength{0},
    control_caLength{0},
    control_characterArray{},
    control_numberCharactersPerVectorElement{},
    experimentalVecStringCache{},
    controlVecStringCache{}
{
    return;
}

FixtureCachingStdMapStringString::FixtureCachingStdMapStringString(const std::vector<std::string> vec_string,
                                                                   const std::size_t control_ncpv_length,
                                                                   const std::unique_ptr<std::size_t[]> & control_ncpv,
                                                                   const std::size_t control_ca_length,
                                                                   const std::unique_ptr<char[]> & control_ca ) :
    myTestString{},
    control_ncpvLength{control_ncpv_length},
    control_caLength{control_ca_length},
    control_characterArray{},
    control_numberCharactersPerVectorElement{},
    experimentalVecStringCache(vec_string),
    controlVecStringCache{}
{
    // Create a copy of the unique pointers control_ncpv and control_ca, and use
    // the copies to create the control VectorStringCache.  
    std::unique_ptr<std::size_t[]> tmp_control_ncpv = std::make_unique_for_overwrite<std::size_t[]>(control_ncpv_length);
    for (std::size_t ip=0; ip < control_ncpv_length; ip++)
    {
        tmp_control_ncpv[ip] =  control_ncpv[ip];
    }

    std::unique_ptr<char[]> tmp_control_ca = std::make_unique_for_overwrite<char[]>(control_ca_length);
    for (std::size_t ip=0; ip < control_ca_length; ip++)
    {
        tmp_control_ca[ip] = control_ca[ip];  
    }

    this->controlVecStringCache = 
        STRING_UTILITIES::VectorStringCache(control_ncpv_length,
                                            std::move(tmp_control_ncpv),
                                            control_ca_length,
                                            std::move(tmp_control_ca));
    return;
}

FixtureCachingStdMapStringString::FixtureCachingStdMapStringString( FixtureCachingStdMapStringString const & other) :
    myTestString(other.myTestString),
    control_ncpvLength{other.control_ncpvLength},
    control_caLength{other.control_caLength},
    control_characterArray{},
    control_numberCharactersPerVectorElement{},
    experimentalVecStringCache(other.experimentalVecStringCache),
    controlVecStringCache(other.controlVecStringCache)
{
    if (this != &other)
    {
        // Create a copy of the unique pointers control_ncpv and control_ca, and use
        // the copies to create the control VectorStringCache.  
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
void FixtureCachingStdMapStringString::setup()
{
    // Setup experimentalVecStringCache
    this->setupExperimentalVecStringCache_();

    // Setup controlVecStringCache
    this->setupControlVecStringCache_();

    return;
}

void FixtureCachingStdMapStringString::teardown()
{
    return;
}
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

void FixtureCachingStdMapStringString::setupExperimentalVecStringCache_()
{
    // The control data to form the experimental fixture.
    this->myTestString = {std::string("ABCDEFG"),
                          std::string("12345678"),
                          std::string("abcdefghi")
                         };
    this->experimentalVecStringCache = STRING_UTILITIES::VectorStringCache(this->myTestString);


    return;
}

void FixtureCachingStdMapStringString::setupControlVecStringCache_()
{
    this->control_ncpvLength = 3;
    this->control_numberCharactersPerVectorElement = 
        std::make_unique_for_overwrite<std::size_t[]>(this->control_ncpvLength);
    this->control_numberCharactersPerVectorElement[0] = (this->myTestString[0]).size();
    this->control_numberCharactersPerVectorElement[1] = (this->myTestString[1]).size();
    this->control_numberCharactersPerVectorElement[2] = (this->myTestString[2]).size();
    this->control_caLength = 0;
    for ( auto it = (this->myTestString).begin(); it != (this->myTestString).end(); ++it)
    {
        auto str_length = (*it).length();
        this->control_ncpvLength += str_length;
    }
    this->control_ncpvLength += 1;

    this->control_characterArray = std::make_unique_for_overwrite<char[]>(this->control_caLength);

    std::size_t jp = 0;
    for ( auto it = (this->myTestString).begin(); it != (this->myTestString).end(); ++it)
    {
        auto str_length = (*it).length();
        for (auto ip=0; ip < str_length; ++ip)
        {
            this->control_characterArray[jp] = (*it)[ip];
            ++jp;
        }
    }
    this->control_characterArray[jp] = '\0';

    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
