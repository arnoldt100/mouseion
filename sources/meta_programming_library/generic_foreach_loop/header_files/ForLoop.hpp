#ifndef  MPL_ForLoop_INC
#define  MPL_ForLoop_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"

namespace MPL
{



// =====================================================================================
//        Class:  ForLoop
//  Description:  
// =====================================================================================

template<int N_initial, int N_final, int N, typename TypeList, class Wrapper>
class ForLoopOverTypeListNext
{
    public:

        void operator()()
        {
            if constexpr ( (N_initial <= N) && (N <= N_final )  )
            {
                // Instantiate an instance of the Wrapper for the N'th iteration
                // and do functor call.
                Wrapper member;
                member .template operator()<N>();
               
                // Compute the increment.
                constexpr auto dN = ( N_initial <= N_final ) ? 1 : -1;

                // Call ForLoopOverTypeListNext for next ieration.
                ForLoopOverTypeListNext<N_initial,N_final,N+dN,TypeList,Wrapper> a_forloop;
                a_forloop();
            }
            return;
        }

        std::shared_ptr<Wrapper> wrapper_; 

}; // -----  end of class ForLoopOverTypeListNext  -----

template<typename TypeList, class Wrapper >
class ForLoopOverTypeList
{
    public:

        ForLoopOverTypeList()
        {
            return;
        }

        void operator()()
        {
            // Compute the bounds of the TypeList. 
            constexpr auto N_initial=0;
            constexpr auto N_final = MPL::mpl_size<TypeList>::value-1;

            // The values of N_initial or N_final can't be negative for it will
            // break the indexing of TypeList. The TypeList uses positive integers
            // for its indexing.
            if constexpr ( ( N_initial < 0 ) || (N_final < 0) )
            {
                return; 
            }

            // Compute the index for the wrapper functor call.
            constexpr auto N = ( N_initial <= N_final ) ? N_initial : N_final;

            if constexpr ( (N_initial <= N) && (N <= N_final )  )
            {
                // Instantiate an instance of the Wrapper for the N'th iteration
                // and do functor call.
                Wrapper member;
                member .template operator()<N>();

                // Compute the increment.
                constexpr auto dN = ( N_initial <= N_final ) ? 1 : -1;

                // Call ForLoopOverTypeListNext for next ieration.
                ForLoopOverTypeListNext<N_initial,N_final,N+dN,TypeList,Wrapper> a_forloop;
                a_forloop();
            }
            return;

            std::shared_ptr<Wrapper> wrapper_; 

        }

}; // -----  end of class ForLoopOverTypeList  -----



}; // namespace MPL

#endif   /* ----- #ifndef MPL_ForLoop_INC  ----- */
