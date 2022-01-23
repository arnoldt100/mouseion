#ifndef  MOUSEION_MPLAliases_INC
#define  MOUSEION_MPLAliases_INC

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

//-----------------------------------------------------
//  Below we define aliases to boost mp11 meta        -
//  programming library.                              -
//                                                    -
//-----------------------------------------------------

//-----------------------------------------------------
// The alias to the the boost mp11 typelist.
//
//-----------------------------------------------------
template<typename ...T>
using mpl_typelist = boost::mp11::mp_list<T...>;

//-----------------------------------------------------
// The alias to the the boost mp11 transformation type
// that just returns the same type. It’s useful both as
// such, and as a type wrapper for passing types as
// values to functions.
//-----------------------------------------------------
template<typename T>
using mpl_type2type = boost::mp11::mp_identity<T>;

template<typename L>
using mpl_size = boost::mp11::mp_size<L>;

template<typename L>
using mpl_rest = boost::mp11::mp_rest<L>;

template<typename L>
using mpl_rest_size = mpl_size< mpl_rest<L> >;

template<typename L>
using mpl_front = boost::mp11::mp_front<L>;

template<typename L>
using mpl_front_size = mpl_size< mpl_front<L> >;


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_MPLAliases_INC  ----- 
