#ifndef  MOUSEION_DefaultCatchAll_INC
#define  MOUSEION_DefaultCatchAll_INC


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
#include "ErrorUnknownVisitor.h"

namespace MPL
{

//--------------------------------------------------------//
//-------------------- Forward Declarations --------------//
//--------------------------------------------------------//
class BaseVisitor;

// =====================================================================================
//        Class:  DefaultCatchAll
//  Description:  
//  =====================================================================================
template<class R, class Visited>
class DefaultCatchAll
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  DefaultCatchAll
        //      Method:  DefaultCatchAll :: DefaultCatchAll
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        DefaultCatchAll ()   // constructor
        {
            return;
        }

        DefaultCatchAll (const DefaultCatchAll & other)   // copy constructor
        {
            return;
        }		// -----  end of method DefaultCatchAll::DefaultCatchAll  -----

        DefaultCatchAll (DefaultCatchAll && other)   // copy-move constructor
        {
            return;
        }		// -----  end of method DefaultCatchAll::DefaultCatchAll  -----


        virtual ~DefaultCatchAll ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        DefaultCatchAll& operator= ( const DefaultCatchAll &other ) // assignment operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        DefaultCatchAll& operator= ( DefaultCatchAll && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        // ====================  STATIC        =======================================
        static R OnUnknownVisitor(Visited& v , BaseVisitor& bv )
        {
            std::cout << "I'm an unknown visitor: " << std::endl << std::flush;
            throw ErrorUnknownVisitor();
            return R();
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class DefaultCatchAll  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_DefaultCatchAll_INC  ----- 
