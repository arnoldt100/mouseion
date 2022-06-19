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


template<template<typename,typename> class F, typename AbstractProduct, typename IdentifierType, class TList>
class RegisterObjectFactories 
{
    public :
        RegisterObjectFactories(const int nm=0) :
            number_objects_registered_(nm) 
        {
            return;
        }

        void operator()(F<AbstractProduct,IdentifierType> & obj_factory)
        {
            return;
        }

    private:
        int number_objects_registered_;
};

}; // namespace MPL

#endif   /* ----- #ifndef MPL_RegisterObjectFactories_INC  ----- */
