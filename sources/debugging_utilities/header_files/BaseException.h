#ifndef MOUSEION_BaseException_INC
#define MOUSEION_BaseException_INC
//! \file BaseException.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MOUSEION
{

//! \brief The base class of which all error classes inherit from.
class BaseException : public std::exception
{
    public:
        // ====================  LIFECYCLE     =======================================

        BaseException ();   // constructor

        BaseException (const BaseException & other);   // copy constructor

        BaseException (BaseException && other);   // copy-move constructor

        virtual ~BaseException ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        BaseException& operator= ( const BaseException &other ); // assignment operator

        BaseException& operator= ( BaseException && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class BaseException  -----


}; // namespace MOUSEION

#endif // MOUSEION_BaseException_INC
