#ifndef  MOUSEION_BaseVisitor_INC
#define  MOUSEION_BaseVisitor_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MPL
{

// =====================================================================================
//        Class:  BaseVisitor
//  Description:  
//  =====================================================================================
class BaseVisitor
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  BaseVisitor
        //      Method:  BaseVisitor :: BaseVisitor
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        BaseVisitor ();   // constructor

        BaseVisitor (const BaseVisitor & other);   // copy constructor

        BaseVisitor (BaseVisitor && other);   // copy-move constructor

        virtual ~BaseVisitor ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        BaseVisitor& operator= ( const BaseVisitor &other ); // assignment operator

        BaseVisitor& operator= ( BaseVisitor && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class BaseVisitor  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_BaseVisitor_INC  ----- 
