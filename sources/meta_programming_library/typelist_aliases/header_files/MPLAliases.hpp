#ifndef  MOUSEION_MPLAliases_INC
#define  MOUSEION_MPLAliases_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <type_traits>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "boost/mp11.hpp"

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

// ---------------------------------------------------
// The alias for 
// template <int I> 
// using mp_int =std::integral_constant<int, N>
//
// ---------------------------------------------------
template <int T>
using mpl_int = boost::mp11::mp_int<T>;

//-----------------------------------------------------
// The alias to the the boost mp11 transformation type
// that just returns the same type. It’s useful both as
// such, and as a type wrapper for passing types as
// values to functions.
//-----------------------------------------------------
template<typename T>
using mpl_type2type = boost::mp11::mp_identity<T>;

// ----------------------------------------------------
// Wraps a static constant of type bool.
// ----------------------------------------------------
template <bool T>
using mpl_bool = boost::mp11::mp_bool<T>;

// ----------------------------------------------------
// Same as std::bool_const in C++17
// Wraps the static constant true type.
// ----------------------------------------------------
using mpl_true_type = boost::mp11::mp_bool<true>;

//-----------------------------------------------------
// The alias to boost mp11 mp_size which is the alias
// template<std::size_t N> using mpl_size = std::integral_constant<std::size_t, N>;
//-----------------------------------------------------
template<typename L>
using mpl_size = boost::mp11::mp_size<L>;

//-----------------------------------------------------
// The alias to boost mp11 list size 0.
//-----------------------------------------------------
using mpl_size_0 = mpl_size<mpl_typelist<>>; 

//-----------------------------------------------------
// The alias to boost mp11 list size 1.
//-----------------------------------------------------
using mpl_size_1 = mpl_size< mpl_typelist<int>>; 

// ---------------------------------------------------
// The alias for boost::mp11::mp_empty
// ---------------------------------------------------
template <typename L>
using mpl_empty = boost::mp11::mp_empty<L>;

//-----------------------------------------------------
// The alias to boost mp11 to pop the first list 
// element and return the remainder of the list.
//-----------------------------------------------------
template<typename L>
using mpl_rest = boost::mp11::mp_rest<L>;

//-----------------------------------------------------
// The alias to boost mp11 to pop the first list 
// element and return the size of the remainder of the 
// list.
//-----------------------------------------------------
template<typename L>
using mpl_rest_size = mpl_size< mpl_rest<L> >;

//-----------------------------------------------------
// The alias to boost mp11 to pop the first list 
// element and return the front of the  list.
//-----------------------------------------------------
template<typename L>
using mpl_front = boost::mp11::mp_front<L>;

//-----------------------------------------------------
// The alias to boost mp11 to pop the first list 
// element and return the size of the front of the
// list element..
//-----------------------------------------------------
template<typename L>
using mpl_front_size = mpl_size< mpl_front<L> >;

//-----------------------------------------------------
// The alias to boost mp11 to reverse the elements
// of the typelist.
//-----------------------------------------------------
template<typename L>
using mpl_reverse = boost::mp11::mp_reverse<L>;

// ----------------------------------------------------
// The alias to boost mp11 to return the I-th element
// of L, zero-based.
// ----------------------------------------------------
template <typename L,std::size_t I>
using mpl_at_c = boost::mp11::mp_at_c<L,I>;

// ----------------------------------------------------
// mp_if_c<true, T, E...> is an alias for T. 
// mp_if_c<false, T, E...> is an alias for E. 
// Otherwise, the result is a substitution failure.
// ----------------------------------------------------
template <bool C, class T, class... E>
using mpl_if_c = boost::mp11::mp_if_c<C,T,E...>;

// ----------------------------------------------------
// If Derived is derived from Base or if both are the same non-union class (in
// both cases ignoring cv-qualification), provides the member constant value
// equal to true. Otherwise value is false.
// ----------------------------------------------------
template<class Base,class Derived>
using mpl_is_base_of = std::is_base_of<Base,Derived>;

// ----------------------------------------------------
// Returns a list of the same form as L that consists of N concatenated copies
// of L.
// ----------------------------------------------------
template <typename L, std::size_t N>
using mpl_repeat_c = boost::mp11::mp_repeat_c<L,N>;

// ----------------------------------------------------
// mpl_transform<F, L1<T1…>, L2<T2…>, …, Ln<Tn…>> applies F to each successive
// tuple of elements and returns L1<F<T1, T2, …, Tn>…>
// ----------------------------------------------------
template<template<class...> class F, class... L> 
using mpl_transform = boost::mp11::mp_transform<F,L...>;

// ----------------------------------------------------
// mpl_find<L, V> returns the index at which the type V is located in the list
// L.  It’s an alias for boost::mp_size_t<I>. If L does not contain V,
// mpl_find<L, V> is mpl_size<L>.
// ----------------------------------------------------
template<typename L, typename V>
using mpl_find = boost::mp11::mp_find<L,V>;

// --------------------------------------------------G--
// mpl_size_type is the template parameter type used in
//  std::integral_constant<mpl_size_type,N> for MP11.
// ----------------------------------------------------
using mpl_size_type = mpl_size_1::value_type; 

// ----------------------------------------------------
// N is a type argument where N::value must be a nonnegative number. Returns
// mp_list<std::integral_constant<T, 0>, std::integral_constant<T, 1>, ... , 
// std::integral_constant<T, N::value-1>> where T is the type of N::value.
// ----------------------------------------------------
template<typename N>
using mpl_iota = boost::mp11::mp_iota<N>;

// ---------------------------------------------------
// mp_apply<F, L> applies the metafunction F to the contents of the list L,
// that is, mp_apply<F, L<T….> is an alias for F<T….> 
// ---------------------------------------------------
template< template<class...> class F, class L>
using mpl_apply = boost::mp11::mp_apply<F,L>;

}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_MPLAliases_INC  ----- 
