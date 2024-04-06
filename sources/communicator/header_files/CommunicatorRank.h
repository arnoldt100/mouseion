#ifndef COMMUNICATOR_CommunicatorRank_INC
#define COMMUNICATOR_CommunicatorRank_INC
//! \file CommunicatorRank.h
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

class CommunicatorRank
{
    public:
        using rank_t = std::ptrdiff_t;

    public:

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        CommunicatorRank ();   // constructor

        explicit CommunicatorRank (rank_t const & rank );   // constructor

        //! The copy constructor.
        CommunicatorRank (const CommunicatorRank & other);   // copy constructor

        //! The move constructor.
        CommunicatorRank (CommunicatorRank && other);   // copy-move constructor

        ~CommunicatorRank ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        CommunicatorRank * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        CommunicatorRank& operator= ( const CommunicatorRank &other ); // assignment operator

        //! The move assignment operator.
        CommunicatorRank& operator= ( CommunicatorRank && other ); // assignment-move operator

        rank_t operator()() const ;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        rank_t communicatorRank_; 

}; // -----  End of class CommunicatorRank  -----


}; // End of namespace COMMUNICATOR

#endif // COMMUNICATOR_CommunicatorRank_INC
