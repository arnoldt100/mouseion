#ifndef  MOUSEION_ErrorUnknownVisitor_INC
#define  MOUSEION_ErrorUnknownVisitor_INC


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

namespace MPL
{

// =====================================================================================
//        Class:  ErrorUnknownVisitor
//  Description:  
//  =====================================================================================
class ErrorUnknownVisitor : public std::exception
{
    public:
        // ====================  LIFECYCLE     =======================================

        ErrorUnknownVisitor ();   // constructor

        ErrorUnknownVisitor (const ErrorUnknownVisitor & other);   // copy constructor

        ErrorUnknownVisitor (ErrorUnknownVisitor && other);   // copy-move constructor

        ~ErrorUnknownVisitor ();  // destructor

        // ====================  ACCESSORS     =======================================
        const char* what() const noexcept;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorUnknownVisitor& operator= ( const ErrorUnknownVisitor &other ); // assignment operator

        ErrorUnknownVisitor& operator= ( ErrorUnknownVisitor && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ErrorUnknownVisitor  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_ErrorUnknownVisitor_INC  ----- 
