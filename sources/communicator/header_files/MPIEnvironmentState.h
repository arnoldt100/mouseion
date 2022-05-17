#ifndef  COMMUNICATOR_MPIEnvironmentState_INC
#define  COMMUNICATOR_MPIEnvironmentState_INC

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

// =====================================================================================
//        Class:  MPIEnvironmentState
//  Description:  
//  =====================================================================================
class MPIEnvironmentState
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  MPIEnvironmentState
        //      Method:  MPIEnvironmentState :: MPIEnvironmentState
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        MPIEnvironmentState ();   // constructor

        MPIEnvironmentState (const MPIEnvironmentState & other);   // copy constructor

        MPIEnvironmentState (MPIEnvironmentState && other);   // copy-move constructor

        virtual ~MPIEnvironmentState ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        void enable();

        void disable();

        // ====================  OPERATORS     =======================================

        MPIEnvironmentState& operator= ( const MPIEnvironmentState &other ); // assignment operator

        MPIEnvironmentState& operator= ( MPIEnvironmentState && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  MUTATORS      =======================================
        virtual void enable_();

        virtual void disable_();

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MPIEnvironmentState  -----


}; // namespace __NAMESPACE__

#endif   /* ----- #ifndef COMMUNICATOR_MPIEnvironmentState_INC  ----- */
