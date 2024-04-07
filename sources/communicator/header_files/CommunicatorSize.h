#ifndef COMMUNICATOR_CommunicatorSize_INC
#define COMMUNICATOR_CommunicatorSize_INC
//! \file CommunicatorSize.h
//!
//! \brief Brief description
//!
//! \details Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cstddef>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR
{

class CommunicatorSize
{
    public:
        using value_t = std::ptrdiff_t;

    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        CommunicatorSize ();   // constructor

        //! The default constructor.
        explicit CommunicatorSize ( const CommunicatorSize::value_t & my_value);   // constructor

        //! The copy constructor.
        CommunicatorSize (const CommunicatorSize & other);   // copy constructor

        //! The move constructor.
        CommunicatorSize (CommunicatorSize && other);   // copy-move constructor

        ~CommunicatorSize ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        CommunicatorSize * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        CommunicatorSize& operator= ( const CommunicatorSize &other ); // assignment operator

        //! The move assignment operator.
        CommunicatorSize& operator= ( CommunicatorSize && other ); // assignment-move operator

        CommunicatorSize::value_t operator()() const;
                                                      //
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        value_t communicatorSize_; 

}; // -----  End of class CommunicatorSize  -----


}; // End of namespace COMMUNICATOR

#endif // COMMUNICATOR_CommunicatorSize_INC
