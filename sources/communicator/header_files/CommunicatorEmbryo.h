#ifndef COMMUNICATOR_CommunicatorEmbryo_INC
#define COMMUNICATOR_CommunicatorEmbryo_INC
//! \file CommunicatorEmbryo.h
//!
//! \brief Brief description
//!
//! \details Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR
{

class CommunicatorEmbryo
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        CommunicatorEmbryo ();   // constructor

        //! The copy constructor.
        CommunicatorEmbryo (const CommunicatorEmbryo & other);   // copy constructor

        //! The move constructor.
        CommunicatorEmbryo (CommunicatorEmbryo && other);   // copy-move constructor

        ~CommunicatorEmbryo ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        CommunicatorEmbryo * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        CommunicatorEmbryo& operator= ( const CommunicatorEmbryo &other ); // assignment operator

        //! The move assignment operator.
        CommunicatorEmbryo& operator= ( CommunicatorEmbryo && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class CommunicatorEmbryo  -----


}; // End of namespace COMMUNICATOR

#endif // COMMUNICATOR_CommunicatorEmbryo_INC
