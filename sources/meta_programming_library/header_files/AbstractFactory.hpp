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

template <typename TL1, template<class...> class MF1>
using GenScatterHierarchy = boost::mp11::mp_rename<TL1,MF1>;

// =====================================================================================
//        Class:  AbstractFactory
//  Description:  
//  =====================================================================================
template <typename TypeList, template<typename> typename Unit=AbstractFactoryUnit >
class AbstractFactory : public GenScatterHierarchy<TypeList,Unit>
{
    template<typename T1>
    using Type2Type = boost::mp11::mp_identity<T1>; 

    using ProductList= TypeList;

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
        template <typename T2> 
        T2* Create()
        {
            Unit<T2> & unit = *this;
            return unit.DoCreate(Type2Type<T2>());
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
