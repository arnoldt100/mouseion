#ifndef COMMUNICATOR_MASTERPROCESS_INC
#define COMMUNICATOR_MASTERPROCESS_INC
//! @file master_process.h

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
//        Class:  MasterProcess
//  Description:  
//  =====================================================================================
class MasterProcess
{
    public:
        // ====================  LIFECYCLE     =======================================

        MasterProcess ();   // constructor

        MasterProcess (const bool master_process);   // constructor

        MasterProcess (const MasterProcess & other);   // copy constructor

        MasterProcess (MasterProcess && other);   // copy-move constructor

        ~MasterProcess ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MasterProcess& operator= ( const MasterProcess &other ); // assignment operator

        MasterProcess& operator= ( MasterProcess && other ); // assignment-move operator

        bool operator()() const;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        bool masterProcess_;

}; // -----  end of class MasterProcess  -----


}; // namespace COMMUNICATOR

#endif // COMMUNICATOR_MASTERPROCESS_INC
