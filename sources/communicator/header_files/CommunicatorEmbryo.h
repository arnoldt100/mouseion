#ifndef COMMUNICATOR_CommunicatorEmbryo_INC
#define COMMUNICATOR_CommunicatorEmbryo_INC
//! \file CommunicatorEmbryo.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <array>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR
{

//! Contains information to build a communicator.
class CommunicatorEmbryo
{
    public:

        // ====================  DATA MEMBERS  =======================================
        enum struct communicator_types {rectangular};

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        CommunicatorEmbryo ();   // constructor

        CommunicatorEmbryo(const communicator_types comm_type,
                           const std::array<std::size_t,3> communicator_spatial_decomposition);

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
        //! \brief Stores the lattice type for the communicator.
        communicator_types communicatorType_;
        
        //! \brief Stores the spatial decomposition of the communicator.
        //!
        //! \details The array has the for [a,b,c] where 
        //! "a" is the dimension of the communicator spatial decomposition for the 0'th dimension.
        //! "b" is the dimension of the communicator spatial decomposition for the first dimension.
        //! "c" is the dimension of the communicator spatial decomposition for the second dimension.
        //! For rectangular coordinates a, b and c are respectively the x,
        //! y and z dimensions.
        std::array<std::size_t,3> communicatorSpatialDecomposition_;


}; // -----  End of class CommunicatorEmbryo  -----


}; // End of namespace COMMUNICATOR

#endif // COMMUNICATOR_CommunicatorEmbryo_INC
