#ifndef  MOUSEION_AbstractFactory_INC
#define  MOUSEION_AbstractFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GenerateScatteredHierarchy.hpp"
#include "AbstractFactoryUnit.hpp"

namespace MPL
{

// =====================================================================================
//        Class:  AbstractFactory
//  Description:  
//  =====================================================================================
template <
           typename TypeList,
           template<typename> typename Unit=AbstractFactoryUnit
         >
class AbstractFactory : public GenerateScatteredHierarchy<Unit, mpl_size<TypeList>,TypeList>
{

    public:
        using ProductList = TypeList;

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
            if (this != &other)
            {

            }
            return;
        }

        AbstractFactory (AbstractFactory && other)  // copy-move constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        virtual ~AbstractFactory () // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        template <typename AbstractProduct> 
        AbstractProduct* Create()
        {
            Unit<AbstractProduct> & unit = *this;
            return unit.DoCreate(mpl_type2type<AbstractProduct>());
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
