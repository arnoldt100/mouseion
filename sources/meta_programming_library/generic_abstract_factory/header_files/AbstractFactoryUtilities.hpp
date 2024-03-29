#ifndef MPL_AbstractFactoryUtilities_INC
#define MPL_AbstractFactoryUtilities_INC
//! @file AbstractFactoryUtilities.hpp
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MPL
{

template<typename AbstractProductsTypeList, typename ConcreteProductsTypeList>
class AbstractFactoryUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        AbstractFactoryUtilities ()   // constructor
        {
            return;
        }

        ~AbstractFactoryUtilities ()  // destructor
        {
            return;
        }


    public:

        template <typename abstract_product_t>
        static constexpr std::size_t findIndex()
        {
            using list_base = MPL::mpl_repeat_c<MPL::mpl_typelist<abstract_product_t>, 
            MPL::mpl_size<AbstractProductsTypeList>::value>;
            using R = MPL::mpl_transform<my_is_base_of_,AbstractProductsTypeList,list_base>;
            using my_index = MPL::mpl_find<R,MPL::mpl_true_type>;
            return my_index::value;
        } 

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        template<class Base,class Derived>
        using my_is_base_of_ = typename MPL::mpl_bool<MPL::mpl_is_base_of<Base,Derived>::value>;

    public:

        template <typename abstract_product_t>
        using corresponding_concrete_task = MPL::mpl_at_c<ConcreteProductsTypeList,findIndex<abstract_product_t>()>;

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AbstractFactoryUtilities  -----



}; // namespace MPL

#endif // MPL_AbstractFactoryUtilities_INC
