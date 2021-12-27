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
#include "AbstractFactoryUnit.hpp"

namespace MPL
{

// =====================================================================================
//        Class:  AbstractFactory
//  Description:  
//  =====================================================================================
template <typename TList, template<typename> typename unit=AbstractFactoryUnit >
class AbstractFactory : public boost::mp11::rename<TList,unit>()
{
    template<typename T>
    using Type2Type = boost::mp11::mp_identity<T>; 

    using ProductList= TList;

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
        template <typename T> T* Create()
        {
            Unit <T> & unit = *this;
            return unit.DoCreate(Type2Type<T>());
        }

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
