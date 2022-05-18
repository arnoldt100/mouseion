#ifndef  COMMUNICATOR_NullMPIEnvironment_INC
#define  COMMUNICATOR_NullMPIEnvironment_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIEnvironmentState.h"

namespace COMMUNICATOR
{

// =====================================================================================
//        Class:  NullMPIEnvironment
//  Description:  
//  =====================================================================================
class NullMPIEnvironment : public MPIEnvironmentState
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  NullMPIEnvironment
        //      Method:  NullMPIEnvironment :: NullMPIEnvironment
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        NullMPIEnvironment ();   // constructor

        NullMPIEnvironment (const NullMPIEnvironment & other);   // copy constructor

        NullMPIEnvironment (NullMPIEnvironment && other);   // copy-move constructor

        ~NullMPIEnvironment ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        NullMPIEnvironment& operator= ( const NullMPIEnvironment &other ); // assignment operator

        NullMPIEnvironment& operator= ( NullMPIEnvironment && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  MUTATORS      =======================================

        void enable_() override;

        void disable_() override;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class NullMPIEnvironment  -----


}; // namespace COMMUNICATOR

#endif   /* ----- #ifndef COMMUNICATOR_NullMPIEnvironment_INC  ----- */
