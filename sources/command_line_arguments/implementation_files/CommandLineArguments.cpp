//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <cstring>
#include <new>
#include <algorithm>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandLineArguments.h"
#include "AssertValidValueForType.hpp"
#include "Array1d.hpp" 
#include "Pointer2d.hpp"

namespace COMMANDLINE {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommandLineArguments::CommandLineArguments() :
_numberOfArguments(0)
{
    return;
}

CommandLineArguments::CommandLineArguments( const int argc, char const * const *const & argv) :
_numberOfArguments(static_cast<std::size_t>(argc))
{
    
    assertm(argc >= 0, "argc is negative");
    for (int ip=0; ip < argc; ++ip)
    {
        const std::string aArgument(argv[ip]); 
        (this->_commandLineArguments).push_back(aArgument);
    }
    return;
}

CommandLineArguments::CommandLineArguments( const CommandLineArguments &other ) 
{
    if (this != &other)
    {
        this->_numberOfArguments=other._numberOfArguments;
        this->_commandLineArguments = other._commandLineArguments;
    }
    return;
}

CommandLineArguments::CommandLineArguments( CommandLineArguments && other ) 
{
    if (this != &other)
    {
        this->_numberOfArguments = other._numberOfArguments;
        this->_commandLineArguments = std::move(other._commandLineArguments);
        other._numberOfArguments = 0;
    }
    return;
}
CommandLineArguments::~CommandLineArguments()
{
    return;
}

//============================= ACCESSORS ====================================
void CommandLineArguments::reformCommandLineArguments(int & argc, char** & argv) const
{
    // Ensure that argv is not pointing to valid memory (i.e. argv = nullptr).
    assertm(argv == nullptr, "argv isn't set to nullptr.");

    // We declare some 1d pointer array factories.
    MEMORY_MANAGEMENT::Array1d<char> my_array1d_char;
    MEMORY_MANAGEMENT::Array1d<char*> my_array1d_charptr;

    argc = static_cast<int>(this->_numberOfArguments);
    argv = my_array1d_charptr.createArray(this->_numberOfArguments);
    for (auto ip=static_cast<std::size_t>(0); ip < this->_numberOfArguments; ++ip)
    {
        const auto c_string_length = this->_commandLineArguments[ip].length() + 1;
        argv[ip] = my_array1d_char.createArray(c_string_length);
        strcpy(argv[ip],this->_commandLineArguments[ip].c_str());
    }
    return;
}

bool CommandLineArguments::verifyArgumentInCommandLine( const std::string & str ) const
{
    const auto search = std::find(std::begin(this->_commandLineArguments),
                             std::end(this->_commandLineArguments),
                             str);
    const auto v1 = (search != std::end(this->_commandLineArguments)) ? true : false;

    return v1;
}

//============================= MUTATORS =====================================

void CommandLineArguments::reset()
{
    this->_numberOfArguments=0;
    this->_commandLineArguments.clear();
    return;
}
//============================= OPERATORS ====================================

CommandLineArguments&
CommandLineArguments::operator=( const CommandLineArguments & other )
{
    if (this != &other)
    {
        this->_numberOfArguments = other._numberOfArguments;
        this->_commandLineArguments = other._commandLineArguments;
    }
    return *this;
}

CommandLineArguments&
CommandLineArguments::operator=( CommandLineArguments && other )
{
    if (this != &other)
    {
        this->_numberOfArguments = other._numberOfArguments;
        this->_commandLineArguments = std::move(other._commandLineArguments);
        other._numberOfArguments = 0;
    }
    return *this;
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


} /* namespace COMMANDLINE */
