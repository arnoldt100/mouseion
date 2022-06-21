#ifndef MOUSEION_OpNewFactoryUnit
#define MOUSEION_OpNewFactoryUnit


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"
#include "Pointer.hpp"

namespace MPL
{

     // =====================================================================================
     //        Class:  OpNewFactoryUnit
     //  Description:  
     //  =====================================================================================
    template <typename ConcreteProduct, typename Base>
    class OpNewFactoryUnit : public Base
    {

        public:
            using AbstractProduct = mpl_front<typename Base::ProductList>;

            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  OpNewFactoryUnit
            //      Method:  OpNewFactoryUnit :: OpNewFactoryUnit
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            OpNewFactoryUnit ()   // constructor
            {
                return;
            }

            OpNewFactoryUnit (const OpNewFactoryUnit & other) : // copy constructor
                Base(other)
            {
                if (this != &other)
                {

                }
                return;
            }

            OpNewFactoryUnit (OpNewFactoryUnit && other) : // copy-move constructor
                Base(std::move(other))
            {
                if (this != &other)
                {

                }
                return;
            }

            virtual ~OpNewFactoryUnit ()  // destructor
            {
                return;
            }

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================
            ConcreteProduct* DoCreate(mpl_type2type<AbstractProduct>)
            {
                return new ConcreteProduct;
            }

            // ====================  OPERATORS     =======================================

            OpNewFactoryUnit& operator= ( const OpNewFactoryUnit &other ) // assignment operator
            {
                if ( this != &other)
                {
                    Base::operator=(other);
                }
                return *this;
            }

            OpNewFactoryUnit& operator= ( OpNewFactoryUnit && other ) // assignment-move operator
            {
                if (this != &other)
                {

                }
                return *this;
            }

        protected:

            using ProductList = mpl_rest<typename Base::ProductList>;

            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            using BaseProductList = typename Base::ProductList;

            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class OpNewFactoryUnit  -----


}; // namespace MPL

#endif // MOUSEION_OpNewFactoryUnit
