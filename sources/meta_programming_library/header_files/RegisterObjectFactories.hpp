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
        RegisterObjectFactories(const int nm=0) :
            number_objects_registered_(nm) 
        {
            return;
        }

        void operator()(F<baseclass,classID> & obj_factory)
        {

            if (  this->number_objects_registered_ <  MPL::mpl_size<TList>::value )
            {
                std::cout << "Size of typelist is " << MPL::mpl_size<TList>::value << std::endl;

                // The index of the next type to be registerd is this->number_objects_registered_ 
                constexpr int idx = MPL::mpl_size<TList>::value;

                // The class ID is this->number_objects_registered_ + 1
                constexpr int id = this->number_objects_registered_ + 1;

                obj_factory.registerFactory(id, MPL::mpl_at_c<TList,idx>::create);
            }
            return;
        }

    private:
        int number_objects_registered_;
};

template<template<typename,typename> class F, typename baseclass, typename classID>
class RegisterObjectFactories< F, 
                               baseclass,
                               classID,
                               mpl_typelist<> > 
{
    public :
        void operator()(F<baseclass,classID> & obj_factory)
        {
            return;
        }
};

}; // namespace MPL

#endif   /* ----- #ifndef MPL_RegisterObjectFactories_INC  ----- */
