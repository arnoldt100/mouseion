#ifndef  MOUSEION_AbstractFactoryUnit_INC
#define  MOUSEION_AbstractFactoryUnit_INC

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
//        Class:  AbstractFactoryUnit
//  Description:  
//  =====================================================================================
template<typename T>
class AbstractFactoryUnit
{
    template<typename T>
    using Type2Type = boost::mp11::mp_identity<T>; 

    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  AbstractFactoryUnit
        //      Method:  AbstractFactoryUnit :: AbstractFactoryUnit
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        AbstractFactoryUnit () // constructor
        {
            return;
        }

        AbstractFactoryUnit (const AbstractFactoryUnit & other) // copy constructor
        {
            return;
        }

        AbstractFactoryUnit (AbstractFactoryUnit && other)   // copy-move constructor
        {
            return;
        }

        virtual ~AbstractFactoryUnit () // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        virtual T* DoCreate(Type2Type<T>)=0;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AbstractFactoryUnit& operator= ( const AbstractFactoryUnit &other ) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        AbstractFactoryUnit& operator= ( AbstractFactoryUnit && other ) // assignment-move operator
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

}; // -----  end of class AbstractFactoryUnit  -----


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_AbstractFactoryUnit_INC  ----- 
