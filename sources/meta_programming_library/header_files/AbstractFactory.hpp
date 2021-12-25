#ifndef  MOUSEION_AbstractFactory_INC
#define  MOUSEION_AbstractFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/mp11.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MPL
{

// =====================================================================================
//        Class:  AbstractFactory
//  Description:  
//  =====================================================================================
class AbstractFactory
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  AbstractFactory
        //      Method:  AbstractFactory :: AbstractFactory
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        AbstractFactory () // constructor
        {
            return;
        }

        AbstractFactory (const AbstractFactory & other) // copy constructor
        {
            return;
        }

        AbstractFactory (AbstractFactory && other)  // copy-move constructor
        {
            return;
        }

        virtual ~AbstractFactory () // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AbstractFactory& operator= ( const AbstractFactory &other ) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator


        AbstractFactory& operator= ( AbstractFactory && other ) // assignment-move operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AbstractFactory  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_AbstractFactory_INC  ----- 
