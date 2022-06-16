#ifndef  MOUSEION_Command_INC
#define  MOUSEION_Command_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MPL
{

// =====================================================================================
//        Class:  Command
//  Description:  
//  =====================================================================================
class Command
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  Command
        //      Method:  Command :: Command
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        Command ();   // constructor


        Command (const Command & other);   // copy constructor

        Command (Command && other);   // copy-move constructor

        virtual ~Command ()=0;  // destructor

        // ====================  ACCESSORS     =======================================
        void doCommand() const;

        void undoCommand() const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        Command& operator= ( const Command &other ); // assignment operator

        Command& operator= ( Command && other ); // assignment-move operator

    protected:
        // ====================  ACCESSORS     =======================================
        virtual void doCommand_() const;

        virtual void undoCommand_() const;

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class Command  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_Command_INC  ----- 
