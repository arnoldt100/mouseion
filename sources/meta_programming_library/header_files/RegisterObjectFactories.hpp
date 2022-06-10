#ifndef  MPL_RegisterObjectFactories_INC
#define  MPL_RegisterObjectFactories_INC

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
#include "MPLAliases.hpp"

namespace MPL
{


template<template<typename,typename> class F, typename baseclass, typename classID, class TList>
class RegisterObjectFactories 
{
    public :

        void operator()(F<baseclass,classID> & arg1)
        {
            std::cout << "Size of typelist is " << MPL::mpl_size<TList>::value << std::endl;
            return;
        }
};

template<template<typename,typename> class F, typename baseclass, typename classID>
class RegisterObjectFactories< F, 
                               baseclass,
                               classID,
                               mpl_typelist<> > 
{
    public :
        void operator()(F<baseclass,classID> & arg1)
        {
            return;
        }
};

}; // namespace MPL

#endif   /* ----- #ifndef MPL_RegisterObjectFactories_INC  ----- */
