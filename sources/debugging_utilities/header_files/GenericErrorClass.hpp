#ifndef MOUSEION_GenericErrorClass_INC
#define MOUSEION_GenericErrorClass_INC
//! \file GenericErrorClass.h
//!
//! \brief Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "BaseException.h"

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <utility>
#include <string>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MOUSEION
{

template< typename ClassType>
class GenericErrorClass : MOUSEION::BaseException
{
    public:

        // ====================  LIFECYCLE     =======================================

        GenericErrorClass () :  // constructor
            MOUSEION::BaseException(),
            errorMessage_{}
        {
            return;
        }

        GenericErrorClass (const std::string message) :  // constructor
            MOUSEION::BaseException(),
            errorMessage_{message}
        {
            return;
        }

        GenericErrorClass (const GenericErrorClass & other) :  // copy constructor
            MOUSEION::BaseException(other),
            errorMessage_{other.errorMessage_}
        {
            if (this != &other)
            {
            }
            return;
        }

        GenericErrorClass (GenericErrorClass && other):   // copy-move constructor
            MOUSEION::BaseException(std::move(other)),
            errorMessage_{std::move(other.errorMessage_)}
        {
            if (this != &other)
            {
            }
        return;
        }		// -----  end of method GenericErrorClass::GenericErrorClass  -----

         ~GenericErrorClass ()  // destructor
         {
             return;
         }

        // ====================  ACCESSORS     =======================================

        const char* what() const noexcept
        {
            return this->errorMessage_.c_str();
        }

        GenericErrorClass * clone () const
        {
            return new GenericErrorClass(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericErrorClass& operator= ( const GenericErrorClass &other ) // assignment operator
        {
            if (this != &other)
            {
                MOUSEION::BaseException::operator=(other);
                this->errorMessage_ = other.errorMessage_;
            }
            return *this;
        } // assignment operator

        GenericErrorClass& operator= ( GenericErrorClass && other ) // assignment-move operator
        {
            if (this != &other)
            {
                MOUSEION::BaseException::operator=(std::move(other));
                this->errorMessage_ = std::move(other.errorMessage_);
            }
            return *this;
        } // assignment operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string errorMessage_;
        
}; // -----  end of class GenericErrorClass  -----


}; // namespace MOUSEION

#endif // MOUSEION_GenericErrorClass_INC
